#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <math.h>

int getInt(FILE*);
int intcompar(const void*, const void*);
/*
 read line = fgets(char*, size, FILE*)
 read char = fgetc(FILE*)
 read int = getInt(FILE*) (not built-in)

fprintf(file*, format, variables (no pointers))

ascii:
'0' = 48
'a' = 97
'A' = 65

void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
base = addr of first element
 
*/

int main() {
    
    FILE* fp = fopen("infile.txt", "r");
    FILE* op = fopen("outfile.txt", "w");

    int T = getInt(fp);

    for (int t = 1; t <= T; t++) {


        fprintf(op, "Case #%d: %d\n", t, ans);
    }
    
    fclose(fp);
    fclose(op);

}



int getInt(FILE* fp) {
    int i = 0;
    char c = fgetc(fp);
    while (c >= '0' && c <= '9') {
        i = i * 10 + (c - '0');
        c = fgetc(fp);
    }
    return i;
}
int intcompar(const void* a, const void* b) {
    const int* x = (const int*) a;
    const int* y = (const int*) b;
    return *x - *y;
}
