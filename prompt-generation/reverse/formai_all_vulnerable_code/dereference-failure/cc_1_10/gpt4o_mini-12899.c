//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define JSON_OBJ_START '{'
#define JSON_OBJ_END '}'
#define JSON_ARR_START '['
#define JSON_ARR_END ']'
#define JSON_STRING '\"'
#define JSON_COLON ':'
#define JSON_COMMA ','

typedef enum {
    JSON_TYPE_NULL,
    JSON_TYPE_BOOLEAN,
    JSON_TYPE_NUMBER,
    JSON_TYPE_STRING,
    JSON_TYPE_OBJECT,
    JSON_TYPE_ARRAY
} JsonType;

typedef struct JsonValue JsonValue;

struct JsonValue {
    JsonType type;
    union {
        int boolean;
        double number;
        char *string;
        struct JsonObject *object; // Define officially later
        struct JsonArray *array;   // Define officially later
    } value;
};

typedef struct JsonObject {
    char *key;
    JsonValue *value;
    struct JsonObject *next;
} JsonObject;

typedef struct JsonArray {
    JsonValue *value;
    struct JsonArray *next;
} JsonArray;

void free_json_value(JsonValue *value) {
    if (!value) return;
    
    switch (value->type) {
        case JSON_TYPE_STRING:
            free(value->value.string);
            break;
        case JSON_TYPE_OBJECT:
            // recursion for freeing JsonObject needed
            break;
        case JSON_TYPE_ARRAY:
            // recursion for freeing JsonArray needed
            break;
        default:
            break;
    }
    free(value);
}

JsonValue *parse_value(const char **json);

JsonValue *parse_number(const char **json) {
    JsonValue *value = malloc(sizeof(JsonValue));
    char *end;

    value->type = JSON_TYPE_NUMBER;
    value->value.number = strtod(*json, &end);
    *json = end;
    
    return value;
}

JsonValue *parse_string(const char **json) {
    JsonValue *value = malloc(sizeof(JsonValue));
    const char *start = ++(*json);
    
    while (**json != JSON_STRING && **json != '\0') {
        (*json)++;
    }
    
    size_t length = *json - start;
    value->type = JSON_TYPE_STRING;
    value->value.string = malloc(length + 1);
    
    strncpy(value->value.string, start, length);
    value->value.string[length] = '\0';
    (*json)++;
    
    return value;
}

JsonValue *parse_object(const char **json) {
    JsonValue *value = malloc(sizeof(JsonValue));
    JsonObject *head = NULL;
    JsonObject *current = NULL;
    
    value->type = JSON_TYPE_OBJECT;
    *json += 1; // Skip '{'
    
    while (**json != JSON_OBJ_END) {
        if (isspace(**json)) {  // Ignore whitespaces
            (*json)++;
            continue;
        }
        
        JsonObject *new_object = malloc(sizeof(JsonObject));
        new_object->key = parse_string(json)->value.string;
        
        if (**json == JSON_COLON) {
            (*json)++; // Skip ':'
            new_object->value = parse_value(json);
            new_object->next = NULL;
            
            if (head == NULL) {
                head = new_object;
                current = new_object;
            } else {
                current->next = new_object;
                current = new_object;
            }
        }

        if (**json == JSON_COMMA) {
            (*json)++; // Skip ','
        }
    }
    
    *json += 1; // Skip '}'
    value->value.object = head;
    
    return value;
}

JsonValue *parse_array(const char **json) {
   JsonValue *value = malloc(sizeof(JsonValue));
   JsonArray *head = NULL;
   JsonArray *current = NULL;
   
   value->type = JSON_TYPE_ARRAY;
   *json += 1; // Skip '['

   while (**json != JSON_ARR_END) {
       if (isspace(**json)) {  // Ignore whitespaces
            (*json)++;
            continue;
       }
       
       JsonArray *new_array_item = malloc(sizeof(JsonArray));
       new_array_item->value = parse_value(json);
       new_array_item->next = NULL;

       if (head == NULL) {
           head = new_array_item;
           current = new_array_item;
       } else {
           current->next = new_array_item;
           current = new_array_item;
       }

       if (**json == JSON_COMMA) {
           (*json)++; // Skip ','
       }
   }
   
   *json += 1; // Skip ']'
   value->value.array = head;

   return value;
}

JsonValue *parse_value(const char **json) {
    JsonValue *value = NULL;

    if (**json == JSON_STRING) {
        value = parse_string(json);
    } else if (isdigit(**json) || **json == '-') {
        value = parse_number(json);
    } else if (**json == JSON_OBJ_START) {
        value = parse_object(json);
    } else if (**json == JSON_ARR_START) {
        value = parse_array(json);
    } else if (strncmp(*json, "true", 4) == 0) {
        value = malloc(sizeof(JsonValue));
        value->type = JSON_TYPE_BOOLEAN;
        value->value.boolean = 1;
        *json += 4;
    } else if (strncmp(*json, "false", 5) == 0) {
        value = malloc(sizeof(JsonValue));
        value->type = JSON_TYPE_BOOLEAN;
        value->value.boolean = 0;
        *json += 5;
    } else if (strncmp(*json, "null", 4) == 0) {
        value = malloc(sizeof(JsonValue));
        value->type = JSON_TYPE_NULL;
        *json += 4;
    }

    return value;
}

void print_json_value(JsonValue *value) {
    if (!value) return;

    switch (value->type) {
        case JSON_TYPE_NULL:
            printf("null");
            break;
        case JSON_TYPE_BOOLEAN:
            printf(value->value.boolean ? "true" : "false");
            break;
        case JSON_TYPE_NUMBER:
            printf("%f", value->value.number);
            break;
        case JSON_TYPE_STRING:
            printf("\"%s\"", value->value.string);
            break;
        case JSON_TYPE_OBJECT:
            printf("{ ");
            JsonObject *current = value->value.object;
            while (current) {
                printf("\"%s\": ", current->key);
                print_json_value(current->value);
                current = current->next;
                if (current) printf(", ");
            }
            printf(" }");
            break;
        case JSON_TYPE_ARRAY:
            printf("[ ");
            JsonArray *current_array = value->value.array;
            while (current_array) {
                print_json_value(current_array->value);
                current_array = current_array->next;
                if (current_array) printf(", ");
            }
            printf(" ]");
            break;
    }
}

int main() {
    const char *json_text = "{\"name\":\"John\", \"age\":30, \"isStudent\":false, \"courses\":[\"Math\", \"Science\"], \"address\":null}";
    const char *json_pointer = json_text;

    JsonValue *parsed_json = parse_value(&json_pointer);
    printf("Parsed JSON:\n");
    print_json_value(parsed_json);
    printf("\n");

    // Free allocated memory (not complete for objects/arrays)
    free_json_value(parsed_json);
    
    return 0;
}