//FormAI DATASET v1.0 Category: Error handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void open_file(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        if (errno == ENOENT) {  // File not found
            printf("Error: \"%s\" not found.\n", filename);
            exit(EXIT_FAILURE);
        } else if (errno == EACCES) {  // Permission denied
            printf("Error: \"%s\" could not be opened. Permission denied.\n", filename);
            exit(EXIT_FAILURE);
        } else {  // Other errors
            perror("Error");
            exit(EXIT_FAILURE);
        }
    }
}

void read_file(FILE *fp) {
    int c;
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }
    if (ferror(fp)) {  // File reading error
        perror("Error");
        exit(EXIT_FAILURE);
    }
}

void close_file(FILE *fp) {
    int ret = fclose(fp);
    if (ret == EOF) {  // File closing error
        perror("Error");
        exit(EXIT_FAILURE);
    }
}

int main() {
    char *filename = "test.txt";
    
    open_file(filename);
    
    FILE *fp = fopen(filename, "r");
    read_file(fp);
    close_file(fp);
    
    return 0;
}