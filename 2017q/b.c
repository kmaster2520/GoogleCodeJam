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
    int T, n;
    fscanf(fp, "%d\n", &T);

    for (int t = 1; t <= T; t++) {
        char num[20];
        int i = 0;
        while (1) {
            char c = fgetc(fp);
            if (c < 48 || c > 57) {
                num[i] = '\0';
                break;
            } else {
                num[i] = c;
            }
            i++;
        }
        //printf("got here\n");

        int j = i - 1;
        if (j == 0) {
            fprintf(op, "Case #%d: %c\n", t, num[j]);
            continue;
        }

        int k = j;
        while (j >= 1) {
            if (num[j - 1] > num[j]) {
                for (int l = j; l <= k; l++) {
                    num[l] = 57;
                }
                num[j - 1]--;
            }
            j--;
        }

        fprintf(op, "Case #%d: ", t);
        int l = 0;
        if (num[0] == 48) {
            l++;
        }
        for (l = l; l <= k; l++) {
            fprintf(op, "%c", num[l]);
        }
        fprintf(op, "\n");
        //fprintf(op, "Case #%d: %s\n", t, num);

    }
    
    fclose(fp);
    fclose(op);

}
