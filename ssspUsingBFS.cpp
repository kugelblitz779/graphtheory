#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> arr[100001];
int vis[100001];
vector<int> res;
int dist[10001];


void bfs(int node){

	queue<pair<int, int> > q;

	q.push(make_pair(node, 0));
	vis[node] = 1;

	while(!q.empty()){

		pair<int, int> n = q.front();
		int curr = n.first;
		int level = n.second;
		dist[curr] = level;
		res.push_back(curr);
		q.pop();

		for(int child : arr[curr]){
			if(!vis[child]){
				q.push(make_pair(child, level+1));
				vis[child] = 1; 
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



	int n; cin>>n;

	for(int i=1; i<=n-1; i++){

		int a, b; cin>>a>>b;

		arr[a].push_back(b);
		arr[b].push_back(a);

	}


	bfs(1);

	for(int i=1; i<=n; i++){
		cout<<dist[i]<<" ";
	}
	cout<<endl;



	return 0;
}
