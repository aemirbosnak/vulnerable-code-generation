//Falcon-180B DATASET v1.0 Category: Error handling ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define ERR_MAX 100

typedef struct {
    char *message;
    int code;
} error_t;

static error_t errors[ERR_MAX];
static int err_count = 0;

void err_init(void) {
    memset(errors, 0, sizeof(errors));
}

int err_push(char *msg, int code) {
    if (err_count >= ERR_MAX) {
        return -1;
    }

    errors[err_count].message = strdup(msg);
    errors[err_count].code = code;
    err_count++;

    return 0;
}

void err_pop(int count) {
    if (count > err_count) {
        count = err_count;
    }

    for (int i = 0; i < count; i++) {
        free(errors[i].message);
        memset(&errors[i], 0, sizeof(error_t));
    }

    err_count -= count;
}

void err_print(void) {
    for (int i = 0; i < err_count; i++) {
        fprintf(stderr, "Error %d: %s\n", errors[i].code, errors[i].message);
    }
}

int main(void) {
    err_init();

    err_push("Invalid argument", 1);
    err_push("File not found", 2);
    err_push("Permission denied", 3);

    if (err_count == 0) {
        printf("No errors\n");
    } else {
        err_print();
    }

    err_pop(2);

    if (err_count == 0) {
        printf("No errors\n");
    } else {
        err_print();
    }

    return 0;
}