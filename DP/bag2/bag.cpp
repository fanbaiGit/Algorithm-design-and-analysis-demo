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
    for (int i = 0; i < n; i++)
    {
        int tmp;
        fin >> tmp;
        wight.push_back(tmp);
        fin >> tmp;
        value.push_back(tmp);
    }
    fout << Solution(n, v, wight, value);
    return 0;
}

int Solution(int n, int v, vector<int> wight, vector<int> value)
{
    vector<int> bag(v + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = v; j >= wight[i]; j--)
        {
            bag[j] = MAXINT(bag[j], bag[j - wight[i]] + value[i]);
        }
        // cout << i << ": ";
        // for (int j = 1; j <= v; j++)
        // {
        //     cout << bag[j] << "  ";
        // }
        // cout << endl;
    }
    return bag[v];
}

int MAXINT(int a, int b)
{
    return a < b ? b : a;
}