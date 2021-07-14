#include <fstream>
#include <vector>
using namespace std;

void Solution(int n, vector<int> &arr);
void Merge(int pos, int len, int n, vector<int> &arr);

int main()
{
    fstream fin("mergesort.in", ios::in), fout("mergesort.out", ios::out);
    int n;
    vector<int> arr;
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        fin >> tmp;
        arr.push_back(tmp);
    }
    Solution(n, arr);
    fout << arr[0];
    for (int i = 1; i < n; i++)
        fout << " " << arr[i];
    return 0;
}

void Solution(int n, vector<int> &arr)
{
    for (int len = 2; len <= 2 * n; len *= 2)
    {
        int pos = 0;
        while (pos < n)
        {
            Merge(pos, len, n, arr);
            pos += len;
        }
    }
}

void Merge(int left, int len, int n, vector<int> &arr)
{
    int right = left + len > n ? n : left + len;
    if (left + 1 == right || left == right)
    {
        n += 0;
    }
    else if (left + 2 == right)
    {
        if (arr[left] > arr[right - 1])
        {
            int tmp = arr[left];
            arr[left] = arr[right - 1];
            arr[right - 1] = tmp;
        }
    }
    else
    {
        int mid = left + len / 2;
        int len_left = 0;
        int len_right = 0;
        vector<int> L;
        vector<int> R;
        for (int i = left; i < mid; i++)
        {
            len_left++;
            L.push_back(arr[i]);
        }
        for (int i = mid; i < right; i++)
        {
            R.push_back(arr[i]);
            len_right++;
        }
        int left_pos = 0;
        int right_pos = 0;
        int i = left;
        while (left_pos < len_left && right_pos < len_right)
        {
            if (L[left_pos] <= R[right_pos])
            {
                arr[i++] = L[left_pos++];
            }
            else
            {
                arr[i++] = R[right_pos++];
            }
        }
        if (left_pos == len_left)
        {
            while (i < right)
                arr[i++] = R[right_pos++];
        }
        else
        {
            while (i < right)
                arr[i++] = L[left_pos++];
        }
    }
    return;
}