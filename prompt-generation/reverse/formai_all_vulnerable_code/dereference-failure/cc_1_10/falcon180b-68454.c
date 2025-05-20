//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEYS 100

typedef struct {
    char *key;
    char *value;
} KeyValuePair;

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *token;
    int num_keys = 0;
    KeyValuePair *keys = NULL;

    if (argc < 2) {
        printf("Usage: %s <resume.txt>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        token = strtok(line, ":");
        while (token!= NULL) {
            num_keys++;
            if (num_keys == MAX_KEYS) {
                printf("Error: Too many keys.\n");
                fclose(fp);
                return 1;
            }
            keys = realloc(keys, sizeof(KeyValuePair) * (num_keys + 1));
            keys[num_keys - 1].key = strdup(token);
            token = strtok(NULL, ":");
            if (token == NULL) {
                keys[num_keys - 1].value = strdup("");
            } else {
                keys[num_keys - 1].value = strdup(token);
            }
        }
    }

    fclose(fp);

    printf("Name: %s\n", keys[0].value);
    printf("Education: %s\n", keys[1].value);
    printf("Experience: %s\n", keys[2].value);

    for (int i = 0; i < num_keys; i++) {
        free(keys[i].key);
        free(keys[i].value);
    }
    free(keys);

    return 0;
}