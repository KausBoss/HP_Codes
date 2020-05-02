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
	int t;
	cin>>t;
	while(t--){
		int n, k;
		int a[100], pre[100]={0};
		cin>>n>>k;
		for(int i=0; i<n; i++){
			cin>>a[i];
			if(i==0){pre[i]=a[i];}
			else{pre[i]=pre[i-1]+a[i];}
		}
		int max_pre=pre[k-1];
		for(int i=k; i<n; i++){
			int curr=pre[i]-pre[i-k];
			max_pre = max(max_pre, curr);
		}
		vector<int> ans;
		int i=0, j=k-1;
		while(j<n){
			if()
		}
	}
}