//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

struct json_obj {
    char *key;
    char *value;
};

void parse_json(char *json_str) {
    int len = strlen(json_str);
    char *key = NULL, *value = NULL;
    int key_len = 0, val_len = 0;
    int i = 0, j = 0;
    while (i < len) {
        if (json_str[i] == '"') {
            j = i + 1;
            while (j < len && json_str[j] != '"') {
                j++;
            }
            if (j == len) {
                break;
            }
            if (!key) {
                key = (char *)malloc(j - i);
                strncpy(key, json_str + i + 1, j - i - 1);
                key[j - i - 1] = '\0';
                key_len = j - i - 1;
            } else {
                value = (char *)malloc(j - i);
                strncpy(value, json_str + i + 1, j - i - 1);
                value[j - i - 1] = '\0';
                val_len = j - i - 1;
                printf("%.*s: %.*s\n", key_len, key, val_len, value);
                free(value);
                value = NULL;
            }
        }
        i++;
    }
    if (key) {
        free(key);
    }
}

int main() {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    while (fgets(buffer, BUFFER_SIZE - 1, stdin) != NULL) {
        parse_json(buffer);
        memset(buffer, 0, BUFFER_SIZE);
    }
    return 0;
}