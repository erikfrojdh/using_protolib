# using_protolib


## Build and install protolib

First build and install protolib. It's highly recommended to install in a custom location.

```
git clone https://github.com/erikfrojdh/protolib.git
cd protolib
mkdir build && cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/path/where/to/install
make -j8
make install

```


## Build the examples

Since we install in a custom location we need to give the path where protolib is installed. This is the same path as in the above code. 

Also make sure that root is installed and that you have sourced thisroot.sh

```
git clone https://github.com/erikfrojdh/using_protolib.git
cd using_protolib
mkdir build && cd build
cmake .. -DCMAKE_PREFIX_PATH=/path/where/protolib/is/installed
make -j8