//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *data;
    int size;
} String;

int str_compare(const void *a, const void *b) {
    return strcmp(*(String **)a, *(String **)b);
}

void str_free(void *ptr) {
    String *string = (String *)ptr;
    if (string!= NULL) {
        free(string->data);
        free(string);
    }
}

int main() {
    String *array[MAX_SIZE];
    int count = 0;
    char input[MAX_SIZE];

    while (fgets(input, MAX_SIZE, stdin)!= NULL) {
        if (count >= MAX_SIZE) {
            printf("Error: Maximum size reached.\n");
            break;
        }
        array[count] = (String *)malloc(sizeof(String));
        array[count]->data = strdup(input);
        array[count]->size = strlen(input);
        count++;
    }

    qsort(array, count, sizeof(String *), str_compare);

    printf("Sorted strings:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", array[i]->data);
        free(array[i]->data);
        free(array[i]);
    }

    return 0;
}