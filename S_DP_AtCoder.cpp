#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 1000000007

ll dp[10005][101][2];
string s;
ll d;


ll solve(ll pos, ll modi, bool tight){
	//base case
	if(pos == s.length()){
		return modi==0;
	}
	//recursive case
	if(dp[pos][modi][tight]!=-1){return dp[pos][modi][tight];}

	ll ans=0
	ll end= (tight)?(s[i]-'0'):9;
	for(ll i=0; i<=end; i++){
		ans += (pos+1, (modi+i)%d, tight&(i==end));
	}
	return dp[pos][modi][tight] = ans;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	memset(dp, -1, sizeof(dp));
	cin>>s;
	cin>>d;
	cout<< solve(0, 0, 1);
}