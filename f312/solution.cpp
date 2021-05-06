#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
  int a1, b1, c1, a2, b2, c2, n;
  scanf("%d %d %d", &a1, &b1, &c1);
  scanf("%d %d %d", &a2, &b2, &c2);
  scanf("%d", &n);

  int result = INT_MIN;
  for(int i = 0, j = n; i <= n; i++, j--) {
    int y1 = a1 * i * i + b1 * i + c1;
    int y2 = a2 * j * j + b2 * j + c2;
    result = max(result, y1 + y2);
  }

  printf("%d\n", result);

  return 0;
}
