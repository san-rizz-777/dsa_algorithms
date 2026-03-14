#include<vector>

using namespace std;

//Dsu class for modularity
class DSU{
	public:
		//constructor
		DSU(int count) : n(count)
		{
                        
			parent.resize(n);
			size.resize(n,1);
			rank.resize(n,1);

			//populate the parent array 
			for(int i=0;i<n;i++)
			{
				//everyone is parent of own 
				parent[i] = i;
			}
		}


                int findParent(int node)
		{
			return parent[node]==node? node : findParent(parent[node]);
		}


                //union by size
                void UnionBySize(int node1, int node2)
		{
			//first find the parent
			int u_p1 = findParent(node1);
			int u_p2 = findParent(node2);
                        
			//if same parent
			if(u_p1==u_p2)    return;

			if(size[u_p1]>size[u_p2])
			{
				//join smaller to bigger
				parent[u_p2] = u_p1;
				size[u_p1]+=size[u_p2];
			}
			else{
				parent[u_p1] = u_p2;
				size[u_p2] += size[u_p1];
			}
		}

		//union by rank
		void UnionByRank(int node1, int node2)
		{
			//find the parents of them
			int u_p1 = findParent(node1);
			int u_p2 = findParent(node2);

                        if(u_p1==u_p2)   return;

			if(rank[u_p1]>rank[u_p2])
			{
				parent[u_p2] = u_p1;
                                rank[u_p1]++;
			}
			else{
				parent[u_p1] = u_p2;
				rank[u_p2]++;
			}
		}

                
	private:
		vector<int> parent;
		vector<int> size;
		vector<int> rank;
		int n;
};
