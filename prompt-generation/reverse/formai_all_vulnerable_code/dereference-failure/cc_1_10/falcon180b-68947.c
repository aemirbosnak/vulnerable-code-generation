//Falcon-180B DATASET v1.0 Category: File handling ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FILE_NAME_SIZE 256

typedef struct {
    char *filename;
    FILE *file;
    int line_num;
} File;

int read_file(File *f) {
    char line[MAX_LINE_SIZE];
    int ret;

    fseek(f->file, 0L, SEEK_SET);

    while ((ret = fgets(line, MAX_LINE_SIZE, f->file))!= NULL) {
        printf("%d: %s", f->line_num, line);
        f->line_num++;
    }

    return ret;
}

int write_file(File *f, char *data) {
    int ret;

    ret = fprintf(f->file, "%s", data);

    if (ret < 0) {
        printf("Error writing to file.\n");
        return -1;
    }

    return ret;
}

int main(int argc, char **argv) {
    File f;
    char filename[MAX_FILE_NAME_SIZE];
    char *data;
    int len;

    if (argc < 3) {
        printf("Usage: %s <filename> <data>\n", argv[0]);
        return 1;
    }

    strncpy(filename, argv[1], MAX_FILE_NAME_SIZE);
    data = argv[2];
    len = strlen(data);

    f.filename = filename;
    f.file = fopen(filename, "a");

    if (f.file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    f.line_num = 0;

    while (len > 0) {
        int ret;

        if (len > MAX_LINE_SIZE) {
            ret = write_file(&f, data);
            data += MAX_LINE_SIZE;
            len -= MAX_LINE_SIZE;
        } else {
            ret = write_file(&f, data);
            break;
        }
    }

    fclose(f.file);

    return 0;
}