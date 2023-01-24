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
#define debug(x) cerr << (#x) << " = " << (x) << endl
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for(int i = a; i < (b); ++i)

int n;
int isprime[30001];

ll lowest(){
    if(isprime[n]){
        return n;
    }
    double bestlog = inf;
    ll bestmod;
    for(int i = 0; i+i <= n; i++){
        if(isprime[i] && isprime[n-i]){
            bestlog = log(i)+log(n-i);
            bestmod = i*(n-i);
            break;
        }
    }
    for(ll i = 0; i <= min(n,100); i++){
        if(!isprime[i]) continue;
        for(ll j = 0; j <= i; j++){
            if(isprime[j] && isprime[n-i-j]){
                double lg = log(i)+log(j)+log(n-i-j);
                if(lg < bestlog){
                    bestlog = lg;
                    bestmod = i*j*(n-i-j)%mod;
                }
            }
        }
    }
    for(ll i = 0; i <= min(n,10); i++){
        if(!isprime[i]) continue;
        for(ll j = 0; j <= i; j++){
            if(!isprime[j]) continue;
            for(ll k = 0; k <= j; k++){
                if(isprime[k] && isprime[n-i-j-k]){
                    double lg = log(i)+log(j)+log(k)+log(n-i-j-k);
                    if(lg < bestlog){
                        bestlog = lg;
                        bestmod = i*j*k*(n-i-j-k)%mod;
                    }
                }
            }
        }
    }
    return bestmod;
}

ll highest(){
    ll ans = 1;
    int m = n;
    while(m>0 && m%3 != 0) ans=ans*2%mod, m-=2;
    while(m>0) ans=ans*3%mod, m-=3;
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cin >> n;

    memset(isprime, -1, sizeof(isprime));
    isprime[0] = isprime[1] = 0;
    for(int i = 2; i < 30001; i++){
        if(!isprime[i]) continue;
        isprime[i] = 1;
        for(int j = 2*i; j < 30001; j+=i){
            isprime[j] = 0;
        }
    }

    cout << lowest() << " " << highest() << endl;

}
