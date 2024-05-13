/*****************************************************************/
/*    NAME: Michael Benjamin                                     */
/*    ORGN: Dept of Mechanical Engineering, MIT, Cambridge MA    */
/*    FILE: RMW_MOOSApp.cpp                                      */
/*    DATE: June 26th, 2008                                      */
/*                                                               */
/* This file is part of MOOS-IvP                                 */
/*                                                               */
/* MOOS-IvP is free software: you can redistribute it and/or     */
/* modify it under the terms of the GNU General Public License   */
/* as published by the Free Software Foundation, either version  */
/* 3 of the License, or (at your option) any later version.      */
/*                                                               */
/* MOOS-IvP is distributed in the hope that it will be useful,   */
/* but WITHOUT ANY WARRANTY; without even the implied warranty   */
/* of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See  */
/* the GNU General Public License for more details.              */
/*                                                               */
/* You should have received a copy of the GNU General Public     */
/* License along with MOOS-IvP.  If not, see                     */
/* <http://www.gnu.org/licenses/>.                               */
/*****************************************************************/

#include <iterator>
#include "RMW_MOOSApp.h"
#include "MBUtils.h"

using namespace std;

//---------------------------------------------------------
// Constructor

RMW_MOOSApp::RMW_MOOSApp()
{
  m_tally_recd = 0;
  m_tally_sent = 0;
  m_iterations = 0;

  m_start_time_postings   = 0;
  m_start_time_iterations = 0;

  m_input_wptx = "ROSWP_X";
  m_input_wpty = "ROSWP_Y";
  m_wpt_x = 0;
  m_wpt_y = 0;

  m_output_pt = "point=" + to_string(m_wpt_x) + ", " + to_string(m_wpt_y);
}

//---------------------------------------------------------
// Procedure: OnNewMail

bool RMW_MOOSApp::OnNewMail(MOOSMSG_LIST &NewMail)
{
  MOOSMSG_LIST::iterator p;
  for(p=NewMail.begin(); p!=NewMail.end(); p++) {
    CMOOSMsg &msg = *p;
    string key   = msg.GetKey();
    if(MOOSStrCmp(msg.GetKey(), m_input_wptx) && (msg.IsDouble())){
        m_tally_recd++;
        m_wpt_x = msg.GetDouble();
    }else if(MOOSStrCmp(msg.GetKey(), m_input_wptx) && (msg.IsDouble())){
      m_tally_recd++;
      m_wpt_y = msg.GetDouble();
    }
    m_tally_recd++;
    m_output_pt = "point=" + to_string(m_wpt_x) + ", " + to_string(m_wpt_y);
    // We don't need the below, but we keep anyway for clarity
    // string str = msg.GetString();
    // double dbl = msg.GetDouble();
    // bool   is_string = msg.IsDouble();
    // bool   is_double = msg.IsDouble();

    // if(key == m_output_name) 
    //   m_tally_recd++;
  }
  //  cout << "In On New Mail!!!!!!!!!!!!" << endl; 
  return true;
}


//---------------------------------------------------------
// Procedure: OnConnectToServer

bool RMW_MOOSApp::OnConnectToServer()
{
  RegisterVariables();  
  return(true);
}


//------------------------------------------------------------
// Procedure: RegisterVariables

void RMW_MOOSApp::RegisterVariables()
{
  if(m_output_name != "")
    Register(m_output_name, 0);
}


//---------------------------------------------------------
// Procedure: Iterate()

bool RMW_MOOSApp::Iterate()
{
  m_iterations++;

  unsigned int i, amt = (m_tally_recd - m_tally_sent);
  for(i=0; i<amt; i++) {
    m_tally_sent++;
    Notify(m_output_name, m_output_pt);
  }
  
  // If this is the first iteration just note the start time, otherwise
  // note the currently calculated frequency and post it to the DB.
  if(m_start_time_iterations == 0)
    m_start_time_iterations = MOOSTime();
  else {
    double delta_time = (MOOSTime() - m_start_time_iterations);
    double frequency = 0;
    if(delta_time > 0)
      frequency  = (double)(m_iterations) / delta_time;
    Notify(m_output_name+"_ITER_HZ", frequency);
  }
    

  // If this is the first time a received msg has been noted, just
  // note the start time, otherwise calculate and post the frequency.
  if(amt > 0) {
    if(m_start_time_postings == 0)
      m_start_time_postings = MOOSTime();
    else {
      double delta_time = (MOOSTime() - m_start_time_postings);
      double frequency  = 0;
      if(delta_time > 0)
	frequency = (double)(m_tally_sent) / delta_time;
      Notify(m_output_name+"_POST_HZ", frequency);
    }
  }
  return(true);
}



//---------------------------------------------------------
// Procedure: OnStartUp()
//      Note: happens before connection is open

bool RMW_MOOSApp::OnStartUp()
{
  STRING_LIST sParams;
  m_MissionReader.EnableVerbatimQuoting(true);
  //m_MissionReader.EnableVerbatimQuoting(false);
  m_MissionReader.GetConfigurationAndPreserveSpace(GetAppName(), sParams);

  //m_MissionReader.GetConfiguration(GetAppName(), sParams);
  
  STRING_LIST::iterator p;
  for(p = sParams.begin();p!=sParams.end();p++) {
    string line  = *p;
    cout << "[" << line << "]" << endl;

    string param = tolower(biteStringX(line, '='));
    string value = line;
    
    if(param == "output_var")
      m_output_name = value;
    else if(param == "input_x"){
      m_input_wptx = value;
    }
    else if(param == "input_y"){
      m_input_wpty = value;
    }
  }

  RegisterVariables();
  return(true);
}











