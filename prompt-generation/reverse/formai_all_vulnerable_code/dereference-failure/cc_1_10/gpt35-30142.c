//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 20
#define MAX_VAL_LEN 50
#define JSON_LEN 100

typedef struct KeyValue {
    char key[MAX_KEY_LEN];
    char value[MAX_VAL_LEN];
} KeyValue;

int parser(char *json, KeyValue *keyvalue) {
    // Checks if json string is valid
    if (json[0] != '{' || json[strlen(json)-1] != '}') {
        printf("Invalid JSON string format.\n");
        return 0;
    }

    int i = 1;
    int j = 1;
    int count = 0;

    while (json[i] != '}') {
        if (json[i] == '{') {
            i++;
            continue;
        }

        char key[MAX_KEY_LEN];
        char value[MAX_VAL_LEN];

        int k = 0;
        while (json[i] != ':') {
            key[k] = json[i];
            k++;
            i++;
        }

        i++; // skip : character
        int v = 0;
        while (json[i] != ',' && json[i] != '}') {
            value[v] = json[i];
            v++;
            i++;
        }

        strcpy(keyvalue[count].key, key);
        strcpy(keyvalue[count].value, value);
        count++;

        if (json[i] == '}') {
            break;
        }

        i++;
    }

    return count;
}

int main() {
    char json[JSON_LEN] = "{\
        \"name\": \"John Doe\",\
        \"age\": 30,\
        \"hobbies\": [\"reading\", \"writing\"],\
        \"address\": {\
            \"street\": \"123 Oak St\",\
            \"city\": \"Seattle\",\
            \"state\": \"WA\"\
        }\
    }";

    KeyValue keyvalue[MAX_KEY_LEN];
    int count = parser(json, keyvalue);

    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", keyvalue[i].key, keyvalue[i].value);
    }

    return 0;
}