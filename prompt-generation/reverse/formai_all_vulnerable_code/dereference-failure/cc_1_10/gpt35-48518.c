//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define JSON_OBJECT 0
#define JSON_ARRAY 1
#define JSON_STRING 2
#define JSON_NUMBER 3
#define JSON_TRUE 4
#define JSON_FALSE 5
#define JSON_NULL 6

typedef struct JSONValue {
    int type;
    union value {
        char* string;
        double number;
        struct JSONValue* elements;
    } val;
} JSONValue;

JSONValue* parseJSON(char* jsonString);
JSONValue parseJSONObject(char* jsonString, int* index);
JSONValue parseJSONArray(char* jsonString, int* index);
JSONValue parseJSONString(char* jsonString, int* index);
JSONValue parseJSONNumber(char* jsonString, int* index);
JSONValue parseJSONBoolean(char* jsonString, int* index);
JSONValue parseJSONNull(char* jsonString, int* index);
char* substring(char* str, int start, int end);

int main() {
    char input[] = "{\"name\": \"John Smith\", \"age\": 31, \"city\": \"New York\", \"isMarried\": false}";
    JSONValue* result = parseJSON(input);

    printf("name: %s\n", result[0].val.string);
    printf("age: %.0f\n", result[1].val.number);
    printf("city: %s\n", result[2].val.string);
    printf("isMarried: %s\n", result[3].val.string ? "true" : "false");

    free(result);

    return 0;
}

JSONValue* parseJSON(char* jsonString) {
    int index = 0;
    int numElements = 0;
    JSONValue* elements = malloc(sizeof(JSONValue));

    while (jsonString[index] != '\0') {
        if (jsonString[index] == '{') {
            elements[numElements] = parseJSONObject(jsonString, &index);
            elements = realloc(elements, sizeof(JSONValue) * (++numElements + 1));
        } else if (jsonString[index] == '[') {
            elements[numElements] = parseJSONArray(jsonString, &index);
            elements = realloc(elements, sizeof(JSONValue) * (++numElements + 1));
        } else if (jsonString[index] == '\"') {
            elements[numElements] = parseJSONString(jsonString, &index);
            elements = realloc(elements, sizeof(JSONValue) * (++numElements + 1));
        } else if (isdigit(jsonString[index])) {
            elements[numElements] = parseJSONNumber(jsonString, &index);
            elements = realloc(elements, sizeof(JSONValue) * (++numElements + 1));
        } else if (jsonString[index] == 't' || jsonString[index] == 'f') {
            elements[numElements] = parseJSONBoolean(jsonString, &index);
            elements = realloc(elements, sizeof(JSONValue) * (++numElements + 1));
        } else if (jsonString[index] == 'n') {
            elements[numElements] = parseJSONNull(jsonString, &index);
            elements = realloc(elements, sizeof(JSONValue) * (++numElements + 1));
        }

        while (jsonString[index] != ',' && jsonString[index] != '\0') {
            index++;
        }

        if (jsonString[index] == ',') {
            index++;
        }
    }

    elements[numElements].type = -1;
    elements[numElements].val.elements = NULL;

    return elements;
}

JSONValue parseJSONObject(char* jsonString, int* index) {
    (*index)++;
    JSONValue jsonObject;
    int numElements = 0;
    jsonObject.type = JSON_OBJECT;
    jsonObject.val.elements = malloc(sizeof(JSONValue));

    while (jsonString[*index] != '}') {
        JSONValue jsonValue = parseJSONString(jsonString, index);

        while (jsonString[*index] != ':') {
            (*index)++;
        }
        (*index)++;

        if (jsonString[*index] == '{') {
            jsonValue = parseJSONObject(jsonString, index);
        } else if (jsonString[*index] == '[') {
            jsonValue = parseJSONArray(jsonString, index);
        } else if (jsonString[*index] == '\"') {
            jsonValue = parseJSONString(jsonString, index);
        } else if (isdigit(jsonString[*index])) {
            jsonValue = parseJSONNumber(jsonString, index);
        } else if (jsonString[*index] == 't' || jsonString[*index] == 'f') {
            jsonValue = parseJSONBoolean(jsonString, index);
        } else if (jsonString[*index] == 'n') {
            jsonValue = parseJSONNull(jsonString, index);
        }

        jsonObject.val.elements[numElements++] = jsonValue;
        jsonObject.val.elements = realloc(jsonObject.val.elements, sizeof(JSONValue) * (numElements + 1));

        while (jsonString[*index] != ',' && jsonString[*index] != '}') {
            (*index)++;
        }
        
        if (jsonString[*index] == ',') {
            (*index)++;
        }
    }

    jsonObject.val.elements[numElements].type = -1;
    jsonObject.val.elements[numElements].val.elements = NULL;

    (*index)++;

    return jsonObject;
}

JSONValue parseJSONArray(char* jsonString, int* index) {
    (*index)++;
    JSONValue jsonArray;
    int numElements = 0;
    jsonArray.type = JSON_ARRAY;
    jsonArray.val.elements = malloc(sizeof(JSONValue));

    while (jsonString[*index] != ']') {
        JSONValue jsonValue;

        if (jsonString[*index] == '{') {
            jsonValue = parseJSONObject(jsonString, index);
        } else if (jsonString[*index] == '[') {
            jsonValue = parseJSONArray(jsonString, index);
        } else if (jsonString[*index] == '\"') {
            jsonValue = parseJSONString(jsonString, index);
        } else if (isdigit(jsonString[*index])) {
            jsonValue = parseJSONNumber(jsonString, index);
        } else if (jsonString[*index] == 't' || jsonString[*index] == 'f') {
            jsonValue = parseJSONBoolean(jsonString, index);
        } else if (jsonString[*index] == 'n') {
            jsonValue = parseJSONNull(jsonString, index);
        }

        jsonArray.val.elements[numElements++] = jsonValue;
        jsonArray.val.elements = realloc(jsonArray.val.elements, sizeof(JSONValue) * (numElements + 1));

        while (jsonString[*index] != ',' && jsonString[*index] != ']') {
            (*index)++;
        }

        if (jsonString[*index] == ',') {
            (*index)++;
        }
    }

    jsonArray.val.elements[numElements].type = -1;
    jsonArray.val.elements[numElements].val.elements = NULL;

    (*index)++;

    return jsonArray;
}

JSONValue parseJSONString(char* jsonString, int* index) {
    JSONValue jsonStringValue;
    int start = ++(*index);

    while (jsonString[*index] != '\"') {
        (*index)++;
    }

    int end = *index;
    (*index)++;

    jsonStringValue.type = JSON_STRING;
    jsonStringValue.val.string = substring(jsonString, start, end);

    return jsonStringValue;
}

JSONValue parseJSONNumber(char* jsonString, int* index) {
    JSONValue jsonNumberValue;
    int start = *index;

    while (isdigit(jsonString[*index]) || jsonString[*index] == '.' || jsonString[*index] == '-' || jsonString[*index] == '+') {
        (*index)++;
    }

    int end = *index;
    char* stringValue = substring(jsonString, start, end);
    jsonNumberValue.type = JSON_NUMBER;
    jsonNumberValue.val.number = atof(stringValue);
    free(stringValue);

    return jsonNumberValue;
}

JSONValue parseJSONBoolean(char* jsonString, int* index) {
    JSONValue jsonBooleanValue;

    if (jsonString[*index] == 't') {
        jsonBooleanValue.type = JSON_TRUE;
        jsonBooleanValue.val.string = "true";
        (*index) += 4;
    } else {
        jsonBooleanValue.type = JSON_FALSE;
        jsonBooleanValue.val.string = "false";
        (*index) += 5;
    }

    return jsonBooleanValue;
}

JSONValue parseJSONNull(char* jsonString, int* index) {
    JSONValue jsonNullValue;
    jsonNullValue.type = JSON_NULL;
    jsonNullValue.val.string = NULL;
    (*index) += 4;

    return jsonNullValue;
}

char* substring(char* str, int start, int end) {
    int length = end - start;
    char* subStr = malloc(sizeof(char) * (length + 1));
    strncpy(subStr, str + start, length);
    subStr[length] = '\0';

    return subStr;
}