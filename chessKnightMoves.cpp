#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define ll long long
using namespace std;

int endX, endY;

int vis[10][10];
char arr[10][10];
int dist[10][10];
int dx[] = {-1, -1, 1, 1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};


bool isValid(int x, int y){

	if(x < 1 || x > 8 || y < 1 || y > 8){
		return false;
	}

	if(vis[x][y]){
		return false;
	}

	return true;
}



int bfs(int x, int y){

	vis[x][y] = 1;
	dist[x][y] = 0;

	queue<pair<int, int> > q;

	q.push({x, y});

	while(!q.empty()){

		pair<int, int> p = q.front();

		int X = p.first;
		int Y = p.second;

		q.pop();

		for(int i=0; i<8; i++){

			if(isValid(X+dx[i], Y+dy[i])){
				dist[X+dx[i]][Y+dy[i]] = dist[X][Y] + 1;
				vis[X+dx[i]][Y+dy[i]] = 1;
				q.push({X+dx[i], Y+dy[i]});

				if(X+dx[i] == endX && Y+dy[i] == endY){
					return dist[endX][endY];
				}
			}

		}

	}

	return -1;

}





int main(){

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int q; cin>>q;

	int startX, startY;
	for(int i=0; i<q; i++){

		for(int i=1; i<=8; i++){
			for(int j=1; j<=8; j++){
				vis[i][j] = 0;
			}
		}

		string s, e;
		cin>>s>>e;

		startX = s[0] - 'a' + 1;
		startY = s[1] - '0';
		
		endX = e[0] - 'a' + 1;
		endY = e[1] - '0';


		cout<<bfs(startX, startY)<<endl;
	}

	


	


	return 0;
}