#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <math.h>

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
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int main() {
    
    FILE* fp = fopen("infile.txt", "r");
    FILE* op = fopen("outfile.txt", "w");

    int T = getInt(fp);
    int n, p;

    for (int t = 1; t <= T; t++) {
        n = getInt(fp);
        p = getInt(fp);
        //printf("%d %d\n", n, p);
        int mins[n][p], maxs[n][p];
        int serv[n];
        for (int i = 0; i < n; i++) {
            serv[i] = getInt(fp);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < p; j++) {
                int v = getInt(fp);
                mins[i][j] = ceil(1.0 * v / (serv[i] * 1.1));
                maxs[i][j] = floor(1.0 * v / (serv[i] * 0.9));
                //printf("%d %d\n", mins[i][j], maxs[i][j]);
            }
        }
        int total = 0;
        //printf("%d\n", serv[0]);
        for (int k = 0; k < p; k++) {
            int packs[n];
            packs[0] = k;
            int foundPack = 1;
            if (maxs[0][k] < 1 || maxs[0][k] < mins[0][k]) {
                //printf("cont %d\n", k);
                continue;
            }
            if (mins[0][k] <= 0 && maxs[0][k] <= 0) {
                continue;
            }
            for (int i = 1; i < n; i++) {
                int foundOne = 0;
                for (int j = 0; j < p; j++) {
                    if (mins[i][j] < 0 || mins[i][j] > maxs[i][j]) {
                        continue;
                    }
                    if (mins[i][j] <= 0 && maxs[i][j] <= 0) {
                        continue;
                    }
                    if ( max(maxs[0][k], maxs[i][j]) - min(mins[0][k], mins[i][j]) <= (maxs[0][k] - mins[0][k]) + (maxs[i][j] - mins[i][j]) ) {
                        foundOne = 1;
                        packs[i] = j;
                    }
                }
                if (foundOne == 0) {
                    foundPack = 0;
                    break;
                }
            }
            if (foundPack == 1) {
                total++;
                for (int i = 1; i < n; i++) {
                    mins[i][packs[i]] = -1;

                }
            }

        }

        fprintf(op, "Case #%d: %d\n", t, total);

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
