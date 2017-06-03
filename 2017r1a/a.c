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
    int r, c;

    for (int t = 1; t <= T; t++) {
        r = getInt(fp);
        c = getInt(fp);
        int qc = 0;
        char cake[r*c];
        char visited[26];
        for (int rr = 0; rr < r; rr++) {
            for (int cc = 0; cc < c; cc++) {
                cake[rr*c + cc] = fgetc(fp);
                if (cake[rr*c + cc] == '?') {
                    qc++;
                }
            }
            fgetc(fp);
        }
        //
        for (int rr = 0; rr < r; rr++) {
            for (int cc = 0; cc < c; cc++) {
                //
                if (cake[rr*c + cc] != '?') {
                    
                }
                //
            }
        }


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
