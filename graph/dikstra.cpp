#include<iostream>
#include<set>
#include<vector>
#include<utility>


using namespace std;


vector<int> dikstra(const vector<vector<pair<int,int>>>&adj, int src)
{
	int V = adj.size();
	vector<int> dist(V, 1e9);
	set<pair<int,int>> st;

	st.insert({0,src});

	while(!st.empty())
	{
		auto it = *st.begin();
		st.erase(it);
		auto node = it.second;
		auto wt = it.first;

		for(auto it_ : adj[node]){
			auto n_wt = it_.first;
			auto n_node = it_.second;

			if((n_wt+wt)<dist[n_node])
			{
				if(dist[n_node]!=1e9)
				{
					st.erase({dist[n_node], n_node});
				}

				dist[n_node] = n_wt+wt;
				st.insert({dist[n_node], n_node});
			}
		}

	}

	return dist;
}
