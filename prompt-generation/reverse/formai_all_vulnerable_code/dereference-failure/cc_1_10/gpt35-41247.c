//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_KEY_LENGTH 100
#define MAX_VAL_LENGTH 100

typedef struct json {
    char key[MAX_KEY_LENGTH];
    char val[MAX_VAL_LENGTH];
    struct json *next;
} json_t;

json_t *json_parse(char *str);
void json_free(json_t *json);
void json_print(json_t *json);

json_t* json_parse_object(char **str) {
    json_t *head = NULL;
    json_t **cur = &head;
    int key_len, val_len;
    char *key, *val;

    while (**str != '}') {
        // get key
        if (**str != '\"') {
            printf("Error: Expected key at position %ld\n", *str - str[0] + 1);
            json_free(head);
            return NULL;
        }
        ++(*str);
        key_len = 0;
        key = *str;
        while (**str != '\"') {
            if (**str == '\0') {
                printf("Error: Unterminated key at position %ld\n", *str - str[0] + 1);
                json_free(head);
                return NULL;
            }
            ++(*str);
            ++key_len;
            if (key_len >= MAX_KEY_LENGTH) {
                printf("Error: Key too long at position %ld\n", *str - str[0] + 1 - key_len);
                json_free(head);
                return NULL;
            }
        }
        ++(*str);
        (*str)++; // skip ':'
        while (**str == ' ' || **str == '\t' || **str == '\n') {
            ++(*str);
        }
        // get val
        if (**str != '\"') {
            printf("Error: Expected val at position %ld\n", *str - str[0] + 1);
            json_free(head);
            return NULL;
        }
        ++(*str);
        val_len = 0;
        val = *str;
        while (**str != '\"') {
            if (**str == '\0') {
                printf("Error: Unterminated val at position %ld\n", *str - str[0] + 1);
                json_free(head);
                return NULL;
            }
            ++(*str);
            ++val_len;
            if (val_len >= MAX_VAL_LENGTH) {
                printf("Error: Val too long at position %ld\n", *str - str[0] + 1 - val_len);
                json_free(head);
                return NULL;
            }
        }
        (*str)++;
        // add to list
        *cur = malloc(sizeof(json_t));
        strncpy((*cur)->key, key, key_len);
        (*cur)->key[key_len] = '\0';
        strncpy((*cur)->val, val, val_len);
        (*cur)->val[val_len] = '\0';
        cur = &((*cur)->next);
        while (**str == ' ' || **str == '\t' || **str == '\n' || **str == ',') {
            ++(*str);
        }
    }
    (*str)++;
    *cur = NULL;
    return head;
}

json_t* json_parse_value(char **str) {
    json_t *json;
    int val_len;
    char *val;

    if (*str == NULL || **str == '\0') {
        printf("Error: Unterminated val\n");
        return NULL;
    }
    json = malloc(sizeof(json_t));
    if (**str == '{') {
        (*str)++;
        json->next = json_parse_object(str);
        if (json->next == NULL) {
            free(json);
            return NULL;
        }
    } else if (**str == '\"') {
        (*str)++;
        val_len = 0;
        val = *str;
        while (**str != '\"') {
            if (**str == '\0') {
                printf("Error: Unterminated val at position %ld\n", *str - str[0] + 1);
                json_free(json);
                return NULL;
            }
            ++(*str);
            ++val_len;
            if (val_len >= MAX_VAL_LENGTH) {
                printf("Error: Val too long at position %ld\n", *str - str[0] + 1 - val_len);
                json_free(json);
                return NULL;
            }
        }
        (*str)++;
        json->next = NULL;
    } else {
        printf("Error: Invalid val at position %ld\n", *str - str[0] + 1);
        free(json);
        return NULL;
    }

    strncpy(json->val, val, val_len);
    json->val[val_len] = '\0';

    return json;
}

json_t *json_parse(char *str) {
    json_t *json = malloc(sizeof(json_t));
    if (*str != '{') {
        printf("Error: Invalid JSON (missing '{')\n");
        free(json);
        return NULL;
    }
    str++;
    json->next = json_parse_object(&str);
    if (json->next == NULL) {
        free(json);
        return NULL;
    }
    return json;
}

void json_free(json_t *json) {
    while (json != NULL) {
        json_t *next = json->next;
        free(json);
        json = next;
    }
}

void json_print(json_t *json) {
    while (json != NULL) {
        printf("%s: %s\n", json->key, json->val);
        json = json->next;
    }
}

int main() {
    json_t *json;
    char *str = "{ \"name\": \"John\", \"age\": 30 }";
    json = json_parse(str);
    json_print(json);
    json_free(json);
    return 0;
}