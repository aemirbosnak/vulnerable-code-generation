//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

#define MAX_LINE_LEN 1024
#define MAX_BUF_LEN 4096

void *malloc_with_flair(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("MALLOC FAILED WITH SIZE %zu\n", size);
        exit(1);
    }
    return ptr;
}

void *realloc_with_flair(void *ptr, size_t size) {
    void *new_ptr = realloc(ptr, size);
    if (new_ptr == NULL) {
        printf("REALLOC FAILED WITH PTR %p AND SIZE %zu\n", ptr, size);
        exit(1);
    }
    return new_ptr;
}

int main() {
    char *line;
    size_t line_len;
    char *buf = malloc_with_flair(MAX_BUF_LEN);
    if (buf == NULL) {
        printf("MALLOC FAILED WITH MAX_BUF_LEN %zu\n", MAX_BUF_LEN);
        exit(1);
    }

    while (1) {
        printf("Enter a line: ");
        line = malloc_with_flair(MAX_LINE_LEN);
        if (line == NULL) {
            printf("MALLOC FAILED WITH MAX_LINE_LEN %zu\n", MAX_LINE_LEN);
            exit(1);
        }
        fgets(line, MAX_LINE_LEN, stdin);
        line_len = strlen(line);
        if (line_len > 0 && line[line_len - 1] == '\n') {
            line[line_len - 1] = '\0';
        }

        if (strcmp(line, "QUIT") == 0) {
            break;
        }

        // Do something with the line
        // ...

        free(line);
    }

    free(buf);
    return 0;
}