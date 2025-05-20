//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct JSONValue {
    char *key;
    char *value;
    struct JSONValue *next;
} JSONValue;

typedef struct JSONObject {
    JSONValue *head;
} JSONObject;

JSONObject* createJSONObject() {
    JSONObject *obj = (JSONObject *)malloc(sizeof(JSONObject));
    obj->head = NULL;
    return obj;
}

void freeJSONObject(JSONObject *obj) {
    JSONValue *current = obj->head;
    while (current) {
        JSONValue *tmp = current;
        current = current->next;
        free(tmp->key);
        free(tmp->value);
        free(tmp);
    }
    free(obj);
}

char* trimWhitespace(const char* str) {
    while (isspace(*str)) str++;
    if (*str == 0) return strdup("");
    
    const char *end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) end--;
    
    size_t len = end - str + 2; // +2 for null terminator and width adjustment
    char *result = (char *)malloc(len);
    strncpy(result, str, len - 1);
    result[len - 1] = '\0';
    
    return result;
}

char* extractKeyValuePair(const char *json, int *index) {
    char *key = NULL, *value = NULL;
    char buffer[1024];
    
    int i = *index;
    while (json[i] && json[i] != ':') {
        i++;
    }
    if (json[i] == ':') {
        key = trimWhitespace(strndup(json + *index, i - *index));
        i++; // Move past ':'
        
        while (json[i] && (json[i] == ' ' || json[i] == ':')) i++;
        int valueStart = i;

        while (json[i] && json[i] != ',' && json[i] != '}') {
            i++;
        }
        
        if (valueStart < i) {
            value = trimWhitespace(strndup(json + valueStart, i - valueStart));
        }
    }
    
    *index = i;
    return (char *)key ? key : value;
}

void addKeyValue(JSONObject *obj, const char *key, const char *value) {
    JSONValue *newValue = (JSONValue *)malloc(sizeof(JSONValue));
    newValue->key = key;
    newValue->value = value;
    newValue->next = obj->head;
    obj->head = newValue;
}

void printJSONObject(JSONObject *obj) {
    JSONValue *current = obj->head;
    printf("{\n");
    while (current) {
        printf("    \"%s\": \"%s\"", current->key, current->value);
        if (current->next) printf(",");
        printf("\n");
        current = current->next;
    }
    printf("}\n");
}

void parseJSON(JSONObject *obj, const char *json) {
    int index = 0;
    while (json[index]) {
        char *key = extractKeyValuePair(json, &index);
        if (!key) break;
        
        char *value = extractKeyValuePair(json, &index);
        if (!value) break;

        addKeyValue(obj, key, value);
    }
}

int main() {
    const char *jsonSample = "{\"name\": \"Alice\", \"age\": \"30\", \"city\": \"Wonderland\"}";
    
    JSONObject *jsonObj = createJSONObject();
    parseJSON(jsonObj, jsonSample);
    
    printf("Parsed JSON Object:\n");
    printJSONObject(jsonObj);
    
    freeJSONObject(jsonObj);
    return 0;
}