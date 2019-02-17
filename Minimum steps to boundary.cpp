/* Input: matrix[] = {1, 1, 1, 0, 1}
                  {1, 0, 2, 0, 1}
                  {0, 0, 1, 0, 1}
                  {1, 0, 1, 1, 0}
Output: 2
Move to the right and then move
upwards to reach the nearest boundary
edge.

Input: matrix[] = {1, 1, 1, 1, 1}
                  {1, 0, 2, 0, 1}
                  {1, 0, 1, 0, 1}
                  {1, 1, 1, 1, 1}
Output: -1
*/
#include <bits/stdc++.h>
using namespace std;
#define r 4
#define c 5

// checking validity
bool check(int i, int j, int mat[r], int m,int n){
    if (i>=0 && i<m && j>0 && j<n)
    {
        if (mat[i][j] == 0)
        {
            return true;
        }
        return false;
    }
}

// Minimum steps
int findMinStep(int m,int n, mat[r]){
    int indx,indy;
    indx=indy=-1;
    // finding distace betn only 2 points
    for (int i= 0; i< n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j]==2)
            {
                indx=i,indy=j;
                break;
            }
        }
        if (indx != -1)
        {
            /* code */
            break;
        }
    }
}

std::queue<pair> int,pair<int,int>>> q;
q.push(make_push(0,(indx,indy)));

// checks if already on boundary
if (check(indx, indy, n, m, mat))
{
    /* code */
    return 0;
}

// marks visited
bool vis[r];
memset(vis,0,sizeof vis);

// itarate the std::queue<int> name;
while (!q.empty())
{
    auto it = q.front;
    q.pop();

    // get the position
    int x = it.second.first;
    int y = it.second.second;

    //Moves
    int val = it.first;

    if (x == 0 || x == (n - 1) || y == 0 || y == (m - 1))
    {
        return val;
    }
}
