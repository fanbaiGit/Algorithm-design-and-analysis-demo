#include <fstream>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct nodeI
{
    int start;
    int end;
    int wight;
} Edge;

bool cmp(Edge a, Edge b);
int solution(vector<Edge> edge, int n, int m);
int find(int a, vector<int> &parent);
void unite(int a, int b, vector<int> &parent, vector<int> &Rank);

int main()
{
    fstream fin("data.in", ios::in), fout("data.out", ios::out);
    int n, m;
    fin >> n >> m;
    vector<Edge> edge;
    vector<int> parent;
    vector<int> Rank;
    for (int i = 0; i < m; i++)
    {
        Edge Etmp;
        fin >> Etmp.start;
        fin >> Etmp.end;
        fin >> Etmp.wight;
        edge.push_back(Etmp);
    }
    for (int i = 0; i < n; i++)
    {
        sort(edge.begin(), edge.end(), cmp);
    }
    int res = solution(edge, n, m);
    fout << res;
    return 0;
}

int solution(vector<Edge> edge, int n, int m)
{
    int res = 0;
    int node = 1;
    vector<int> parent(n + 1, 0);
    vector<int> Rank(n + 1, 0);
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    for (int i = 0; i < int(edge.size()) && node != n; i++)
    {
        if (find(edge[i].start, parent) != find(edge[i].end, parent))
        {
            unite(edge[i].start, edge[i].end, parent, Rank);
            res += edge[i].wight;
            // edge.erase(edge.begin() + i);
            // i--;
            node++;
        }
    }
    if (node != n)
        return -1;
    return res;
}

bool cmp(Edge a, Edge b)
{
    return a.wight < b.wight;
}

int find(int a, vector<int> &parent)
{
    if (a != parent[a])
    {
        parent[a] = find(parent[a], parent);
    }
    return parent[a];
}

void unite(int a, int b, vector<int> &parent, vector<int> &Rank)
{
    int aRoot = find(a, parent);
    int bRoot = find(b, parent);
    if (Rank[aRoot] < Rank[bRoot]) //a并入b
        parent[aRoot] = bRoot;
    else //b并入a
    {
        parent[bRoot] = aRoot;
        if (Rank[aRoot] == Rank[bRoot]) //为秩加1
            Rank[aRoot]++;
    }
}