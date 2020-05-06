#include <bits/stdc++.h>

using namespace std;

#define ll long 

map<pair<int,string>,int> m;

int func(string x, int i, string s){
	//base case
	if(i == s.length()){
		return 0;
	}
	//recursive case
	if(x[i] == s[i]){return func(x, i+1, s);}
	if(m.count(make_pair(i,x))){return m[make_pair(i,x)];}
	string ret=x;
	int ans=INT_MAX;
	for(int j=i; j<s.length(); j++){
		x[j]=s[i];
		ans = min(ans, func(x, i+1, s));
	}
	m[make_pair(i,ret)]=ans;
	return ans;
}

string compress(string s){
	string ans="";
	ans +=s[0];
	for(int i=1;i<s.length();i++){
		if(s[i]!=ans[ans.length()-1]){
			ans += s[i];
		}
	}
	return ans;
}
int strangePrinter(string s) {
    s = compress(s);
    string ans=s;
    for(auto &x:ans){
    	x='_';
    }
    return func(ans, 0, s);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
}
