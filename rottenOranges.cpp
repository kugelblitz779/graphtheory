#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define int int64_t
#define pii pair<int, int>
#define vi vector<int>
#define mpii map<int, int>
using namespace std;

int N, M;
int arr[101][101];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};


bool isValid(int x, int y){

	if(x < 1 || x > N || y < 1 || y > M){
		return false;
	}

	if(arr[x][y] == 0 || arr[x][y] == 2){
		return false;
	}

	return true;
}


int bfs(){

	queue<pii> q;

	int c = 0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			if(arr[i][j] == 2){
				q.push({i, j});
			}else if(arr[i][j] == 1){
				c++;
			}
		}
	}

	int iter = 0;

	while(!q.empty()){

		int sz = q.size();

		iter++;

		while(sz--){

			pii p = q.front();
			q.pop();

			int X = p.first;
			int Y = p.second;


			for(int i=0; i<4; i++){
				if(isValid(X+dx[i], Y+dy[i])){
					arr[X+dx[i]][Y+dy[i]] = 2;
					c--;
					q.push({X+dx[i], Y+dy[i]});
				}
			}

		}

		if(c == 0){
			return iter;
		}


	}

	return -1;


}


int32_t main(){

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin>>N>>M;

	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cin>>arr[i][j];
		}
	}

	
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}


	cout<<bfs()<<"\n";

	return 0;
}