#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> arr[1000001];
int vis[1000001];

int cc[1000001];
int curr;


void dfs(int node){

	vis[node] = 1;
	cc[node] = curr;

	for(int child : arr[node]){
		if(!vis[child]){
			dfs(child);
		}
	}

}


int main(){

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int t; cin>>t;

	while(t--){

		int n, k, a, b;
		string op;
		vector<pair<int, int> > vp;
		cin>>n>>k;

		for(int i=1; i<=n; i++){
			vis[i] = 0;
			arr[i].clear();
		}

		for(int i=1; i<=k; i++){
			cin>>a>>op>>b;

			if(op == "="){
				arr[a].push_back(b);
				arr[b].push_back(a);
			}else{
				vp.push_back({a, b});
			}
		}

		curr = 0;

		for(int i=1; i<=n; i++){
			if(!vis[i]){
				dfs(i), curr++;
			}
		}

		bool ff = 0;
		for(int i=0; i<vp.size(); i++){
			int a = vp[i].first;
			int b = vp[i].second;

			if(cc[a] == cc[b]){
				ff = 1;
				break;
			}
		}


		if(ff){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
		}

	}





	return 0;
}
