//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a structure to store JSON data */
typedef struct {
    char* name;
    char* value;
} JSONData;

/* Main function that parses a JSON string and stores the data in a JSONData array */
JSONData* parseJSON(char* jsonString, int* numData){
    // Allocate memory for JSONData array to store parsed data
    JSONData* data = malloc(sizeof(JSONData) * 10);

    char* currChar = jsonString;
    int index = 0;
    while(*currChar != '\0'){
        // Find name of the data element
        char* nameStart = strchr(currChar, '\"') + 1;
        char* nameEnd = strchr(nameStart, '\"');
        int nameLen = nameEnd - nameStart;
        char* name = malloc(nameLen + 1);
        strncpy(name, nameStart, nameLen);
        name[nameLen] = '\0';

        // Find value of the data element
        char* valueStart = strchr(nameEnd, ':') + 1;
        char* valueEnd;
        if (*valueStart == '\"') {
            valueStart++;
            valueEnd = strchr(valueStart, '\"');
        } else {
            valueEnd = strchr(valueStart, ',');
        }
        int valueLen = valueEnd - valueStart;
        char* value = malloc(valueLen + 1);
        strncpy(value, valueStart, valueLen);
        value[valueLen] = '\0';

        // Store the parsed data in the JSONData array
        data[index].name = name;
        data[index].value = value;

        currChar = valueEnd + 1;
        index++;
    }

    // Store the number of data elements parsed
    *numData = index;
    return data;
}

int main(){
    // Example JSON string to parse
    char jsonString[] = "{"
                        "\"name\": \"John Doe\","
                        "\"age\": 25,"
                        "\"email\": \"johndoe@example.com\""
                        "}";

    // Parse the JSON string and store the parsed data in a JSONData array
    int numData;
    JSONData* data = parseJSON(jsonString, &numData);

    // Print the parsed data
    for(int i=0; i<numData; i++){
        printf("%s: %s\n", data[i].name, data[i].value);
    }

    // Free the allocated memory
    for(int i=0; i<numData; i++){
        free(data[i].name);
        free(data[i].value);
    }
    free(data);

    return 0;
}