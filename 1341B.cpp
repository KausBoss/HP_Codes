#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define inf 200000

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll t;
	cin>>t;
	while(t--){
		ll n, k;
		ll a[inf], peak[inf]={0};
		cin>>n>>k;
		for(ll i=0; i<n; i++){
			cin>>a[i];
		}
		for(ll i=1; i<n-1; i++){
			if(a[i]>a[i-1] && a[i]>a[i+1]){
				peak[i]=69;
			}
		}
		ll mxbr=INT_MIN; 
		ll id=0, brk=0;

		for(ll i=1; i<=k; i++){
			if(peak[i]==69){
				brk++;
			}
		}

		for(ll i=k+1; i<n-1; i++){
			if(peak[i]==1){
				brk++;
			}
			if(peak[i-k-1]==1){brk--;}
			if(brk > mxbr){
				mxbr=brk;
				id=i-k;
			}
		}
		cout<<mxbr<<" "<<id<<endl;
	}
}