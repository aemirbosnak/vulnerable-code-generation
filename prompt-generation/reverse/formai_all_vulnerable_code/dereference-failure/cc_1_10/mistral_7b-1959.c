//MISTRAL-7B DATASET v1.0 Category: Building a JSON Parser ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char key[25];
    union {
        char str[50];
        int intVal;
    } value;
} JsonKeyValue;

void parseJSON(const char *json, JsonKeyValue *jsonArray, int *count) {
    int index = 0, len = 0, inString = false;
    char c;

    *count = 0;
    jsonArray = calloc(1, sizeof(JsonKeyValue) * 10);

    while ((c = json[index++])) {
        if (inString) {
            if (c == '}') {
                jsonArray[*count].key[len] = '\0';
                inString = false;
                (*count)++;

                if (strlen(jsonArray[*count - 1].key) >= 24) {
                    fprintf(stderr, "Error: Key name too long\n");
                    free(jsonArray);
                    return;
                }

                index--;
                continue;
            }
            len++;
        }

        if (c == '{' || c == '}') {
            if (!inString) {
                if (json[index - 1] != '\\') {
                    jsonArray[*count].key[len] = '\0';
                    index--;
                    (*count)++;

                    if (strlen(jsonArray[*count - 1].key) >= 24) {
                        fprintf(stderr, "Error: Key name too long\n");
                        free(jsonArray);
                        return;
                    }
                }
            }
            inString = false;
            continue;
        }

        if (c == ':' && !inString) {
            inString = true;
            jsonArray[*count].key[len] = '\0';
            continue;
        }

        if (inString && (c != '\\' || json[index - 1] != '\\')) {
            jsonArray[*count].value.str[len] = c;
            len++;
        } else {
            if (!inString) {
                jsonArray[*count].value.intVal = strtol(json + index - 1, NULL, 10);
                index -= (strlen(json + index - 1) + 1);
            }
        }
    }

    free(jsonArray + *count);
    jsonArray = realloc(jsonArray, sizeof(JsonKeyValue) * (*count + 1));

    if (strlen(json[index - 1]) > 0) {
        jsonArray[*count].key[len] = '\0';
        (*count)++;
    }

    jsonArray[*count].key[0] = '\0';
}

int main() {
    const char json[] = "{\"name\":\"hello world\",\"age\":25}";
    JsonKeyValue *jsonArray = NULL;
    int count = 0;

    parseJSON(json, jsonArray, &count);

    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", jsonArray[i].key, jsonArray[i].value.str);

        if (strcmp(jsonArray[i].key, "age") == 0) {
            printf("Age is: %d\n", jsonArray[i].value.intVal);
            break;
        }
    }

    free(jsonArray);

    return 0;
}