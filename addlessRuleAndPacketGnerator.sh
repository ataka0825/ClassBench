#! /bin/bash


if [ $# -ne 10 ];then

    echo "指定された引数は$#個です。"  
    echo "実行するには10個の引数が必要です。"
    exit 1
fi


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


./db_generator1 -bc ./parameter_files/$1 $2 $3 $4 $5 MyFilters10k # generate MyFilters10k
cat MyFilters10k | awk {' print $1 '} | sed -e 's/@//g' > tmpRuleSACIDR
cat MyFilters10k | awk {' print $2 '} > tmpRuleDACIDR
./ZeroOneMask tmpRuleSACIDR > tmpRuleSAZOM
./ZeroOneMask tmpRuleDACIDR > tmpRuleDAZOM
paste -d '' tmpRuleSAZOM tmpRuleDAZOM > $6
./trace_generator1 $7 $8 $9 MyFilters10k # generate MyFilters10k_trace
cat MyFilters10k_trace | awk {' print $1 '} > tmpPacketSA10
cat MyFilters10k_trace | awk {' print $2 '} > tmpPacketDA10
./tenTotwo tmpPacketSA10 > tmpPacketSA2
./tenTotwo tmpPacketDA10 > tmpPacketDA2
paste -d '' tmpPacketSA2 tmpPacketDA2 > ${10}
rm tmp*
rm MyFilters10k*
