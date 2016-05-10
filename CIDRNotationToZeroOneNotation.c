#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//#include<time.h>

char* CIDRToZOM(int* );
void tenTotwo(int* );
char* randomZOM(char*,char*,char*);

int main(int argc,char* argv[])
{

  int oct[5];


  FILE *fp;
  fp=fopen(argv[1],"r");
  if(fp==NULL){
    printf("%sファイルが開けません\n",argv[1]);
    return -1;
  }
  //  srand((unsigned int)time(NULL));
  
  while(fscanf(fp,"%d.%d.%d.%d/%d",&oct[0],&oct[1],&oct[2],&oct[3],&oct[4]) != EOF){
    printf("%s\n",randomZOM(CIDRToZOM(oct),argv[2],argv[3]));    
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


char* randomZOM(char* RZOM,char* pro1,char* pro2)
{
  int ran,i=0;
 
    while(i<32){
      ran=(rand()%100)+1; 
      if(RZOM[i]!='*'&&ran<=(atof(pro1)*100))
	RZOM[i]='*';
      else if(ran<=(atof(pro2)*100))
	RZOM[i]=rand()%2 ? '1' : '0'; 
      i++;
    }  
    
    return RZOM;
}
