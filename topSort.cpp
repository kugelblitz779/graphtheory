#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define ll long long
using namespace std;

vector<int> arr[100001];
vector<int> res;
int in[100001];


void topSort(int n){

	queue<int> q;

	for(int i=1; i<=n; i++){
		if(in[i] == 0){
			q.push(i);
		}
	}

	while(!q.empty()){

		int curr = q.front();
		res.push_back(curr);
		q.pop();

		for(int child : arr[curr]){

			in[child]--;
			if(in[child] == 0){
				q.push(child);
			}

		}

	}

	cout<<"Top Sort :"<<endl;
	for(int x : res){
		cout<<x<<" ";
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
		in[b]++;

	}


	
	topSort(n);
	


	return 0;
}