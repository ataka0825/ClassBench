#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//#include<time.h>

int* addPacketEvaluation(char*,char*,int*);

int main(int argc,char* argv[])
{

  int i=0,eval[255];
  char filter[255][255],packet[255];
  FILE *fp1,fp2;
  
  fp1=fopen(argv[1],"r");
  if(fp1==NULL){
    printf("%sファイルが開けません\n",argv[1]);
    return -1;
  }
  
    fp2=fopen(argv[1],"r");
  if(fp2==NULL){
    printf("%sファイルが開けません\n",argv[2]);
    return -1;
  }

  while(fscanf(fp1,"%s",&filter[i]) != EOF){
    i++;
}
  i=0;
  while(fscanf(fp2,"%s",&packet) != EOF){
    addPacketEvaluation(filter,packet,eval);
    i++;

  }

  for(i=0;filter[i]!='/0';i++){
    printf("%s %d\n",filter[i],eval[i]);
  }
  
  fclose(fp1)
  fclose(fp2);
  return 0;
}



void addPacketEvaluation(char* filter,char* packet,int* eval)
{
  int i,j; 
  for(i=0;;i++){
    if(strlen(filter[i])!=strlen(packet)){
      printf("ルールリストとパケットの長さが一致しません")
	}
    for(j=0;filter[i][j]!='\0';j++){
      if(filter[i][j]!=packet[j]&&filter[i][j]!='*')
	break;
    }
  }
      

    }
  
	printf("%s %d",filter[i],eval)

}

