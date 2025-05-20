//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1024

char *parse_string(char *json_str, char *key);

int main ()
{
    char json[MAX_SIZE];
    char *value;
    char *key = "name";

    printf("Enter a JSON string: ");
    fgets(json, MAX_SIZE, stdin);

    value = parse_string(json, key);

    if (value != NULL) {
        printf("%s: %s\n", key, value);
    } else {
        printf("Error: Key not found\n");
    }

    return 0;
}

char *parse_string(char *json_str, char *key)
{
    char *start = strstr(json_str, key);

    if (start == NULL) {
        return NULL;
    }

    char *value_start = strstr(start, ":");
    int value_len = 0;
    char *value_end = NULL;
    char *value = NULL;

    if (value_start != NULL) {
        value_end = strstr(value_start, ",");
        if (value_end == NULL) {
            value_end = strstr(value_start, "}");
        }
        if (value_end != NULL) {
            value_len = value_end - (value_start + 1);
            value = malloc(sizeof(char) * (value_len + 1));
            strncpy(value, (value_start + 2), value_len - 2);
            value[value_len - 2] = '\0';
        }
    }

    return value;
}