//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 256

// Define a JSON object and its properties
typedef struct {
    char *name;
    int id;
    char *description;
} JSONObject;

// Read and parse JSON object from a file
JSONObject* readJSONFromFile(char* filename) {
    JSONObject* json = NULL;
    char buffer[MAX_BUF_SIZE] = "";
    char* temp;
    FILE* fp;

    // Open the file and read the contents
    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error: Failed to open file '%s'!\n", filename);
        return NULL;
    }
    while(fgets(buffer, MAX_BUF_SIZE, fp)) {
        if(json == NULL) {
            json = (JSONObject*) malloc(sizeof(JSONObject));
        }
        // Parse the JSON object properties
        temp = strtok(buffer, ":");
        if(strcmp(temp, "name") == 0) {
            temp = strtok(NULL, "");
            json->name = (char*) malloc(strlen(temp));
            strcpy(json->name, temp);
        } else if(strcmp(temp, "id") == 0) {
            temp = strtok(NULL, "");
            sscanf(temp, "%d", &json->id);
        } else if(strcmp(temp, "description") == 0) {
            temp = strtok(NULL, "");
            json->description = (char*) malloc(strlen(temp));
            strcpy(json->description, temp);
        }
    }
    fclose(fp);
    return json;
}

int main() {
    JSONObject* json;
    char* filename = "example.json";
    json = readJSONFromFile(filename);

    // Print the JSON object properties
    if(json != NULL) {
        printf("JSON Object\n");
        printf("Name: %s\n", json->name);
        printf("ID: %d\n", json->id);
        printf("Description: %s\n", json->description);
        // Clean up the memory allocated for the JSON object
        free(json->name);
        free(json->description);
        free(json);
    } else {
        printf("Error: Failed to read JSON object from file '%s'!\n", filename);
    }

    return 0;
}