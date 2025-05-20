//Falcon-180B DATASET v1.0 Category: Error handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define ERROR_MAX 256

typedef struct {
    int err_no;
    char err_msg[ERROR_MAX];
} Error;

static Error error_stack[ERROR_MAX];
static int err_count = 0;

void push_error(int err_num, char* msg) {
    if (err_count >= ERROR_MAX) {
        fprintf(stderr, "Error stack overflow!\n");
        exit(1);
    }
    error_stack[err_count].err_no = err_num;
    strncpy(error_stack[err_count].err_msg, msg, ERROR_MAX - 1);
    err_count++;
}

void pop_error() {
    if (err_count <= 0) {
        fprintf(stderr, "Error stack underflow!\n");
        exit(1);
    }
    err_count--;
}

int get_error_count() {
    return err_count;
}

int get_last_error_num() {
    if (err_count <= 0) {
        return 0;
    }
    return error_stack[err_count - 1].err_no;
}

char* get_last_error_msg() {
    if (err_count <= 0) {
        return "";
    }
    return error_stack[err_count - 1].err_msg;
}

void clear_error_stack() {
    err_count = 0;
}

int main() {
    FILE* fp;
    char* filename = "nonexistent.txt";
    char buffer[1024];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        push_error(errno, strerror(errno));
    }

    if (fread(buffer, sizeof(char), 1024, fp) == 0) {
        push_error(0, "Failed to read from file.");
    }

    fclose(fp);
    if (ferror(fp)) {
        push_error(errno, strerror(errno));
    }

    printf("Error count: %d\n", get_error_count());
    printf("Last error number: %d\n", get_last_error_num());
    printf("Last error message: %s\n", get_last_error_msg());

    clear_error_stack();
    printf("Error count after clear: %d\n", get_error_count());

    return 0;
}