//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100

typedef struct {
    char *name;
    char *value;
} cookie_t;

typedef struct {
    int count;
    cookie_t *cookies;
} cookie_jar_t;

cookie_jar_t *create_cookie_jar() {
    cookie_jar_t *jar = (cookie_jar_t *) malloc(sizeof(cookie_jar_t));
    jar->count = 0;
    jar->cookies = (cookie_t *) malloc(MAX_SIZE * sizeof(cookie_t));
    return jar;
}

void destroy_cookie_jar(cookie_jar_t *jar) {
    free(jar->cookies);
    free(jar);
}

void add_cookie(cookie_jar_t *jar, char *name, char *value) {
    if (jar->count >= MAX_SIZE) {
        printf("Cookie jar is full.\n");
        return;
    }
    cookie_t *cookie = &jar->cookies[jar->count];
    cookie->name = strdup(name);
    cookie->value = strdup(value);
    jar->count++;
}

void print_cookies(cookie_jar_t *jar) {
    for (int i = 0; i < jar->count; i++) {
        printf("Name: %s, Value: %s\n", jar->cookies[i].name, jar->cookies[i].value);
    }
}

int main() {
    cookie_jar_t *jar = create_cookie_jar();
    add_cookie(jar, "username", "JohnDoe");
    add_cookie(jar, "password", "password123");
    print_cookies(jar);
    destroy_cookie_jar(jar);
    return 0;
}