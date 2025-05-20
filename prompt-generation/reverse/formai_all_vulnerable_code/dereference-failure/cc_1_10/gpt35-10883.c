//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *key;
    char *value;
} json_pair;

typedef struct{
    int size;
    json_pair *pairs;
} json_object;

json_object* parse_json(char *input);

int main(){
    // Sample JSON input
    char *input = "{ \"name\": \"John Doe\", \"age\": 28, \"city\": \"New York\" }";

    // Parse the JSON input
    json_object *parsed = parse_json(input);

    // Print the parsed JSON
    printf("Parsed JSON object:\n");
    for(int i=0; i<parsed->size; i++){
        printf("%s: %s\n", parsed->pairs[i].key, parsed->pairs[i].value);
    }

    // Free the parsed JSON object
    free(parsed->pairs);
    free(parsed);

    return 0;
}

json_object* parse_json(char *input){
    json_object *parsed = (json_object*) malloc(sizeof(json_object));
    parsed->size = 0;
    parsed->pairs = NULL;

    char *token, *key, *value;
    token = strtok(input, "{}\",:");
    while(token != NULL){
        if(parsed->size % 2 == 0){
            key = (char*) malloc(strlen(token) + 1);
            strcpy(key, token);
        } else {
            value = (char*) malloc(strlen(token) + 1);
            strcpy(value, token);

            // Add new pair to the parsed JSON object
            json_pair pair = { key, value };
            parsed->pairs = (json_pair*) realloc(parsed->pairs, (parsed->size+1) * sizeof(json_pair));
            parsed->pairs[parsed->size] = pair;
            parsed->size++;
        }

        token = strtok(NULL, "{}\",:");
    }

    return parsed;
}