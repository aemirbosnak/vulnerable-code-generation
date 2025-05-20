//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_SIZE 1024

typedef struct JSONObject {
    char *key;
    char *value;
    struct JSONObject *next;
} JSONObject;

typedef struct JSONParser {
    JSONObject *head;
} JSONParser;

JSONObject *createJSONObject(char *key, char *value) {
    JSONObject *newObject = (JSONObject*) malloc(sizeof(JSONObject));
    newObject->key = (char*) malloc(strlen(key)+1);
    newObject->value = (char*) malloc(strlen(value)+1);
    strcpy(newObject->key, key);
    strcpy(newObject->value, value);
    newObject->next = NULL;
    return newObject;
}

void addJSONObject(JSONParser *jsonParser, char *key, char *value) {
    JSONObject *newObject = createJSONObject(key, value);
    if(jsonParser->head == NULL) {
        jsonParser->head = newObject;
    } else {
        JSONObject *temp = jsonParser->head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newObject;
    }
}

void printJSONObject(JSONObject *jsonObject) {
    printf("{ \"%s\": \"%s\" }", jsonObject->key, jsonObject->value);
}

void printJSON(JSONParser *jsonParser) {
    printf("[");
    JSONObject *temp = jsonParser->head;
    while(temp != NULL) {
        printJSONObject(temp);
        if(temp->next != NULL) {
            printf(",");
        }
        temp = temp->next;
    }
    printf("]");
}

JSONParser *parseJSON(char *json) {
    JSONParser *jsonParser = (JSONParser*) malloc(sizeof(JSONParser));
    jsonParser->head = NULL;
    char *token = strtok(json, ":,");
    char *key = NULL;
    char *value = NULL;
    int i=0;
    while(token != NULL) {
        if(i%2 == 0) {
            key = token;
        } else {
            value = token;
            addJSONObject(jsonParser, key, value);
        }
        token = strtok(NULL, ":,");
        i++;
    }
    return jsonParser;
}

int main() {
    char json[MAX_JSON_SIZE] = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
    JSONParser *jsonParser = parseJSON(json);
    printJSON(jsonParser);
    return 0;
}