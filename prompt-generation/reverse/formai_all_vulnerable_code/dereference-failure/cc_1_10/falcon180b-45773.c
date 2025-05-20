//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *name;
    int size;
} file_t;

file_t *files = NULL;
int num_files = 0;

void add_file(char *filename) {
    file_t *new_file = (file_t *) malloc(sizeof(file_t));
    new_file->name = strdup(filename);
    new_file->size = 0;
    files = realloc(files, sizeof(file_t) * ++num_files);
    files[num_files - 1] = *new_file;
}

void read_file(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int line_length = strlen(line);
        if (line_length > 0 && line[line_length - 1] == '\n') {
            line[--line_length] = '\0';
        }

        for (int i = 0; i < num_files; i++) {
            if (strcmp(files[i].name, filename) == 0) {
                files[i].size += line_length;
                break;
            }
        }
    }

    fclose(file);
}

void print_files() {
    for (int i = 0; i < num_files; i++) {
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file1> <file2>...\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        add_file(argv[i]);
    }

    for (int i = 0; i < num_files; i++) {
        read_file(files[i].name);
    }

    print_files();

    return 0;
}