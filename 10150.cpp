#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

#define MAX 26000
int parent[MAX];
bool doublets(string a, string b) {
    int d=0;
    for (size_t i = 0; i < a.length(); i++)  d+= (a[i]!=b[i]);
    return d==1;
}
void printPath(int ai, int zi, vector<string> ws) {
    if (ai != zi)
        printPath(ai, parent[zi], ws);
    cout << ws[zi] << endl;
}
int main() {

    string a, z, word;
    vector<string> words[MAX];
    while (getline(cin, word) && word.size()) {
        if(words[word.size()].empty()) words[word.size()].push_back(""); // sentiel to start @ i=1.
        words[word.size()].push_back(word);
    }

    int CASE = 0;
    while ((cin >> a >> z)) {
        if (CASE++)
            cout << endl;
        vector<string> ws = words[a.size()];
        size_t ai = find(ws.begin(), ws.end(), a) - ws.begin();
        size_t zi = find(ws.begin(), ws.end(), z) - ws.begin();

        if (a.size() != z.size() || ai == ws.size() || zi == ws.size())
            cout << "No solution." << endl;
        else {
            memset(parent, 0, sizeof parent);
            parent[ai] = ai;
            queue<size_t> q;
            q.push(ai);
            while (q.size() && q.front() != zi) {
                int u = q.front();
                q.pop();
                for (size_t v = 0; v < ws.size(); v++) {
                    if (!parent[v] && doublets(ws[u], ws[v])) {
                        parent[v] = u;
                        q.push(v);
                    }
                }
            }
            if(!parent[zi]) cout << "No solution." << endl;
            else printPath(ai, zi, ws);
        }
    }
    return 0;
}
