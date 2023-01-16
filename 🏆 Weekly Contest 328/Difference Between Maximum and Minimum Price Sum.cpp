// https://leetcode.com/problems/difference-between-maximum-and-minimum-price-sum/

class Solution
{
public:
    vector<map<int, long long>> dp;

    long long traverse(int node, vector<vector<int>> &adj, vector<int> &price, int prev)
    {
        // if present in dp return
        if (dp[node].count(prev))
            return dp[node][prev];

        // else current nodes price is max
        long long mx = price[node];
        // traverse all childs/neighbours of "node"
        for (auto &child : adj[node])
        {
            if (child == prev)
                continue;                                       // don't go the way you came
            long long temp = traverse(child, adj, price, node); // recursion
            mx = max(mx, 1ll * price[node] + temp);
        }
        return dp[node][prev] = mx;
    }

    long long maxOutput(int n, vector<vector<int>> &edges, vector<int> &price)
    {

        dp.clear();
        dp.resize(n);

        // create adjecency list
        vector<vector<int>> adj(n);
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // traverse all nodes for possible paths
        long long res = 0;
        for (int i = 0; i < n; ++i)
        {
            // path with max sum - if you at same node
            long long temp = traverse(i, adj, price, -1) - price[i];
            res = max(res, temp);
        }
        return res;
    }
};