#include <iostream>
#include <vector>
using namespace std;

#define INF 99999
#define V 4

void printSolution(vector<vector<int>>& dist);

void floydWarshall(vector<vector<int>>& graph) {
    vector<vector<int>> dist = graph;

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printSolution(dist);
}

void printSolution(vector<vector<int>>& dist) {
    cout << "Shortest distances between every pair of vertices:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF" << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> graph = { {3, 5, INF, INF},
                                  {3, 0, INF, 7},
                                  {2, 5, 3, 4},
                                  {3, 2, 4, 0} };
    floydWarshall(graph);
    return 0;
}
