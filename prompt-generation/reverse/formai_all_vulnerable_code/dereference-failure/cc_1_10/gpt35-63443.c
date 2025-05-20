//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
#define MAX_JSON_LENGTH 100
 
typedef enum {
    JSON_STRING,
    JSON_INTEGER,
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_NULL
} json_type;
 
typedef struct {
    json_type type;
    void *data;
} json_value;
 
typedef struct {
    int size;
    int capacity;
    json_value *values;
} json_array;
 
typedef struct {
    char *key;
    json_value *value;
} json_member;
 
typedef struct {
    int size;
    int capacity;
    json_member *members;
} json_object;
 
json_value *parse_value(const char **json);
 
void skip_ws(const char **json) {
    while (isspace(**json)) {
        (*json)++;
    }
}
 
json_value *parse_string(const char **json) {
    char *str = malloc(MAX_JSON_LENGTH);
    int i = 0;
    (*json)++;
    while (**json != '\"') {
        str[i++] = **json;
        (*json)++;
    }
    str[i] = '\0';
    (*json)++;
    json_value *value = malloc(sizeof(json_value));
    value->type = JSON_STRING;
    value->data = (void *) str;
    return value;
}
 
json_value *parse_integer(const char **json) {
    int value = 0;
    int sign = 1;
    if (**json == '-') {
        sign = -1;
        (*json)++;
    }
    while (isdigit(**json)) {
        value *= 10;
        value += **json - '0';
        (*json)++;
    }
    json_value *jvalue = malloc(sizeof(json_value));
    jvalue->type = JSON_INTEGER;
    jvalue->data = (void *) (long long) (sign * value);
    return jvalue;
}
 
json_value *parse_array(const char **json) {
    (*json)++;
    skip_ws(json);
    json_array *jarray = malloc(sizeof(json_array));
    jarray->size = 0;
    jarray->capacity = 16;
    jarray->values = malloc(jarray->capacity * sizeof(json_value));
    while (**json != ']') {
        json_value *jvalue = parse_value(json);
        if (jvalue == NULL) {
            break;
        }
        if (jarray->size == jarray->capacity) {
            jarray->capacity *= 2;
            jarray->values = realloc(jarray->values, jarray->capacity * sizeof(json_value));
        }
        jarray->values[jarray->size++] = *jvalue;
        skip_ws(json);
        if (**json == ',') {
            (*json)++;
            skip_ws(json);
        }
    }
    (*json)++;
    json_value *jvalue = malloc(sizeof(json_value));
    jvalue->type = JSON_ARRAY;
    jvalue->data = (void *) jarray;
    return jvalue;
}
 
json_value *parse_object(const char **json) {
    (*json)++;
    skip_ws(json);
    json_object *jobject = malloc(sizeof(json_object));
    jobject->size = 0;
    jobject->capacity = 16;
    jobject->members = malloc(jobject->capacity * sizeof(json_member));
    while (**json != '}') {
        json_value *jvalue = parse_value(json);
        if (jvalue == NULL) {
            break;
        }
        skip_ws(json);
        if (**json != ':') {
            break;
        }
        (*json)++;
        skip_ws(json);
        if (jobject->size == jobject->capacity) {
            jobject->capacity *= 2;
            jobject->members = realloc(jobject->members, jobject->capacity * sizeof(json_member));
        }
        if (**json == '\"') {
            char *key = malloc(MAX_JSON_LENGTH);
            int i = 0;
            (*json)++;
            while (**json != '\"') {
                key[i++] = **json;
                (*json)++;
            }
            key[i] = '\0';
            json_member member;
            member.key = key;
            member.value = jvalue;
            jobject->members[jobject->size++] = member;
            (*json)++;
        }
        skip_ws(json);
        if (**json == ',') {
            (*json)++;
            skip_ws(json);
        }
    }
    (*json)++;
    json_value *jvalue = malloc(sizeof(json_value));
    jvalue->type = JSON_OBJECT;
    jvalue->data = (void *) jobject;
    return jvalue;
}
 
json_value *parse_value(const char **json) {
    skip_ws(json);
    switch (**json) {
        case '\"': return parse_string(json);
        case '{': return parse_object(json);
        case '[': return parse_array(json);
        case 'n': (*json) += 4;
                  return (json_value *) JSON_NULL;
        default: if (isdigit(**json) || **json == '-') {
                     return parse_integer(json);
                 }
                 else {
                     return NULL;
                 }
    }
}
 
void print_json(json_value *json) {
    switch (json->type) {
        case JSON_STRING: printf("\"%s\"", (char *) json->data);
                           break;
        case JSON_INTEGER: printf("%lld", (long long) json->data);
                            break;
        case JSON_OBJECT: printf("{\n");
                           json_object *jobject = (json_object *) json->data;
                           for(int i=0;i<jobject->size;i++) {
                               printf("\"%s\": ", jobject->members[i].key);
                               print_json(jobject->members[i].value);
                               if (i<jobject->size-1) {
                                   printf(",\n");
                               }
                           }
                           printf("\n}");
                           break;
        case JSON_ARRAY: printf("[\n");
                          json_array *jarray = (json_array *) json->data;
                          for (int i=0;i<jarray->size;i++) {
                              print_json(&(jarray->values[i]));
                              if (i<jarray->size-1) {
                                  printf(",\n");
                              }
                          }
                          printf("\n]");
                          break;
        case JSON_NULL: printf("null");
                        break;
    }
}
 
int main() {
    const char *json_string = "{\n"
                              "\"name\": \"John Doe\",\n"
                              "\"age\": 25,\n"
                              "\"hobbies\": [\n"
                              "\"reading\",\n"
                              "\"running\",\n"
                              "\"coding\"\n"
                              "],\n"
                              "\"address\": {\n"
                              "\"street\": \"123 Main St\",\n"
                              "\"city\": \"Anytown\",\n"
                              "\"state\": \"CA\",\n"
                              "\"zip\": 12345\n"
                              "},\n"
                              "\"details\": null\n"
                              "}";
    json_value *json = parse_value(&json_string);
    print_json(json);
    return 0;
}