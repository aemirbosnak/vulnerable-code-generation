//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUTS 10
#define MAX_URL_LENGTH 256

typedef struct {
    char url[MAX_URL_LENGTH];
    bool is_valid;
} input_t;

input_t inputs[MAX_INPUTS];

void sanitize_url(char *url) {
    int i;
    for (i = 0; url[i] != '\0'; i++) {
        if (url[i] >= 'A' && url[i] <= 'Z') {
            url[i] += 'a' - 'A';
        }
        if (url[i] >= 'a' && url[i] <= 'z') {
            url[i] = '_' + (url[i] - 'a');
        }
        if (url[i] >= '0' && url[i] <= '9') {
            url[i] = url[i];
        } else if (strchr("./%_~", url[i])) {
            url[i] = url[i];
        } else {
            url[i] = '_';
        }
    }
    url[i] = '\0';
}

int main(int argc, char *argv[]) {
    int i;

    if (argc > MAX_INPUTS) {
        printf("Error: Too many inputs.\n");
        return 1;
    }

    for (i = 0; i < argc; i++) {
        strcpy(inputs[i].url, argv[i]);
        sanitize_url(inputs[i].url);
        inputs[i].is_valid = true;
    }

    for (i = 0; i < argc; i++) {
        printf("Input %d: %s\n", i + 1, inputs[i].url);
    }

    return 0;
}