//
// Created by hunordbcz on 07.12.2020.
//

#include "FillMemory.h"

FillMemory::FillMemory() : MemoryAlgorithm("Fill Memory") {

}

void FillMemory::runCode(int size) {
    int nrElements = (size * 1024 * 1024) / sizeof(Node) / 2;

    vector<Node*> nodes(nrElements);
    RDTSC_START()
    for (int i=0; i<nrElements; ++i) {
        nodes[i] = new Node;
    }
    RDTSC_STOP()

    Node *node  = nodes[0];
    nodes.clear(); nodes.shrink_to_fit();

    Node* prev;
    while (node) {
        prev = node;
        node = node->next;
        delete(prev);
    }


}
