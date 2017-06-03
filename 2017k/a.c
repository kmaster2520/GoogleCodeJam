#include <stdio.h>
//#include <string.h>
//#include <math.h>

/*
 fscanf(file*, format, pointers to variables)
 fprintf(file*, format, variables (no pointers))

ascii:
'0' = 48
'a' = 97
'A' = 65

void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
base = addr of first element

 
*/

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    
    FILE* fp = fopen("infile.txt", "r");
    FILE* op = fopen("outfile.txt", "w");
    int T, r, c;
    fscanf(fp, "%d\n", &T);
    int p = 1000000007;

    for (int t = 1; t <= T; t++) {

        fscanf(fp, "%d %d\n", &r, &c);
        int mins = min(r, c);
        int total = 0;

        for (int l1 = 1; l1 < r; l1++) {
            for (int l2 = 0; l2 < c; l2++) {
                int h = l1 + l2;
                if (h > mins) {
                    continue;
                }
                int delta = ( ((r-h)%p) * ((c-h)%p) ) % p;
                total = ( (total % p) + delta) % p;
            }
        }

        fprintf(op, "Case #%d: %d\n", t, total);

    }
    
    fclose(fp);
    fclose(op);

}
