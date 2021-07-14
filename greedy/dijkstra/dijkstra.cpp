#include <fstream>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct nodeI
{
    int end;
    int wight;
} Edge;

typedef struct nodeII
{
    int start;
    int val;
    vector<Edge> edge;
} Node;

bool cmp(Edge a, Edge b);
void DFS(vector<Node> map, vector<int> &vised, int start, int dest, int ans);
int solution(vector<Node> map, int n, int m);
bool find(vector<int> L, int target);
int findIndex(vector<int> L, int target);

int main()
{
    fstream fin("data.in", ios::in), fout("data.out", ios::out);
    int n, m;
    fin >> n >> m;
    // int dest;
    // dest = n;
    // vector<int> vised(n + 1, 0);
    vector<Node> map;
    cout << "Reading..." << endl;
    for (int i = 0; i <= n; i++)
    {
        Node Ntmp;
        Ntmp.start = i;
        Ntmp.val = 0;
        map.push_back(Ntmp);
    }
    for (int i = 0; i < m; i++)
    {
        Edge EtmpStart;
        Edge EtmpEnd;
        int start;
        int end;
        int wight;
        fin >> start;
        fin >> end;
        fin >> wight;
        EtmpStart.end = end;
        EtmpStart.wight = wight;
        EtmpEnd.end = start;
        EtmpEnd.wight = wight;
        map[start].edge.push_back(EtmpStart);
        map[end].edge.push_back(EtmpEnd);
    }
    for (int i = 0; i < n; i++)
    {
        sort(map[i].edge.begin(), map[i].edge.end(), cmp);
    }
    // DFS(map, vised, 1, dest, 0);
    cout << "solution..." << endl;
    int res = solution(map, n, m);
    fout << res;
    return 0;
}

// void DFS(vector<Node> map, vector<int> &vised, int start, int dest, int ans) //深度优先算法
// {
//     if (start == dest)
//     {
//         if (ans < res || res == -1)
//             res = ans;
//         return;
//     }
//     for (auto iter = map[start].edge.begin(); iter != map[start].edge.end(); ++iter)
//     {
//         Edge Etmp = *iter;
//         if (vised[Etmp.end] != 1)
//         {
//             vised[Etmp.end] = 1;
//             DFS(map, vised, Etmp.end, dest, ans + Etmp.wight);
//             vised[Etmp.end] = 0;
//         }
//     }
// }

int solution(vector<Node> map, int n, int m)
{
    int node = 1;
    vector<int> A;
    vector<int> B;
    for (int i = 2; i <= n; i++)
        B.push_back(i);
    A.push_back(1);
    while (node != n)
    {
        int min = 0x7FFFFFFF;
        int next;
        for (auto iter = A.begin(); iter != A.end(); ++iter)
        {
            Node cur = map[*iter];
            for (auto item = cur.edge.begin(); item != cur.edge.end(); ++item)
            {
                if (find(B, item->end))
                {
                    if (cur.val + item->wight < min)
                    {
                        min = cur.val + item->wight;
                        next = item->end;
                    }
                }
            }
        }
        if (min != 0x7FFFFFFF)
        {
            A.push_back(next);
            B.erase(B.begin() + findIndex(B, next));
            map[next].val = min;
            node++;
            if (next == n)
                return min;
        }
        else
        {
            return -1;
        }
    }
    return map[n].val;
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
