#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void bfs(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::bfs(int s)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    list<int> queue;
    visited[s] = true;
    queue.push_back(s);

    list<int>::iterator i;

    while (!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main()
{
    srand(time(0));

    int n = 10;
    double time, t;
    
    FILE *fp;

    fp = fopen("q1_plot_c.txt", "w");

    if(fp == NULL){
        printf("ERROR Opening File.\n");
    }

    while (n <= 100000)
    {
        time = t = 0.0;
        for (int k = 1; k <= 10; k++)
        {
            Graph g(n);
            for (int i = 0; i < n; i++)
            {
                g.addEdge(0, i);
            }

            ///MERGE SORT BEGINS
            time = clock();
            ///START
            g.bfs(rand() % k);
            ///END
            time = clock() - time;
            ///MERGE SORT ENDS
            t += ((double)time) / CLOCKS_PER_SEC;
        }
        time = t / 10;

        printf("\nTIME:%d, %f\n\n", n, time);

        fprintf(fp, "%d, %lf\n", n, time);

        n *= 10;
    }
    fclose(fp);
    
    return 0;
}
