//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structure for holding key-value pairs
struct KeyValuePair
{
    char* key;
    char* value;
};

//structure for holding JSON object
struct JSONObject
{
    struct KeyValuePair** pairs;
    int size;
};

//function to parse JSON string
struct JSONObject* parseJSON(char* jsonString)
{
    //initialize object with size 0
    struct JSONObject* object = (struct JSONObject*) malloc(sizeof(struct JSONObject));
    object->size = 0;

    //check if JSON string is valid
    if(jsonString[0] != '{' || jsonString[strlen(jsonString)-1] != '}')
    {
        printf("Invalid JSON string!\n");
        return NULL;
    }

    //skip first and last character
    jsonString++;

    //loop through json string
    while(*jsonString != '}')
    {
        //skip white space
        while(*jsonString == ' ' || *jsonString == '\n' || *jsonString == '\t')
        {
            jsonString++;
        }

        //allocate memory for key
        char* key = (char*)malloc(sizeof(char)*100);

        //extract key
        int index = 0;
        while(*jsonString != ':')
        {
            key[index++] = *jsonString++;
        }
        key[index] = '\0';

        //skip colon
        jsonString++;

        //skip white space
        while(*jsonString == ' ' || *jsonString == '\n' || *jsonString == '\t')
        {
            jsonString++;
        }

        //allocate memory for value
        char* value = (char*)malloc(sizeof(char)*100);

        //extract value
        index = 0;
        while(*jsonString != ',' && *jsonString != '}')
        {
            value[index++] = *jsonString++;
        }
        value[index] = '\0';

        //skip comma
        if(*jsonString == ',')
        {
            jsonString++;
        }

        //create key-value pair
        struct KeyValuePair* pair = (struct KeyValuePair*)malloc(sizeof(struct KeyValuePair));
        pair->key = key;
        pair->value = value;

        //increase object size and allocate memory for pairs accordingly
        object->size++;
        object->pairs = (struct KeyValuePair**)realloc(object->pairs, sizeof(struct KeyValuePair*)*object->size);
        object->pairs[object->size-1] = pair;
    }

    //return parsed JSON object
    return object;
}

//function to print JSON object
void printJSON(struct JSONObject* object)
{
    printf("{");
    for(int i=0; i<object->size; i++)
    {
        printf("\"%s\":\"%s\"", object->pairs[i]->key, object->pairs[i]->value);
        if(i != object->size-1)
        {
            printf(",");
        }
    }
    printf("}");
}

int main()
{
    //example JSON string
    char* jsonString = "{\"first_name\": \"John\", \"last_name\": \"Doe\", \"age\": 30}";

    //parse JSON string
    struct JSONObject* object = parseJSON(jsonString);

    //print JSON object
    printJSON(object);

    //free memory allocated for JSON object
    for(int i=0; i<object->size; i++)
    {
        free(object->pairs[i]->key);
        free(object->pairs[i]->value);
        free(object->pairs[i]);
    }
    free(object->pairs);
    free(object);

    return 0;
}