#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
int i,j,k,l,t,sr1;
float sr2;
char s[100000];
while(scanf("%d",&t)==1)
{
scanf("\r");
for(i=0;i<t;i++)
 {
 gets(s);
 l=strlen(s);
 sr2=sqrt(l);
 sr1=sqrt(l);
 if(sr1==sr2)
  for(j=0;j<sr1;j++)
   for(k=j;k<l;k+=sr1)
    printf("%c",s[k]);
 else
 printf("INVALID");
 printf("\n");
 }
}
}