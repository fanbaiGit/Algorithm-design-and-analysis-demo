#include <fstream>
#include <vector>
using namespace std;

void Solution(vector<int> &aminaomas, int low_pos, int high_pos);

int main()
{
    fstream fin("quicksort.in", ios::in), fout("quicksort.out", ios::out);
    int n;
    vector<int> aminaomas;
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        fin >> tmp;
        aminaomas.push_back(tmp);
    }
    Solution(aminaomas, 0, n - 1);
    for (int i = 0; i < n; i++)
        fout << aminaomas[i] << " ";
    fout << endl;
    fin.close();
    fout.close();
    return 0;
}

void Solution(vector<int> &aminaomas, int low_pos, int high_pos)
{
    int start_pos = low_pos, end_pos = high_pos;
    int piv = aminaomas[low_pos];
    if (start_pos >= end_pos)
        return;
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
    Solution(aminaomas, low_pos, start_pos - 1);
    Solution(aminaomas, start_pos + 1, high_pos);
}
