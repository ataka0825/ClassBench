# ClassBench ルール変換プログラム

ClassBench 

http://www.arl.wustl.edu/classbench/ 

で生成したルールを0, 1, *のルールへ変換するプログラム群

##目的
* trace generater で生成したパケットを64ビットの２進表記で表示させる.　     
例）  
 デフォルトでは32ビットの２進表記を8つに区切らず10進表記で表示していた.  
 理想は01100111100110111010011001010000と表示されてほしい所  
 現実はそれを01100111100110111010011001010000と表示されずに1738253904と表示される.　　

* filterset generaterで生成されるルールリストを0,1,＊で表現される形に変換する.   
 　さらに,0,1を＊に,＊を０,１に確率Pで変換する.
　例）  
   生成されるルールのアドレスは103.155.166.80/27のようにCIDR表記で表される.  
   103.155.166.80/27はプレフィックス長が27なのでサブネットマスクは11111111111111111111111111100000になる.  
   よって  
     01100111100110111010011001010000  
     11111111111111111111111111100000  
     01100111100110111010011001010000  
   より,
   0,1,* で表すと  
      011001111001101110100110010*****
   となる.ここで*は don't care を表す.  
   さらに,任意のマスクを含むルールにしたいので,0,1に0,1をマスクに変換する.
   つまり011001111001101110100110010*****を  
   01＊00111＊0011＊0111＊0＊10＊011001＊010＊00のように加工する.  
*  評価パケット数を付け加える  　

##Usage   
http://www.arl.wustl.edu/classbench からFilter Set GeneratorとTrace GeneratorとParameter filesをダウンロードする.     
コンパイルしたdb_generatorとtrace_generatorにシェルスクリプトのパラメーターを好きなように変えて走らせる.  
０,１,＊で構成されたルールリストRuleZOMと2進表記のパケットpacket2が生成される.  

implementation：  
 ./addlessRuleAndPacketGenerator.sh  (input parameter file) (number of filters) (smoothness(0~64)) (address scope(-1~1)) (application scope(-1~1)) (output Rule_filename) (Pareto parameter a) (Pareto parameter b) (scale) (output Packet_filename)



$ git clone git@github.com:tanakalab/ClassBench.git  
$ cd ClassBench  
$ wget http://www.arl.wustl.edu/classbench/db_generator.tar.gz  
$ wget http://www.arl.wustl.edu/classbench/trace_generator.tar.gz  
$ wget http://www.arl.wustl.edu/classbench/parameter_files.tar.gz  
$ tar xfvz db_generator.tar.gz  
$ tar xfvz trace_generator.tar.gz  
$ tar xfvz parameter_files.tar.gz  
$ cd db_generator  
$ make all  
$ cd ../trace_generator  
$ make all  
$ cd ..  
$ cp db_generator/db_generator ./db_generator1   
& cp trace_generator/trace_generator ./trace_generator1  
$ gcc -O3 CIDRNotationToZeroOneNotation.c -o ZeroOneMask -lm  
$ gcc -O3 tenTotwo.c -o tenTotwo -lm  
$ cp parameter_files/acl1_seed  ./  
$ ./addlessRuleAndPacketGenerator.sh



