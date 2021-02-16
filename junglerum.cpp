#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define ll long long
using namespace std;

int n;

char arr[31][31];
int vis[31][31];
int dist[31][31];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


bool isValid(int x, int y){

	if(x < 1 || x > n || y < 1 || y > n){
		return false;
	}

	if(vis[x][y] || arr[x][y] == 'T'){
		return false;
	}

	return true;

}



void bfs(int x, int y){

	vis[x][y] = 1;
	dist[x][y] = 0;

	queue<pair<int, int> > q;

	q.push({x, y});

	while(!q.empty()){

		pair<int, int> p = q.front();

		int X = p.first;
		int Y = p.second;

		q.pop();

		for(int i=0; i<4; i++){
			if(isValid(X+dx[i], Y+dy[i])){
				dist[X+dx[i]][Y+dy[i]] = dist[X][Y] + 1;
				vis[X+dx[i]][Y+dy[i]] = 1;
				q.push({X+dx[i], Y+dy[i]});
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


	cin>>n;

	int startX, startY, endX, endY;

	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>arr[i][j];

			if(arr[i][j] == 'S'){
				startX = i;
				startY = j;
			}

			if(arr[i][j] == 'E'){
				endX = i;
				endY = j;
			}
		}
	}


	bfs(1, 1);

	cout<<dist[endX][endY]<<endl;


	return 0;
}