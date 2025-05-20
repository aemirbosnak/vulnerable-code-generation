//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_LINE_LEN 1024

struct FileMetadata {
    int num_functions;
    int num_variables;
    int num_preprocessor_directives;
};

void extract_metadata(char *filename) {
    int fd;
    char line[MAX_LINE_LEN];
    char *token;
    char *save_ptr;
    int num_functions = 0;
    int num_variables = 0;
    int num_preprocessor_directives = 0;

    fd = open(filename, O_RDONLY);

    if (fd < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LINE_LEN, fd) != NULL) {
        token = strtok_r(line, " \t\n", &save_ptr);

        if (strcmp(token, "#define") == 0) {
            num_preprocessor_directives++;
            continue;
        }

        if (strcmp(token, "int") == 0 || strcmp(token, "float") == 0 || strcmp(token, "double") == 0) {
            num_variables++;
            continue;
        }

        if (strcmp(token, "void") != 0 && strcmp(token, "main") != 0) {
            num_functions++;
        }

        while ((token = strtok_r(NULL, " \t\n", &save_ptr)) != NULL) {
            if (strcmp(token, "{") == 0) {
                num_functions++;
                break;
            }
        }
    }

    close(fd);

    printf("File metadata:\n");
    printf("Number of functions: %d\n", num_functions);
    printf("Number of variables: %d\n", num_variables);
    printf("Number of preprocessor directives: %d\n", num_preprocessor_directives);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    extract_metadata(argv[1]);

    return EXIT_SUCCESS;
}