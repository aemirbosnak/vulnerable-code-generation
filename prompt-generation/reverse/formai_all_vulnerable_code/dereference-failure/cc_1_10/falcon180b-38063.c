//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 1000

typedef struct {
    char *data;
    int length;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
} File;

void read_file(File *file, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    int line_num = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        int length = strlen(line);
        if (length > 0 && line[length - 1] == '\n') {
            line[--length] = '\0';
        }
        Line *new_line = malloc(sizeof(Line));
        new_line->data = strdup(line);
        new_line->length = length;
        file->lines[line_num++] = *new_line;
    }
    file->num_lines = line_num;
    fclose(fp);
}

int calculate_checksum(File *file) {
    int checksum = 0;
    for (int i = 0; i < file->num_lines; i++) {
        Line *line = &file->lines[i];
        for (int j = 0; j < line->length; j++) {
            if (isprint(line->data[j])) {
                checksum += line->data[j];
            }
        }
    }
    return checksum;
}

void print_checksum(int checksum) {
    printf("Checksum: %d\n", checksum);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    File file;
    read_file(&file, argv[1]);

    int checksum = calculate_checksum(&file);
    print_checksum(checksum);

    for (int i = 0; i < file.num_lines; i++) {
        Line *line = &file.lines[i];
        printf("%s\n", line->data);
    }

    for (int i = 0; i < file.num_lines; i++) {
        free(file.lines[i].data);
    }
    free(file.lines);

    return 0;
}