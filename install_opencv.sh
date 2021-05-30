cd /tmp/
wget https://github.com/opencv/opencv/archive/4.5.0.tar.gz
wget -O opencv_contrib.tar.gz https://github.com/opencv/opencv_contrib/archive/4.5.0.tar.gz

tar -xf 4.5.0.tar.gz
tar -xf opencv_contrib.tar.gz

cd ./opencv-4.5.0 && mkdir build
cd build

cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/usr/local -DOPENCV_EXTRA_MODULES_PATH=../../opencv_contrib-4.5.0/modules ..
make -j7
sudo make install
