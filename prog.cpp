#include <iostream>
#include <vector>
using namespace std;

class edge
{
  public:
    int source;
    int destination;
    int cost;

    edge(int s, int d, int c)
    {
        source = s;
        destination = d;
        cost = c;
    }
};

class djk
{
    int adj[300][300];

  public:
    int max;
    djk()
    {
        max = 0;

        for (int i = 0; i < 300; i++)
            for (int j = 0; j < 300; j++)
                adj[i][j] = 0;
    }

    void list(int s, int d, int c)
    {
        max += c;
        adj[s - 1][d - 1] = c;
    }

    int adjCost(int s, int d, int n)
    {
        int cost[n];
        int vertex[n];

        for (int k = 0; k < n; k++)
        {
            cost[i] = max;
            vertex[k] = 0;
        }
        cost[s - 1] = 0;

        for (int count = 0; count < n - 1; count++)
        {
            int u = minDistance(cost, vertex, n);

            vertex[u] = 1;

            for (int v = 0; v < n - 1; v++)

                if (!vertex[v] && adj[u][v] && cost[u] != INT_MAX && cost[u] + adj[u][v] < cost[v])
                    cost[v] = cost[u] + adj[u][v];
        }
    }

    int minDistance(int c[], int v[], int n)
    {
        int min = INT_MAX, min_index;

        for (int i = 0; i < n; i++)
            if (v[i] == false && cost[i] <= min)
                min = cost[i], min_index = i;

        return min_index;
    }
};

int main()
{
    int n;
    cin >> n;

    int s, d, c;
    djk D = new djk;
    vector<edge> E;

    for (int i = 0; i < n; i++)
    {
        cin >> s >> d >> c;
        E.push_back(new edge(s, d, c);
        D.list(s, d, c);
    }
    D.max++;

    int cost = 0;

    for (int i = 0; i < n; i++)
    {
        D.list(E[i].source, E[i].destination, D.max);

        int t = D.adjCost(E[i].source, E[i].destination, n);
        if (t > cost)
            cost = t;

        D.list(E[i].source, E[i].destination, E[i].cost);
    }

    cout << cost << endl;
    return 0;
}