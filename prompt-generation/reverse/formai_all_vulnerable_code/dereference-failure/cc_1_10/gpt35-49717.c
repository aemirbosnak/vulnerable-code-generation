//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

typedef struct {
    char key[MAX_LENGTH];
    char value[MAX_LENGTH];
} KeyValuePair;

typedef struct {
    KeyValuePair pairs[MAX_LENGTH];
    int numPairs;
} JsonObject;

char* readJsonFile(char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file %s.\n", fileName);
        exit(1);
    }

    long fileSize;
    fseek(file, 0L, SEEK_END);
    fileSize = ftell(file);
    rewind(file);

    char* jsonString = (char*)malloc(fileSize * sizeof(char));
    if (jsonString == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }

    fread(jsonString, 1, fileSize, file);
    fclose(file);

    return jsonString;
}

void parseJson(char* jsonString, JsonObject* jsonObject) {
    jsonObject->numPairs = 0;

    int i = 0;
    while (jsonString[i] != '\0') {
        if (jsonString[i] == '{') {
            i++;
            while (jsonString[i] != '}') {
                KeyValuePair pair = {"", ""};

                // get key
                while (jsonString[i] != ':') {
                    if (!isspace(jsonString[i])) {
                        strncat(pair.key, &jsonString[i], 1);
                    }
                    i++;
                }
                i++;

                // get value
                while (jsonString[i] != ',' && jsonString[i] != '}') {
                    if (!isspace(jsonString[i])) {
                        strncat(pair.value, &jsonString[i], 1);
                    }
                    i++;
                }

                jsonObject->pairs[jsonObject->numPairs] = pair;
                jsonObject->numPairs++;

                if (jsonString[i] == ',') {
                    i++;
                }
            }
            break;
        }
        i++;
    }
}

int main() {
    char* jsonString = readJsonFile("example.json");
    JsonObject jsonObject;

    parseJson(jsonString, &jsonObject);

    printf("Parsed JSON:\n");
    for (int i = 0; i < jsonObject.numPairs; i++) {
        printf("%s: %s\n", jsonObject.pairs[i].key, jsonObject.pairs[i].value);
    }

    free(jsonString);
    return 0;
}