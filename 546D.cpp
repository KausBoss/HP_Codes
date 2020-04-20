#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 5000001
#define F(a) (a*(a+1))/2



vector<ll> prime;
 void sieve(){
 	//bool pr[inf];
 	bitset<inf> pr;
 	//memset(pr, true, sizeof(pr));
 	for(ll i=3; i*i<=inf; i+=2){
 		if(!pr[i]){
 			for(ll j=i*i; j<=inf; j+=2*i){
 				pr[j]=1;
 			}
 		}
 	}
 	prime.push_back(2);
 	for(ll i=3; i<inf; i+=2){
 		if(!pr[i]){
 			prime.push_back(i);
 		}
 	}
 }


ll factor(ll n){
	//base case
	if(n==1){
		return 0;
	}
	//recursive case
	int i=0; 
	while(n%prime[i]!=0){
		i++;
	}
	return factor(n/prime[i]) +1;
}

 int main(){
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	sieve();
 	/*
 	cout<<prime.size();
 	cout<<"\n"<<prime.back()<<" "<<prime[0];
 	
 	for(int i=0; i<prime.size()/2; i++){
 		cout<<prime[i]<<" ";
 	}
 	*/
 	int t;
 	cin>>t;
 	while(t--){
 		ll a, b;
 		cin>>a>>b;
 		ll count=0;
 		ll start, end;
 		if (b+1 == a){
 			count = factor(a);
 		}
 		else{
 			for(ll i=0; prime[i]<=a; i++){
 				ll n = prime[i];
 				ll start = n*((b+1)/n);
 				if(start<(b+1)){start += n;}

 				end = n*(a/n);
 				if(end>a){end -= n;}

 				count +=((end-start)/n) + 1;

 				//checking for powers 
 				start = log(b+1)/log(n);
 				ll num = pow(n, start);
 				if(num < (b+1)){start++;}

 				end = log(a)/log(n);
 				ll num2 = pow(n, end);
 				if(num2 > a){end--;}

 				if(start <= end){
 					if(start>1){
 						start-=2;
 						end-=1;
 						count+= F(end) - F(start);
 					}
 				}

 			}
 		}
 		cout<<count<<"\n";	
 	}
 }