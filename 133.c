#include <stdio.h>
 
int main() {
  int n, k, m;
  while (scanf("%d%d%d", &n, &k, &m) && n) {
    int people = 0, times = 0, left = 0, right = n + 1, p[21] = {0};
    while (people < n) {
      int L = k, R = m;
      if (L > (n - people)) L %= (n - people);
      if (R > (n - people)) R %= (n - people);
      if (!L) L = n - people;
      if (!R) R = n - people;
      for (; L; L--) {
        left++;
        if (left > n) left -= n;
        while (p[left]) {
          left++;
          if (left > n) left -= n;
        }
      }
      for (; R; R--) {
        right--;
        if (!right) right += n;
        while (p[right]) {
          right--;
          if (!right) right += n;
        }
      }
      times += 2;
      people += 2;
      printf("%3d", left);
      if (right != left) printf("%3d", right);
      else people--;
      if (!(times % 2) && people < n) printf(",");
      p[left] = 1;
      p[right] = 1;
    }
    puts("");
  }
  return 0;
}