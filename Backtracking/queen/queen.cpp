#include <fstream>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int sum = 0;
int n;

void Backtrack(int t, vector<int> &x);
bool place(int t, vector<int> x);

int main()
{
    fstream fin("queen.in", ios::in), fout("queen.out", ios::out);
    fin >> n;
    vector<int> x(n + 1, 0);
    Backtrack(1, x);
    fout << sum;
    return 0;
}

void Backtrack(int t, vector<int> &x)
{
    if (t > n)
    {
        sum++;
        return;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            x[t] = i;
            if (place(t, x))
                Backtrack(t + 1, x);
        }
    }
}

bool place(int t, vector<int> x)
{
    for (int i = 1; i < t; i++)
        if (x[i] == x[t] || (abs(i - t) == abs(x[i] - x[t])))
            return false;
    return true;
}