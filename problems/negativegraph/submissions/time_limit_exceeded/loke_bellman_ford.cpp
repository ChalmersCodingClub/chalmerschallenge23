#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int N, M, K, A, B; cin >> N >> M >> K >> A >> B;
    vector<vector<pii>> graph(N);
    rep(i, 0, M) {
        ll a,b,c; cin >> a >> b >> c;
        graph[a].push_back(make_pair(c,b));
    }
    vi dist(N, 1e18);
    dist[A] = 0;
    rep(i, 0, N) {
        rep(a, 0, N) {
            trav(cb, graph[a]) {
                ll c,b; tie(c,b) = cb;
                dist[b] = min(dist[b], dist[a]+c);
            }
        }
    }
		ll dist_b_before = dist[B];
    rep(i, 0, N) {
        rep(a, 0, N) {
            trav(cb, graph[a]) {
                ll c,b; tie(c,b) = cb;
                dist[b] = min(dist[b], dist[a]+c);
            }
        }
    }
		ll dist_b_after = dist[B];
    if (dist_b_after == 1e18) {
        cout << "POSITIVE INFINITY" << endl;
    } else if (dist_b_after != dist_b_before) {
        cout << "NEGATIVE INFINITY" << endl;
    } else {
        cout << dist_b_after << endl;
    }
}
