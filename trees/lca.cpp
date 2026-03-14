#include<vector>

using namespace std;

const int MAX_N = 10000;
const int LOG = 14;
vector<int> children[MAX_N];
int up[MAX_N][LOG];           ///////up[v][j] is 2^jth ancestorr of v
int depth[MAX_N];
//dfs to join the graph
void dfs(int a)
{
	for(int b : children[a])
	{
		up[b][0] = a;
                depth[b] = depth[a] + 1;

		for(int j=1;j<LOG;j++)
		{
			up[b][j] = up[up[b][j-1]][j-1];
		}
                ///dfs of the b 
		dfs(b);
	}
}


////O(N)
int get_lca(int a, int b)
{
	///swap if 
	if(depth[a]<depth[b])   swap(a,b);

	while(depth[a]>depth[b])
	{
		a = up[a][0];
	}

	while(a!=b)
	{
		a = up[a][0];
		b = up[b][0];
	}

	return a;
}

///now by binary search
int get_lca_binary(int a,int b)
{
	if(depth(a)<depth(b))    swap(a,b);

	//I want a's depth to be more
	int k = depth[a] - depth[b];

	//now climb the a to reach depth of b by binary jumps
	for(int i=LOG-1;j>=0;j--)
	{
		//checks if power of 2 or not
		if(k & (1<<j))   //if can jump then jump 
		{
			a = up[a][j];
		}
	}


	if(a==b)   return a;   //if same then return 
			       //
	///now jump both of them
	for(int j=LOG-1;j>=0;j--)
	{
		if(up[a][j]!=up[b][j])
		{
			//if not equal then jump otherwise dont as it wont be lca (might overshoot lca)
			a = up[a][j];
			b = up[b][j];
		}
	}

	return up[a][0]; //return immediate parent of a 
}


