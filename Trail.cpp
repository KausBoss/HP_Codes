#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long
int main(){
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		if(n==1){
			cout<<1<<"\n"<<1<<" "<<1<<"\n";
			continue;
		}
		cout<<n/2<<"\n";
		for(int i=1; i<n; i=i+2){
			if(i+2>=n && n%2==1){
				cout<<3<<" "<<i<<" "<<i+1<<" "<<n<<"\n";
				break;
			}
			cout<<2<<" "<<i<<" "<<i+1<<"\n";
		}
	}
}