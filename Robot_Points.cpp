#include <bits/stdc++.h>

using namespace std;

#define ll long long

int MaxPoints(int a[][5], int i, int j, int n){
	//base case
	if(i < 0){
		return 0;
	}
	//recursive case
	int left, right, seedha;
	left = right = seedha =-2;
	int ret = ((a[i][j]==-1)&&(i>=n-5))?0:a[i][j];

	seedha = MaxPoints(a, i-1, j, n);

	if(j!=0){
		left = MaxPoints(a, i-1, j-1, n);
	}
	if(j!=n-1){
		right = MaxPoints(a, i-1, j+1, n);
	}
	return (ret + max(left, max(seedha, right)));
}

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
		int n, a[13][5];
		cin>>n;
		for(int i=0; i<n; i++){
			for(int j=0; j<5; j++){
				cin>>a[i][j];
			}
		}
		for(int i=0; i<5; i++){a[n][i]=0;}
		cout<<MaxPoints(a, n, 2, n)<<endl;
	}
}