//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_FILES 10

typedef struct {
    char filename[MAX_LINE_LENGTH];
    FILE *fp;
} FileHandle;

void print_help_and_exit(void) {
    printf("\nUsage: file_magician <operation> <filename1> [filename2 ...]\n");
    printf("Operations:\n");
    printf("  read   - Read data from files.\n");
    printf("  write  - Write data to files.\n");
    printf("  append - Append data to files.\n");
    printf("  delete - Delete files.\n");
    printf("Example: file_magician read config.ini\n");
    printf("         file_magician write output.txt Hello World!\n");
    printf("         file_magician append log.txt This is a log entry.\n");
    printf("         file_magician delete temp.txt\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    int i;
    FileHandle files[MAX_NUM_FILES];

    if (argc < 2) {
        print_help_and_exit();
    }

    if (strcmp(argv[1], "read") == 0) {
        for (i = 2; i < argc; ++i) {
            strcpy(files[i - 1].filename, argv[i]);
            files[i - 1].fp = fopen(files[i - 1].filename, "r");

            if (files[i - 1].fp == NULL) {
                fprintf(stderr, "Error opening file %s\n", files[i - 1].filename);
                return EXIT_FAILURE;
            }

            char buffer[MAX_LINE_LENGTH];
            size_t bytes_read;

            while (fgets(buffer, sizeof(buffer), files[i - 1].fp) != NULL) {
                printf("%s", buffer);
            }

            fclose(files[i - 1].fp);
        }
    } else if (strcmp(argv[1], "write") == 0) {
        // Write operation implementation here
    } else if (strcmp(argv[1], "append") == 0) {
        // Append operation implementation here
    } else if (strcmp(argv[1], "delete") == 0) {
        for (i = 2; i < argc; ++i) {
            if (remove(argv[i]) != 0) {
                perror("Error deleting file");
                return EXIT_FAILURE;
            }
        }
    } else {
        print_help_and_exit();
    }

    return EXIT_SUCCESS;
}