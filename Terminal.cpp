//
// Created by debre on 11/8/2020.
//

#include <iostream>
#include "Terminal.h"

char Terminal::readChar() {
    return (char)getchar();
}

void Terminal::printString(const string& text) {
    cout << text;
}

void Terminal::printMenu() {
    cout<< "Menu comes here:\n";
}

void Terminal::clear() {
    system ("cls");
}
