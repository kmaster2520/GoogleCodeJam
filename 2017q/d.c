#include <stdio.h>
//#include <string.h>
//#include <math.h>

/*
 fscanf(file*, format, pointers to variables)
 fprintf(file*, format, variables (no pointers))
 
*/

int main() {
    
    FILE* fp = fopen("infile.txt", "r");
    FILE* op = fopen("outfile.txt", "w");
    int T;
    fscanf(fp, "%d\n", &T);

    for (int t = 1; t <= T; t++) {

    }
    
    fclose(fp);
    fclose(op);

}
