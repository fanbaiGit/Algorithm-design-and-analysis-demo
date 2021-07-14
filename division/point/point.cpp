#include <fstream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iomanip>
using namespace std;

typedef struct Node
{
    int x, y;
} Point;

double Solution(vector<Point> &point, int low, int high);
bool cmp(Point a, Point b);
double dis(Point a, Point b);

int main()
{
    fstream fin("point.in", ios::in), fout("point.out", ios::out);
    int n;
    fin >> n;
    vector<Point> point;
    for (int i = 0; i < n; i++)
    {
        Point tmp;
        fin >> tmp.x >> tmp.y;
        point.push_back(tmp);
    }
    sort(point.begin(), point.end(), cmp);
    double res = Solution(point, 0, n - 1);
    // printf("%.4lf", res);
    fout << fixed << setprecision(2) << res;
    fin.close();
    fout.close();
    return 0;
}

double Solution(vector<Point> &point, int low, int high)
{
    double min = 0;
    if (low == high - 1)
        return dis(point[low], point[high]);
    else if (low == high - 2)
    {
        double n1 = dis(point[low], point[low + 1]);
        double n2 = dis(point[high], point[high - 1]);
        return n1 < n2 ? n1 : n2;
    }
    else
    {
        int mid = (low + high) / 2;
        double d1 = Solution(point, low, mid);
        double d2 = Solution(point, mid + 1, high);
        min = d1 < d2 ? d1 : d2;
        double x = point[mid].x - min;
        for (int i = mid; i >= low; i--)
        {
            if (point[i].x < x)
                break;
            for (int j = mid + 1; j <= high; j++)
            {
                if (point[j].x - point[i].x > min)
                    break;
                if (point[j].y < point[i].y - min || point[j].y > point[i].y + min)
                    continue;
                double d3 = dis(point[i], point[j]);
                min = min < d3 ? min : d3;
            }
        }
    }
    return min;
}

bool cmp(Point a, Point b)
{
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

double dis(Point a, Point b)
{
    return sqrt(pow((a.y - b.y), 2) + pow((a.x - b.x), 2));
}