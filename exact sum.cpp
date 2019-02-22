#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n,cost,i,j,x,y,flag,mn,res,book1,book2;
    while(scanf("%d",&n)!=EOF){
        int a[n];
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        cin>>cost;
        for(i=0,flag=0,mn=10000000;i<n;i++){
            for(j=i;j<n;j++){
                x=a[i];
                y=a[j];
                res=abs(x-y);
                if(x+y==cost&&res<mn){
                    book1=x;
                    book2=y;
                    mn=res;
                }
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n",book1,book2);
    }
    return 0;
}