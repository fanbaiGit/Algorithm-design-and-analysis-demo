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
int solution(vector<Edge> edge, int n);
bool find(vector<int> L, int target);
int findIndex(vector<int> L, int target);

int main()
{
    fstream fin("data.in", ios::in), fout("data.out", ios::out);
    int n, m;
    fin >> n >> m;
    vector<Edge> edge;
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
    int res = solution(edge, n);
    fout << res;
    return 0;
}

int solution(vector<Edge> edge, int n)
{
    int res = 0;
    // int p = 1;
    vector<int> A;
    vector<int> B;
    for (int i = 2; i <= n; i++)
        B.push_back(i);
    A.push_back(1);
    while (!B.empty())
    {
        // printf("1 \n");
        for (int i = 0; i < int(edge.size()); i++)
        {
            if (find(A, edge[i].start) && find(B, edge[i].end))
            {
                res += edge[i].wight;
                A.push_back(edge[i].end);
                B.erase(B.begin() + findIndex(B, edge[i].end));
                edge.erase(edge.begin() + i);
                break;
            }
            else if (find(B, edge[i].start) && find(A, edge[i].end))
            {
                res += edge[i].wight;
                A.push_back(edge[i].start);
                B.erase(B.begin() + findIndex(B, edge[i].start));
                edge.erase(edge.begin() + i);
                break;
            }
            else if (find(A, edge[i].start) && find(A, edge[i].end))
            {
                edge.erase(edge.begin() + i);
                break;
            }
        }
    }
    return res;
}

bool cmp(Edge a, Edge b)
{
    return a.wight < b.wight;
}

bool find(vector<int> L, int target)
{
    vector<int>::iterator result = find(L.begin(), L.end(), target);
    return result != L.end();
}

int findIndex(vector<int> L, int target)
{
    vector<int>::iterator result = find(L.begin(), L.end(), target);
    return result - L.begin();
}
