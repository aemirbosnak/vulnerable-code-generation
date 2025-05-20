//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct for key-value pairs in JSON */
typedef struct {
    char* key;
    char* value;
} KeyValuePair;

/* Struct to hold a single JSON object */
typedef struct {
    int num_pairs;
    KeyValuePair *pairs;
} JSONObject;

/* Struct to hold a list of JSON objects */
typedef struct {
    int num_objects;
    JSONObject *objects;
} JSONArray;

/* Prototype for recursive JSON parsing function */
void parse_json(char *json_str, int *i, JSONObject *json_obj);

/* Main function */
int main() {
    char *json_str = "{\"name\": \"John Smith\", \"age\": 35, \"isMarried\": true}";
    JSONObject json_obj;
    json_obj.num_pairs = 0;
    json_obj.pairs = (KeyValuePair*)malloc(sizeof(KeyValuePair) * 10);

    int i = 0;
    parse_json(json_str, &i, &json_obj);

    for (int j = 0; j < json_obj.num_pairs; j++) {
        printf("%s: %s\n", json_obj.pairs[j].key, json_obj.pairs[j].value);
        free(json_obj.pairs[j].key);
        free(json_obj.pairs[j].value);
    }

    free(json_obj.pairs);

    return 0;
}

/* Recursive JSON parsing function */
void parse_json(char *json_str, int *i, JSONObject *json_obj) {
    while (json_str[*i] != '\0') {
        if (json_str[*i] == '{') {
            (*i)++;
            parse_json(json_str, i, json_obj);
        } else if (json_str[*i] == '}') {
            (*i)++;
            return;
        } else if (json_str[*i] == '"') {
            (*i)++;
            /* Get the key */
            int key_len = 0;
            while (json_str[*i + key_len] != ':') {
                key_len++;
            }
            char *key = (char*)malloc(sizeof(char) * (key_len + 1));
            for (int j = 0; j < key_len; j++) {
                key[j] = json_str[*i + j];
            }
            key[key_len] = '\0';
            (*i) += key_len + 2;
            /* Get the value */
            int value_len = 0;
            while (json_str[*i + value_len] != ',' && json_str[*i + value_len] != '}') {
                value_len++;
            }
            char *value = (char*)malloc(sizeof(char) * (value_len + 1));
            for (int j = 0; j < value_len; j++) {
                value[j] = json_str[*i + j];
            }
            value[value_len] = '\0';
            (*i) += value_len + 1;
            /* Add the key-value pair to the JSON object */
            json_obj->pairs[json_obj->num_pairs].key = key;
            json_obj->pairs[json_obj->num_pairs].value = value;
            json_obj->num_pairs++;
        } else {
            (*i)++;
        }
    }
}