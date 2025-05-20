//MISTRAL-7B DATASET v1.0 Category: Building a JSON Parser ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char key[50];
    char value[100];
} JsonKeyValue;

JsonKeyValue json_parser(char *json) {
    JsonKeyValue kv;
    int len = strlen(json);
    int i = 0, j = 0, key_start = -1, value_start = -1;

    while (i < len) {
        if (json[i] == ':') {
            if (key_start != -1) {
                value_start = i + 1;
                break;
            } else {
                key_start = i - 1;
            }
        }
        i++;
    }

    if (key_start == -1 || value_start == -1) {
        printf("Invalid JSON format\n");
        json_parser(++json);
        return (JsonKeyValue){0};
    }

    strncpy(kv.key, json + key_start, value_start - key_start);
    kv.key[value_start - key_start] = '\0';

    j = value_start;
    int value_len = 0;
    while (json[j] != ',' && json[j] != '}') {
        if (json[j] != '\\' || (json[j + 1] != 'n' && json[j + 1] != 'u')) {
            kv.value[value_len++] = json[j];
        } else {
            if (!strncmp(json + j, "null", 4)) {
                kv.value[value_len] = '\0';
                break;
            }
            j += 2;
        }
        j++;
    }

    kv.value[value_len] = '\0';
    return kv;
}

int main() {
    char json[] = "{\"name\":\"John Doe\"}";
    JsonKeyValue kv = json_parser(json);
    printf("Key: %s, Value: %s\n", kv.key, kv.value);
    return 0;
}