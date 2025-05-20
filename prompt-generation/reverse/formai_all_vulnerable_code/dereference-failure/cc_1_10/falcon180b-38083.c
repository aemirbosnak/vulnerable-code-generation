//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

typedef struct {
    char *string;
    int length;
} StringInfo;

void init_string_info(StringInfo *info) {
    info->string = NULL;
    info->length = 0;
}

void set_string(StringInfo *info, char *str) {
    if (info->string!= NULL) {
        free(info->string);
    }
    info->string = strdup(str);
    info->length = strlen(str);
}

int compare_strings(StringInfo *info1, StringInfo *info2) {
    return strcmp(info1->string, info2->string);
}

int main() {
    int num_strings;
    StringInfo *strings;
    char input_string[MAX_STRING_LENGTH];
    char delimiter = '\n';

    printf("Enter the number of strings: ");
    scanf("%d", &num_strings);

    strings = malloc(num_strings * sizeof(StringInfo));

    for (int i = 0; i < num_strings; i++) {
        printf("Enter string %d: ", i + 1);
        fgets(input_string, MAX_STRING_LENGTH, stdin);
        input_string[strcspn(input_string, "\n")] = '\0';
        set_string(&strings[i], input_string);
    }

    qsort(strings, num_strings, sizeof(StringInfo), compare_strings);

    for (int i = 0; i < num_strings; i++) {
        printf("Sorted string %d: %s\n", i + 1, strings[i].string);
    }

    free(strings);

    return 0;
}