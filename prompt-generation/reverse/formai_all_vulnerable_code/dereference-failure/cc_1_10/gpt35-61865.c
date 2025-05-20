//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Defines the maximum number of characters that can be in a key/value string
#define MAX_STRING_LENGTH 100

//Defines the maximum number of key/value pairs that can be in the JSON string
#define MAX_PAIRS 10

//Defines a struct to hold key/value pairs
typedef struct KeyValuePair {
    char key[MAX_STRING_LENGTH];
    char value[MAX_STRING_LENGTH];
} KeyValuePair;

//Defines a struct to hold the JSON object
typedef struct JSONObject {
    KeyValuePair pairs[MAX_PAIRS];
    int count;
} JSONObject;

//Takes in a string and a delimiter character and splits the string into an array of strings
char** split(char* string, char delimiter) {
    int i, j, k;
    int num_tokens = 0;
    int token_length = 0;
    int string_length = strlen(string);
    char current_char;

    //Loops through the string to count the number of tokens
    for(i = 0; i < string_length; i++) {
        current_char = *(string+i);
        if(current_char == delimiter || i == string_length-1) {
            num_tokens++;
            token_length = 0;
        } else {
            token_length++;
        }
    }

    //Allocates memory for the array of strings
    char** tokens = malloc(sizeof(char*)*num_tokens);
    for(i = 0; i < num_tokens; i++) {
        *(tokens+i) = malloc(sizeof(char)*(token_length+1));
    }

    //Loops through the string again to split it into tokens and add them to the array
    k = 0;
    for(i = 0; i < num_tokens; i++) {
        token_length = 0;
        for(j = k; j < string_length; j++) {
            current_char = *(string+j);
            if(current_char == delimiter || j == string_length-1) {
                memcpy(*(tokens+i)+token_length, string+k, j-k+1);
                token_length = 0;
                k = j+1;
                break;
            } else {
                token_length++;
            }
        }
    }
    return tokens;
}

//Parses a JSON string and returns a JSONObject
JSONObject parse(char* string) {
    JSONObject object;
    object.count = 0;
    char** tokens = split(string, ':');
    int num_tokens = sizeof(tokens)/sizeof(tokens[0]);

    //Loops through the array of tokens and adds key/value pairs to the JSONObject
    int i, j, k;
    for(i = 0; i < num_tokens; i++) {
        //Sanity check to make sure we have an even number of tokens
        if(i % 2 == 0) {
            KeyValuePair pair;
            strcpy(pair.key, *(tokens+i));
            strcpy(pair.value, *(tokens+i+1));
            *(object.pairs+object.count) = pair;
            object.count++;
        }
    }

    //Frees dynamically allocated memory
    for(i = 0; i < num_tokens; i++) {
        free(*(tokens+i));
    }
    free(tokens);
    return object;
}

int main() {
    char* json = "{\"name\":\"Bob\",\"age\":30,\"city\":\"New York\"}";
    JSONObject object = parse(json);

    //Prints out the key/value pairs in the JSONObject
    int i;
    for(i = 0; i < object.count; i++) {
        printf("Key: %s, Value: %s\n", (object.pairs+i)->key, (object.pairs+i)->value);
    }
    return 0;
}