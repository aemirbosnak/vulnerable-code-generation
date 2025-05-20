//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    char *value;
} JsonPair;

typedef struct {
    JsonPair *pairs;
    size_t size;
} JsonObject;

JsonObject *parse_json(const char *json) {
    JsonObject *obj = malloc(sizeof(JsonObject));
    
    obj->size = 0;
    obj->pairs = malloc(sizeof(JsonPair));
    
    char *tok = strtok((char *) json, "{,:}");
    char *key, *val;
    int flag = 0;
    
    while (tok != NULL) {
        if (flag == 0) {
            key = tok;
            flag = 1;
        } else {
            val = tok;
            flag = 0;
            
            obj->size++;
            obj->pairs = realloc(obj->pairs, obj->size * sizeof(JsonPair));
            obj->pairs[obj->size - 1].key = malloc(strlen(key) * sizeof(char));
            obj->pairs[obj->size - 1].value = malloc(strlen(val) * sizeof(char));
            
            strcpy(obj->pairs[obj->size - 1].key, key);
            strcpy(obj->pairs[obj->size - 1].value, val);
        }
        
        tok = strtok(NULL, "{,:}");
    }
    
    return obj;
}

int main() {
    const char *json = "{\"name\":\"John\", \"age\":30, \"city\":\"New York\"}";
    JsonObject *obj = parse_json(json);
    
    for (int i = 0; i < obj->size; i++) {
        printf("%s:%s\n", obj->pairs[i].key, obj->pairs[i].value);
    }
    
    // free memory
    for (int i = 0; i < obj->size; i++) {
        free(obj->pairs[i].key);
        free(obj->pairs[i].value);
    }
    
    free(obj->pairs);
    free(obj);
    
    return 0;
}