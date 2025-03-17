#include "dijkstras.h"


int main() {
    Graph G;
    try {
        file_to_graph("src/large.txt", G);
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    int source, destination;
    cout << "Enter the source vertex: ";
    cin >> source;
    cout << "Enter the destination vertex: ";
    cin >> destination;

    if (source < 0 || source >= G.numVertices || destination < 0 || destination >= G.numVertices) {
        cout << "Invalid source or destination vertex." << endl;
        return 1;
    }

    vector<int> previous(G.numVertices, -1);
    vector<int> distances = dijkstra_shortest_path(G, source, previous);
    vector<int> path = extract_shortest_path(distances, previous, destination);
    int totalDistance = distances[destination];

    print_path(path, totalDistance);

    return 0;
}