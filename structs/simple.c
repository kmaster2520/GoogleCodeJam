#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fib(int n) {
    int a = 1;
    int b = 0; // f(0)
    int m = abs(n);
    for (int i = 0; i < m; i++) {
        int c = a + b;
        a = b;
        b = c;
    }
    if (n%2 == 0) {
        return -1 * b;
    }
    return b;
}

int main() {

}