#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> arr[100001];
int vis[100001];
int subsize[100001];

int dfs(int node){

	vis[node] = 1;
	int curr_size = 1;

	for(int child : arr[node]){
		if(!vis[child]){

			curr_size += dfs(child);

		}
	}

	subsize[node] = curr_size;
	return curr_size;

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



	int subtree_of_root = dfs(1);

	for(int i=1; i<=n; i++){
		cout<<subsize[i]<<" ";
	}
	cout<<endl;

	cout<<subtree_of_root<<endl;


	return 0;
}