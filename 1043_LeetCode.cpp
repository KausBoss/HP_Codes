#include <bits/stdc++.h>

using namespace std;

#define ll long long
vector<int> dp;
int maxSumAfterPartitioning(vector<int>& A, int K) {
    int N = A.size();
    dp = vector<int>(N,0);
    for (int i = 0; i < N; ++i) {
        int curMax = 0;
        for (int k = 1; k <= K && i - k + 1 >= 0; ++k) {
            curMax = max(curMax, A[i - k + 1]);
            dp[i] = max(dp[i], (i >= k ? dp[i - k] : 0) + curMax * k);
        }
    }
    return dp[N - 1];
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	vector<int> v{1,15,7,9,2,5,10};
	maxSumAfterPartitioning(v, 3);
	for(auto x:dp){
		cout<<x<<" ";
	}
}
