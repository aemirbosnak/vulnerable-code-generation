//Falcon-180B DATASET v1.0 Category: File handling ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE_SIZE 1000

typedef struct {
    char filename[MAX_LINE_SIZE];
    FILE *fp;
    int lineno;
    char line[MAX_LINE_SIZE];
} FILE_HANDLE;

FILE_HANDLE *open_file(char *filename) {
    FILE_HANDLE *fp = (FILE_HANDLE *)malloc(sizeof(FILE_HANDLE));
    strcpy(fp->filename, filename);
    fp->fp = fopen(filename, "r");
    fp->lineno = 0;
    return fp;
}

int read_line(FILE_HANDLE *fp) {
    char c;
    int i = 0;
    while((c = fgetc(fp->fp))!= EOF) {
        if(i < MAX_LINE_SIZE - 1) {
            fp->line[i++] = c;
        } else {
            printf("Line truncated at %d characters.\n", MAX_LINE_SIZE - 1);
            break;
        }
    }
    fp->line[i] = '\0';
    fp->lineno++;
    return i;
}

void print_line(FILE_HANDLE *fp) {
    printf("%s:%d: %s\n", fp->filename, fp->lineno, fp->line);
}

int main() {
    FILE_HANDLE *fp = open_file("example.txt");
    int i;
    while((i = read_line(fp))!= 0) {
        print_line(fp);
    }
    fclose(fp->fp);
    free(fp);
    return 0;
}