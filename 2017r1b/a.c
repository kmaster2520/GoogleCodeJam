#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <math.h>

int getInt(FILE*);
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
    int n, d;


    for (int t = 1; t <= T; t++) {
        d = getInt(fp);
        n = getInt(fp);
        int k[n];
        int s[n];
        for (int i = 0; i < n; i++) {
            k[i] = getInt(fp);
            s[i] = getInt(fp);
        }
        //
        double best = 0.0; // longest time for horse
        for (int i = 0; i < n; i++) {
            double time = 1.0 * (d - k[i]) / s[i];
            if (time > best) {
                best = time;
            }
        }
        double maxs = d / best;

        fprintf(op, "Case #%d: %.7f\n", t, maxs);

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
