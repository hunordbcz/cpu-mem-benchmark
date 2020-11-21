//
// Created by hdebreczeni on 21.11.2020.
//

#include "Ackermann.h"

void Ackermann::runCode() {
    int n = 2, m = 3;

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

Ackermann::Ackermann() : Algorithm("Ackermann"){

}
