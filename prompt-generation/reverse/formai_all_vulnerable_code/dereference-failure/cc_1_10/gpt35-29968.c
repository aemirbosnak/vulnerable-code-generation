//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char* json; //String with json data
    size_t position; //Position in the string
} json_string;

typedef struct {
    char* key;
    char* value;
} json_property;

typedef struct {
    json_property ** properties;
    size_t count;
} json_object;

typedef struct {
    char** items;
    size_t count;
} json_array;

// Function prototypes
json_string* create_json_string(char* json);
void free_json_string(json_string* str);
char peek(json_string* str);
char get_next(json_string* str);
void skip_whitespace(json_string* str);
char* parse_string(json_string* str);
char* parse_number(json_string* str);
json_object* parse_object(json_string* str);
json_array* parse_array(json_string* str);
json_property* parse_property(json_string* str);

int main() {
    char json[] = "{\"name\":\"John Smith\",\"age\":30,\"cities\":[\"New York\",\"Los Angeles\",\"Chicago\"],\"isMarried\":false}";
    json_string* json_str = create_json_string(json);

    json_object* obj = parse_object(json_str);

    printf("Name: %s\nAge: %s\nIs Married: %s\n",
           obj->properties[0]->value,
           obj->properties[1]->value,
           obj->properties[3]->value);

    json_array* cities = (json_array*) obj->properties[2]->value;

    printf("Cities: ");
    for (int i = 0; i < cities->count; i++) {
        printf("%s", cities->items[i]);
        if (i != cities->count - 1) printf(", ");
    }
    printf("\n");

    // Free memory
    for (int i = 0; i < obj->count; i++) {
        free(obj->properties[i]->key);
        free(obj->properties[i]->value);
        free(obj->properties[i]);
    }
    free(obj->properties);
    free(obj);
    free_json_string(json_str);

    return 0;
}

json_string* create_json_string(char* json) {
    json_string* str = (json_string*) malloc(sizeof(json_string));
    str->json = json;
    str->position = 0;
    return str;
}

void free_json_string(json_string* str) {
    free(str);
}

char peek(json_string* str) {
    return str->json[str->position];
}

char get_next(json_string* str) {
    char c = str->json[str->position];
    str->position++;
    return c;
}

void skip_whitespace(json_string* str) {
    char c;
    do {
        c = get_next(str);
    } while (isspace(c));
    str->position--;
}

char* parse_string(json_string* str) {
    char* string = (char*) malloc(sizeof(char));
    char c;
    size_t length = 0;
    do {
        c = get_next(str);
        if (c == '\\') {
            c = get_next(str);
            switch (c) {
                case '\"': c = '\"'; break;
                case '\\': c = '\\'; break;
                case '/': c = '/'; break;
                case 'b': c = '\b'; break;
                case 'f': c = '\f'; break;
                case 'n': c = '\n'; break;
                case 'r': c = '\r'; break;
                case 't': c = '\t'; break;
                case 'u': // Unicode escape
                    printf("Unicode escape not implemented\n");
                    exit(1);
                    break;
            }
        } else if (c == '\"') {
            string[length] = '\0';
            return string;
        }
        string[length] = c;
        length++;
        string = (char*) realloc(string, sizeof(char) * (length + 1));
    } while (c != '\0');
    return NULL;
}

char* parse_number(json_string* str) {
    char* number = (char*) malloc(sizeof(char));
    char c;
    size_t length = 0;
    do {
        c = get_next(str);
        if (isdigit(c) || c == '-' || c == '+' || c == '.' || c == 'e' || c == 'E') {
            number[length] = c;
            length++;
            number = (char*) realloc(number, sizeof(char) * (length + 1));
        } else {
            number[length] = '\0';
            str->position--;
            return number;
        }
    } while (c != '\0');
    return NULL;
}

json_object* parse_object(json_string* str) {
    json_object* obj = (json_object*) malloc(sizeof(json_object));
    obj->count = 0;
    obj->properties = NULL;
    char c;
    do {
        skip_whitespace(str);
        c = get_next(str);

        if (c == '}') {
            return obj;
        } else if (c == '\"') {
            str->position--;
            json_property* prop = parse_property(str);
            obj->count++;
            obj->properties = (json_property**) realloc(obj->properties, sizeof(json_property*) * obj->count);
            obj->properties[obj->count-1] = prop;
        } else if (c == ',') {
            // Do nothing
        } else {
            printf("Unexpected character: %c\n", c);
            exit(1);
        }
    } while (c != '\0');
    return NULL;
}

json_array* parse_array(json_string* str) {
    json_array* arr = (json_array*) malloc(sizeof(json_array));
    arr->count = 0;
    arr->items = NULL;
    char c;
    do {
        skip_whitespace(str);
        c = get_next(str);

        if (c == ']') {
            return arr;
        } else if (c == '\"') {
            str->position--;
            char* string = parse_string(str);
            arr->count++;
            arr->items = (char**) realloc(arr->items, sizeof(char*) * arr->count);
            arr->items[arr->count-1] = string;
        } else if (c == '[') {
            str->position--;
            json_array* inner_arr = parse_array(str);
            arr->count++;
            arr->items = (char**) realloc(arr->items, sizeof(char*) * arr->count);
            arr->items[arr->count-1] = (char*) inner_arr;
        } else if (isdigit(c) || c == '-') {
            str->position--;
            char* number = parse_number(str);
            arr->count++;
            arr->items = (char**) realloc(arr->items, sizeof(char*) * arr->count);
            arr->items[arr->count-1] = number;
        } else if (c == '{') {
            str->position--;
            json_object* inner_obj = parse_object(str);
            arr->count++;
            arr->items = (char**) realloc(arr->items, sizeof(char*) * arr->count);
            arr->items[arr->count-1] = (char*) inner_obj;
        } else if (c == ',') {
            // Do nothing
        } else {
            printf("Unexpected character: %c\n", c);
            exit(1);
        }
    } while (c != '\0');
    return NULL;
}

json_property* parse_property(json_string* str) {
    json_property* prop = (json_property*) malloc(sizeof(json_property));
    prop->key = parse_string(str);
    skip_whitespace(str);
    char c = get_next(str);
    if (c != ':') {
        printf("Expected ':' but found: %c\n", c);
        exit(1);
    }
    skip_whitespace(str);
    c = peek(str);
    if (c == '\"') {
        prop->value = parse_string(str);
    } else if (c == '[') {
        str->position--;
        prop->value = (char*) parse_array(str);
    } else if (isdigit(c) || c == '-') {
        str->position--;
        prop->value = parse_number(str);
    } else if (c == '{') {
        str->position--;
        prop->value = (char*) parse_object(str);
    } else {
        printf("Unexpected character: %c\n", c);
        exit(1);
    }
    return prop;
}