//Falcon2-11B DATASET v1.0 Category: Building a JSON Parser ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
} JSON;

int parse_json(char *json, JSON *result) {
    if (!json ||!result)
        return -1;

    char *ptr = strstr(json, "{");
    if (!ptr) {
        fprintf(stderr, "Invalid JSON: No opening brace\n");
        return -1;
    }

    ptr = strstr(ptr + 1, "}");
    if (!ptr) {
        fprintf(stderr, "Invalid JSON: No closing brace\n");
        return -1;
    }

    ptr = strstr(ptr + 1, ":");
    if (!ptr) {
        fprintf(stderr, "Invalid JSON: No colon\n");
        return -1;
    }

    ptr = strstr(ptr + 1, "}");
    if (!ptr) {
        fprintf(stderr, "Invalid JSON: No closing brace\n");
        return -1;
    }

    ptr = strstr(ptr + 1, ":");
    if (!ptr) {
        fprintf(stderr, "Invalid JSON: No colon\n");
        return -1;
    }

    ptr = strstr(ptr + 1, "}");
    if (!ptr) {
        fprintf(stderr, "Invalid JSON: No closing brace\n");
        return -1;
    }

    ptr = strstr(ptr + 1, ":");
    if (!ptr) {
        fprintf(stderr, "Invalid JSON: No colon\n");
        return -1;
    }

    ptr = strstr(ptr + 1, "}");
    if (!ptr) {
        fprintf(stderr, "Invalid JSON: No closing brace\n");
        return -1;
    }

    result->name = strdup(ptr + 1);

    return 0;
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <json-string>\n", argv[0]);
        return 1;
    }

    char *json = argv[1];
    JSON result;
    int rc = parse_json(json, &result);
    if (rc < 0) {
        fprintf(stderr, "Error parsing JSON: %s\n", json);
        return 1;
    }

    printf("name: %s\n", result.name);

    return 0;
}