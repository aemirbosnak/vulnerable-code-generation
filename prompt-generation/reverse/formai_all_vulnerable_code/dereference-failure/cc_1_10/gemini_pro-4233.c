//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1024

typedef struct {
    char *key;
    char *value;
} JSONPair;

typedef struct {
    int count;
    JSONPair *pairs;
} JSONObject;

JSONObject *
json_object_new(void) {
    JSONObject *object = malloc(sizeof(JSONObject));
    object->count = 0;
    object->pairs = NULL;
    return object;
}

void
json_object_free(JSONObject *object) {
    for (int i = 0; i < object->count; i++) {
        free(object->pairs[i].key);
        free(object->pairs[i].value);
    }
    free(object->pairs);
    free(object);
}

int
json_object_add_pair(JSONObject *object, char *key, char *value) {
    object->pairs = realloc(object->pairs, (object->count + 1) * sizeof(JSONPair));
    if (object->pairs == NULL) {
        return -1;
    }
    object->pairs[object->count].key = strdup(key);
    object->pairs[object->count].value = strdup(value);
    object->count++;
    return 0;
}

char *
json_object_get_value(JSONObject *object, char *key) {
    for (int i = 0; i < object->count; i++) {
        if (strcmp(object->pairs[i].key, key) == 0) {
            return object->pairs[i].value;
        }
    }
    return NULL;
}

int
json_parse(char *json, JSONObject **object) {
    char *token;
    char *key;
    char *value;
    int in_string = 0;
    int in_object = 0;
    int in_array = 0;
    char *start_string = NULL;
    char *start_key = NULL;
    char *start_value = NULL;
    *object = json_object_new();
    for (char *p = json; *p != '\0'; p++) {
        if (*p == '"') {
            if (in_string == 0) {
                if (in_object == 1) {
                    start_key = p;
                } else if (in_array == 1) {
                    start_value = p;
                }
                in_string = 1;
            } else {
                if (in_object == 1) {
                    key = strndup(start_key, p - start_key);
                    start_key = NULL;
                } else if (in_array == 1) {
                    value = strndup(start_value, p - start_value);
                    start_value = NULL;
                    json_object_add_pair(*object, key, value);
                    free(key);
                }
                in_string = 0;
            }
        } else if (*p == ':' && in_string == 0) {
            if (in_object == 0) {
                return -1;
            }
            start_value = p + 1;
        } else if (*p == '{' && in_string == 0) {
            if (in_object == 1) {
                return -1;
            }
            in_object = 1;
        } else if (*p == '}' && in_string == 0) {
            if (in_object == 0) {
                return -1;
            }
            in_object = 0;
        } else if (*p == '[' && in_string == 0) {
            if (in_array == 1) {
                return -1;
            }
            in_array = 1;
        } else if (*p == ']' && in_string == 0) {
            if (in_array == 0) {
                return -1;
            }
            in_array = 0;
        } else if (*p == ',' && in_string == 0) {
            if (in_object == 1) {
                value = strndup(start_value, p - start_value);
                start_value = NULL;
                json_object_add_pair(*object, key, value);
                free(key);
            } else if (in_array == 1) {
                value = strndup(start_value, p - start_value);
                start_value = NULL;
                json_object_add_pair(*object, NULL, value);
            }
        }
    }
    if (in_string || in_object || in_array) {
        return -1;
    }
    return 0;
}

int
main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <json string>\n", argv[0]);
        return 1;
    }
    JSONObject *object;
    if (json_parse(argv[1], &object) != 0) {
        fprintf(stderr, "Error parsing JSON string\n");
        return 1;
    }
    for (int i = 0; i < object->count; i++) {
        printf("%s: %s\n", object->pairs[i].key, object->pairs[i].value);
    }
    json_object_free(object);
    return 0;
}