//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_LENGTH 1024

struct JsonElement {
    char *name;
    char *value;
    struct JsonElement *child;
    struct JsonElement *next;
};

struct JsonElement *parseJson(char *jsonString);

int main()
{
    char json[MAX_JSON_LENGTH] = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
    struct JsonElement *jsonElement = parseJson(json);
    printf("JSON Name: %s\n", jsonElement->name);
    printf("JSON Value: %s\n", jsonElement->value);
    printf("JSON Child Name: %s\n", jsonElement->child->name);
    printf("JSON Child Value: %s\n", jsonElement->child->value);
    printf("JSON Next Name: %s\n", jsonElement->next->name);
    printf("JSON Next Value: %s\n", jsonElement->next->value);

    return 0;
}

struct JsonElement *parseJson(char *jsonString) {
    struct JsonElement *root = NULL;
    struct JsonElement *currentElement = NULL;

    int jsonStringIndex = 0;

    while (jsonString[jsonStringIndex] != '\0') {
        char *name = NULL;
        char *value = NULL;

        if (jsonString[jsonStringIndex] == '{') {
            struct JsonElement *newElement = malloc(sizeof(struct JsonElement));
            newElement->child = parseJson(jsonString + jsonStringIndex + 1);
            if (root == NULL) {
                root = newElement;
            }
            if (currentElement != NULL) {
                currentElement->next = newElement;
            }
            currentElement = newElement;
            jsonStringIndex += strlen(currentElement->name) + strlen(currentElement->value) + 4;
        }
        else if (jsonString[jsonStringIndex] == ',') {
            currentElement = currentElement->next;
            jsonStringIndex += strlen(currentElement->name) + strlen(currentElement->value) + 2;
        }
        else {
            name = malloc(sizeof(char) * 50);
            value = malloc(sizeof(char) * 50);
            int nameIndex = 0;
            int valueIndex = 0;

            while (jsonString[jsonStringIndex] != ':' && jsonString[jsonStringIndex] != '\0') {
                name[nameIndex] = jsonString[jsonStringIndex];
                nameIndex++;
                jsonStringIndex++;
            }
            jsonStringIndex++;

            while (jsonString[jsonStringIndex] != ',' && jsonString[jsonStringIndex] != '\0' && jsonString[jsonStringIndex] != '}') {
                value[valueIndex] = jsonString[jsonStringIndex];
                valueIndex++;
                jsonStringIndex++;
            }

            struct JsonElement *newElement = malloc(sizeof(struct JsonElement));
            newElement->name = name;
            newElement->value = value;
            newElement->child = NULL;
            newElement->next = NULL;

            if (root == NULL) {
                root = newElement;
            }
            if (currentElement != NULL) {
                currentElement->next = newElement;
            }
            currentElement = newElement;

            if (jsonString[jsonStringIndex] == '}') {
                break;
            }

            jsonStringIndex += 1;
        }
    }

    return root;
}