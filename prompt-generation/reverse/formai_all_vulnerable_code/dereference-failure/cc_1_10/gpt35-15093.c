//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { JSON_STRING, JSON_NUMBER, JSON_OBJECT } json_type;

typedef struct {
    char *name;
    json_type type;
    union {
        char *string_value;
        double number_value;
        struct json_object *object_value;
    } value;
} json_object;



char* get_json_string(const char *json_str, char *key) {
    char *begin = strstr(json_str, key);
    if (!begin) return NULL;

    char *value_str = strchr(begin, ':');
    if (!value_str) return NULL;
    value_str++;

    // Skip any white-space before and after the value
    while (*value_str && isspace(*value_str)) ++value_str;

    if (*value_str == '\"') {
        // This is a string value
        const char *end = strchr(value_str + 1, '\"');
        if (!end) return NULL;
        char *result = (char*) calloc(1, end - value_str);
        strncpy(result, value_str + 1, end - value_str - 1);
        return result;
    }
    else {
        // This is a number value
        return strdup(value_str);
    }
}


json_object* parse_json(const char *json_str) {
    json_object *root = (json_object*) malloc(sizeof(json_object));
    memset(root, 0, sizeof(json_object));
    root->type = JSON_OBJECT;
    root->value.object_value = NULL;

    char *name = get_json_string(json_str, "\"name\":");
    if (!name) return NULL;
    root->name = name;

    char *description = get_json_string(json_str, "\"description\":");
    if (!description) return NULL;

    char *location = get_json_string(json_str, "\"location\":");
    if (!location) return NULL;

    char *id_str = get_json_string(json_str, "\"id\":");
    if (!id_str) return NULL;
    double id = strtod(id_str, NULL);

    free(id_str);
    free(description);
    free(location);

    return root;
}


void print_json_object(json_object *obj) {
    printf("{\n");
    printf("  \"name\": \"%s\"\n", obj->name);
    printf("  \"id\": %d\n", (int)obj->value.number_value);
    printf("}\n");
}


int main() {
    const char *json_str = "{\"name\": \"John Doe\", \"id\": 123}";

    json_object *root = parse_json(json_str);
    if (!root) {
        printf("Failed to parse JSON string\n");
        return -1;
    }

    print_json_object(root);

    free(root->name);
    free(root->value.object_value);
    free(root);

    return 0;
}