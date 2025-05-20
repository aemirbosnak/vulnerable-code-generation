//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Define a structure to store the data of a JSON element
typedef struct json {
    char key[MAX_SIZE];
    char value[MAX_SIZE];
    struct json *next;
} json;

// Function to parse the JSON string
json* parseJSON(char* jsonString) {
    json *head = NULL, *tail = NULL;

    // Initialize variables to store data
    char key[MAX_SIZE];
    char value[MAX_SIZE];
    char ch;
    int i = 0, j = 0;

    // Start parsing the JSON string
    while (*jsonString != '\0') {
        ch = *jsonString;
        jsonString++;

        // Ignore white spaces
        if (ch == ' ' || ch == '\t' || ch == '\n') {
            continue;
        }

        // Parse the JSON key
        if (ch == '\"') {
            i = 0;
            jsonString++;
            while (*jsonString != '\"') {
                key[i++] = *jsonString;
                jsonString++;
            }
            key[i] = '\0';

            // Ignore the ':' character
            jsonString++;
            jsonString++;
        }

        // Parse the JSON value
        if (ch == '\"') {
            j = 0;
            while (*jsonString != '\"') {
                value[j++] = *jsonString;
                jsonString++;
            }
            value[j] = '\0';

            // Create a new JSON element and add it to the list
            json *node = (json *)malloc(sizeof(json));
            strcpy(node->key, key);
            strcpy(node->value, value);
            node->next = NULL;

            if (head == NULL) {
                head = node;
                tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
        }
    }

    // Return the list of JSON elements
    return head;
}

int main() {
    char jsonString[MAX_SIZE] = "{\"name\":\"John\",\"age\":\"25\",\"country\":\"USA\"}";

    // Parse the JSON string and store the data in a list
    json* jList = parseJSON(jsonString);

    // Print the data stored in the list
    json* itr = jList;
    while (itr != NULL) {
        printf("%s: %s\n", itr->key, itr->value);
        itr = itr->next;
    }

    return 0;
}