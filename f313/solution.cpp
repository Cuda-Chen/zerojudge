#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int r, c, k, m;
    scanf("%d %d %d %d", &r, &c, &k, &m);
    vector<int> arr(r * c);
    vector<int> dirs{1, 0, -1, 0, 1};
    for(int i = 0; i < r * c; i++)
        scanf("%d", &arr[i]);

    while(m--) {
        vector<int> migrant(r * c, 0);
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(arr[i * c + j] != -1) {
                    int counter = 0;
                    for(int k = 0; k < 4; k++) {
                        if((i + dirs[k]) >= 0 &&
                           (i + dirs[k]) < r &&
                           (j + dirs[k + 1]) >= 0 &&
                           (j + dirs[k + 1]) < c &&
                           (arr[(i + dirs[k]) * c + (j + dirs[k + 1])] != -1))
                            counter++;
                    }

                    int temp = arr[i * c + j] / k;
                    arr[i * c + j] -= (temp * counter);

                    for(int k = 0; k < 4; k++) {
                        if((i + dirs[k]) >= 0 &&
                           (i + dirs[k]) < r &&
                           (j + dirs[k + 1]) >= 0 &&
                           (j + dirs[k + 1]) < c &&
                           (arr[(i + dirs[k]) * c + (j + dirs[k + 1])] != -1))
                            migrant[(i + dirs[k]) * c + (j + dirs[k + 1])] += temp;
                    }
                }
            }
        }

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(arr[i * c + j] != -1)
                    arr[i * c + j] += migrant[i * c + j];
            }
        }
    }

    arr.erase(remove(arr.begin(), arr.end(), -1), arr.end()); // remove -1
    printf("%d\n", *min_element(arr.begin(), arr.end()));
    printf("%d\n", *max_element(arr.begin(), arr.end()));

    return 0;
}
