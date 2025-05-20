//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to check if the given character is a digit
int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

// function to check if the given character is a valid alpha character
int isAlpha(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || c == '$');
}

// function to skip white spaces in the given string
char *skipWhiteSpaces(char *str) {
    while (*str == ' ' || *str == '\t' || *str == '\n') {
        str++;
    }
    return str;
}

// structure to hold the key-value pair of a JSON object
struct JSONPair {
    char *key;
    char *value;
};

// structure to hold the JSON object
struct JSONObject {
    struct JSONPair *pairs;
    int pairCount;
};

// function to parse JSON object from a string
struct JSONObject parseJSON(char *str) {
    int length = strlen(str);
    int i = 0;
    
    // skip white spaces in the begining of the string
    str = skipWhiteSpaces(str);
    
    // check if the first character is '{'
    if (*str != '{') {
        printf("Error: Invalid JSON object\n");
        exit(1);
    }
    str++;
    
    // allocate memory for the JSON object
    struct JSONObject obj;
    obj.pairs = (struct JSONPair*) malloc(sizeof(struct JSONPair)*10);
    obj.pairCount = 0;
    
    // loop through the string and parse key-value pairs
    while (*str != '}') {
        // skip white spaces
        str = skipWhiteSpaces(str);
        
        // parse key
        char *key = (char*) malloc(sizeof(char)*50);
        i = 0;
        while (*str != ':' && i < 50) {
            if (!isAlpha(*str)) {
                printf("Error: Invalid key name\n");
                exit(1);
            }
            key[i++] = *str++;
        }
        key[i] = '\0';
        str++;
        
        // skip white spaces
        str = skipWhiteSpaces(str);
        
        // parse value
        char *value = (char*) malloc(sizeof(char)*50);
        i = 0;
        while (*str != ',' && *str != '}' && i < 50) {
            value[i++] = *str++;
        }
        value[i] = '\0';
        
        // add key-value pair to the JSON object
        obj.pairs[obj.pairCount].key = key;
        obj.pairs[obj.pairCount].value = value;
        obj.pairCount++;
        
        // check if there are more key-value pairs
        if (*str == ',') {
            str++;
        }
    }
    
    return obj;
}

int main() {
    // example JSON string
    char *jsonStr = "{\n"
                    "   \"name\": \"John Doe\",\n"
                    "   \"age\": 32,\n"
                    "   \"address\": {\n"
                    "       \"street\": \"123 Main St\",\n"
                    "       \"city\": \"Anytown\",\n"
                    "       \"state\": \"CA\",\n"
                    "       \"zip\": 12345\n"
                    "   },\n"
                    "   \"phone\": [\n"
                    "       {\n"
                    "           \"type\": \"home\",\n"
                    "           \"number\": \"555-555-1234\"\n"
                    "       },\n"
                    "       {\n"
                    "           \"type\": \"work\",\n"
                    "           \"number\": \"555-555-4321\"\n"
                    "       }\n"
                    "   ]\n"
                    "}";

    // parse JSON object from the string
    struct JSONObject obj = parseJSON(jsonStr);
    
    // print the parsed key-value pairs
    int i;
    for (i = 0; i < obj.pairCount; i++) {
        printf("%s: %s\n", obj.pairs[i].key, obj.pairs[i].value);
    }
    
    // free the allocated memory
    for (i = 0; i < obj.pairCount; i++) {
        free(obj.pairs[i].key);
        free(obj.pairs[i].value);
    }
    free(obj.pairs);

    return 0;
}