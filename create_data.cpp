#include "main.h"

void create_data()
{
    srand(time(0));
    for (int i = 0; i < MAX_FILE; i++)
    {
        int vertex = rand() % 200 + 100;
        string name = "data/test" + string(3 - to_string(i).length(), '0') + to_string(i) + ".txt";
        fstream data;
        data.open(name, ios::out);
        data << vertex << '\n';
        for (int j = 0; j < vertex; j++)
        {
            for (int j = 0; j < vertex; j++)
            {
                data << rand() % 1000 << ' ';
            }
            data << '\n';
        }
        data.close();
    }
}

void create_solution()
{
    int **graph;
    for (int i = 0; i < MAX_FILE; i++)
    {
        string data_name = "data/test" + string(3 - to_string(i).length(), '0') + to_string(i) + ".txt";
        fstream data;
        data.open(data_name, ios::in);
        int V;
        data >> V;
        setV(V);
        graph = new int *[V];
        for (int j = 0; j < V; j++)
            graph[j] = new int[V];
        for (int j = 0; j < V; j++)
        {
            for (int k = 0; k < V; k++)
                data >> graph[j][k];
        }
        data.close();
        string solution_name = "solution/test" + string(3 - to_string(i).length(), '0') + to_string(i) + ".txt";
        fstream solution;
        solution.open(solution_name, ios::out);
        solution << "The maximum possible flow is " << fordFulkerson(graph, 0, 5);
        solution.close();
    }
}