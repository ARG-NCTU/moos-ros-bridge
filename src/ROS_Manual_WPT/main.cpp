/*****************************************************************/
/*    NAME: Michael Benjamin                                     */
/*    ORGN: Dept of Mechanical Engineering, MIT, Cambridge MA    */
/*    FILE: main.cpp                                             */
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

#include "MBUtils.h"
#include "ReleaseInfo.h"
#include "ColorParse.h"
#include "RMW_MOOSApp.h"
#include "RMW_Info.h"

using namespace std;

int main(int argc, char *argv[])
{
  string mission_file;
  string run_command = argv[0];
  string input_wpt_x;
  string input_wpt_y;
  string output_var;

  for(int i=1; i<argc; i++) {
    string argi = argv[i];
    if((argi=="-v") || (argi=="--version") || (argi=="-version"))
      showReleaseInfoAndExit();
    else if((argi=="-e") || (argi=="--example") || (argi=="-example"))
      showExampleConfigAndExit();
    else if((argi == "-h") || (argi == "--help") || (argi=="-help"))
      showHelpAndExit();
    else if((argi == "-i") || (argi == "--interface"))
      showInterfaceAndExit();
    else if(strEnds(argi, ".moos") || strEnds(argi, ".moos++"))
      mission_file = argv[i];
    else if(strBegins(argi, "--alias="))
      run_command = argi.substr(8);
    else if(strBegins(argi, "--in_x="))
      input_wpt_x = argi.substr(7);
    else if(strBegins(argi, "--in_y="))
      input_wpt_y = argi.substr(7);
    else if(strBegins(argi, "--out="))
      output_var = argi.substr(6);
    else if(i==2)
      run_command = argi;
  }
  
  if(mission_file == "")
    showHelpAndExit();

  cout << termColor("green");
  cout << "ROS_Manual_WPT launching as " << run_command << endl;
  cout << termColor() << endl;

  RMW_MOOSApp manual_waypt;	
  if(input_wpt_x != "")
    manual_waypt.setInputX(input_wpt_x);
  if(input_wpt_y != "")
    manual_waypt.setInputY(input_wpt_y);
  if(output_var != "")
    manual_waypt.setOutputPT(output_var);

  manual_waypt.Run(run_command.c_str(), mission_file.c_str(), argc, argv);

  return(0);
}











