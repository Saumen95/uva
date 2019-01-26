#include <stdio.h>
#include <string.h>

#define s 25

int block[s][s];
int result[s];
int n;

int find(int val,int &pos)
{
  int position =0,i,j,flag=1;

  for(i=0;i<n && flag;i++)
	  for(j=0;j<result[i];j++)
		  if(block[i][j]==val)
		  {
		    pos=j;
			position=i;
			flag=0;
			break;
		  }
   return position;
}


void return_to_initial(int row, int p)
{
  int val;

  for(p;p<result[row];p++)
  {
    val=block[row][p];
	block[val][result[val]]=block[row][p];
	result[val]++;
  }
}



int main()
{
  char input[50],x[10],y[10];
  int i,j,a,b,pos1,pos2,p;
  //freopen("b.in","r",stdin);



  while((scanf("%d\n",&n))==1)
  {
      /*initialize*/
	for(i=0;i<n;i++)
	{
	  block[i][0]=i;
	  result[i]=1;
	}


	while(gets(input))
	{

	  sscanf(input,"%s %d %s %d\n",&x,&a,&y,&b);

	  if(strcmp(x,"quit")==0)
		  break;

	  if(a==b|| a>=n || b>=n)
		  continue;


	  i=find(a,pos1);
	  j=find(b,pos2);

	  if(i==j)
		  continue;



	  if(strcmp(x,"move")==0)
	  {
	    return_to_initial(i,pos1+1);

		result[i]=pos1;
		if(strcmp(y,"onto")==0)
		{
		  return_to_initial(j,pos2+1);
		  result[j]=pos2+1;
		}

		block[j][result[j]++]=a;
	  }

	  else if(strcmp(x,"pile")==0)
	  {
	    if(strcmp(y,"onto")==0)
		{
		  return_to_initial(j,pos2+1);
		  result[j]=pos2+1;
		}
   	    for(p=pos1;p<result[i];p++)
		  block[j][result[j]++]=block[i][p];

        result[i]=pos1;
	  }
	}
    for(i=0;i<n;i++)
	{
	  printf("%d:",i);

	  if(!result[i])
	  {
	    printf("\n");
		continue;
	  }

	  for(j=0;j<result[i];j++)
		  printf(" %d",block[i][j]);
	  printf("\n");
	}
  }
  return 0;
}