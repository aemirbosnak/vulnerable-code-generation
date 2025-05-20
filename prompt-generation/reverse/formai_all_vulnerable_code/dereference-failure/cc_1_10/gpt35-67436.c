//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

// Struct to hold JSON object
typedef struct {
    char *key;
    char *value;
} JSONObject;

// Struct to hold JSON array
typedef struct {
    char *value;
} JSONArray;

// Print error message and exit program
void showError(char *errorMsg) {
    printf("Error: %s", errorMsg);
    exit(1);
}

// Parse JSON key-value pair
JSONObject parseKVPair(char jsonStr[], int *pos) {
    char key[MAX_LEN], value[MAX_LEN];
    int i = *pos, j = 0;
    JSONObject jsonObject;

    // Skip whitespace and first quote
    while (isspace(jsonStr[i])) i++;
    if (jsonStr[i] != '\"') showError("Invalid JSON syntax: expected '\"'");

    // Store key
    i++;
    while (jsonStr[i] != '\"' && j < MAX_LEN-1) {
        key[j] = jsonStr[i];
        i++;
        j++;
    }
    key[j] = '\0';

    // Skip whitespace and colon
    while (isspace(jsonStr[i])) i++;
    if (jsonStr[i] != ':') showError("Invalid JSON syntax: expected ':'");
    i++;

    // Skip whitespace and first quote
    while (isspace(jsonStr[i])) i++;
    if (jsonStr[i] != '\"') showError("Invalid JSON syntax: expected '\"'");

    // Store value
    j = 0;
    i++;
    while (jsonStr[i] != '\"' && j < MAX_LEN-1) {
        value[j] = jsonStr[i];
        i++;
        j++;
    }
    value[j] = '\0';

    // Update position and create JSONObject
    *pos = i+1;
    jsonObject.key = malloc(strlen(key)+1);
    jsonObject.value = malloc(strlen(value)+1);
    strcpy(jsonObject.key, key);
    strcpy(jsonObject.value, value);
    return jsonObject;
}

// Parse JSON array
JSONArray parseArray(char jsonStr[], int *pos) {
    char value[MAX_LEN];
    int i = *pos, j = 0;
    JSONArray jsonArray;

    // Skip whitespace and first bracket
    while (isspace(jsonStr[i])) i++;
    if (jsonStr[i] != '[') showError("Invalid JSON syntax: expected '['");

    // Store value
    j = 0;
    i++;
    while (jsonStr[i] != ']' && j < MAX_LEN-1) {
        value[j] = jsonStr[i];
        i++;
        j++;
    }
    value[j] = '\0';

    // Update position and create JSONArray
    *pos = i+1;
    jsonArray.value = malloc(strlen(value)+1);
    strcpy(jsonArray.value, value);
    return jsonArray;
}

// Parse JSON object
void parseJSON(char jsonStr[]) {
    JSONObject *jsonObjects[MAX_LEN];
    JSONArray *jsonArrays[MAX_LEN];
    int i = 0, j = 0, k = 0;

    // Skip whitespace and first bracket
    while (isspace(jsonStr[i])) i++;
    if (jsonStr[i] != '{') showError("Invalid JSON syntax: expected '{'");

    // Parse objects and arrays
    i++;
    while (jsonStr[i] != '}' && i < MAX_LEN-1) {
        if (jsonStr[i] == '\"') {
            jsonObjects[j] = malloc(sizeof(JSONObject));
            *jsonObjects[j] = parseKVPair(jsonStr, &i);
            j++;
        }
        else if (jsonStr[i] == '[') {
            jsonArrays[k] = malloc(sizeof(JSONArray));
            *jsonArrays[k] = parseArray(jsonStr, &i);
            k++;
        }
        else if (!isspace(jsonStr[i]) && jsonStr[i] != ',') {
            showError("Invalid JSON syntax");
        }
        else {
            i++;
        }
    }

    // Print objects and arrays
    printf("Parsed JSON:\n");
    for (int l = 0; l < j; l++) {
        printf("%s: %s\n", jsonObjects[l]->key, jsonObjects[l]->value);
        free(jsonObjects[l]->key);
        free(jsonObjects[l]->value);
        free(jsonObjects[l]);
    }
    for (int l = 0; l < k; l++) {
        printf("Array: [%s]\n", jsonArrays[l]->value);
        free(jsonArrays[l]->value);
        free(jsonArrays[l]);
    }

    // Check for closing bracket
    if (jsonStr[i] != '}') showError("Invalid JSON syntax: expected '}'");
}

int main() {
    char jsonStr[MAX_LEN] = "{ \"name\": \"John\", \"age\": \"27\", \"pets\": [\"dog\", \"cat\"] }";
    parseJSON(jsonStr);
    return 0;
}