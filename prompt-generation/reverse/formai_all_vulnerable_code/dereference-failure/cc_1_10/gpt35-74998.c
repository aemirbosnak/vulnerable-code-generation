//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure representing a key-value pair in a JSON object
typedef struct {
    char* key;
    char* value;
} KeyValuePair;

// Structure representing a JSON object
typedef struct {
    int num_pairs;
    KeyValuePair* pairs;
} JSONObject;

// Function to parse a JSON object from a string
JSONObject* parseJSON(char* json_string) {
    JSONObject* jsonObj = (JSONObject*) malloc(sizeof(JSONObject));
    jsonObj->num_pairs = 0;
    jsonObj->pairs = (KeyValuePair*) malloc(sizeof(KeyValuePair));
    char* ptr = json_string;
    while(*ptr != '\0') {
        if (*ptr == '"') {
            char* start = ptr+1;
            char* end = strchr(start, '"');
            *end = '\0';
            jsonObj->num_pairs++;
            jsonObj->pairs = (KeyValuePair*) realloc(jsonObj->pairs,
                sizeof(KeyValuePair) * jsonObj->num_pairs);
            jsonObj->pairs[jsonObj->num_pairs-1].key = strdup(start);
            ptr = end+1;
            while (*ptr != ':') {
                ptr++;
            }
            start = ptr+1;
            while (*start == ' ') {
                start++;
            }
            if (*start == '"') {
                start++;
                end = strchr(start, '"');
                *end = '\0';
                jsonObj->pairs[jsonObj->num_pairs-1].value = strdup(start);
                ptr = end+1;
            } else if (*start == '{') {
                int brace_count = 1;
                end = start+1;
                while (brace_count > 0) {
                    if (*end == '{') {
                        brace_count++;
                    } else if (*end == '}') {
                        brace_count--;
                    }
                    end++;
                }
                char* substring = (char*) malloc(end-start-1);
                strncpy(substring, start+1, end-start-2);
                substring[end-start-2] = '\0';
                JSONObject* nestedObj = parseJSON(substring);
                jsonObj->pairs[jsonObj->num_pairs-1].value =
                    (char*) malloc(sizeof(JSONObject));
                sprintf(jsonObj->pairs[jsonObj->num_pairs-1].value,
                    "%p", (void*) nestedObj);
                ptr = end+1;
            } else {
                end = start;
                while (*end != ',' && *end != '}') {
                    end++;
                }
                *end = '\0';
                jsonObj->pairs[jsonObj->num_pairs-1].value = strdup(start);
                ptr = end+1;
            }
        } else {
            ptr++;
        }
    }
    return jsonObj;
}

int main() {
    char* json_string = "{\"name\":\"John Doe\", \"age\":25, \"address\":{\"city\":\"New York\", \"state\":\"NY\"}}";
    JSONObject* jsonObj = parseJSON(json_string);
    printf("Number of pairs: %d\n", jsonObj->num_pairs);
    for (int i = 0; i < jsonObj->num_pairs; i++) {
        printf("%s: ", jsonObj->pairs[i].key);
        if (jsonObj->pairs[i].value[0] == '{') {
            printf("\n");
            JSONObject* nestedObj =
                (JSONObject*) strtoul(jsonObj->pairs[i].value, NULL, 0);
            for (int j = 0; j < nestedObj->num_pairs; j++) {
                printf("\t%s: %s\n", nestedObj->pairs[j].key,
                    nestedObj->pairs[j].value);
            }
        } else {
            printf("%s\n", jsonObj->pairs[i].value);
        }
    }
    return 0;
}