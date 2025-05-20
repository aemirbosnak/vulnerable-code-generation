//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256
#define BUFFER_SIZE 4096

typedef struct fib_stack {
    int top;
    int data[MAX_CHAR];
} fib_stack;

void fib(int n, fib_stack *fs) {
    if (n <= 0) {
        fs->data[fs->top++] = 0;
        return;
    }

    fib(n - 1, fs);
    fs->data[fs->top++] = fs->data[fs->top - 1] + fs->data[fs->top - 2];
}

int read_char(FILE *fp) {
    int c = fgetc(fp);
    if (feof(fp)) {
        c = EOF;
    }
    return c;
}

void process_char(int c, fib_stack *fs, char *output) {
    fib(c, fs);
    int i = fs->top - 1;
    while (i--) {
        output[i] = "0123456789ABCDEF"[fs->data[i] % 16];
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    fib_stack fs = { .top = -1 };
    char output[BUFFER_SIZE] = { 0 };
    int c;

    while ((c = read_char(fp)) != EOF) {
        process_char(c, &fs, output);
    }

    fclose(fp);

    printf("Encrypted text:\n");
    fwrite(output, sizeof(char), strlen(output), stdout);
    printf("\n");

    return 0;
}