/*****************************************************************/
/*    NAME: Michael Benjamin                                     */
/*    ORGN: Dept of Mechanical Engineering, MIT, Cambridge MA    */
/*    FILE: Relayer.h                                            */
/*    DATE: Jun 26th 2008                                        */
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

#ifndef RMW_MOOSAPP_HEADER
#define RMW_MOOSAPP_HEADER

#include "MOOS/libMOOS/MOOSLib.h"

class RMW_MOOSApp : public CMOOSApp
{
 public:
  RMW_MOOSApp();
  virtual ~RMW_MOOSApp() {}

  bool OnNewMail(MOOSMSG_LIST &NewMail);
  bool Iterate();
  bool OnConnectToServer();
  bool OnStartUp();

  void setOutputPT(std::string s) {m_output_name=s;}
  void setInputX(std::string s) {m_input_wptx=s;}
  void setInputY(std::string s) {m_input_wpty=s;}

 protected:
  void RegisterVariables();

 protected: // State variables
  unsigned long int m_tally_recd;
  unsigned long int m_tally_sent;
  unsigned long int m_iterations;

 protected: // Configuration variables
  std::string       m_output_pt;
  std::string       m_output_name;
  std::string       m_input_wptx;
  std::string       m_input_wpty;
  double            m_wpt_x;
  double            m_wpt_y;
  double            m_start_time_postings;
  double            m_start_time_iterations;
};

#endif 










