#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>

using namespace std;

bool cmp (string x, string y)
{
    string t1 = x + y;
    string t2 = y + x;

    if ( t1 > t2 ) return true;
    return false;
}
int main()
{
    int N;
    string a[55];
    while(scanf("%d",&N)==1)
    {
        if(N==0)
            break;
        for(int i=0;i<N;i++)
            cin>>a[i];
        sort(a,a+N,cmp);
        for(int i=0;i<N;i++)
            cout<<a[i];
        cout<<endl;

    }


    return 0;
}
