#include "dijkstras.h"

int main() {
    Graph G;
    string filename = "src/large.txt";

    try {
        file_to_graph(filename, G);
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    int source = 0;
    int destination = 6;

    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, source, previous);
    
    vector<int> path = extract_shortest_path(distances, previous, destination);

    cout << "From " << source << " to " << destination << ":" << endl;
    print_path(path, distances[destination]);

    return 0;
}