//Falcon-180B DATASET v1.0 Category: Building a JSON Parser ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_SIZE 1024
#define MAX_DEPTH 1000

typedef struct {
    char *key;
    char *value;
} json_pair;

typedef struct {
    json_pair *pairs;
    int count;
    int depth;
} json_object;

typedef struct {
    json_object *object;
    int depth;
} json_context;

char *read_token(FILE *fp) {
    char token[MAX_TOKEN_SIZE] = {0};
    char ch = fgetc(fp);
    int i = 0;

    while (ch!= EOF && ch!= '}' && ch!= ']' && i < MAX_TOKEN_SIZE - 1) {
        if (isspace(ch)) {
            break;
        }
        token[i++] = ch;
        ch = fgetc(fp);
    }
    token[i] = '\0';

    return strdup(token);
}

void free_token(char *token) {
    free(token);
}

void push_context(json_context *context) {
    context->depth++;
    context->object = malloc(sizeof(json_object));
    context->object->pairs = NULL;
    context->object->count = 0;
}

void pop_context(json_context *context) {
    context->depth--;
    free(context->object->pairs);
    free(context->object);
    context->object = NULL;
}

void add_pair(json_object *object, char *key, char *value) {
    json_pair *pair = malloc(sizeof(json_pair));
    pair->key = strdup(key);
    pair->value = strdup(value);
    object->pairs = realloc(object->pairs, sizeof(json_pair) * ++object->count);
    object->pairs[object->count - 1] = *pair;
}

int main(int argc, char *argv[]) {
    FILE *fp = fopen(argv[1], "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    json_context context = {0};

    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file.\n");
        return 1;
    }

    push_context(&context);

    while ((read = getline(&line, &len, fp))!= -1) {
        char *token = read_token(fp);
        if (strcmp(token, "{") == 0) {
            add_pair(context.object, "", "");
        } else if (strcmp(token, "}") == 0 || strcmp(token, "]") == 0) {
            pop_context(&context);
        } else if (strcmp(token, ",") == 0) {
            continue;
        } else if (strcmp(token, "\"") == 0) {
            char *value = read_token(fp);
            add_pair(context.object, context.object->pairs[context.object->count - 1].key, value);
        } else {
            add_pair(context.object, token, "");
        }
        free_token(token);
    }

    pop_context(&context);
    fclose(fp);

    return 0;
}