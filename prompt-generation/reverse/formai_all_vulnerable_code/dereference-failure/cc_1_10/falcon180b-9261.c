//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_SIZE 1024

typedef struct {
    char *name;
    char *value;
} cookie_t;

typedef struct {
    cookie_t *cookies;
    int num_cookies;
} cookie_jar_t;

cookie_jar_t *create_cookie_jar() {
    cookie_jar_t *jar = (cookie_jar_t *)malloc(sizeof(cookie_jar_t));
    jar->cookies = (cookie_t *)malloc(MAX_SIZE * sizeof(cookie_t));
    jar->num_cookies = 0;
    return jar;
}

void add_cookie(cookie_jar_t *jar, char *name, char *value) {
    if (jar->num_cookies >= MAX_SIZE) {
        printf("Cookie jar is full!\n");
        return;
    }
    jar->cookies[jar->num_cookies].name = strdup(name);
    jar->cookies[jar->num_cookies].value = strdup(value);
    jar->num_cookies++;
}

void print_cookies(cookie_jar_t *jar) {
    for (int i = 0; i < jar->num_cookies; i++) {
        printf("Name: %s, Value: %s\n", jar->cookies[i].name, jar->cookies[i].value);
    }
}

void destroy_cookie_jar(cookie_jar_t *jar) {
    for (int i = 0; i < jar->num_cookies; i++) {
        free(jar->cookies[i].name);
        free(jar->cookies[i].value);
    }
    free(jar->cookies);
    free(jar);
}

int main() {
    cookie_jar_t *jar = create_cookie_jar();
    add_cookie(jar, "username", "john");
    add_cookie(jar, "password", "password123");
    print_cookies(jar);
    destroy_cookie_jar(jar);
    return 0;
}