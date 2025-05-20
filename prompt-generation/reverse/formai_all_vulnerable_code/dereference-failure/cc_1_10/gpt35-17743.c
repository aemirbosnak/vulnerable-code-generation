//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a custom data structure to hold JSON values
typedef struct JSONValue {
    char *key;
    char *value;
    struct JSONValue *next;
} JSONValue;

// function to add a new JSON value to the linked list
void addValue(JSONValue **head, char *key, char *value) {
    // allocate memory for a new JSON value
    JSONValue *new_value = (JSONValue*) malloc(sizeof(JSONValue));
    
    // copy key and value strings to new_value struct
    new_value->key = (char*) malloc(strlen(key) + 1);
    new_value->value = (char*) malloc(strlen(value) + 1);
    strcpy(new_value->key, key);
    strcpy(new_value->value, value);
    
    // add new_value to the linked list
    new_value->next = (*head);
    (*head) = new_value;
}

// function to parse a JSON string
JSONValue* parseJSON(char *json_str) {
    JSONValue *head = NULL;
    char *key = NULL, *value = NULL, *p = json_str;
    
    while (*p != '\0') {
        // find start of key
        while (*p != '\"') p++;
        p++; // skip opening quote
        
        // find end of key
        key = p;
        while (*p != '\"') p++;
        *p = '\0'; // terminate key string
        p++; // skip closing quote and colon
        
        // find start of value
        while (*p == ' ' || *p == '\n' || *p == '\r' || *p == '\t' || *p == ':') p++;
        
        if (*p == '\"') {
            p++; // skip opening quote
            value = p;
            while (*p != '\"') p++;
        } else {
            value = p;
            while (*p != ',' && *p != '}') p++;
        }
        
        *p = '\0'; // terminate value string
        addValue(&head, key, value);
        
        if (*p == '}') break;
        
        p++; // skip comma or end brace
    }
    
    return head;
}

// function to print a parsed JSON object
void printJSON(JSONValue *head) {
    JSONValue *p = head;
    printf("{\n");
    while (p != NULL) {
        printf("\t\"%s\": \"%s\"", p->key, p->value);
        
        if (p->next != NULL) {
            printf(",\n");
        } else {
            printf("\n");
        }
        
        p = p->next;
    }
    printf("}\n");
}

int main() {
    char json_str[] = "{\n"
        "\t\"name\": \"John Doe\",\n"
        "\t\"age\": 35,\n"
        "\t\"address\": {\n"
        "\t\t\"street\": \"123 Main St\",\n"
        "\t\t\"city\": \"Anytown\",\n"
        "\t\t\"state\": \"CA\",\n"
        "\t\t\"zip\": \"12345\"\n"
        "\t}\n"
        "}";
    
    JSONValue *json_obj = parseJSON(json_str);
    printJSON(json_obj);
    
    return 0;
}