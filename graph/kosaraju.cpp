#include <vector>
#include <stack>
#include <iostream>

using namespace std;

void dfs(int node, vector<vector<int>>&adj, vector<int>&vis, stack<int>&st)
{
    //mark as visited
    vis[node] = 1;
    
    ///traverse the neighbours
    for(auto it : adj[node])
    {
if(!vis[it])
{
    dfs(it, adj, vis, st);
}
    }

    //push the node into the stack
    st.push(node);
}

void dfs2(int node, vector<vector<int>>&adj, vector<int>&vis)
{
    //mark as visited
    vis[node] = 1;
    
    ///traverse the neighbours
    for(auto it : adj[node])
    {
if(!vis[it])
{
    dfs(it, adj, vis);
}
    }
}

int kosaraju(int n, vector<vector<int>>&adj)
{
    stack<int> st;
    //int n = adj.size();
    //step 1 : dfs to store in the stack
    //according to the insertion timings
    vector<int> vis(n, 0);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(i, adj, vis, st);
        }
    }


    ///reverse the graph
    vector<vector<int>> adj_2(n);
    for(int i=0;i<n;i++)
    {
        vis[i] = 0;
        for(auto it : adj[i])
        {
            adj[it].push_back(i);
        }
    }

    //step 3 : traverse by dfs based upon the stack and count the sccs
    int sccs = 0;
    while(!st.empty())
    {
        auto node = st.top();
        st.pop();
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
dfs2(it, adj, vis);
sccs++;
            }
        }
    }

    return sccs;
}

int main() {
    int n = 5;
    int edges[5][2] = {
        {1, 0}, {0, 2},
        {2, 1}, {0, 3},
        {3, 4}
    };

    vector<vector<int>> adj;
    for (int i = 0; i < 5; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    }

   
    int ans = kosaraju(n, adj);
    cout << "The number of strongly connected components is: " << ans << endl;
    return 0;
}
