#--------------------------------------------------------
# The CMakeLists.txt for:                         ROS_Manual_WPT
# Author(s):                                uwe Zhang
#--------------------------------------------------------

# Set System Specific Libraries
if (${WIN32})
  SET(SYSTEM_LIBS
    wsock32)
else (${WIN32})
  SET(SYSTEM_LIBS
    m
    pthread)
endif (${WIN32})

SET(SRC
   RMW_MOOSApp.cpp  
   RMW_Info.cpp
   main.cpp
)  

ADD_EXECUTABLE(ROS_Manual_WPT ${SRC}	)

TARGET_LINK_LIBRARIES(ROS_Manual_WPT
   ${MOOS_LIBRARIES}
   mbutil
   ${SYSTEM_LIBS})

