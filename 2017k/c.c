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

int main() {
    
    FILE* fp = fopen("infile.txt", "r");
    FILE* op = fopen("outfile.txt", "w");
    int T;
    char s1[205], s2[205];
    fscanf(fp, "%d\n", &T);

    for (int t = 1; t <= T; t++) {
        fscanf(fp, "%s\n", s1);
        fscanf(fp, "%s\n", s2);
    }
    
    fclose(fp);
    fclose(op);

}
