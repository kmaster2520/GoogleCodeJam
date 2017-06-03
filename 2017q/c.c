#include <stdio.h>
//#include <string.h>
#include <math.h>

/*
 fscanf(file*, format, pointers to variables)
 fprintf(file*, format, variables (no pointers))
 
*/

int main() {
    
    FILE* fp = fopen("infile.txt", "r");
    FILE* op = fopen("outfile.txt", "w");
    int T, n, k, m;
    fscanf(fp, "%d\n", &T);

    for (int t = 1; t <= T; t++) {
        
        fscanf(fp, "%d", &n);
        fscanf(fp, "%d", &k);
        //m = n + 2;

        int pk = (int) pow(2, (int)log2(k));
        //printf("%d\n", pk);
        int quo = (n - k) / pk;
        fprintf(op, "Case #%d: %d %d\n", t, quo - quo / 2, quo / 2);




    }
    
    fclose(fp);
    fclose(op);

}
