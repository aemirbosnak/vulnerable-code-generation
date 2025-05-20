//Falcon2-11B DATASET v1.0 Category: Error handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct error {
    char *message;
};

struct error *error_init(char *message) {
    struct error *err = (struct error *) malloc(sizeof(struct error));
    if (err!= NULL) {
        err->message = strdup(message);
    }
    return err;
}

void error_handle(struct error *err) {
    if (err->message!= NULL) {
        printf("Error: %s\n", err->message);
        free(err->message);
        free(err);
    }
}

struct error *error_create() {
    struct error *err = (struct error *) malloc(sizeof(struct error));
    if (err!= NULL) {
        err->message = "Error occurred!";
    }
    return err;
}

void error_destroy(struct error *err) {
    if (err!= NULL) {
        printf("Error: %s\n", err->message);
        free(err->message);
        free(err);
    }
}

char *error_print(struct error *err) {
    if (err!= NULL) {
        printf("Error: %s\n", err->message);
        return err->message;
    }
    return NULL;
}

int main() {
    struct error *err = error_init("Hello World!");
    error_handle(err);
    error_destroy(err);
    return 0;
}