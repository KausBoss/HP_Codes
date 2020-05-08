#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 1000000007

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	if(n==1){cout<<0; return 0;}
	if(n==2){cout<<1; return 0;}
	int ans=1;
	for(int i=3; i<=n; i++){
		ans *= (i-1);
		ans %= mod;
	}
	cout<<ans;
}