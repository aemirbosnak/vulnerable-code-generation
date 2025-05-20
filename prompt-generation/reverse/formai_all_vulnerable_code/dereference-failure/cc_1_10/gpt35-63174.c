//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the structure for the JSON object
typedef struct {
    char* key;
    char* value;
} json_object;

// parse a json string and return an array of json objects
json_object* parse_json(char* input){
    json_object* objects = malloc(sizeof(json_object)*10);
    memset(objects, 0, sizeof(json_object)*10);

    int object_index = 0;
    char* token = strtok(input, "{}, ");
    char* key = NULL;
    int in_string = 0;
    while(token != NULL){
        if(*token == '\"' && *(token-1) != '\\'){
            if(in_string){
                in_string = 0;
                objects[object_index].value = (char*)malloc(strlen(token));
                memset(objects[object_index].value, 0, strlen(token));
                memcpy(objects[object_index].value, key, strlen(key));
                key = NULL;
                object_index++;
            }
            else{
                in_string = 1;
                key = token;
            }
        }
        else if(!in_string && (*token == ',' || *token == '}')){
            in_string = 0;
            if(key != NULL){
                objects[object_index].value = (char*)malloc(strlen(token));
                memset(objects[object_index].value, 0, strlen(token));
                memcpy(objects[object_index].value, key, strlen(key));
                key = NULL;
                object_index++;
            }
        }
        token = strtok(NULL, "{}, ");
    }
    return objects;
}

// main function
int main(){
    char* input = "{\"name\": \"John\",\"age\": 24}";
    json_object* objects = parse_json(input);
    for(int i=0;i<strlen(input);i++){
        printf("%c", input[i]);
    }
    printf("\nParsed JSON:\n");
    for(int i=0;i<2;i++){
        printf("%s\n", objects[i].value);
    }
    return 0;
}