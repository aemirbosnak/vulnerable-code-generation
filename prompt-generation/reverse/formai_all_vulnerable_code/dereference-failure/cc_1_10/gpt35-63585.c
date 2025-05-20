//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: decentralized
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_SIZE 1000

// JSON value types
typedef enum {
    JSON_NULL,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOLEAN,
    JSON_OBJECT,
    JSON_ARRAY
} json_type_t;

// JSON value structure
typedef struct {
    json_type_t type;
    union {
        char *string_val;
        double number_val;
        bool boolean_val;
        struct json_object *object_val;  // pointer to JSON object
        struct json_array *array_val;  // pointer to JSON array
    };
} json_value_t;

// JSON object structure
typedef struct json_object {
    char *key;
    json_value_t value;
    struct json_object *next;  // pointer to next key-value pair
} json_object_t;

// JSON array structure
typedef struct json_array {
    json_value_t value;
    struct json_array *next;  // pointer to next array element
} json_array_t;

// Parses JSON string and returns JSON value
json_value_t parse_json(char *json_str);

// Parses JSON object and returns JSON value
json_value_t parse_object(char **json_str);

// Parses JSON array and returns JSON value
json_value_t parse_array(char **json_str);

// Parses JSON boolean and returns JSON value
json_value_t parse_boolean(char **json_str);

// Parses JSON number and returns JSON value
json_value_t parse_number(char **json_str);

// Parses JSON string and returns JSON value
json_value_t parse_string(char **json_str);

// Skips whitespace in JSON string
void skip_whitespace(char **json_str);

// Extracts and returns string value from JSON string
char *extract_string(char *json_str);

// Extracts and returns number value from JSON string
double extract_number(char *json_str);

int main() {
    char *json_str = "{\"name\":\"John\",\"age\":30,\"married\":true,\"hobbies\":[\"swimming\",\"reading\"]}";
    json_value_t json = parse_json(json_str);

    printf("JSON Object:\n");
    printf("name=%s\n", json.object_val->value.string_val);
    printf("age=%f\n", json.object_val->next->value.number_val);
    printf("married=%d\n", (int)json.object_val->next->next->value.boolean_val);
    printf("hobbies=%s, %s\n", json.object_val->next->next->next->value.array_val->value.string_val,
           json.object_val->next->next->next->value.array_val->next->value.string_val);

    return 0;
}

json_value_t parse_json(char *json_str) {
    skip_whitespace(&json_str);

    if (*json_str == '{') {
        return parse_object(&json_str);
    } else if (*json_str == '[') {
        return parse_array(&json_str);
    }

    return (json_value_t){.type = JSON_NULL};
}

json_value_t parse_object(char **json_str) {
    *json_str += 1;  // skip '{'
    skip_whitespace(json_str);

    json_object_t *head = NULL, *curr = NULL;

    while (**json_str != '}') {
        if (curr) {
            curr->next = malloc(sizeof(json_object_t));
            curr = curr->next;
        } else {
            head = malloc(sizeof(json_object_t));
            curr = head;
        }

        curr->key = extract_string(*json_str);
        skip_whitespace(json_str);
        *json_str += 1;  // skip ':'
        skip_whitespace(json_str);
        curr->value = parse_json(*json_str);
        skip_whitespace(json_str);

        if (**json_str == ',') {
            *json_str += 1;  // skip ','
            skip_whitespace(json_str);
        }
    }

    *json_str += 1;  // skip '}'

    json_value_t json_val = (json_value_t){.type = JSON_OBJECT};
    json_val.object_val = head;
    return json_val;
}

json_value_t parse_array(char **json_str) {
    *json_str += 1;  // skip '['
    skip_whitespace(json_str);

    json_array_t *head = NULL, *curr = NULL;

    while (**json_str != ']') {
        if (curr) {
            curr->next = malloc(sizeof(json_array_t));
            curr = curr->next;
        } else {
            head = malloc(sizeof(json_array_t));
            curr = head;
        }

        curr->value = parse_json(*json_str);
        skip_whitespace(json_str);

        if (**json_str == ',') {
            *json_str += 1;  // skip ','
            skip_whitespace(json_str);
        }
    }

    *json_str += 1;  // skip ']'

    json_value_t json_val = (json_value_t){.type = JSON_ARRAY};
    json_val.array_val = head;
    return json_val;
}

json_value_t parse_boolean(char **json_str) {
    char *true_str = "true";
    char *false_str = "false";

    if (strncmp(*json_str, true_str, strlen(true_str)) == 0) {
        *json_str += strlen(true_str);
        return (json_value_t){.type = JSON_BOOLEAN, .boolean_val = true};
    } else if (strncmp(*json_str, false_str, strlen(false_str)) == 0) {
        *json_str += strlen(false_str);
        return (json_value_t){.type = JSON_BOOLEAN, .boolean_val = false};
    }

    return (json_value_t){.type = JSON_NULL};
}

json_value_t parse_number(char **json_str) {
    char *endptr;
    double value = strtod(*json_str, &endptr);
    *json_str = endptr;
    return (json_value_t){.type = JSON_NUMBER, .number_val = value};
}

json_value_t parse_string(char **json_str) {
    char *value = extract_string(*json_str);
    return (json_value_t){.type = JSON_STRING, .string_val = value};
}

void skip_whitespace(char **json_str) {
    while (**json_str == ' ' || **json_str == '\t' || **json_str == '\n' || **json_str == '\r') {
        *json_str += 1;
    }
}

char *extract_string(char *json_str) {
    char *start = strchr(json_str, '\"');

    if (start == NULL) {
        return NULL;
    }

    start++;  // skip '\"'

    char *end = strchr(start, '\"');

    if (end == NULL) {
        return NULL;
    }

    int len = end - start;
    char *value = malloc((len + 1) * sizeof(char));
    strncpy(value, start, len);
    value[len] = '\0';

    return value;
}

double extract_number(char *json_str) {
    char *endptr;
    return strtod(json_str, &endptr);
}