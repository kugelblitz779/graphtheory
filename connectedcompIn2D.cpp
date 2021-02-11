#include<bits/stdc++.h>
#define ll long long
using namespace std;

int N, M;
int arr[10001][10001];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int vis[10001][10001];


bool isValid(int x, int y){

	if(x < 1 || x > N || y < 1 || y > M){
		return false;
	}

	if(vis[x][y] || !arr[x][y]){
		return false;
	}

	return true;

}


void dfs(int x, int y){

	vis[x][y] = 1;

	for(int i=0; i<4; i++){
		if(isValid(x+dx[i], y+dy[i])){
			dfs(x+dx[i], y+dy[i]);
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

	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cin>>arr[i][j];
		}
	}

	int cc = 0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){

			if(!vis[i][j] && arr[i][j]){
				cc++;
				dfs(i, j);
			}
		}
	}
	


	cout<<cc<<endl;
	return 0;
}