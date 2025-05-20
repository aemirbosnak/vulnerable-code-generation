//FormAI DATASET v1.0 Category: Browser Plugin ; Style: safe
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/* Define custom types */
typedef struct {
    char *key;
    char *value;
} kvp_t;

typedef struct {
    kvp_t *kvps;
    size_t size;
} dict_t;

/* Initialize a dictionary */
static void dict_init(dict_t *d) {
    d->kvps = NULL;
    d->size = 0;
}

/* Add a key-value pair to the dictionary */
static void dict_add(dict_t *d, const char *key, const char *value) {
    kvp_t *p = realloc(d->kvps, sizeof(*d->kvps) * (d->size + 1));
    if (p == NULL) {
        fprintf(stderr, "Memory allocation failure\n");
        exit(EXIT_FAILURE);
    }
    d->kvps = p;
    d->kvps[d->size].key = strdup(key);
    d->kvps[d->size].value = strdup(value);
    d->size++;
}

/* Lookup a value given a key in the dictionary */
static char *dict_get(dict_t *d, const char *key) {
    for (size_t i = 0; i < d->size; i++) {
        if (strcmp(d->kvps[i].key, key) == 0)
            return d->kvps[i].value;
    }
    return NULL;
}

/* Free the memory used by the dictionary */
static void dict_free(dict_t *d) {
    for (size_t i = 0; i < d->size; i++) {
        free(d->kvps[i].key);
        free(d->kvps[i].value);
    }
    free(d->kvps);
    d->kvps = NULL;
    d->size = 0;
}

/* Parse the query string */
static dict_t parse_query_string(const char *qs) {
    dict_t d;
    dict_init(&d);

    size_t len = strlen(qs);
    char *qs_copy = strdup(qs);

    char *tok = NULL;
    char *saveptr1 = NULL;

    /* Split the query string into key-value pairs */
    for (tok = strtok_r(qs_copy, "&", &saveptr1); tok != NULL; tok = strtok_r(NULL, "&", &saveptr1)) {
        char *key = NULL;
        char *value = NULL;

        char *saveptr2 = NULL;
        char *tok2 = strtok_r(tok, "=", &saveptr2);
        if (tok2 != NULL) {
            key = tok2;

            tok2 = strtok_r(NULL, "=", &saveptr2);
            if (tok2 != NULL) {
                value = tok2;

                /* URL decode the key and value */
                for (size_t i = 0; i < strlen(key); i++) {
                    key[i] = (key[i] == '+') ? ' ' : key[i];
                }
                for (size_t i = 0; i < strlen(value); i++) {
                    value[i] = (value[i] == '+') ? ' ' : value[i];
                }
                char *key_decoded = calloc(sizeof(char), strlen(key) + 1);
                char *value_decoded = calloc(sizeof(char), strlen(value) + 1);
                if (key_decoded == NULL || value_decoded == NULL) {
                    fprintf(stderr, "Memory allocation failure\n");
                    exit(EXIT_FAILURE);
                }
                size_t j = 0;
                for (size_t i = 0; i < strlen(key); i++, j++) {
                    if (key[i] == '%') {
                        char hex[3] = { key[i+1], key[i+2], '\0' };
                        int num = (int)strtoul(hex, NULL, 16);
                        key_decoded[j] = (char)num;
                        i += 2;
                    }
                    else {
                        key_decoded[j] = key[i];
                    }
                }
                j = 0;
                for (size_t i = 0; i < strlen(value); i++, j++) {
                    if (value[i] == '%') {
                        char hex[3] = { value[i+1], value[i+2], '\0' };
                        int num = (int)strtoul(hex, NULL, 16);
                        value_decoded[j] = (char)num;
                        i += 2;
                    }
                    else {
                        value_decoded[j] = value[i];
                    }
                }

                dict_add(&d, key_decoded, value_decoded);

                free(key_decoded);
                free(value_decoded);
            }
        }
    }

    free(qs_copy);

    return d;
}

/* Encode a string for use in a URL */
static char *url_encode(const char *str) {
    size_t len = strlen(str);
    char *encoded = calloc(sizeof(char), 3*len + 1);
    if (encoded == NULL) {
        fprintf(stderr, "Memory allocation failure\n");
        exit(EXIT_FAILURE);
    }
    size_t j = 0;
    for (size_t i = 0; i < len; i++) {
        if (isalnum(str[i]) || str[i] == '-' || str[i] == '_' || str[i] == '.' || str[i] == '~') {
            encoded[j++] = str[i];
        }
        else {
            sprintf(encoded+j, "%%%02X", str[i]);
            j += 3;
        }
    }
    return encoded;
}

/* Main function */
int main(int argc, char **argv) {
    /* Parse the query string */
    dict_t d = parse_query_string(argv[1]);

    /* Print the key-value pairs */
    for (size_t i = 0; i < d.size; i++) {
        printf("%s=%s\n", d.kvps[i].key, d.kvps[i].value);
    }

    /* Encode some strings */
    char *str1 = url_encode("hello world");
    char *str2 = url_encode(" &;?=+");

    printf("%s\n", str1);
    printf("%s\n", str2);

    /* Free the dictionary */
    dict_free(&d);

    /* Free the encoded strings */
    free(str1);
    free(str2);

    return 0;
}