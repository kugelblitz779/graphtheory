#include<bits/stdc++.h>
#define ll long long
using namespace std;

int N, M;
int vis[1001][1001];


bool isValid(int x, int y){

	if(x < 1 || x > N || y < 1 || y > M){
		return false;
	}

	if(vis[x][y]){
		return false;
	}

	return true;

}

void dfsOnGrid(int x, int y){

	vis[x][y] = 1;
	cout<<x<<" , "<<y<<endl;

	if(isValid(x-1, y)){
		dfsOnGrid(x-1, y);
	}

	if(isValid(x, y-1)){
		dfsOnGrid(x, y-1);
	}

	if(isValid(x+1, y)){
		dfsOnGrid(x+1, y);
	}

	if(isValid(x, y+1)){
		dfsOnGrid(x, y+1);
	}


}


int main(){

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>M;


	dfsOnGrid(1, 1);



	return 0;
}