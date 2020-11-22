//
// Created by hdebreczeni on 21.11.2020.
//

#include "Ackermann.h"
Ackermann::Ackermann() : Algorithm("Ackermann"){
    for(int size : {1, 100, 1000, 10000, 100000}){
        scoreBySize.emplace(size, -1);
    }
}

void Ackermann::runTest() {
    vector<int> sizes;
    for(auto const& imap: scoreBySize){
        sizes.push_back(imap.first);
    }

    this->execute(sizes);
}

void Ackermann::runCode(int size) {
    int n = 6, m = 7;

    if (m == 0){
        return;
//        return n + 1;
    }
    else if((m > 0) && (n == 0)){
        return;
//        return ack(m - 1, 1);
    }
    else if((m > 0) && (n > 0)){
        return;
//        return ack(m - 1, ack(m, n - 1));
    }
}
