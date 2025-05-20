//Falcon-180B DATASET v1.0 Category: Building a JSON Parser ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100

typedef struct {
    char *name;
    int value;
} token_t;

token_t tokens[MAX_TOKENS];
int num_tokens;

void add_token(char *name, int value) {
    if (num_tokens >= MAX_TOKENS) {
        fprintf(stderr, "Error: too many tokens\n");
        exit(1);
    }
    tokens[num_tokens] = (token_t) {
       .name = name,
       .value = value
    };
    num_tokens++;
}

int find_token(char *name) {
    for (int i = 0; i < num_tokens; i++) {
        if (strcmp(tokens[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void parse_json(char *json) {
    char *ptr = json;
    char *end = json + strlen(json);
    char *key_start = NULL;
    char *key_end = NULL;
    char *value_start = NULL;
    char *value_end = NULL;
    int nesting = 0;

    while (ptr < end) {
        if (*ptr == '{') {
            nesting++;
        } else if (*ptr == '}') {
            nesting--;
        } else if (*ptr == '\"' && nesting == 0) {
            key_start = ptr + 1;
        } else if (*ptr == ':' && nesting == 0) {
            key_end = ptr;
            value_start = ptr + 1;
        } else if (*ptr == ',' && nesting == 0) {
            value_end = ptr;
            add_token(key_start, key_end - key_start);
            add_token(value_start, value_end - value_start);
            key_start = NULL;
            key_end = NULL;
            value_start = NULL;
            value_end = NULL;
        }
        ptr++;
    }
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <json>\n", argv[0]);
        return 1;
    }

    char *json = argv[1];
    parse_json(json);

    for (int i = 0; i < num_tokens; i++) {
        printf("Token %d: %s = %d\n", i, tokens[i].name, tokens[i].value);
    }

    return 0;
}