//Falcon-180B DATASET v1.0 Category: System administration ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>
#include <dirent.h>

#define BUFFER_SIZE 1024 // size of buffer for reading file contents

char *get_file_contents(char *filename) {
    FILE *file;
    char *contents = NULL;
    long file_size;

    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    contents = malloc(file_size + 1); // +1 for null terminator
    if (contents == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for file contents\n");
        exit(1);
    }

    if (fread(contents, file_size, 1, file)!= 1) {
        fprintf(stderr, "Error: Could not read file contents\n");
        exit(1);
    }

    contents[file_size] = '\0';
    fclose(file);

    return contents;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    char *contents = get_file_contents(filename);

    printf("File contents:\n%s", contents);

    free(contents);
    return 0;
}