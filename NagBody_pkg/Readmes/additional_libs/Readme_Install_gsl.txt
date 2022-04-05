Intructions to install gsl library

Let's go to directory gsl-2.7.1 and

tar xvf gsl-latest.tar.gz

./configure --prefix=$HOME/NagBody_lectures/NagBody_pkg/local 2>&1 | tee configure.log

make 2>&1 | tee make.log
make install 2>&1 | tee make_install.log

Free disk space:

make distclean
