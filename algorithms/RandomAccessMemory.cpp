//
// Created by hunordbcz on 30.11.2020.
//

#include "RandomAccessMemory.h"

RandomAccessMemory::RandomAccessMemory() : MemoryAlgorithm("Random Memory Access (MB)") {

}

void RandomAccessMemory::runCode(int size) {
    int nrElements = (size * 1024 * 1024) / sizeof(Node) / 2;

    vector<Node*> nodes(nrElements);
    for (int i=0; i<nrElements; ++i) {
        nodes[i] = new(nothrow) Node;
        if(!nodes[i]){
            return;
        }
    }

    shuffle(begin(nodes), end(nodes), std::mt19937(std::random_device()()));

    for (int i=0; i< nrElements - 1; ++i) {
        nodes[i]->next = nodes[i+1];
    }

    Node* start_node = nodes[0];
    nodes.clear(); nodes.shrink_to_fit();

    RDTSC_START()
    Node* node = start_node;
    while (node) {
        node = node->next;
    }
    RDTSC_STOP()

    node = start_node;
    Node* prev;
    while (node) {
        prev = node;
        node = node->next;
        delete(prev);
    }
}
