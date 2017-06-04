#include <stdio.h>
#include <stdlib.h>

int getInt(FILE*);
char* getStr(FILE*, int size);

typedef struct sample {
    int a[10];
    int b;
    char* c;
} sample_t;

int main() {
    FILE* fp = fopen("testin.txt", "r");
    int k = getInt(fp);
    int l = getInt(fp);
    char* s = getStr(fp, 10);
    char t[20];
    fgets(t, sizeof(t), fp);
    printf("%d %d %s %s\n", k, l, s, t);

    free(s);
    fclose(fp);

    int a[5]={4,5,6,7,8};
    char b = 1;
    printf("%d\n", a[b]);
    printf("%lu\n", sizeof(a));
    printf("%lu\n", sizeof(sample_t));

    printf("%.3f\n", 3.14159265);

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



char* getStr(FILE* fp, int size) {
    char* str = malloc(size * sizeof(char));
    int i = 0;
    char c = fgetc(fp);
    while (c >= 33 && c <= 126 && i < size - 1) {
        str[i++] = c;
        c = fgetc(fp);
    }
    str[i] = 0;
    return str;
}