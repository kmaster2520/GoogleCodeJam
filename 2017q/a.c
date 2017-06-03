#include <stdio.h>
//#include <string.h>
//#include <math.h>

/*
 fscanf(file*, format, pointers to variables)
 fprintf(file*, format, variables (no pointers))
 
*/

int isDone(char* pc) {
    int unflipped =  0;
    int i = 0;
    while ( *(pc + i) != '\0' ) {
        if ( *(pc + i) == '-' ) {
            unflipped++;
            return 0;
        }
        i++;
    }

    return 1;
}

int main() {
    
    FILE* fp = fopen("infile.txt", "r");
    FILE* op = fopen("outfile.txt", "w");
    int T, n, i;
    fscanf(fp, "%d\n", &T);

    for (int t = 1; t <= T; t++) {
        char pcakes[15];
        i = -1;
        while (1) {
            char c = fgetc(fp);
            pcakes[++i] = c; //+ = 43, - = 45, sum = 89
            if (c == ' ') {
                pcakes[i] = '\0';
                break;
            }
        }
        fscanf(fp, "%d\n", &n);

        if (isDone(pcakes) == 1) {
            fprintf(op, "Case #%d: 0\n", t);
            continue;
        }

        



        fprintf(op, "%s %d\n", pcakes, n);
    }
    
    fclose(fp);
    fclose(op);

}
