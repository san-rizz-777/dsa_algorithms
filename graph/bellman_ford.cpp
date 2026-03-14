#include<vector>


////effective for the negative weights
///where dikstra fails


vector<int> bellman_ford(const vector<vector<int>>& edges,int src,int V)
{
       vector<int> dist(V, 1e9);
       dist[src] = 0;

       //loop upto n-1 	times 
       for(int i=0;i<(V-1);i++)
       {
	       for(auto it : edges)
	       {
		       int u = it[0];
		       int v = it[1];
		       int weight = it[2];


		       if(dist[u]!=1e9 && (dist[u]+weight)<dist[v])
		       {
			      dist[v] = weight + dist[u];
		       }

	       }
       }

      ///after relaxation of n-1 nodes if another less weight found means negative cycle 
      for(auto it : edges)
      {
	     int u = it[0];
	    int v = it[1];
	   int weight  = it[2];

	  if(dist[u]!=1e9 && (dist[u]+weight)<dist[v])
	  {
		 return {-1}; ///negative cycle found.....

	  }

      }

} 
