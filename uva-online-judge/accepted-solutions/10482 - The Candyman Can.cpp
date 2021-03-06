//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 10482 - The Candyman Can
// Time Limit   : .000s
// Description  :
//============================================================================
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a) | (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 644

int n, m, a[35], k = 0, res;
int f[35][maxN][maxN];

void find(int a, int b) {
    int mn = min(a, min(b, m - a - b));
    int mx = max(a, max(b, m - a - b));
    res = min(res, mx - mn);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    fill(f, 0);
    int cases;
    for (scanf("%d", &cases); cases--; ) {
        ++k;
        scanf("%d ", &n);
        m = 0;
        fr(i, 1, n) {
            scanf("%d", &a[i]);
            m += a[i];
        }
        res = INF;
        sort(a + 1, a + n + 1);
        f[0][0][0] = k;
        find(0, 0);
        fr(i, 0, n) fr(u, 0, m) fr(v, 0, m) if (f[i][u][v] == k) {
            find(u, v);
            
            if (i == n) continue;
            
            f[i + 1][u][v] = k;
            int uu = u + a[i + 1], vv = v;
            if (uu > vv) swap(uu, vv);
            f[i + 1][uu][vv] = k;
            
            uu = u; vv = v + a[i + 1];
            if (uu > vv) swap(uu, vv);
            f[i + 1][uu][vv]= k;
        }
        printf("Case %d: %d\n", k, res);
    }
    return 0;
}

/* Copyright (C) 2012, LamPhanViet */
