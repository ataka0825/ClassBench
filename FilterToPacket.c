#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//#include<time.h>
/*
char* CIDRToZOM(int* );
void tenTotwo(int* );
*/
char* createpacket(char*,char*);

int main(int argc,char* argv[])
{

  char filter[255];


  FILE *fp;
  fp=fopen(argv[1],"r");
  if(fp==NULL){
    printf("%sファイルが開けません\n",argv[1]);
    return -1;
  }
  //  srand((unsigned int)time(NULL));
  
  while(fscanf(fp,"%s",filter) != EOF){
    printf("%s\n",createpacket(filter,argv[2]));   
  }
  
   fclose(fp);

  return 0;
}


char* createpacket(char* ZOM,char* pro)
{
  int ran,i=0;
 
  while(i<32){
    ran=(rand()%100)+1; 
    if(ZOM[i]=='*')
      ZOM[i]=rand()%2 ? '1' : '0'; 
    else if(ran<=(atof(pro)*100))
      ZOM[i]=rand()%2 ? '1' : '0'; 
    i++;
  }  
  
  return ZOM;
}



/*
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

*/
