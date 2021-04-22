# download MOOS file
cd ~/
svn co https://oceanai.mit.edu/svn/moos-ivp-aro/trunk/ moos-ivp
cd moos-ivp
svn update

# building software
sudo apt-get install g++ cmake xterm -y
sudo apt-get install libfltk1.3-dev freeglut3-dev libpng-dev libjpeg-dev -y
sudo apt-get install libxft-dev libxinerama-dev libtiff5-dev -y

./build-moos.sh
./build-ivp.sh

