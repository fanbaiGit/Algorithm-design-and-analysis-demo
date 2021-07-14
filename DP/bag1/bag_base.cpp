#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

int Solution(int n, int v, vector<int> wight, vector<int> value);
int MAXINT(int a, int b);

int main()
{
    fstream fin("bag.in", ios::in), fout("bag.out", ios::out);
    int n, v;
    vector<int> wight;
    vector<int> value;
    wight.push_back(0);
    value.push_back(0);
    fin >> v >> n;
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        fin >> tmp;
        wight.push_back(tmp);
        fin >> tmp;
        value.push_back(tmp);
    }
    fout << Solution(n, v, wight, value);
    // cout << Solution(n, v, wight, value);
    return 0;
}

int Solution(int n, int v, vector<int> wight, vector<int> value)
{
    vector<vector<int>> bag;
    for (int i = 0; i <= n; i++)
    {
        vector<int> tmp(v + 1, 0);
        bag.push_back(tmp);
    }
    for (int i = 1; i <= n; i++)
    {
        // int k = i - 1;
        for (int j = v; j >= 1; j--)
        {
            if (wight[i] <= j)
                bag[i][j] = MAXINT(bag[i - 1][j], bag[i - 1][j - wight[i]] + value[i]);
            else
                bag[i][j] = bag[i - 1][j];
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << ": ";
    //     for (int j = 1; j <= v; j++)
    //     {
    //         cout << bag[i][j] << "  ";
    //     }
    //     cout << endl;
    // }
    return bag[n][v];
}

int MAXINT(int a, int b)
{
    return a < b ? b : a;
}
