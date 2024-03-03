#include <vector>

using namespace std;

class vectorStack {
private:
    vector<int> vec;
public:
    void add(int);
    void remove();
    bool isEmpty(){return vec.empty();}
    int top();
    double average();
    void print();
};

