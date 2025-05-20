//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    JSON_NULL,
    JSON_BOOL,
    JSON_NUMBER,
    JSON_STRING,
    JSON_OBJECT,
    JSON_ARRAY
} json_type;

typedef struct JSONValue JSONValue;

struct JSONValue {
    json_type type;
    union {
        int          boolean;
        double       number;
        char        *string;
        struct { char **keys; JSONValue **values; int length; } object;
        struct { JSONValue **values; int length; } array;
    } data;
};

char *json_parse_string(const char *json) {
    char *string = malloc(strlen(json) - 1);
    int i = 1, j = 0;
    while (json[i] != '\"') {
        if (json[i] == '\\') {
            i++;
            switch (json[i]) {
                case '\"': string[j++] = '\"'; break;
                case '\\': string[j++] = '\\'; break;
                case '/':  string[j++] = '/';  break;
                case 'b':  string[j++] = '\b'; break;
                case 'f':  string[j++] = '\f'; break;
                case 'n':  string[j++] = '\n'; break;
                case 'r':  string[j++] = '\r'; break;
                case 't':  string[j++] = '\t'; break;
            }
        } else {
            string[j++] = json[i];
        }
        i++;
    }
    string[j] = '\0';
    return string;
}

JSONValue *json_parse_value(const char *json);

JSONValue *json_parse_array(const char *json) {
    json++;
    JSONValue **values = malloc(sizeof(JSONValue*) * 16);
    int length = 0, capacity = 16;
    while (*json != ']') {
        if (length == capacity) {
            capacity *= 2;
            values = realloc(values, sizeof(JSONValue*) * capacity);
        }
        if (*json == ',') {
            json++;
            continue;
        }
        values[length++] = json_parse_value(json);
        char c = *json;
        while (c != ',' && c != ']') c = *(++json);
    }
    json++;
    JSONValue *result = malloc(sizeof(JSONValue));
    result->type = JSON_ARRAY;
    result->data.array.values = values;
    result->data.array.length = length;
    return result;
}

JSONValue *json_parse_object(const char *json) {
    json++;
    char **keys = malloc(sizeof(char*) * 16);
    JSONValue **values = malloc(sizeof(JSONValue*) * 16);
    int length = 0, capacity = 16;
    while (*json != '}') {
        if (length == capacity) {
            capacity *= 2;
            keys = realloc(keys, sizeof(char*) * capacity);
            values = realloc(values, sizeof(JSONValue*) * capacity);
        }
        if (*json == ',') {
            json++;
            continue;
        }
        keys[length] = json_parse_string(json);
        json += strlen(keys[length]) + 2;
        values[length] = json_parse_value(json);
        length++;
        char c = *json;
        while (c != ',' && c != '}') c = *(++json);
    }
    json++;
    JSONValue *result = malloc(sizeof(JSONValue));
    result->type = JSON_OBJECT;
    result->data.object.keys = keys;
    result->data.object.values = values;
    result->data.object.length = length;
    return result;
}

JSONValue *json_parse_value(const char *json) {
    switch (*json) {
        case '\0':      return NULL;
        case 'n':       return malloc(sizeof(JSONValue)); // JSON_NULL
        case 'f':
        case 't': {
            JSONValue *result = malloc(sizeof(JSONValue));
            result->type = JSON_BOOL;
            result->data.boolean = (*json == 't');
            return result;
        }
        case '\"': {
            JSONValue *result = malloc(sizeof(JSONValue));
            result->type = JSON_STRING;
            result->data.string = json_parse_string(json);
            return result;
        }
        case '[':       return json_parse_array(json);
        case '{':       return json_parse_object(json);
        default: {
            JSONValue *result = malloc(sizeof(JSONValue));
            result->type = JSON_NUMBER;
            result->data.number = atof(json);
            return result;
        }
    }
}

JSONValue *json_parse(const char *json) {
    return json_parse_value(json);
}

int main() {
    const char *json = "{\"name\":\"Homer Simpson\",\"age\":39,\"wife\":\"Marge Simpson\",\"children\":[{\"name\":\"Bart Simpson\",\"age\":10},{\"name\":\"Lisa Simpson\",\"age\":8},{\"name\":\"Maggie Simpson\",\"age\":1}],\"car\":{\"make\":\"Plymouth\",\"model\":\"Belvedere\"}}";
    JSONValue *value = json_parse(json);
    printf("name=%s\n", value->data.object.values[0]->data.string);
    printf("age=%g\n", value->data.object.values[1]->data.number);
    printf("wife=%s\n", value->data.object.values[2]->data.string);
    printf("children[0].name=%s\n", value->data.object.values[3]->data.array.values[0]->data.object.values[0]->data.string);
    printf("children[0].age=%g\n", value->data.object.values[3]->data.array.values[0]->data.object.values[1]->data.number);
    printf("children[1].name=%s\n", value->data.object.values[3]->data.array.values[1]->data.object.values[0]->data.string);
    printf("children[1].age=%g\n", value->data.object.values[3]->data.array.values[1]->data.object.values[1]->data.number);
    printf("children[2].name=%s\n", value->data.object.values[3]->data.array.values[2]->data.object.values[0]->data.string);
    printf("children[2].age=%g\n", value->data.object.values[3]->data.array.values[2]->data.object.values[1]->data.number);
    printf("car.make=%s\n", value->data.object.values[4]->data.object.values[0]->data.string);
    printf("car.model=%s\n", value->data.object.values[4]->data.object.values[1]->data.string);
    return 0; // Who needs return statement?
}