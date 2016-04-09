#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void tenTotwo(char*);

int main(int argc,char *argv[])
{
  char s[255];
  char *answer;
  FILE *fp;
  fp=fopen(argv[1],"r");
  if(fp==NULL){
    printf("%sファイルが開けません\n",argv[1]);
    return -1;
  }

  while( fgets( s,255,fp ) != NULL )
  {
    tenTotwo(s);
    //printf("%s\n", answer);
  }
	
  fclose(fp);
  return 0;
}



void tenTotwo(char* y)
{

  char *ends;
  //  char ans[32];
  unsigned long ul=strtoul(y,&ends,0);
  //printf("%ld\n", ul);
  unsigned two[32];
  int i = 0;
  while (ul != 0 && ul != 1) {
    two[i] = ul%2;
    ul = ul >> 1;
    ++i;
  }

  two[i] = ul%2;
  ++i;

  for (; i < 32; ++i) {
    two[i] = 0;
  }

  int j = 0;  
  for (i = 31; i >= 0; --i) {
    //   ans[j]=two[i];
   j++;
   printf("%d",two[i]);
  }

  putchar('\n');
 
  /*
const int n = snprintf(NULL, 0, "%lu", ulong_value);
assert(n > 0);
char buf[n+1];
int c = snprintf(buf, n+1, "%lu", ulong_value);
assert(buf[n] == '\0');
assert(c == n);
  */

  //return (ultostr(two,&ends,0));
  //return ans;
}
 
