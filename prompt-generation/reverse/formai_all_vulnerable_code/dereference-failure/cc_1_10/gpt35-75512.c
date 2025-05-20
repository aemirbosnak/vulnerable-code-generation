//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 10485760 //10 MB

void recover(char *filename) {
    char buffer[MAX_FILE_SIZE];
    FILE *file;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    size_t num_read = fread(buffer, 1, MAX_FILE_SIZE, file);
    if (num_read == 0) {
        printf("Error: Could not read file %s\n", filename);
        fclose(file);
        return;
    }

    fclose(file);

    char *output_filename = (char*)malloc(strlen(filename) + 5);
    strcpy(output_filename, filename);
    strcat(output_filename, ".rec");

    file = fopen(output_filename, "w");
    if (file == NULL) {
        printf("Error: Could not create recovery file %s\n", output_filename);
        free(output_filename);
        return;
    }

    fwrite(buffer, 1, num_read, file);

    fclose(file);
    free(output_filename);

    printf("File %s successfully recovered as %s\n", filename, output_filename);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: data-recover <filename1> [<filename2> ...]\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        recover(argv[i]);
    }

    return 0;
}