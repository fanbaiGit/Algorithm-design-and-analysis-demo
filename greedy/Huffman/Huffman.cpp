#include <fstream>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>
using namespace std;

typedef struct node
{
    double weight;             //结点权重
    struct node *left, *right; //父结点、左孩子、右孩子在数组中的位置下标
} HTNode, *HuffmanTree;

struct Fcmp
{
    bool operator()(HTNode *a, HTNode *b)
    {
        return a->weight > b->weight;
    }
};

typedef priority_queue<HTNode *, vector<HTNode *>, Fcmp> Fqueue;
double res = 0.0;
// priority_queue<HTNode*, vector<HTNode*>,Fcmp > arr;

HuffmanTree creatTree(Fqueue arr);
void DFS(HuffmanTree root, int deep);

int main()
{
    fstream fin("data.in", ios::in), fout("data.out", ios::out);
    int n;
    fin >> n;
    Fqueue arr;
    for (int i = 0; i < n; i++)
    {
        HTNode *tmp = new HTNode;
        fin >> tmp->weight;
        tmp->left = nullptr;
        tmp->right = nullptr;
        arr.push(tmp);
    }
    HuffmanTree root = creatTree(arr);
    DFS(root, 0);
    fout << fixed << setprecision(3) << res;
    return 0;
}

HuffmanTree creatTree(Fqueue arr)
{
    HuffmanTree root = nullptr;
    while (arr.size() > 1)
    {
        HTNode *cur = new HTNode;
        HTNode *left = arr.top();
        arr.pop();
        HTNode *right = arr.top();
        arr.pop();
        cur->weight = left->weight + right->weight;
        cur->left = left;
        cur->right = right;
        arr.push(cur);
    }
    root = arr.top();
    arr.pop();
    return root;
}

void DFS(HuffmanTree root, int deep)
{
    if (!root->left && !root->right)
    {
        res += root->weight * deep;
        return;
    }
    DFS(root->left, deep + 1);
    DFS(root->right, deep + 1);
}