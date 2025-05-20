//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    JSON_NULL,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NUMBER,
    JSON_STRING,
    JSON_OBJECT,
    JSON_ARRAY
} JsonType;

typedef struct JsonNode {
    JsonType type;
    union {
        char *string_val;
        double number_val;
        struct JsonNode *children; // For objects and arrays
    } value;
    struct JsonNode *next; // For linked list of key-value pairs in object
} JsonNode;

// Function declarations
JsonNode* json_parse(const char *text);
void json_free(JsonNode *node);
void json_print(const JsonNode *node, int indent);
void skip_whitespace(const char **text);
JsonNode* parse_value(const char **text);
JsonNode* parse_object(const char **text);
JsonNode* parse_array(const char **text);
JsonNode* parse_string(const char **text);
JsonNode* parse_number(const char **text);
JsonNode* parse_true(const char **text);
JsonNode* parse_false(const char **text);
JsonNode* parse_null(const char **text);

// Main parsing function
JsonNode* json_parse(const char *text) {
    skip_whitespace(&text);
    JsonNode *node = parse_value(&text);
    skip_whitespace(&text);
    if (*text != '\0') {
        fprintf(stderr, "Error: Trailing characters after JSON data\n");
        json_free(node);
        return NULL;
    }
    return node;
}

// Skip whitespace characters in the string
void skip_whitespace(const char **text) {
    while (isspace(**text)) (*text)++;
}

// Parse a JSON value
JsonNode* parse_value(const char **text) {
    switch (**text) {
        case '{': return parse_object(text);
        case '[': return parse_array(text);
        case '"': return parse_string(text);
        case 't': return parse_true(text);
        case 'f': return parse_false(text);
        case 'n': return parse_null(text);
        default:
            if (isdigit(**text) || **text == '-') {
                return parse_number(text);
            }
            fprintf(stderr, "Error: Invalid JSON value\n");
            return NULL;
    }
}

// Parse a JSON object
JsonNode* parse_object(const char **text) {
    JsonNode *object = malloc(sizeof(JsonNode));
    object->type = JSON_OBJECT;
    object->next = NULL;
    (*text)++; // Skip '{'
    skip_whitespace(text);

    if (**text == '}') {
        (*text)++;
        return object;
    }
    
    // Parse key-value pairs
    JsonNode **tail = &object->value.children;
    
    while (1) {
        JsonNode *key = parse_string(text);
        skip_whitespace(text);
        if (**text != ':') {
            fprintf(stderr, "Error: Expected ':' after key\n");
            json_free(object);
            return NULL;
        }
        (*text)++; // Skip ':'
        
        skip_whitespace(text);
        JsonNode *value = parse_value(text);
        if (!key || !value) {
            json_free(object);
            return NULL;
        }

        key->next = value; // Link key and value in the JsonNode
        *tail = key; // Attach to the object
        tail = &value->next;

        skip_whitespace(text);
        if (**text == '}') {
            (*text)++;
            break;
        }
        if (**text != ',') {
            fprintf(stderr, "Error: Expected ',' or '}' in object\n");
            json_free(object);
            return NULL;
        }
        (*text)++; // Skip ','
        skip_whitespace(text);
    }
    return object;
}

// Parse a JSON array
JsonNode* parse_array(const char **text) {
    JsonNode *array = malloc(sizeof(JsonNode));
    array->type = JSON_ARRAY;
    array->next = NULL;
    (*text)++; // Skip '['
    skip_whitespace(text);

    if (**text == ']') {
        (*text)++;
        return array;
    }

    JsonNode **tail = &array->value.children;

    while (1) {
        JsonNode *value = parse_value(text);
        if (!value) {
            json_free(array);
            return NULL;
        }

        *tail = value;
        tail = &value->next;

        skip_whitespace(text);
        if (**text == ']') {
            (*text)++;
            break;
        }
        if (**text != ',') {
            fprintf(stderr, "Error: Expected ',' or ']' in array\n");
            json_free(array);
            return NULL;
        }
        (*text)++; // Skip ','
        skip_whitespace(text);
    }
    return array;
}

// Parse a JSON string
JsonNode* parse_string(const char **text) {
    (*text)++; // Skip initial '"'
    const char *start = *text;
    
    while (**text != '"' && **text != '\0') {
        (*text)++;
    }
    
    if (**text != '"') {
        fprintf(stderr, "Error: Unmatched quotes in string\n");
        return NULL;
    }
    
    int length = *text - start;
    char *str = malloc(length + 1);
    strncpy(str, start, length);
    str[length] = '\0'; // Null terminate

    (*text)++; // Skip final '"'
    
    JsonNode *node = malloc(sizeof(JsonNode));
    node->type = JSON_STRING;
    node->value.string_val = str;
    node->next = NULL;
    return node;
}

// Parse a JSON number
JsonNode* parse_number(const char **text) {
    const char *start = *text;
    if (**text == '-') (*text)++;
    if (**text == '0') (*text)++;
    else {
        if (isdigit(**text)) {
            while (isdigit(**text)) (*text)++;
        } else {
            fprintf(stderr, "Error: Invalid number format\n");
            return NULL;
        }
    }
    
    if (**text == '.') {
        (*text)++;
        if (!isdigit(**text)) {
            fprintf(stderr, "Error: Invalid number format\n");
            return NULL;
        }
        while (isdigit(**text)) (*text)++;
    }
    
    char *num_str = strndup(start, *text - start);
    JsonNode *node = malloc(sizeof(JsonNode));
    node->type = JSON_NUMBER;
    node->value.number_val = strtod(num_str, NULL);
    free(num_str);
    node->next = NULL;
    return node;
}

// Parse JSON true
JsonNode* parse_true(const char **text) {
    if (strncmp(*text, "true", 4) != 0) {
        fprintf(stderr, "Error: Expected 'true'\n");
        return NULL;
    }
    *text += 4;

    JsonNode *node = malloc(sizeof(JsonNode));
    node->type = JSON_TRUE;
    node->next = NULL;
    return node;
}

// Parse JSON false
JsonNode* parse_false(const char **text) {
    if (strncmp(*text, "false", 5) != 0) {
        fprintf(stderr, "Error: Expected 'false'\n");
        return NULL;
    }
    *text += 5;

    JsonNode *node = malloc(sizeof(JsonNode));
    node->type = JSON_FALSE;
    node->next = NULL;
    return node;
}

// Parse JSON null
JsonNode* parse_null(const char **text) {
    if (strncmp(*text, "null", 4) != 0) {
        fprintf(stderr, "Error: Expected 'null'\n");
        return NULL;
    }
    *text += 4;

    JsonNode *node = malloc(sizeof(JsonNode));
    node->type = JSON_NULL;
    node->next = NULL;
    return node;
}

// Free JSON node
void json_free(JsonNode *node) {
    if (!node) return;

    if (node->type == JSON_STRING) {
        free(node->value.string_val);
    } else if (node->type == JSON_OBJECT || node->type == JSON_ARRAY) {
        JsonNode *child = node->value.children;
        while (child) {
            JsonNode *next = child->next;
            json_free(child);
            child = next;
        }
    }
    free(node);
}

// Print JSON in a readable format
void json_print(const JsonNode *node, int indent) {
    if (!node) return;

    for (int i = 0; i < indent; i++) printf(" ");
    
    switch (node->type) {
        case JSON_NULL:
            printf("null\n");
            break;
        case JSON_TRUE:
            printf("true\n");
            break;
        case JSON_FALSE:
            printf("false\n");
            break;
        case JSON_NUMBER:
            printf("%f\n", node->value.number_val);
            break;
        case JSON_STRING:
            printf("\"%s\"\n", node->value.string_val);
            break;
        case JSON_OBJECT:
            printf("{\n");
            for (JsonNode *child = node->value.children; child; child = child->next) {
                json_print(child, indent + 2);
            }
            for (int i = 0; i < indent; i++) printf(" ");
            printf("}\n");
            break;
        case JSON_ARRAY:
            printf("[\n");
            for (JsonNode *child = node->value.children; child; child = child->next) {
                json_print(child, indent + 2);
            }
            for (int i = 0; i < indent; i++) printf(" ");
            printf("]\n");
            break;
    }
}

// Sample main function to test the parser
int main() {
    const char *json_text = "{\"key1\": \"value1\", \"key2\": [1, 2, 3], \"key3\": null}";
    JsonNode *json = json_parse(json_text);
    if (json) {
        json_print(json, 0);
        json_free(json);
    } else {
        fprintf(stderr, "Parsing failed.\n");
    }

    return 0;
}