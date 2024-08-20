#include <iostream>
#include <queue>
#include <unordered_map>
#include <limits>



std::unordered_map<int, int> dijkstra(int start, std::unordered_map<int, std::unordered_map<int, int> > graph) {


    std::unordered_map<int, int> distances;
    std::priority_queue<std::pair<int, int> > pq;

    if(graph.empty()){
        throw std::range_error("Der Graph ist leer!");
    }


    for (auto& pair : graph) {
        distances[pair.first] = std::numeric_limits<int>::max();
    }
    distances[start] = 0;

    pq.push(std::make_pair(0, start));

    while (!pq.empty()) {
        int currentDistance = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (currentDistance > distances[currentNode]) {
            continue;
        }

        for (auto& neighbor : graph[currentNode]) {
            int neighborNode = neighbor.first;
            int weight = neighbor.second;

            int distance = currentDistance + weight;

            if (distance < distances[neighborNode]) {
                distances[neighborNode] = distance;
                pq.push(std::make_pair(distance, neighborNode));
            }
        }
    }

    return distances;
}

/*int main() {
    // Beispielgraph erstellen

    std::unordered_map<int, std::unordered_map<int, int>> graph;
    graph = {
            {0, {{1, 4}, {2, 1}}},
            {1, {{3, 1}}},
            {2, {{1, 2}, {3, 5}}},
            {3, {}}
    };


    // Den Algorithmus ausführen
    std::unordered_map<int, int> distances = algorithm(0,graph);

    // Ergebnis ausgeben
    std::cout << "Kürzeste Wege von Knoten 0 zu allen anderen Knoten:" << std::endl;
    for (auto& pair : distances) {
        std::cout << "Knoten " << pair.first << ": " << pair.second << std::endl;
    }


    return 0;
}*/

// pseudo code

//FUNCTION algorithm(start, graph):
//  distances = new Dictionary()
//  priority_queue = new MinHeap()
//
//  FOR each node IN graph:
//      distances[node] = INFINITY
//
//  distances[start] = 0
//
//  priority_queue.insert((0, start))
//
//  WHILE NOT priority_queue.isEmpty():
//       (currentDistance, currentNode) = priority_queue.extractMin()
//
//        IF currentDistance > distances[currentNode]:
//          CONTINUE
//
//        FOR each neighbor, weight IN graph[currentNode]:
//          distance = currentDistance + weight
//
//          IF distance < distances[neighbor]:
//              distances[neighbor] = distance
//              priority_queue.insert((distance, neighbor))
//
//RETURN distances
