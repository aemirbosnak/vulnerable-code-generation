//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int size;
    char *data;
} file;

file *files;
int num_files;

void add_file(char *name, int size, char *data) {
    files = realloc(files, sizeof(file) * (num_files + 1));
    files[num_files].name = strdup(name);
    files[num_files].size = size;
    files[num_files].data = malloc(size);
    memcpy(files[num_files].data, data, size);
    num_files++;
}

void print_files() {
    for (int i = 0; i < num_files; i++) {
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }
}

void recover_file(char *name) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            FILE *fp = fopen(name, "wb");
            fwrite(files[i].data, 1, files[i].size, fp);
            fclose(fp);
            printf("File '%s' recovered successfully.\n", name);
            return;
        }
    }
    printf("File '%s' not found.\n", name);
}

int main() {
    // Create some files
    add_file("file1.txt", 10, "Hello world!");
    add_file("file2.txt", 15, "This is a test file.");
    add_file("file3.txt", 20, "This is another test file.");

    // Print the list of files
    print_files();

    // Recover a file
    recover_file("file2.txt");

    return 0;
}