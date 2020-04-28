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
	string t;
	cin>>t;
	char s[t.length()];
	for(int i=0; i<t.length(); i++){
		s[i]=t[i];
	}
	s[t.length() - 1]='\0';
	char *ptr = strtok(s,"/");
	while(ptr!=NULL){
		while(*ptr!='\0'){
			cout<<*ptr++<<" ";
		}
		cout<<"|"<<ptr<<"|"<<endl;
		ptr=strtok(NULL, "/");
	}
}