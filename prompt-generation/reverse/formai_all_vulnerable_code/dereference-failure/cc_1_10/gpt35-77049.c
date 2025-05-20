//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL
} json_type_t;

typedef struct json_t {
    json_type_t type;
    union {
        struct {
            char *key;
            struct json_t *value;
            struct json_t *next;
        } object;
        struct {
            struct json_t *value;
            struct json_t *next;
        } array;
        char *string;
        double number;
    } data;    
} json_t;

static json_t *parse_value(const char **p);

static void die(const char *msg)
{
    fprintf(stderr, "Error: %s.\n", msg);
    exit(EXIT_FAILURE);
}

static char *parse_string(const char **p)
{
    char *str, *dest;
    int len = 0;
    
    if (**p != '"') {
        die("Expected string.");
    }
    
    ++(*p);
    
    while (**p && **p != '"') {
        if (**p == '\\') {
            ++(*p);
            
            switch (**p) {
            case '"':
            case '/':
            case '\\':
            case 'b':
            case 'f':
            case 'n':
            case 'r':
            case 't':
                ++(*p);
                break;
            case 'u':
                ++(*p);
                
                for (int i = 0; i < 4; ++i) {
                    if (**p >= '0' && **p <= '9' ||
                            **p >= 'a' && **p <= 'f' ||
                            **p >= 'A' && **p <= 'F') {
                        ++(*p);
                    } else {
                        die("Invalid unicode escape.");
                    }
                }
                break;
            default:
                die("Invalid escape.");
                break;
            }
        } else {
            ++(*p);
        }
        ++len;
    }
    
    if (**p != '"') {
        die("Expected string.");
    }
    
    ++(*p);
    
    str = (char *) malloc(len + 1);
    
    if (!str) {
        die("Out of memory.");
    }
    
    dest = str;
    
    *dest++ = '"';
    
    --len;
    
    while (len--) {
        if (**p == '\\') {
            ++(*p);
            
            switch (**p) {
            case '"':
                *dest++ = '\"';
                break;
            case '/':
                *dest++ = '/';
                break;
            case '\\':
                *dest++ = '\\';
                break;
            case 'b':
                *dest++ = '\b';
                break;
            case 'f':
                *dest++ = '\f';
                break;
            case 'n':
                *dest++ = '\n';
                break;
            case 'r':
                *dest++ = '\r';
                break;
            case 't':
                *dest++ = '\t';
                break;
            case 'u':
                ++(*p);
                //parse unicode escape
                break;
            }
        } else {
            *dest++ = **p;
            ++(*p);
        }
    }
    
    *dest++ = '"';
    *dest = '\0';

    return str;
}

static json_t *parse_object(const char **p)
{
    json_t *object, *current_object = NULL, *new_object;
    char *key;

    if (**p != '{') {
        die("Expected object.");
    }

    ++(*p);

    object = (json_t *) malloc(sizeof(json_t));

    if (!object) {
        die("Out of memory.");
    }

    object->type = JSON_OBJECT;
    object->data.object.key = NULL;
    object->data.object.value = NULL;
    object->data.object.next = NULL;

    while (**p && **p != '}') {
        if (**p == ',') {
            ++(*p);
        }

        if (**p != '"') {
            die("Expected string.");
        }

        key = parse_string(p);

        if (**p != ':') {
            die("Expected colon.");
        }

        ++(*p);

        new_object = (json_t *) malloc(sizeof(json_t));

        if (!new_object) {
            die("Out of memory.");
        }

        new_object->data.object.key = key;
        new_object->data.object.value = parse_value(p);
        new_object->data.object.next = NULL;

        if (!current_object) {
            object->data.object.value = new_object;
            current_object = new_object;
        } else {
            current_object->data.object.next = new_object;
            current_object = new_object;
        }
    }

    if (**p != '}') {
        die("Expected object.");
    }

    ++(*p);

    return object;
}

static json_t *parse_array(const char **p)
{
    json_t *array, *current_array = NULL, *new_array;

    if (**p != '[') {
        die("Expected array.");
    }

    ++(*p);

    array = (json_t *) malloc(sizeof(json_t));

    if (!array) {
        die("Out of memory.");
    }

    array->type = JSON_ARRAY;
    array->data.array.value = NULL;
    array->data.array.next = NULL;

    while (**p && **p != ']') {
        if (**p == ',') {
            ++(*p);
        }

        new_array = (json_t *) malloc(sizeof(json_t));

        if (!new_array) {
            die("Out of memory.");
        }

        new_array->data.array.next = NULL;

        if (!current_array) {
            array->data.array.value = new_array;
            current_array = new_array;
        } else {
            current_array->data.array.next = new_array;
            current_array = new_array;
        }

        current_array->data.array.value = parse_value(p);
    }

    if (**p != ']') {
        die("Expected array.");
    }

    ++(*p);

    return array;
}

static json_t *parse_number(const char **p)
{
    char *endptr;
    json_t *num;

    num = (json_t *) malloc(sizeof(json_t));

    if (!num) {
        die("Out of memory.");
    }

    num->type = JSON_NUMBER;
    num->data.number = strtod(*p, &endptr);

    if (*p == endptr) {
        die("Expected number.");
    }

    *p = endptr;

    return num;
}

static json_t *parse_true(const char **p)
{
    if (strncmp(*p, "true", 4) != 0) {
        die("Expected true.");
    }

    *p += 4;

    return (json_t *) JSON_TRUE;
}

static json_t *parse_false(const char **p)
{
    if (strncmp(*p, "false", 5) != 0) {
        die("Expected false.");
    }

    *p += 5;

    return (json_t *) JSON_FALSE;
}

static json_t *parse_null(const char **p)
{
    if (strncmp(*p, "null", 4) != 0) {
        die("Expected null.");
    }

    *p += 4;

    return (json_t *) JSON_NULL;
}

static json_t *parse_value(const char **p)
{
    switch (**p) {
    case '{':
        return parse_object(p);
    case '[':
        return parse_array(p);
    case '"':
        return (json_t *) parse_string(p);
    case '-':
    case '0'...'9':
        return parse_number(p);
    case 't':
        return parse_true(p);
    case 'f':
        return parse_false(p);
    case 'n':
        return parse_null(p);
    default:
        break;
    }

    die("Unexpected value.");
    return NULL;
}

static void print_json(json_t *json, int indent)
{
    char *padding = (char *) calloc(indent + 1, sizeof(char));

    if (!padding) {
        die("Out of memory.");
    }

    memset(padding, '\t', indent);
    padding[indent] = '\0';

    switch (json->type) {
    case JSON_OBJECT:
        printf("%s{\n", padding);
        for (json_t *p = json->data.object.value; p; p = p->data.object.next) {
            printf("%s\t\"%s\": ", padding, p->data.object.key);
            print_json(p->data.object.value, indent + 1);
        }
        printf("%s}", padding);
        break;
    case JSON_ARRAY:
        printf("%s[\n", padding);
        for (json_t *p = json->data.array.value; p; p = p->data.array.next) {
            print_json(p->data.array.value, indent + 1);
        }
        printf("%s]", padding);
        break;
    case JSON_STRING:
        printf("\"%s\"", json->data.string);
        break;
    case JSON_NUMBER:
        printf("%f", json->data.number);
        break;
    case JSON_TRUE:
        printf("true");
        break;
    case JSON_FALSE:
        printf("false");
        break;
    case JSON_NULL:
        printf("null");
        break;
    default:
        break;
    }

    free(padding);
}

int main(int argc, char *argv[])
{
    const char *test_str = "{\"foo\": 123, \"bar\": [\"foo\", \"bar\", {\"baz\": true}], \"qux\": null}";
    json_t *json;

    printf("Parsing JSON:\n%s\n\n", test_str);

    json = parse_value(&test_str);

    if (json) {
        printf("Parsed JSON:\n");
        print_json(json, 0);
        printf("\n");
    } else {
        die("Failed to parse JSON.");
    }

    return EXIT_SUCCESS;
}