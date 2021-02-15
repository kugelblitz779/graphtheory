#include<bits/stdc++.h>
#define ll long long
using namespace std;

int N, M;
int arr[10001][10001];
int vis[10001][10001];
int dist[10001][10001];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool isValid(int x, int y){

	if(x > N || x < 1 || y > M || y < 1){
		return false;
	}
	if(vis[x][y]){
		return false;
	}

	return true;

}


void bfs(int x, int y){

	queue<pair<int, int> > q;
	dist[x][y] = 0;
	vis[x][y] = 1;

	q.push({1, 1});

	while(!q.empty()){

		pair<int, int> p = q.front();
		q.pop();

		int currX = p.first;
		int currY = p.second;

		for(int i=0; i<4; i++){
			if(isValid(currX+dx[i], currY+dy[i])){
				dist[currX+dx[i]][currY+dy[i]] = dist[currX][currY] + 1;
				vis[currX+dx[i]][currY+dy[i]] = 1;
				q.push({currX+dx[i], currY+dy[i]});
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


	cin>>N>>M;


	bfs(1, 1);
	
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cout<<dist[i][j]<<" ";
		}
		cout<<"\n";
	}


	return 0;
}