//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    char *value;
} KeyValuePair;

typedef struct {
    int size;
    KeyValuePair *values;
} JsonObject;

JsonObject parseJson(char *jsonString) {
    JsonObject object;
    object.size = 0;
    object.values = (KeyValuePair*)malloc(sizeof(KeyValuePair));

    char *token;
    char *rest = jsonString;
    while ((token = strtok_r(rest, "{}", &rest))) {
        char *pairToken;
        char *pairRest = token;
        while ((pairToken = strtok_r(pairRest, ",\":", &pairRest))) {
            if (object.size % 2 == 0) {
                object.values = (KeyValuePair*)realloc(object.values, sizeof(KeyValuePair) * (object.size + 1));
                object.values[object.size].key = pairToken;
            } else {
                object.values[object.size].value = pairToken;
            }
            object.size++;
        }
    }

    return object;
}

int main() {
    char *jsonString = "{\"hello\":\"world\",\"foo\":\"bar\"}";

    JsonObject object = parseJson(jsonString);

    for (int i = 0; i < object.size; i++) {
        printf("%s: %s\n", object.values[i].key, object.values[i].value);
    }

    free(object.values);

    return 0;
}