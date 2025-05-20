//FormAI DATASET v1.0 Category: Error handling ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

struct error {
    int code;
    char *msg;
};

struct status {
    int id;
    char *name;
};

void check_error(int code) {
    struct error errors[] = {
        {1, "Invalid input"},
        {2, "File not found"},
        {3, "Memory allocation failed"},
        {4, "Divide by zero error"},
        {5, "Invalid operation"}
    };

    for (int i = 0; i < sizeof(errors)/sizeof(struct error); i++) {
        if (errors[i].code == code) {
            fprintf(stderr, "ERROR: %s\n", errors[i].msg);
            exit(code);
        }
    }
}

struct status *create_status(int id, char *name) {
    struct status *s = malloc(sizeof(struct status));
    if (!s) {
        check_error(3);
    }
    s->id = id;
    s->name = name;
    return s;
}

void print_status(struct status *s) {
    if (!s) {
        check_error(1);
    }
    printf("ID: %d, Name: %s\n", s->id, s->name);
}

int divide(int a, int b) {
    if (b == 0) {
        check_error(4);
    }
    return a/b;
}

int main() {
    struct status *s1 = create_status(1, "Active");
    struct status *s2 = NULL;
    print_status(s1);
    print_status(s2);
    int a = 10, b = 0;
    int result = divide(a, b);
    printf("Result: %d\n", result);
    return 0;
}