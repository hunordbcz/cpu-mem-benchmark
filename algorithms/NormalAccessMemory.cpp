//
// Created by hunordbcz on 07.12.2020.
//

#include "NormalAccessMemory.h"

int NormalAccessMemory::runCode(int size) {
    int nrElements = (size * 1024 * 1024) / sizeof(Node) / 2;

    vector<Node*> nodes(nrElements);
    for (int i=0; i<nrElements; ++i) {
        nodes[i] = new(nothrow) Node;
        if(!nodes[i]){
            return 0;
        }
    }

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

    return 0;
}

NormalAccessMemory::NormalAccessMemory() : MemoryAlgorithm("Normal Access Memory") {}
