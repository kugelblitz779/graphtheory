#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> arr[100001];
int vis[100001];
pair<int, int> maxi = make_pair(INT_MIN, -1);


void dfs(int node, int level){

	vis[node] = 1;

	if(level > maxi.first){
		maxi.first = level;
		maxi.second = node;
	}

	for(int child : arr[node]){

		if(!vis[child]){
			dfs(child, level + 1);
		}
	}


}


int main(){

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n; cin>>n;

	for(int i=1; i<=n-1; i++){

		int a, b; cin>>a>>b;

		arr[a].push_back(b);
		arr[b].push_back(a);

	}


	dfs(1, 0);

	pair<int, int> p = maxi;
	cout<<p.first<<p.second<<endl;

	for(int i=1; i<=n; i++){
		vis[i] = 0;
	}

	maxi.first = INT_MIN;
	maxi.second = -1;

	dfs(p.second, 0);



	pair<int, int> fin = maxi;

	cout<<fin.first<<fin.second<<endl;



	return 0;
}