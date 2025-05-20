//Falcon2-11B DATASET v1.0 Category: Ebook reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

struct file {
    char* filename;
    FILE* file;
    char* contents;
    size_t size;
};

void read_file(const char* filename, char* buffer) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
        return;
    }
    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    rewind(file);

    buffer = (char*) malloc(sizeof(char) * (file_size + 1));
    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    fread(buffer, sizeof(char), file_size, file);
    buffer[file_size] = '\0';

    fclose(file);
}

int main() {
    srand(time(NULL));
    int num_files = 100;
    char* files[num_files];
    char* contents[num_files];

    for (int i = 0; i < num_files; i++) {
        char* filename = (char*) malloc(sizeof(char) * 100);
        strncpy(filename, "file", 100);
        int random_num = rand() % 10;
        sprintf(filename + 5, "%d", random_num);
        files[i] = filename;

        read_file(filename, contents[i]);
    }

    for (int i = 0; i < num_files; i++) {
        printf("%s\n", contents[i]);
    }

    free(files);
    for (int i = 0; i < num_files; i++) {
        free(contents[i]);
    }

    return 0;
}