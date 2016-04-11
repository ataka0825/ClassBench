#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void CIDRToZOM(char*);
char* tenTotwo(char*, int);


int main(int argc,char* argv[])
{
  
  char*  rule=malloc(32);
  FILE *fp;
  fp=fopen(argv[1],"r");
  if(fp==NULL){
    printf("%sファイルが開けません\n",argv[1]);
    return -1;
  }

  CIDRToZOM(rule);
  fclose(fp);

  return 0;
}

void CIDRToZOM(char* input)
{

  char* oct1 = (char*)calloc(8,sizeof(char));
  char* oct2 = (char*)calloc(8,sizeof(char));
  char* oct3 = (char*)calloc(8,sizeof(char));
  char* oct4 = (char*)calloc(8,sizeof(char));
  //int num10=atoi(x);
  oct1=tenTotwo(oct1,32);
  printf("%s\n", oct1);

  //char* = strstr(input,".");
  free(oct1);
  free(oct2);
  free(oct3);
  free(oct4);

}

char* tenTotwo(char* oct, int num10)
{
  char *ends;
  char ans[8];
  //printf("%ld\n", num10);
  unsigned two[8];
  int i = 0;
  while (num10 != 0 && num10 != 1) {
    two[i] = num10%2;
    if (two[i] == 0)
      ans[i] = '0';
    else
      ans[i] = '1';
    num10 = num10 >> 1;
    ++i;
  }

  two[i] = num10%2;
  if (two[i] == 0)
    ans[i] = '0';
  else
    ans[i] = '1';
  ++i;

  for (; i < 8; ++i) {
    two[i] = 0;
    ans[i] = '0';
  }

  int j = 0;  
  for (i = 7; i >= 0; --i) {
   //   printf("%d",two[i]);
   //printf("%c",ans[i]);
   oct[j] = ans[i];
   j++;
  }

  //putchar('\n');
 
  return oct;
}
