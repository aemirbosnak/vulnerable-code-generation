//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>

#define MAX_NAME_LEN 100
#define MAX_VALUE_LEN 1000
#define MAX_COOKIES 100

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} cookie_t;

int num_cookies = 0;
cookie_t cookies[MAX_COOKIES];

void add_cookie(char* name, char* value) {
    if (num_cookies >= MAX_COOKIES) {
        printf("Error: Too many cookies.\n");
        return;
    }

    strcpy(cookies[num_cookies].name, name);
    strcpy(cookies[num_cookies].value, value);

    num_cookies++;
}

void print_cookies() {
    for (int i = 0; i < num_cookies; i++) {
        printf("%s=%s\n", cookies[i].name, cookies[i].value);
    }
}

int main() {
    char* input = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&input, &len, stdin))!= -1) {
        if (input[0] == '#') {
            continue;
        }

        char* name = strtok(input, "=");
        char* value = strtok(NULL, "=");

        if (name == NULL || value == NULL) {
            printf("Error: Invalid cookie format.\n");
            continue;
        }

        add_cookie(name, value);
    }

    print_cookies();

    return 0;
}