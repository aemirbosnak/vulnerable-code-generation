//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BRAVE_ERR_MAX_MSG_LEN 100
#define BRAVE_ERR_MAX_DEPTH 5

typedef struct {
    const char *file;
    const char *func;
    int line;
    const char *msg;
} BraveErr;

BraveErr braveErrCreate(const char *file, const char *func, int line, const char *msg) {
    BraveErr err;
    err.file = file;
    err.func = func;
    err.line = line;
    err.msg = msg;
    return err;
}

void braveErrPrint(BraveErr err) {
    printf("Error: %s (%s:%d) %s\n", err.file, err.func, err.line, err.msg);
}

int braveErrGetDepth(BraveErr err) {
    return err.line;
}

const char *braveErrGetFile(BraveErr err) {
    return err.file;
}

const char *braveErrGetFunc(BraveErr err) {
    return err.func;
}

const char *braveErrGetMsg(BraveErr err) {
    return err.msg;
}

void braveErrFree(BraveErr *err) {
    free(err->file);
    free(err->func);
    free(err->msg);
    free(err);
}

int main() {
    BraveErr err = braveErrCreate("example.c", "exampleFunction", 10, "This is an example error");
    if (err.msg[0] == '\0') {
        printf("No errors found\n");
    } else {
        braveErrPrint(err);
    }

    err = braveErrCreate("example.c", "exampleFunction", 20, "This is another example error");
    if (err.msg[0] == '\0') {
        printf("No errors found\n");
    } else {
        braveErrPrint(err);
    }

    err = braveErrCreate("example.c", "exampleFunction", 30, "This is a third example error");
    if (err.msg[0] == '\0') {
        printf("No errors found\n");
    } else {
        braveErrPrint(err);
    }

    braveErrFree(&err);

    return 0;
}