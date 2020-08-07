#include <iostream>

using namespace std;

extern "C" {
    int sum(int x, int y);
}

int main() {
    sum(2,3);
    return 0;
}