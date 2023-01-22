#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
const int inf = 0x3f3f3f3f;
const ll linf = 1234567890123456789;
const ll mod = 1000000007;
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " = " << (x) << endl
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for(int i = (a); i < int(b); i++)
#define trav(x, a) for(auto& x : a)

int n, k;
int a1, a2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n >> k;
    cin >> a1 >> a2;
    h = vvi(n, vi(k));
    vpi hs;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            cin >> h[i][j];
            hs.emplace_back(h[i][j], j);
        }
    }
    sort(all(hs));

    int lo = 0, hi = 0;
    while(1){

    }
}
