#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int getPrefixLength(char*);
int getFourthOctet(char*);
int getThirdOctet(char*);
int getSecondOctet(char*);
int getFirstOctet(char*);
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

  CIDRToZOM("133.72.254.128/27");
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

  oct1=tenTotwo(oct1,getFirstOctet(input));
  printf("%s\n", oct1);

  //char* = strstr(input,".");
  free(oct1);
  free(oct2);
  free(oct3);
  free(oct4);

}

int getFirstOctet(char* rule)
{
  char oct1[3];
  {
    int i = 0;
    while (rule[i] != '.') {
      printf("%d\n",i);
      oct1[i] = rule[i];
      ++i;
    }
    if (2 == i) {
      oct1[i]='\0';
    }
    else if (1 == i) {
      oct1[i]='\0'
      oct1[++i]='\0'
    }
  }
  return atoi(oct1);

}
int getSecondOctet(char* rule)
{
  char oct2[3];
  {
    int j = 0;
    while (rule[j] != '.') {
      j++;
    }
    j++;
     while (rule[j] != '.') {
      printf("%d\n",j);
      oct2[j] = rule[j];
      ++j;
    }

    if (2 == j) {
      oct2[j]='\0';
    }
    else if (1 == j) {
      oct2[j]='\0'
      oct2[++j]='\0'
    }
  }
  return atoi(oct1);

}
int getThirdOctet(char* rule)
{
  char oct3[3];
  {
    int k = 0;
    while (rule[k] != '.') {
      ++k;
    }
    k++;
    while (rule[k] != '.') {
      ++k;
    }  
    k++;
    while (rule[k] != '.') {
      printf("%d\n",j);
      oct3[k] = rule[k];
      ++k;
    }
    if (2 == k) {
      oct3[k]='\0';
    }
    else if (1 == k) {
      oct3[k]='\0'
      oct3[++k]='\0'
    }
  }
  return atoi(oct1);

}
int getFourthOctet(char* rule)
{
  char oct3[3];
  {
    int l = 0;
    while (rule[l] != '.') {
      ++l;
    }  
    while (rule[l] != '.') {
      ++l;
    }
    while (rule[l] != '.') {
      ++l;
    } 
    while (rule[l] != '/') {
      printf("%d\n",l);
      oct4[l] = rule[l];
      ++l;
    }
    if (2 == l) {
      oct4[l]='\0';
    }
    else if (1 == l) {
      oct4[l]='\0'
      oct4[++l]='\0'
    }
  }
  return atoi(oct1);

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
