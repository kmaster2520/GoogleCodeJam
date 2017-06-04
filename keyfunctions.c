void sortDual(int* a, int* b, int len, char o) {
    for (int i = 0; i < len; i++) {
        for (int j = i; j > 0; j--) {
            if ((a[j] > a[j-1] && o == 'd') || (a[j] < a[j-1] && o == 'a')) {
                int temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
                temp = b[j];
                b[j] = b[j-1];
                b[j-1] = temp;
            }
        }
    }
}

typedef struct tuple_t {
    int a;
    int b;
} tuple;
typedef struct triple_t {
    int a;
    int b;
    int c;
} triple;

int tuplecompar (const void* a, const void* b) {
    const tuple* x = (const tuple*) a;
    const tuple* y = (const tuple*) b;
    return (*x).a - (*y).a;
}
int triplecompar (const void* a, const void* b) {
    const triple* x = (const triple*) a;
    const triple* y = (const triple*) b;
    return (*x).a - (*y).a;
}

void printarray(int* a, int l) {
    printf("[");
    for (int i = 0; i < l; i++) {
        printf("%d ", a[i]);
    }
    printf("]\n");
}