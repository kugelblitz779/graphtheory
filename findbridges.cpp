#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define ll long long
using namespace std;

vector<int> arr[100001];
int vis[100001];
int in[100001];
int low[100001];
int timer;

void findBridges(int node, int parent){

	vis[node] = 1;
	in[node] = low[node] = timer;
	timer++;

	for(int child : arr[node]){

		if(child == parent) continue;

		if(vis[child]){

			//parent != child && already visited -> back edge
			//also means that this child is an ancestor of node
			//back edge can never be bridge !

			low[node] = min(low[node], in[child]);

		}else{

			//not visited && is not a parent -> forward edge
			//bridge condition checked here

			findBridges(child, node);

			if(low[child] > in[node]){
				cout<<"bridge found ->"<<node<<" "<<child<<endl;
			}

			low[node] = min(low[child], low[node]); 


		}

	}


}




int main(){

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n, m; cin>>n>>m;

	for(int i=1; i<=m; i++){

		int a, b; cin>>a>>b;

		arr[a].push_back(b);
		arr[b].push_back(a);

	}


	timer = 0;

	findBridges(1, -1);


	return 0;
}