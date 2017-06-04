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

double carea(int r) { // area of circle
    return 3.14159265358979323846 * r * r;
}

double harea(int r, int h) { // marginal area
    return 3.14159265358979323846 * 2 * r * h;
}

// sort descending
void sortDual(int* a, int* b, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = i; j > 0; j--) {
            if (a[j] > a[j-1]) {
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


// Ample Syrup
int main() {
    
    FILE* fp = fopen("infile.txt", "r");
    FILE* op = fopen("outfile.txt", "w");

    int T = getInt(fp);

    for (int t = 1; t <= T; t++) {
        int n = getInt(fp);
        int k = getInt(fp);
        int r[n], h[n];
        for (int i = 0; i < n; i++) {
            r[i] = getInt(fp);
            h[i] = getInt(fp);
        }
        //
        sortDual(r, h, n);
        double ans = 0.0;
        int li = n-1; //limit index
        for (int i = k-1; i >= 0; i--) {
            double bestArea = 0.0;
            double bestli = i-1;
            for (int j = i; j <= li; j++) {
                double area = harea(r[j], h[j]);
                if (bestArea < area) {
                    bestli = j-1;
                    bestArea = area;
                }
            }
            ans += bestArea;
            li = bestli;
        }
        ans += carea(r[li+1]);


        fprintf(op, "Case #%d: %.9f\n", t, ans);
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
