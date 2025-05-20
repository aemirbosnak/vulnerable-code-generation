//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: single-threaded
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define MAX_JSON_SIZE 1024

// Struct to hold key-value pairs
typedef struct _pair {
    char* key;
    char* value;
} Pair;

// Struct to hold JSON
typedef struct _json {
    Pair** pairs;
    int num_pairs;
} JSON;

// Function to parse key-value pairs
Pair* parse_pair(char* json_str) {
    char* key = strtok(json_str, ":");
    char* value = strtok(NULL, ",");
    Pair* pair = malloc(sizeof(Pair));
    pair->key = key;
    pair->value = value;
    return pair;
}

// Function to parse JSON string
JSON* parse_json(char* json_str) {
    JSON* json = malloc(sizeof(JSON));
    json->pairs = malloc(sizeof(Pair)*MAX_JSON_SIZE);
    
    // Remove curly braces from JSON string
    json_str++;
    json_str[strlen(json_str)-1] = '\0';
    
    // Parse key-value pairs and add to JSON struct
    char* pair_str = strtok(json_str, ",");
    while (pair_str != NULL) {
        Pair* pair = parse_pair(pair_str);
        json->pairs[json->num_pairs++] = pair;
        pair_str = strtok(NULL, ",");
    }
    
    return json;
}

// Function to pretty print JSON
void print_json(JSON* json) {
    printf("{\n");
    for (int i = 0; i < json->num_pairs; i++) {
        printf("\t\"%s\": \"%s\"\n", json->pairs[i]->key, json->pairs[i]->value);
    }
    printf("}\n");
}

int main() {
    char* json_str = "{\"name\": \"John\", \"age\": 30}";
    JSON* json = parse_json(json_str);
    print_json(json);
    return 0;
}