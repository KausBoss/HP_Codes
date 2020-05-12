#include <bits/stdc++.h>

using namespace std;

#define ll signed long long int
const int N = 1e5+1;
map<pair<string,ll>,ll> dp;
unordered_map<string,bool> m;
string s;
ll *a=NULL; 
int n;

bool sub(string v){
	if(m.count(v)){ return m[v];}
	ll grid[N][5] = {0};
	v = " "+v;
	string hd = " hard";
	for(int i=1; i<=v.length(); i++){
		for(int j=1; j<=4; j++){
			if(v[i] == hd[j]){ grid[i][j] = grid[i-1][j-1]+1;}
			else{grid[i][j]= max(grid[i-1][j], grid[i][j-1]);}
		}
	}
	m[v] = grid[v.length()-1][4]>3;
	//if(m[v]){cout<<"hard present in "<<v<<endl;}
	//else{cout<<"hard absent in "<<v<<endl;}
	return m[v];
	//return grid[v.length()-1][4]>3;
}

ll ways(ll i,  string v, ll cost){
	//base case
	if(i == n){
		return (sub(v))?1e11:cost;
	}
	//recursive case
	if(dp.count(make_pair(v, i))){ return dp[make_pair(v, i)];}

	v.push_back(s[i]);
	ll op1 = ways(i+1, v, cost);
	v.pop_back();

	ll op2 = ways(i+1, v, cost + a[i]);	
	dp[make_pair(v, i)] = min(op1, op2);
	return dp[make_pair(v, i)];
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	cin>>n;
	cin>>s;
	a = new ll[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
    cout<<ways(0, "", 0);
	// for(auto x:dp){
	// 	cout<<x.first.first<<" "<<m[x.first.first]<<" "<<x.second<<endl;
	// }
}