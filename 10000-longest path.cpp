#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <math.h>
#define N 1000000
using namespace std;
 
int d [100 + 2] [100 + 2];
 
void reset (int n)
{
    for ( int i = 0; i <= n; i++ ) {
        for ( int j = 0; j <= n; j++ )
            d [i] [j] = INT_MIN;
        d [i] [i] = 0;
    }
}
 
int main ()
{
    int n;
    int cases = 0;
 
    while ( scanf ("%d", &n) && n ) {
        reset (n);
        int startNode;
        scanf ("%d", &startNode);
 
        int x;
        int y;
 
        while ( scanf ("%d %d", &x, &y) ) {
            if ( x == 0 && y == 0 )
                break;
               d [x] [y] = 1;
        }
 
        for ( int k = 1; k <= n; k++ ) {
            for ( int i = 1; i <= n; i++ ) {
                if ( d [i] [k] != INT_MIN ) {
                    for ( int j = 1; j <= n; j++ ) {
                        if ( d [k] [j] != INT_MIN )
                            d [i] [j] = max (d [i] [j], d [i] [k] + d [k] [j]);
                    }
                }
            }
        }
 
        int length = 0;
        int finishesAt;
 
        for ( int i = 1; i <= n; i++ ) {
            if ( length < d [startNode] [i] ) {
                length = d [startNode] [i];
                finishesAt = i;
            }
        }
 
        printf ("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",
        ++cases, startNode, length, finishesAt);
    }
 
    return 0;
}