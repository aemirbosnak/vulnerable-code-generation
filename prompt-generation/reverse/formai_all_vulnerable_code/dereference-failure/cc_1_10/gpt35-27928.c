//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure for JSON Object
struct JsonObject {
    char* key;
    char* value;
};

//Function to parse JSON string and extract JSON Object
struct JsonObject parseJsonString(char* jsonString) {
    int keyStartIndex = -1;
    int keyEndIndex = -1;
    int valueStartIndex = -1;
    int valueEndIndex = -1;

    for(int i=0; i<strlen(jsonString); i++) {
        if(jsonString[i] == '\"' && keyStartIndex == -1) {
            keyStartIndex = i+1;
        } else if(jsonString[i] == '\"' && keyStartIndex != -1 && keyEndIndex == -1) {
            keyEndIndex = i;
        } else if(jsonString[i] == '\"' && keyEndIndex != -1 && valueStartIndex == -1) {
            valueStartIndex = i+1;
        } else if(jsonString[i] == '\"' && valueStartIndex != -1 && valueEndIndex == -1) {
            valueEndIndex = i;
        }

        if(keyStartIndex != -1 && keyEndIndex != -1 && valueStartIndex != -1 && valueEndIndex != -1) {
            break;
        }
    }

    char* key = (char*) malloc(keyEndIndex - keyStartIndex + 1);
    char* value = (char*) malloc(valueEndIndex - valueStartIndex + 1);
    
    strncpy(key, jsonString+keyStartIndex, keyEndIndex-keyStartIndex);
    strncpy(value, jsonString+valueStartIndex, valueEndIndex-valueStartIndex);

    struct JsonObject jsonObject;
    jsonObject.key = key;
    jsonObject.value = value;
    return jsonObject;
}

//Driver function
int main() {
    char JSON_STRING[] = "{\"name\":\"John\", \"age\":30, \"address\":\"New York\"}";
    struct JsonObject jsonObject = parseJsonString(JSON_STRING);
    printf("Key: %s\nValue: %s", jsonObject.key, jsonObject.value);
    return 0;
}