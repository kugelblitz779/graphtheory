#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> arr[1000001];
int vis[1000001];
int level[1000001];
int dist[1000001];


void bfs(int node){

	queue<int> q;
	q.push(node);

	vis[node] = 1;
	dist[node] = 0;

	while(!q.empty()){

		int n = q.front();
		q.pop();


		for(int child : arr[n]){
			if(!vis[child]){
				q.push(child);
				vis[child] = 1;
				dist[child] = dist[n] + 1;
				level[dist[child]]++;
			}
		}

	}

}



int main(){

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n, m, a, b, src, dist;
	cin>>n>>m;

	for(int i=1; i<=m; i++){
		cin>>a>>b;

		arr[a].push_back(b);
		arr[b].push_back(a);
	}


	int q;
	cin>>q;

	while(q--){

		cin>>src>>dist;
		for(int i=0; i<=n; i++){
			vis[i] = 0, level[i] = 0;
		}

		bfs(src);
		cout<<level[dist]<<endl;

	}



	return 0;
}
