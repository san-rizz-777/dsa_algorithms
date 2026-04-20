#include <queue>
#include <utility>
#include <vector>

////Prim's algorithm
///used to calculate the minimum spanning tree

long long prim(const vector<vector<int>>&adj)
{
	int n = adj.size();
	vector<int> vis(n, 0);  //visited array
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;       //min-heap
											//greedily taking the minimum weights per node
	pq.push({0,0});
	long long sum = 0;
	while(!pq.empty())
	{
		pair<int,int> it = pq.top();
		pq.pop();
		int node = it.second;
		int weight = it.first;

		if(vis[node])   continue;  ///if already visited dont visit again
                sum += weight;
	       	vis[node] = 1;  //mark as visited 
		for(auto f : adj[node])
		{
			//traverse the neightbours
			auto n_node = f.second;
			auto wt = f.first;
			if(!vis[node])
			{
				//if not visited then push it
			     pq.push({wt, n_node});
			}
		}
	}

	return sum;
}
