#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define pb push_back 
using namespace std;
int A[400010], pref[30][400010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x, y, z, t;
	cin >> n >> x >> y >> z >> t;
	for(int i = 1; i <= n; i++){
		cin >> A[i];
	}
	for(int b = 0; b < 30; b++){
		for(int i = 1; i <= n; i++){
			if(A[i] & (1 << b))
				pref[b][i]++;
			pref[b][i] += pref[b][i - 1];
		}
	}
	ll ans = 0;
	for(int i = x; i <= z; i++){
		for(int b = 0; b < 30; b++){
			if(A[i] & (1 << b)){
				int x = (pref[b][t] - pref[b][y - 1]) % 2;
				ans ^= (1 << b) * (x);
			} 
		}
	}
	cout << ans << '\n';

}