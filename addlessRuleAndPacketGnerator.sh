#! /bin/bash

./db_generator -bc acl1_seed 10000 2 0.5 -0.1 MyFilters10k # generate MyFilters10k
./trace_generator 1 0.1 10 MyFilters10k # generate MyFilters10k_trace
cat MyFilters10k_trace | awk {' print $1 '} > tmpPacketSA10
cat MyFilters10k_trace | awk {' print $2 '} > tmpPacketDA10
./tenTotwo tmpPacketSA10 > tmpPacketSA2
./tenTotwo tmpPacketDA10 > tmpPacketDA2
paste -d '' tmpPacketSA2 tmpPacketDA2 > packet2
rm tmp*
rm MyFilters10k*
