//Falcon-180B DATASET v1.0 Category: Memory management ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// define a struct for our data
struct data {
    int value;
    char *string;
};

// function to allocate memory for a new data struct
struct data *data_new() {
    struct data *d = malloc(sizeof(struct data));
    if (d == NULL) {
        printf("Error: failed to allocate memory for data struct\n");
        exit(1);
    }
    return d;
}

// function to free memory for a data struct
void data_free(struct data *d) {
    if (d == NULL) {
        printf("Error: attempted to free NULL data struct\n");
        exit(1);
    }
    free(d);
}

// function to print a data struct
void data_print(struct data *d) {
    if (d == NULL) {
        printf("Error: attempted to print NULL data struct\n");
        exit(1);
    }
    printf("value: %d, string: %s\n", d->value, d->string);
}

int main() {
    // allocate memory for a new data struct
    struct data *d = data_new();
    d->value = 42;
    d->string = strdup("the answer");

    // print the data struct
    data_print(d);

    // free memory for the data struct
    data_free(d);

    return 0;
}