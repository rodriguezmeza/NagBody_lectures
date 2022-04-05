Instruction to install plplot

Extract plplot located in NagBody_sources/additional_libs:

tar xvf plplot-5.15.0.tar.gz

Go to directory plplot-5.15.0

cd NagBody_lectures/NagBody_pkg/NagBody_sources/additional_libs/plplot-5.15.0

(directory name may change with the version)

Un pack it

tar xvf plplot-5.15.0.tar.gz

If necessary do:

export CC="gcc -O2"
export CXX="g++ -O2"
export FC="gfortran -O2"

Then execute:

mkdir build_dir
cd build_dir

We may install without Python, lua (luac), psttf.

In linux Ubuntu:

cmake -DCMAKE_INSTALL_PREFIX=$HOME/NagBody_lectures/NagBody_pkg/local/plplot -DENABLE_DYNDRIVERS=OFF -DPLD_psttfc=OFF -DPLD_plmeta=OFF .. >& cmake.out


In Mac OS X:

cmake -DCMAKE_INSTALL_PREFIX=$HOME/NagBody_lectures//NagBody_pkg/local/plplot -DENABLE_DYNDRIVERS=OFF -DPLD_psttfc=OFF -DPLD_plmeta=OFF -DENABLE_python:BOOL=OFF -DENABLE_lua:BOOL=OFF -DPLD_luac=OFF -DENABLE_cxx:BOOL=OFF -DPLD_psttf=OFF .. 2>&1 | tee cmake.out


Then execute:

make 2>&1 | tee make.out
make install 2>&1 | tee make_install.out

cd ..
rm -fR build_dir


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% LINUX UBUNTU %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

May be necessary to install cmake:

sudo apt-get install cmake

and the following packages:

sudo apt-get install libx11-dev
sudo apt-get install gnuplot
sudo apt-get install xorg-dev
sudo apt-get install liblasi-dev
sudo apt-get install swig
sudo apt-get install tcl




