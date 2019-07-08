#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    long numgroups;
    scanf("%lu\n", &numgroups);
    long groups[5] = {0};
    long temp;
    do
    {
        scanf("%lu\n",&temp);
        ++groups[temp];

    } while (--numgroups);
    long total = groups[4];
    total += groups[3];
    groups[1] -= groups[3];
    total += groups[2]/2 + groups[2]%2;
    groups[1] -= 2 * (groups[2] % 2);
    if (groups[1] > 0) {
      /* code */
      total += groups[1]/4 + (groups[1]%4 > 0);
    }

    printf("%lu\n",total);
    
    return 0;
}
