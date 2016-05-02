#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//#include<time.h>

char* CIDRToZOM(int* );
void tenTotwo(int* );
char* randomZOM(char*,char*);

int main(int argc,char* argv[])
{
 
  int s_add[5],d_add[5],s_port[2],d_port[2],protocol[2],matches[2];


  FILE *fp;


 fp=fopen(argv[1],"r");
  if(fp==NULL){
    printf("%sファイルが開けません\n",argv[1]);
    return -1;
  }
 printf("hello!\n"); 

  //  srand((unsigned int)time(NULL));

  if(fscanf(fp,"@%d.%d.%d.%d/%d\t%d.%d.%d.%d/%d\t%d : %d\t%d : %d\t%x/%x\t%x/%x",&s_add[0],&s_add[1],&s_add[2],&s_add[3],&s_add[4],&d_add[0],&d_add[1],&d_add[2],&d_add[3],&d_add[4],&s_port[0],&s_port[1],&d_port[0],&d_port[1],&protocol[0],&protocol[1],&matches[0],&matches[1]) != EOF){
    printf("@%d.%d.%d.%d/%d %d.%d.%d.%d/%d %d:%d %d:%d %x/%x %x/%x\n",s_add[0],s_add[1],s_add[2],s_add[3],s_add[4],d_add[0],d_add[1],d_add[2],d_add[3],d_add[4],s_port[0],s_port[1],d_port[0],d_port[1],protocol[0],protocol[1],matches[0],matches[1]);

//    printf("%s\n",randomZOM(CIDRToZOM(oct),argv[2]));    
  }
  
   fclose(fp);

  return 0;
}

char *CIDRToZOM(int* add)
{
  static char ZOM[255];
  int i; 

  for(i=0;i<4;i++){
    tenTotwo(add);
    ++add;
  }

  sprintf(ZOM,"%08d%08d%08d%08d",add[-4],add[-3],add[-2],add[-1]);
  //  printf("%s\n",ZOM);
 

  //  printf("%c\n",ZOM[33]);
 for(i=0;(add[0]+i)<32;i++){
    ZOM[add[0]+i]='*';
  }
  return ZOM;
}

void  tenTotwo(int* add)
{
  unsigned two[8];
  int i = 0;

   while (*add != 0 && *add!= 1) {
    two[i] = *add%2;
    *add = *add >> 1;
    ++i;
  }
  two[i] = *add;
  *add = 0;
  while(i>=0){
    *add = *add + two[i]*pow(10,i);
    i--;
  }
}



char* randomZOM(char* RZOM,char* pro)
{
  int ran,i=0;
 
    while(i<32){
      ran=(rand()%100)+1; 
      if(RZOM[i]!='*'&&ran<=(atof(pro)*100))
	RZOM[i]='*';
      else if(ran<=(/*1-*/atof(pro)*100))
	RZOM[i]=rand()%2 ? '1' : '0'; 
      i++;
    }  
    
    return RZOM;
}
