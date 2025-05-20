//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JSON_OBJECT 1
#define JSON_STRING 2
#define JSON_ARRAY 3

/* A JSON value can be one of these types */
struct json_value {
    int type;
    union {
        char *string;
        struct json_object *object;
        struct json_array *array;
    } value;
};

/* A JSON object represents a dictionary-like collection of name-value pairs */
struct json_object {
    int count; // number of name-value pairs in this object
    char **names; // array of names
    struct json_value **values; // array of values
};

/* A JSON array represents an ordered collection of values */
struct json_array {
    int count; // number of elements in this array
    struct json_value **values; // array of values
};

/* Parse a JSON value from the given string */
struct json_value *json_parse_value(char *str);

/* Parse a JSON object from the given string */
struct json_object *json_parse_object(char *str);

/* Parse a JSON array from the given string */
struct json_array *json_parse_array(char *str);

/* Extract a string value from a JSON value */
char *json_extract_string(struct json_value *value);

/* Extract an object value from a JSON value */
struct json_object *json_extract_object(struct json_value *value);

/* Extract an array value from a JSON value */
struct json_array *json_extract_array(struct json_value *value);

/* Release memory used by a JSON value */
void json_free_value(struct json_value *value);

/* Release memory used by a JSON object */
void json_free_object(struct json_object *object);

/* Release memory used by a JSON array */
void json_free_array(struct json_array *array);

/* Main program */
int main() {
    char *json_str = "{\"name\":\"Alice\",\"age\":20}";

    struct json_value *value = json_parse_value(json_str);

    if (value->type == JSON_OBJECT) {
        struct json_object *object = json_extract_object(value);
        int i;
        for (i = 0; i < object->count; i++) {
            printf("%s: %s\n", object->names[i], json_extract_string(object->values[i]));
        }
        json_free_object(object);
    }

    json_free_value(value);

    return 0;
}

/* Parse a JSON value from the given string */
struct json_value *json_parse_value(char *str) {
    // TODO: implement this function
    return NULL;
}

/* Parse a JSON object from the given string */
struct json_object *json_parse_object(char *str) {
    // TODO: implement this function
    return NULL;
}

/* Parse a JSON array from the given string */
struct json_array *json_parse_array(char *str) {
    // TODO: implement this function
    return NULL;
}

/* Extract a string value from a JSON value */
char *json_extract_string(struct json_value *value) {
    if (value->type == JSON_STRING) {
        return value->value.string;
    } else {
        return NULL;
    }
}

/* Extract an object value from a JSON value */
struct json_object *json_extract_object(struct json_value *value) {
    if (value->type == JSON_OBJECT) {
        return value->value.object;
    } else {
        return NULL;
    }
}

/* Extract an array value from a JSON value */
struct json_array *json_extract_array(struct json_value *value) {
    if (value->type == JSON_ARRAY) {
        return value->value.array;
    } else {
        return NULL;
    }
}

/* Release memory used by a JSON value */
void json_free_value(struct json_value *value) {
    if (value == NULL) {
        return;
    }

    switch (value->type) {
        case JSON_STRING:
            free(value->value.string);
            break;
        case JSON_OBJECT:
            json_free_object(value->value.object);
            break;
        case JSON_ARRAY:
            json_free_array(value->value.array);
            break;
        default:
            break;
    }

    free(value);
}

/* Release memory used by a JSON object */
void json_free_object(struct json_object *object) {
    if (object == NULL) {
        return;
    }

    int i;
    for (i = 0; i < object->count; i++) {
        free(object->names[i]);
        json_free_value(object->values[i]);
    }
    free(object->names);
    free(object->values);
    free(object);
}

/* Release memory used by a JSON array */
void json_free_array(struct json_array *array) {
    if (array == NULL) {
        return;
    }

    int i;
    for (i = 0; i < array->count; i++) {
        json_free_value(array->values[i]);
    }
    free(array->values);
    free(array);
}