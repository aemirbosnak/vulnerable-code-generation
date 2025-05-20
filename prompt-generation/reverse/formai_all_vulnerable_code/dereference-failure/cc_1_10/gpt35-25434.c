//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: medieval
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// declaring struct for JSON objects
typedef struct {
    char *name;
    char *value;
} JSON_Object;

// function to parse JSON string into objects
void parseJSON(char *jsonString, JSON_Object **jsonObjects){
    int objectIndex = 0; // to keep track of index of JSON_Object array
    
    // traversing the JSON string characters
    for(int i=0; i<strlen(jsonString); i++){
        // checking for name of the JSON object
        if(jsonString[i] == '<'){
            char *name = (char*)malloc(sizeof(char)*100); // allocating memory for object name
            int j = 0; // to keep track of index of name array
            
            // adding characters of object name until '>' is encountered
            while(jsonString[++i] != '>'){
                name[j] = jsonString[i];
                j++;
            }
            name[j] = '\0'; // adding null character at end of object name
            
            jsonObjects[objectIndex] = (JSON_Object*)malloc(sizeof(JSON_Object)); // assigning memory for JSON_Object
            jsonObjects[objectIndex]->name = name; // adding name to JSON_Object
            
            objectIndex++; // increasing object index for next object
        }
        // checking for value of the JSON object
        else if(jsonString[i] == '['){
            char *value = (char*)malloc(sizeof(char)*100); // allocating memory for object value
            int j = 0; // to keep track of index of value array
            
            // adding characters of object value until ']' is encountered
            while(jsonString[++i] != ']'){
                value[j] = jsonString[i];
                j++;
            }
            value[j] = '\0'; // adding null character at end of object value
            
            int lastObjectIndex = objectIndex - 1; // getting index of last JSON object
            jsonObjects[lastObjectIndex]->value = value; // adding value to last JSON object
        }
    }
}

int main(){
    char jsonString[] = "The <King> [Arthur] requested a <String> [JSON] parser"; // JSON string to be parsed
    JSON_Object **jsonObjects = (JSON_Object**)malloc(sizeof(JSON_Object*)*2); // allocating memory for JSON_Object array
    parseJSON(jsonString, jsonObjects); // parsing JSON string into objects
    
    printf("The JSON objects are:\n");
    for(int i=0; i<2; i++){
        printf("Object name: %s, Object value: %s\n", jsonObjects[i]->name, jsonObjects[i]->value);
    }
    
    return 0;
}