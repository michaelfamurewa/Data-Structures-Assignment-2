#include "vectorStack.h"
#include <iostream>

using namespace std;

void vectorStack::add(int val) {
    vec.push_back(val);
}

void vectorStack::remove() {
    vec.pop_back();
}

int vectorStack::top() {
    //end of the vector represents the top
    return vec.at(vec.size() - 1);
}

double vectorStack::average() {
    int sum = 0;
    for(int i = 0; i < vec.size();i++){
        sum += vec.at(i);
    }
    //turning values to double for division to get accurate average
    return static_cast<double>(sum)/static_cast<double>(vec.size());
}

void vectorStack::print() {
    //Printed in stack format, bottom up
    for(int i = vec.size() -1; i >= 0; i--){
        cout << vec.at(i) << endl;
    }
}
