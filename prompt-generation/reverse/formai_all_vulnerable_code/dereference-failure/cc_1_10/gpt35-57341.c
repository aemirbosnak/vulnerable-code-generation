//FormAI DATASET v1.0 Category: Data recovery tool ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BUFFER_SIZE 1024

/**
 * Read file content into a buffer.
 * @param filename the file name to read.
 * @param buffer the buffer to read into.
 * @param size the maximum buffer size.
 * @return the actual data size read, or -1 if error occurs.
 */
int read_file(const char* filename, char* buffer, int size) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        return -1;
    }
    int n = fread(buffer, 1, size, fp);
    fclose(fp);
    return n;
}

/**
 * Write buffer content into a file.
 * @param filename the file name to write.
 * @param buffer the buffer to write from.
 * @param size the actual data size.
 * @return 0 if success, or -1 if error occurs.
 */
int write_file(const char* filename, const char* buffer, int size) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        return -1;
    }
    fwrite(buffer, size, 1, fp);
    fclose(fp);
    return 0;
}

/**
 * Main function.
 */
int main(int argc, char* argv[]) {
    char input_filename[MAX_FILENAME_LENGTH];
    char output_filename[MAX_FILENAME_LENGTH];
    char buffer[MAX_BUFFER_SIZE];
    int buffer_size, actual_size;
    int option;

    printf("Data recovery tool\n");
    printf("-------------------\n");

    if (argc < 2) {
        printf("Usage: datarecovery <input_file>\n");
        return -1;
    }

    strcpy(input_filename, argv[1]);
    printf("Recovering data from file '%s'\n", input_filename);

    do {
        printf("Select option:\n");
        printf("1: Load file content\n");
        printf("2: Filter file content\n");
        printf("3: Save filtered content\n");
        printf("0: Exit\n");
        printf("> ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                buffer_size = MAX_BUFFER_SIZE;
                actual_size = read_file(input_filename, buffer, buffer_size);
                if (actual_size == -1) {
                    printf("Error: failed to load file content.\n");
                } else {
                    printf("Loaded %d bytes.\n", actual_size);
                }
                break;
            case 2:
                if (actual_size == -1) {
                    printf("Error: no file content is loaded.\n");
                } else {
                    for (int i = 0; i < actual_size; i++) {
                        if (buffer[i] < 32 || buffer[i] > 126) {
                            buffer[i] = ' ';
                        }
                    }
                    printf("Filtered file content.\n");
                }
                break;
            case 3:
                if (actual_size == -1) {
                    printf("Error: no file content is loaded.\n");
                } else {
                    printf("Enter output filename: ");
                    scanf("%s", output_filename);
                    if (write_file(output_filename, buffer, actual_size) == -1) {
                        printf("Error: failed to save file content.\n");
                    } else {
                        printf("Saved %d bytes to file '%s'.\n", actual_size, output_filename);
                    }
                }
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Error: invalid option %d.\n", option);
        }
        printf("\n");
    } while (option != 0);

    return 0;
}