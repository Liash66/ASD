#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <string>

// поиск в ширину
std::vector<int> BFS(const std::vector<std::vector<int>>& graph, int start)
{
    int n = graph.size(); // количество вершин в графе
    std::vector<int> distances(n, -1); // вектор для хранения расстояний
    std::queue<int> queue; // очередь для BFS

    distances[start] = 0;
    queue.push(start);

    // пока очередь не пуста, продолжаем поиск
    while (!queue.empty())
    {
        int current = queue.front();
        queue.pop();

        // обходим всех соседей текущей вершины
        for (int i = 0; i < n; ++i)
        {
            // если сосед существует и его ещё не посетили
            if (graph[current][i] && distances[i] == -1)
            {
                distances[i] = distances[current] + 1; // обновляем расстояние
                queue.push(i); // добавляем вершину в очередь
            }
        }
    }

    return distances;
}

int main()
{
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    int n, start;
    in >> n >> start;

    // cчитываем матрицу смежности
    std::vector<std::vector<int>> graph(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            in >> graph[i][j];
        }
    }

    std::vector<int> distances = BFS(graph, start);

    for (int distance : distances)
    {
        out << distance << " ";
    }

    in.close();
    out.close();

    return 0;
}