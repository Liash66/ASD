#include <iostream>
#include <vector>
using namespace std;

// определение направления поворота p, q и r
int orientation(pair<int, int> p, pair<int, int> q, pair<int, int> r)
{
    int val = (q.second - p.second) * (r.first - q.first) - (q.first - p.first) * (r.second - q.second);
    if (val == 0)
        return 0; // коллинеарны
    else if (val > 0)
        return 1; // по часовой стрелке
    else
        return 2; // против часовой стрелки
}

// алгоритм Джарвиса
vector<pair<int, int>> Jarvis_algorithm(vector<pair<int, int>>& points)
{
    int n = points.size();
    if (n < 3)
        return {};

    vector<pair<int, int>> hull; // вектор с точками
    int l = 0;

    // находим самую нижнюю левую точку
    for (int i = 1; i < n; ++i)
    {
        if (points[i].first < points[l].first)
            l = i;
    }

    int p = l;

    while (true)
    {
        hull.push_back(points[p]);
        int q = (p + 1) % n; // сравниваем текущую точку со следующей
        // находим точку с наибольшим углом, относительно текущей
        for (int i = 0; i < n; ++i)
        {
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }
        p = q;
        if (p == l)
            break;
    }

    return hull;
}


int main()
{
    setlocale(LC_ALL, "rus");

    vector<pair<int, int>> points = { {1, 2}, {3, 0}, {1, 1}, {2, 2}, {0, 0}, {0, 3}, {3, 3} };
    vector<pair<int, int>> convex_hull = Jarvis_algorithm(points);

    for (const auto& point : convex_hull)
    {
        cout << "(" << point.first << ", " << point.second << ") ";
    }

    return 0;
}