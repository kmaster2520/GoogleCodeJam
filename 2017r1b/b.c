#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <math.h>

int getInt(FILE*);
int match(char, char); // 0 - can be adjacent, 1 otherwise
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
    int n;
    char col[6] = {'R', 'O', 'Y', 'G', 'B', 'V'};

    for (int t = 1; t <= T; t++) {
        int n = getInt(fp);
        int c[6];
        for (int i = 0; i < 6; i++) {
            c[i] = getInt(fp);
        }
        // small dataset

        char sol[n+2];
        int rec[6] = {n,n,n,n,n,n};
        sol[0] = ' ';
        sol[n+1] = 0;
        int i = 1;
        while (i <= n) {
            char bc = -1;
            for (int j = 0; j < 6; j++) {
                if (match(col[j],sol[i-1]) == 0 && c[j] > 0) {
                    if (bc < 0) {
                        bc = j;
                    } else {
                        if (c[j] > c[bc]) {
                            bc = j;
                        } else if (c[j] == c[bc] && rec[j] > rec[bc]) {
                            bc = j;
                        }
                    }
                }
            }
            //
            if (bc < 0) {
                break;
            }
            sol[i] = col[bc];
            rec[bc] = i;
            c[bc]--;
            i++;

        }

        if (match(sol[n], sol[1]) == 1 && match(sol[n-2], sol[1]) == 0) {
            char temp = sol[n];
            sol[n] = sol[n-1];
            sol[n-1] = temp;
        }

        if (i <= n || match(sol[n], sol[1]) == 1) {
            fprintf(op, "Case #%d: IMPOSSIBLE\n", t);
        } else {
            fprintf(op, "Case #%d:%s\n", t, sol);
        }
        

    }
    
    fclose(fp);
    fclose(op);

}

int match(char a, char b) {
    if ( a == ' ' || b == ' ') {
        return 0;
    }
    if ( a == 'R' && (b == 'B' || b == 'G' || b =='Y') ) {
        return 0;
    }
    if ( a == 'Y' && (b == 'R' || b == 'V' || b =='B') ) {
        return 0;
    }
    if ( a == 'B' && (b == 'R' || b == 'O' || b =='Y') ) {
        return 0;
    }
    if ( a == 'O' && b == 'B' ) {
        return 0;
    }
    if ( a == 'G' && b == 'R' ) {
        return 0;
    }
    if ( a == 'V' && b == 'Y' ) {
        return 0;
    }
    return 1;
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
