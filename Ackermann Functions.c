#include<stdio.h>

int main()
{
    long long int i,j,n,temp,p,t,max;
    while(scanf("%lld %lld",&i,&j)==2)
    {
        if(i>j)
        {
            temp=i;
            i=j;
            j=temp;
        }
        if(i==0&&j==0) break;
        max=0;
        for(temp=i;temp<=j;temp++)
        {
            t=0;
            for (n=temp;n!=0;)
            {
                if (n%2==1) n=3*n+1;
                else n=n/2;
                t++;
                if(n==1)break;
            }
            if(max<t)
            {
                p=temp;
                max=t;
            }
        }
        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",i,j,p,max);
        }
        return 0;
}