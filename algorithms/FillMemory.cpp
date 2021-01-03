//
// Created by hunordbcz on 07.12.2020.
//

#include "FillMemory.h"

FillMemory::FillMemory() : MemoryAlgorithm("Fill Memory") {

}

int FillMemory::runCode(int size) {
    int nrElements = (size * 1024 * 1024) / sizeof(Node) / 2;

    vector<Node*> nodes(nrElements);
    RDTSC_START()
    for (int i=0; i<nrElements; ++i) {
        nodes[i] = new Node;
    }
    RDTSC_STOP()

    for (int i=0; i<nrElements; ++i) {
        delete(nodes[i]);
    }

    nodes.clear(); nodes.shrink_to_fit();
    return 0;
}
