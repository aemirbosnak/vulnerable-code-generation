//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct JsonNode {
    char type;
    union {
        struct JsonNode *child;
        int number;
        char *string;
    } data;
} JsonNode;

typedef JsonNode *JsonNodePtr;

JsonNodePtr parseJson(char *jsonStr) {
    JsonNodePtr root = NULL;
    char *pJsonStr = jsonStr;
    int i = 0;
    int state = 0; // 0 - start, 1 - key, 2 - value, 3 - string, 4 - end
    char currentKey[256] = "";

    for (i = 0; i < 1024; i++) {
        switch (state) {
            case 0:
                if (*pJsonStr == '"') {
                    state = 1;
                    strcpy(currentKey, "");
                } else if (*pJsonStr == '{' || *pJsonStr == '[') {
                    root = malloc(sizeof(JsonNode));
                    root->type = *pJsonStr;
                    root->data.child = NULL;
                    root->data.number = 0;
                    root->data.string = NULL;
                    state = 2;
                } else {
                    state = -1;
                }
                break;
            case 1:
                if (*pJsonStr == '"') {
                    state = 2;
                } else {
                    strcat(currentKey, *pJsonStr);
                    state = 1;
                }
                break;
            case 2:
                if (*pJsonStr == ':') {
                    state = 3;
                } else if (*pJsonStr == '}' || *pJsonStr == ']') {
                    state = 4;
                } else {
                    state = -1;
                }
                break;
            case 3:
                if (*pJsonStr == '"') {
                    state = 4;
                } else {
                    root->data.string = malloc(strlen(currentKey) + 1);
                    strcpy(root->data.string, currentKey);
                    state = 2;
                }
                break;
            case 4:
                return root;
            default:
                state = -1;
                break;
        }
        pJsonStr++;
    }

    return NULL;
}

int main() {
    char *jsonStr = "{ 'name': 'John Doe', 'age': 30 }";
    JsonNodePtr root = parseJson(jsonStr);

    printf("Name: %s\n", root->data.string);
    printf("Age: %d\n", root->data.number);

    return 0;
}