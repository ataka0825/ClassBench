#! /bin/bash


if [ $# -ne 10 ];then

    echo "指定された引数は$#個です。"  
    echo "実行するには10個の引数が必要です。"
    exit 1
fi

./db_generator1 -bc ./parameter_files/$1 $2 $3 $4 $5 MyFilters10k # generate MyFilters10k
cat MyFilters10k | awk {' print $1 '} | sed -e 's/@//g' > tmpRuleSACIDR
cat MyFilters10k | awk {' print $2 '} > tmpRuleDACIDR
./ZeroOneMask tmpRuleSACIDR $6 > tmpRuleSAZOM
./ZeroOneMask tmpRuleDACIDR $6 > tmpRuleDAZOM
paste -d '' tmpRuleSAZOM tmpRuleDAZOM > $7
./trace_generator1 $8 $9 ${10} MyFilters10k # generate MyFilters10k_trace
cat MyFilters10k_trace | awk {' print $1 '} > tmpPacketSA10
cat MyFilters10k_trace | awk {' print $2 '} > tmpPacketDA10
./tenTotwo tmpPacketSA10 > tmpPacketSA2
./tenTotwo tmpPacketDA10 > tmpPacketDA2
paste -d '' tmpPacketSA2 tmpPacketDA2 > ${11}
rm tmp*
rm MyFilters10k*
