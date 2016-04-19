#! /bin/bash

git clone git@github.com:tanakalab/ClassBench.git
cd ClassBench
wget http://www.arl.wustl.edu/classbench/db_generator.tar.gz
wget http://www.arl.wustl.edu/classbench/trace_generator.tar.gz
wget http://www.arl.wustl.edu/classbench/parameter_files.tar.gz
tar xfvz db_generator.tar.gz
tar xfvz trace_generator.tar.gz
tar xfvz parameter_files.tar.gz
cd db_generator
make all
cd ../trace_generator
make all
cd ..
cp db_generator/db_generator ./db_generator1
cp trace_generator/trace_generator ./trace_generator1
gcc -O3 CIDRNotationToZeroOneNotation.c -o ZeroOneMask -lm
gcc -O3 tenTotwo.c -o tenTotwo -lm
