//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME 256
#define MAX_LINE_SIZE 1024

typedef struct {
    FILE *fp;
    char filename[MAX_FILE_NAME];
    char mode[4];
    char line[MAX_LINE_SIZE];
} file_t;

void init_file(file_t *file, char *filename, char *mode) {
    strcpy(file->filename, filename);
    strcpy(file->mode, mode);
    file->fp = fopen(filename, mode);
    if (file->fp == NULL) {
        printf("Error: Failed to open file '%s'\n", filename);
        exit(1);
    }
}

void close_file(file_t *file) {
    fclose(file->fp);
}

void read_line(file_t *file, char *line) {
    fgets(file->line, MAX_LINE_SIZE, file->fp);
    strcpy(line, file->line);
}

void write_line(file_t *file, char *line) {
    fprintf(file->fp, "%s", line);
}

int compare_lines(char *line1, char *line2) {
    int len1 = strlen(line1);
    int len2 = strlen(line2);
    if (len1!= len2) {
        return 1;
    }
    for (int i = 0; i < len1; i++) {
        if (tolower(line1[i])!= tolower(line2[i])) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char source_file[MAX_FILE_NAME] = "source.txt";
    char target_file[MAX_FILE_NAME] = "target.txt";
    char line[MAX_LINE_SIZE];

    file_t source_file_obj;
    init_file(&source_file_obj, source_file, "r");

    file_t target_file_obj;
    init_file(&target_file_obj, target_file, "w");

    char *mode = "r";
    while (fgets(line, MAX_LINE_SIZE, stdin)!= NULL) {
        if (strcmp(line, "BEGININSTRUCTION") == 0) {
            mode = "r";
        } else if (strcmp(line, "ENDINSTRUCTION") == 0) {
            mode = "w";
        } else if (strcmp(line, "DELETE") == 0) {
            rewind(source_file_obj.fp);
        } else {
            write_line(&target_file_obj, line);
        }
    }

    close_file(&source_file_obj);
    close_file(&target_file_obj);

    return 0;
}