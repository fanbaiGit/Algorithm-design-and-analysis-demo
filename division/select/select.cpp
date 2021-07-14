#include <vector>
#include <fstream>
using namespace std;

int Solution(vector<int> &aminaomas, int low_pos, int high_pos, int k);

int main()
{
    fstream fin("select.in", ios::in), fout("select.out", ios::out);
    int n, k;
    vector<int> aminaomas;
    fin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        fin >> tmp;
        aminaomas.push_back(tmp);
    }
    fout << Solution(aminaomas, 0, n - 1, k);
    fin.close();
    fout.close();
    return 0;
}

int Solution(vector<int> &aminaomas, int low_pos, int high_pos, int k)
{
    int start_pos = low_pos, end_pos = high_pos;
    int piv = aminaomas[low_pos];
    if (start_pos >= end_pos)
        return aminaomas[start_pos];
    while (start_pos < end_pos)
    {
        while (start_pos < end_pos && aminaomas[end_pos] > piv)
            end_pos--;
        if (start_pos < end_pos)
        {
            aminaomas[start_pos] = aminaomas[end_pos];
            start_pos++;
        }
        while (start_pos < end_pos && aminaomas[start_pos] < piv)
            start_pos++;
        if (start_pos < end_pos)
        {
            aminaomas[end_pos] = aminaomas[start_pos];
            end_pos--;
        }
    }
    aminaomas[start_pos] = piv;
    if (start_pos == k - 1)
        return aminaomas[start_pos];
    else if (start_pos > k - 1)
        return Solution(aminaomas, low_pos, start_pos - 1, k);
    else
        return Solution(aminaomas, start_pos + 1, high_pos, k);
}
