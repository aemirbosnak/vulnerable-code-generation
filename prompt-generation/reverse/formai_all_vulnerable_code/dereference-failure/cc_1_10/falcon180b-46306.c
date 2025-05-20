//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR 100

typedef struct {
    char *key;
    char *value;
} KeyValue;

int main() {
    FILE *file;
    char line[MAX_STR];
    KeyValue *keyValue = NULL;
    int count = 0;

    file = fopen("config.ini", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, MAX_STR, file)!= NULL) {
        if (count == 0) {
            keyValue = (KeyValue*)malloc(sizeof(KeyValue));
            keyValue->key = strdup(line);
        }
        else {
            char *temp = strdup(line);
            int len = strlen(temp);
            if (temp[len-1] == '\n') {
                temp[len-1] = '\0';
                len--;
            }
            keyValue->value = strdup(temp);
            count++;
        }
    }

    fclose(file);

    printf("Key\tValue\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%s\n", keyValue[i].key, keyValue[i].value);
    }

    for (int i = 0; i < count; i++) {
        free(keyValue[i].key);
        free(keyValue[i].value);
    }
    free(keyValue);

    return 0;
}