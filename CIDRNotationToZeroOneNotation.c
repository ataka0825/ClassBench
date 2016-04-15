#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char* CIDRToZOM(int* );
void tenTotwo(int* );

int main(int argc,char* argv[])
{

  int oct[5];
  
  FILE *fp;
  fp=fopen(argv[1],"r");
  if(fp==NULL){
    printf("%sファイルが開けません\n",argv[1]);
    return -1;
  }

  
  while(fscanf(fp,"%d.%d.%d.%d/%d",&oct[0],&oct[1],&oct[2],&oct[3],&oct[4]) != EOF){

   printf("%s\n",CIDRToZOM(oct));

  }
  
   fclose(fp);

  return 0;
}

char *CIDRToZOM(int* oct)
{
  static char ZOM[255];
  int i; 

  for(i=0;i<4;i++){
    tenTotwo(oct);
    ++oct;
  }

  sprintf(ZOM,"%08d%08d%08d%08d",oct[-4],oct[-3],oct[-2],oct[-1]);
  //  printf("%s\n",ZOM);
 

  //  printf("%c\n",ZOM[33]);
 for(i=0;(oct[0]+i)<32;i++){
    ZOM[oct[0]+i]='*';
  }
  return ZOM;
}

void  tenTotwo(int* oct)
{
  unsigned two[8];
  int i = 0;

   while (*oct != 0 && *oct!= 1) {
    two[i] = *oct%2;
    *oct = *oct >> 1;
    ++i;
  }
  two[i] = *oct;
  *oct = 0;
  while(i>=0){
    *oct = *oct + two[i]*pow(10,i);
    i--;
  }
}
