//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    char *value;
} pair;

typedef struct {
    size_t count;
    pair *pairs;
} object;

void add_pair(object *obj, char *key, char *value) {
    obj->count++;
    obj->pairs = realloc(obj->pairs, obj->count * sizeof(pair));
    obj->pairs[obj->count - 1].key = key;
    obj->pairs[obj->count - 1].value = value;
}

void print_pair(pair p) {
    printf("\"%s\": \"%s\"\n", p.key, p.value);
}

void print_object(object o) {
    printf("{\n");
    for (size_t i = 0; i < o.count; i++) {
        print_pair(o.pairs[i]);
    }
    printf("}\n");
}

object parse_object(char *str) {
    object obj = {0};
    size_t len = strlen(str);
    char *key = NULL;
    char *value = NULL;

    enum {
        START,
        IN_KEY,
        IN_VALUE,
        IN_STRING_VALUE,
        END_STRING_VALUE,
        END_VALUE,
        END_OBJECT,
        ERROR
    } state = START;

    for (size_t i = 0; i < len; i++) {
        char c = str[i];

        switch (state) {
            case START:
                switch (c) {
                    case '{':
                        state = IN_KEY;
                        break;
                    case ' ':
                    case '\t':
                    case '\n':
                        break;
                    default:
                        state = ERROR;
                        break;
                }
                break;
            case IN_KEY:
                switch (c) {
                    case '\"':
                        key = malloc(1);
                        key[0] = '\0';
                        state = IN_STRING_VALUE;
                        break;
                    case ' ':
                    case '\t':
                    case '\n':
                        break;
                    case '}':
                        state = END_OBJECT;
                        break;
                    default:
                        state = ERROR;
                        break;
                }
                break;
            case IN_VALUE:
                switch (c) {
                    case '\"':
                        value = malloc(1);
                        value[0] = '\0';
                        state = IN_STRING_VALUE;
                        break;
                    case ' ':
                    case '\t':
                    case '\n':
                        break;
                    case '}':
                        state = END_OBJECT;
                        break;
                    default:
                        state = ERROR;
                        break;
                }
                break;
            case IN_STRING_VALUE:
                switch (c) {
                    case '\"':
                        state = END_STRING_VALUE;
                        break;
                    case '\\':
                        state = ERROR;
                        break;
                    default:
                        if (value == NULL) {
                            key = realloc(key, strlen(key) + 2);
                            key[strlen(key)] = c;
                            key[strlen(key) + 1] = '\0';
                        } else {
                            value = realloc(value, strlen(value) + 2);
                            value[strlen(value)] = c;
                            value[strlen(value) + 1] = '\0';
                        }
                        break;
                }
                break;
            case END_STRING_VALUE:
                switch (c) {
                    case ' ':
                    case '\t':
                    case '\n':
                        break;
                    case ',':
                        add_pair(&obj, key, value);
                        key = NULL;
                        value = NULL;
                        state = IN_KEY;
                        break;
                    case '}':
                        add_pair(&obj, key, value);
                        state = END_OBJECT;
                        break;
                    default:
                        state = ERROR;
                        break;
                }
                break;
            case END_VALUE:
                switch (c) {
                    case ' ':
                    case '\t':
                    case '\n':
                        break;
                    case ',':
                        add_pair(&obj, key, value);
                        key = NULL;
                        value = NULL;
                        state = IN_KEY;
                        break;
                    case '}':
                        add_pair(&obj, key, value);
                        state = END_OBJECT;
                        break;
                    default:
                        state = ERROR;
                        break;
                }
                break;
            case END_OBJECT:
                if (c == ' ' || c == '\t' || c == '\n') {
                    break;
                } else {
                    state = ERROR;
                    break;
                }
            case ERROR:
                break;
        }

        if (state == ERROR) {
            break;
        }
    }

    if (state != END_OBJECT) {
        // handle error
        printf("Error parsing JSON object\n");
        exit(EXIT_FAILURE);
    }

    return obj;
}

int main() {
    char *json_str = "{ \"name\": \"John\", \"age\": 30, \"city\": \"New York\" }";

    object obj = parse_object(json_str);
    print_object(obj);

    return 0;
}