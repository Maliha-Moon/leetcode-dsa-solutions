#include <bits/stdc++.h>
using namespace std;

// Function to compute the lowest cost path in a multistage graph
pair<vector<int>, int> compute_lowest_cost_path(unordered_map<int, unordered_map<int, int>> &g, vector<vector<int>> &s)
{
    int sc = s.size(); // Total number of stages in the graph
    int vc = g.size(); // Total number of vertices in the graph

    // Prepare arrays to track minimum costs and the next vertex in the optimal path
    vector<int> cost(vc, numeric_limits<int>::max());
    vector<int> next(vc, -1);

    // Set the cost to reach the sink vertex to zero
    cost[vc - 1] = 0;

    // Traverse the stages from the second last stage to the first stage
    for (int i = sc - 2; i >= 0; i--)
    {
        for (int cur : s[i])
        {
            // Analyze each neighbor of the current vertex to identify the lowest cost path
            for (const auto &nbr : g[cur])
            {
                int adj = nbr.first;
                int weight = nbr.second;
                int total_cost = weight + cost[adj];

                // If a lower cost path is found, update the cost and track the next vertex
                if (total_cost < cost[cur])
                {
                    cost[cur] = total_cost;
                    next[cur] = adj;
                }
            }
        }
    }

    // Build the path from the source to the sink vertex
    vector<int> path;
    int start = 0; // Starting from the source vertex
    while (start != -1)
    {
        path.push_back(start);
        start = next[start];
    }

    // Return the constructed path and the minimum cost as a pair
    return make_pair(path, cost[0]);
}

int main()
{
    // Initialize the multistage graph using an adjacency list
    unordered_map<int, unordered_map<int, int>> g = {
        {0, {{1, 2}, {2, 3}}}, // Vertex 0 connects to 1 (weight 2) and 2 (weight 3)
        {1, {{3, 5}, {4, 2}}}, // Vertex 1 connects to 3 (weight 5) and 4 (weight 2)
        {2, {{3, 4}, {4, 1}}}, // Vertex 2 connects to 3 (weight 4) and 4 (weight 1)
        {3, {{5, 6}}},         // Vertex 3 connects to 5 (weight 6)
        {4, {{5, 3}}},         // Vertex 4 connects to 5 (weight 3)
        {5, {{6, 1}}},         // Vertex 5 connects to 6 (weight 1)
        {6, {{7, 1}}},         // Vertex 6 connects to 7 (weight 1)
        {7, {{8, 1}}},         // Vertex 7 connects to 8 (weight 1)
        {8, {}}                // Vertex 8 is a sink with no outgoing edges
    };

    // Define the stages of the multistage graph
    vector<vector<int>> s = {
        {8},       // Sink stage
        {6, 7},    // Second to last stage
        {3, 4, 5}, // Third stage
        {1, 2}     // First stage
    };

    // Compute the lowest cost path and its corresponding cost
    auto result = compute_lowest_cost_path(g, s);

    // Display the lowest cost path
    cout << "Lowest cost path: ";
    for (int v : result.first)
    {
        cout << v << " ";
    }
    cout << endl;

    // Display the minimum cost
    cout << "Lowest cost: " << result.second << endl;

    return 0;
}
