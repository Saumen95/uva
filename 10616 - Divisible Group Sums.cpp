#include <iostream>
#include <string.h>
using namespace std;
#define datatype signed long int

int main() {
    int n, q, cases = 0;
    cin >> n >> q;
    while (n || q) {
        cases++;
        datatype a[201];
        cout << "SET " << cases << ":" << endl;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int qq = 1; qq <= q; qq++) {
            int d, m;
            cin >> d >> m;
            int now = 0, b4 = 1;
            unsigned long long int T[2][11][20];
            memset(T, 0, sizeof(T));
            T[now][0][0] = 1;
            for (int i = 0; i < n; i++) {
                now = b4;
                b4 = (b4 + 1) % 2;
                for (int j = 0; j <= m; j++)
                    for (int k = 0; k < d; k++)
                        T[now][j][k] = T[b4][j][k];
                for (int j = 0; j < m; j++) {
                    for (int k = 0; k < d; k++) {
                        if (T[b4][j][k] != 0) {
                            int kk = (k + (a[i] % d) + d) % d;
                            T[now][j + 1][kk] += T[b4][j][k];
                        }
                    }
                }
            }
            cout << "QUERY " << qq << ": " << T[now][m][0] << endl;
        }
        cin >> n >> q;
    }
    return 0;
}
