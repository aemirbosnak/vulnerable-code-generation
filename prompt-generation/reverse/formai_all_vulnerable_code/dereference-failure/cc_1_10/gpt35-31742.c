//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//JSON object data structure
struct JSON_Object {
    char *key;
    char *value;
};

//JSON parser function
void parseJSON(char *json) {
    int len = strlen(json);
    struct JSON_Object obj[len/2];
    char *key, *value;
    int i = 0, j = 0, k = 0;

    while (i < len) {
        if (json[i] == '{') {
            i++;
            j = i;
        }
        else if (json[i] == '}') {
            obj[k].key = calloc(i-j+1, sizeof(char));
            obj[k].value = calloc(i-j+1, sizeof(char));
            strncpy(obj[k].key, json+j, strcspn(json+j, ":")-j);
            strncpy(obj[k].value, json+strcspn(json+j, ":")+2, i-strcspn(json+j, ":")-3);
            k++;
            i+=2;
            j = i;
        }
        else {
            i++;
        }
    }

    //printing the parsed JSON object
    for (int i=0; i<k; i++) {
        printf("%s: %s\n", obj[i].key, obj[i].value);
    }
}

int main() {
    char *json = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}";

    printf("JSON String: %s\n", json);

    parseJSON(json);

    return 0;
}