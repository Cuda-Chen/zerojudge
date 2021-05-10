// https://66lemon66.blogspot.com/2021/01/zerojudge-f315-4-c.html
// segment tree

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll int64_t

const int MAX = 1e5 + 1;
int n, x, mx, st[MAX << 3];
pair<int, int> p[MAX];

void update(int pos, int v = 1, int l = 0, int r = mx - 1) {
    if(l == r) {
        st[v] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid)
        update(pos, v << 1, l, mid);
    else
        update(pos, (v << 1) + 1, mid + 1, r);

    st[v] = st[v << 1] + st[(v << 1) + 1];
    return;
}

int query(int l, int r, int v = 1, int L = 0, int R = mx - 1) {
    if(l == L && r == R)
        return st[v];
    int mid = (L + R) >> 1;
    if(r <= mid)
        return query(l, r, v << 1, L, mid);
    else if(l > mid)
        return query(l, r, (v << 1) + 1, mid + 1, R);
    return query(l, mid, v << 1, L, mid) + query(mid + 1, r, (v << 1) + 1, mid + 1, R);
}

int main() {
    fastio;
    memset(p, -1, sizeof(p));
    cin >> n;
    mx = n << 1;
    for(int i = 0; i < mx; i++) {
        cin >> x;
        if(p[x].first == -1)
            p[x].first = i;
        else
            p[x].second = i;
    }

    memset(st, 0, sizeof(st));
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += query(p[i].first, p[i].second);
        update(p[i].first);
        update(p[i].second);
    }

    cout << ans << '\n';

    return 0;
}
