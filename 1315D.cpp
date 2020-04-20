#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define inf 200005

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	map<ll, set<ll>> m;
	ll n, a[inf], temp, ans=0;
	cin>>n;
	for(ll i=0; i<n; i++){
		cin>>a[i];
	}
	for(int i=0; i<n; i++){
		cin>>temp;
		m[a[i]].insert(temp);
	}

	for(auto it=m.begin(); it!=m.end(); it++){
		if(it->second.size() > 1){
			for(auto x=it->second.begin(); x!=it->second.end(); x++){
				ans += *x;
				m[it->first + 1].insert(*x);
			}
		}
	}
	cout<<ans;
}