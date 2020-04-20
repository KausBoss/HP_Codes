#include <bits/stdc++.h>

using namespace std;

int freqq[200005]={0};

bool sorty(pair<int, int> a, pair<int, int> b){
	int at = freqq[a.first]+ freqq[a.second];
	int bt = freqq[b.first]+freqq[b.second];
	return at > bt;
}
int main(){
	memset(freqq, 0, sizeof(freqq));
	int n, k, a, b;
	map<int, int> m;
	priority_queue<int> p;
	vector<pair<int, int>> v;
	set<pair<int, int>> setty;
	m[1]=0;
	p.push(0);
	cin>>n>>k;
	for(int i=0; i<n-1; i++){
		cin>>a>>b;
		freqq[a]++;freqq[b++];
		if(a>b){swap(a,b);}
		v.push_back(make_pair(a,b));
	}
	sort(v.begin(), v.end(), sorty);

	for(int i=0; i<n-1; i++){cout<<v[i].first<<"--"<<v[i].second<<endl; }

	for(int i=0; i<n-1; i++){
		if(m.count(v[i].first)){
			m[v[i].second] = m[v[i].first] +1;
			p.push(m[v[i].first]+1);
		}
		else if(m.count(v[i].second)){
			m[v[i].first] = m[v[i].second] +1;
			p.push(v[i].second+1);
		}
		//else(setty.insert(v[i]));
	}
	// for(auto x:setty){
	// 	if(m.count(x.first)){
	// 		m[x.second]=x.first +1;
	// 	}
	// 	else if(m.count(x.second)){
	// 		m[x.first] = x.second+1; 
	// 	}
	//}
	int ans=0;

	for(int i=0; i<k; i++){
		ans += p.top();
		p.pop();
	}
	cout<<ans;
}