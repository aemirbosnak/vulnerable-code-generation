//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold JSON data
typedef struct {
    char* key;
    char* value;
} JSONData;

// Parse JSON data and return an array of struct
JSONData* parseJSON(char* jsonString, int* count) {
    int index = 0, n = strlen(jsonString), dataIndex = 0, i = 0;
    char* key = NULL;
    char* value = NULL;
    int keyFlag = 0, valueFlag = 0;
    JSONData* jsonData;

    // Count the number of key-value pairs in JSON data
    for (i = 0; i < n; i++) {
        if (jsonString[i] == ':') {
            *count = *count + 1;
        }
    }

    // Allocate memory for JSON data
    jsonData = (JSONData*)malloc(sizeof(JSONData) * (*count));

    // Parse JSON string
    while (index < n) {
        if (jsonString[index] == '\"') {
            if (keyFlag) {
                key = (char*)malloc(sizeof(char) * (dataIndex + 1));
                strncpy(key, jsonString + index - dataIndex, dataIndex);
                key[dataIndex] = '\0';
                dataIndex = 0;
                keyFlag = 0;
            }
            else {
                value = (char*)malloc(sizeof(char) * (dataIndex + 1));
                strncpy(value, jsonString + index - dataIndex, dataIndex);
                value[dataIndex] = '\0';
                dataIndex = 0;
                valueFlag = 0;

                // Save key-value pair to JSON data array
                jsonData[i].key = key;
                jsonData[i].value = value;
                i++;
            }
        }
        else if (jsonString[index] == ':') {
            keyFlag = 1;
        }
        else if (jsonString[index] == ',' || jsonString[index] == '}') {
            dataIndex = 0;
            keyFlag = 0;
            valueFlag = 0;
        }
        else if (jsonString[index] != '{' && jsonString[index] != '}') {
            dataIndex++;
            valueFlag = 1;
        }
        index++;
    }

    return jsonData;
}

int main() {
    char jsonString[] = "{\"name\":\"John\",\"age\":\"25\",\"city\":\"New York\"}";
    int count = 0, i = 0;
    JSONData* jsonData;

    jsonData = parseJSON(jsonString, &count);

    printf("Parsed JSON data:\n");
    for (i = 0; i < count; i++) {
        printf("%s: %s\n", jsonData[i].key, jsonData[i].value);
    }

    // Free allocated memory
    for (i = 0; i < count; i++) {
        free(jsonData[i].key);
        free(jsonData[i].value);
    }
    free(jsonData);

    return 0;
}