#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int t, gray[130]={1};
	for(int i=1; i<130; i++){
		gray[i]=(gray[i-1])^(gray[i-1]>>1);
		cout<<gray[i-1]<<" ";
	}
	// cin>>t;
	// while(t--){
	// 	ll n;
	// 	cin 
	// }
}