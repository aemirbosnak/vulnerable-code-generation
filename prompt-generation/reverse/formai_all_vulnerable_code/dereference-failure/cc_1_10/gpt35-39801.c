//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// A simple JSON object structure.
typedef struct {
    char* key;
    char* value;
} JsonObject;

// Function declarations
char* readFile(char*);
int countChars(char*, char);
int countWords(char*);
void removeQuotes(char*);
JsonObject* parseJson(char*);

// Function to read a file and return its contents.
char* readFile(char* fileName) {
    char* buffer = 0;
    long length;
    FILE* file = fopen(fileName, "rb");

    if (file) {
        fseek(file, 0, SEEK_END);
        length = ftell(file);
        fseek(file, 0, SEEK_SET);
        buffer = malloc(length + 1);
        if (buffer) {
            fread(buffer, 1, length, file);
        }
        fclose(file);
        buffer[length] = '\0';
    }

    return buffer;
}

// Function to count occurrences of a character in the string.
int countChars(char* str, char c) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == c) {
            count++;
        }
    }
    return count;
}

// Function to count words in the string.
int countWords(char* str) {
    int count = 0;
    char* token = strtok(str, "{}[],:\"");

    while (token != NULL) {
        count++;
        token = strtok(NULL, "{}[],:\"");
    }

    return count;
}

// Function to remove quotes from the string.
void removeQuotes(char* str) {
    char* i = str;
    char* j = str;
    while (*j != 0) {
        *i = *j++;
        if (*i != '"') {
            i++;
        }
    }
    *i = 0;
}

// Function to parse JSON string and return a list of JSON objects.
JsonObject* parseJson(char* json) {
    int jsonLength = strlen(json);
    int numOfObjects = countChars(json, '{');
    JsonObject* jsonObjList = malloc(numOfObjects * sizeof(JsonObject));
    int currentObjectIndex = 0;

    for (int i = 0; i < jsonLength; i++) {
        if (json[i] == '{') {
            char* startOfKey = &json[i + 1];
            char* endOfKey = strchr(startOfKey, '\"');
            int keyLength = endOfKey - startOfKey;
            char* key = malloc((keyLength + 1) * sizeof(char));
            strncpy(key, startOfKey, keyLength);
            key[keyLength] = '\0';
            removeQuotes(key);

            char* startOfValue = strchr(endOfKey + 1, ':');
            char* endOfValue = strchr(startOfValue, ',');

            if (endOfValue == NULL) {
                endOfValue = strchr(startOfValue, '}');
            }

            int valueLength = endOfValue - startOfValue;
            char* value = malloc((valueLength + 1) * sizeof(char));
            strncpy(value, startOfValue + 1, valueLength - 1);
            value[valueLength - 2] = '\0';
            removeQuotes(value);

            JsonObject jsonObj = { key, value };

            jsonObjList[currentObjectIndex] = jsonObj;
            currentObjectIndex++;
        }
    }

    return jsonObjList;
}

int main() {
    char* jsonString = readFile("example.json");

    // Get the number of words in the JSON string to check if it is valid.
    int numOfWords = countWords(jsonString);
    if (numOfWords % 2 != 0) {
        printf("Invalid JSON string.\n");
        return 0;
    }

    // Parse the JSON string and get the list of JSON objects.
    JsonObject* jsonObjList = parseJson(jsonString);
    int numOfObjects = countChars(jsonString, '{');

    // Print the key-values pairs of each JSON object.
    for (int i = 0; i < numOfObjects; i++) {
        printf("Key: %s\nValue: %s\n\n", jsonObjList[i].key, jsonObjList[i].value);
    }

    return 0;
}