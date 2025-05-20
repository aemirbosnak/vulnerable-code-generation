//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *value;
} cookie_t;

typedef struct {
    int count;
    cookie_t *cookies;
} cookie_jar_t;

cookie_jar_t *cookie_jar_create() {
    cookie_jar_t *jar = malloc(sizeof(cookie_jar_t));
    jar->count = 0;
    jar->cookies = NULL;
    return jar;
}

void cookie_jar_destroy(cookie_jar_t *jar) {
    int i;
    for (i = 0; i < jar->count; i++) {
        free(jar->cookies[i].name);
        free(jar->cookies[i].value);
    }
    free(jar->cookies);
    free(jar);
}

void cookie_jar_add(cookie_jar_t *jar, char *name, char *value) {
    cookie_t *cookie = malloc(sizeof(cookie_t));
    cookie->name = strdup(name);
    cookie->value = strdup(value);
    jar->cookies = realloc(jar->cookies, sizeof(cookie_t) * (jar->count + 1));
    jar->cookies[jar->count++] = *cookie;
    free(cookie);
}

char *cookie_jar_get(cookie_jar_t *jar, char *name) {
    int i;
    for (i = 0; i < jar->count; i++) {
        if (strcmp(jar->cookies[i].name, name) == 0) {
            return jar->cookies[i].value;
        }
    }
    return NULL;
}

void cookie_jar_print(cookie_jar_t *jar) {
    int i;
    for (i = 0; i < jar->count; i++) {
        printf("%s=%s\n", jar->cookies[i].name, jar->cookies[i].value);
    }
}

int main() {
    cookie_jar_t *jar = cookie_jar_create();
    cookie_jar_add(jar, "username", "john_doe");
    cookie_jar_add(jar, "password", "secret");
    cookie_jar_print(jar);
    char *password = cookie_jar_get(jar, "password");
    printf("password=%s\n", password);
    cookie_jar_destroy(jar);
    return 0;
}