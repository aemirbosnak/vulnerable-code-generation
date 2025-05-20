//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define TAB_SIZE 16
#define MAX_STR_LEN 1024
#define MIN_TO_MATCH 3

typedef struct {
    char str[MAX_STR_LEN];
    int index;
} Element;

void init_table(Element table[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        table[i].index = -1;
    }
}

int hash_func(char *str, int table_size) {
    int hash = 0;
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        hash = (hash * TAB_SIZE + str[i]) % table_size;
    }

    return hash;
}

void jk_search(Element table[], char *find, int size) {
    int i, j, h;

    for (i = 0; i < size; i++) {
        h = hash_func(table[i].str, TAB_SIZE);

        if (table[h].index == -1) {
            strncpy(table[h].str, find, MIN_TO_MATCH - 1);
            table[h].index = i;
            break;
        }

        if (strncmp(table[h].str, find, MIN_TO_MATCH - 1) == 0) {
            printf("Found: %s at position %d.\n", find, table[h].index);
            exit(0);
        }
    }
}

int main() {
    int i, n;
    Element *arr;
    char str[MAX_STR_LEN];

    printf("Enter the number of strings: ");
    scanf("%d", &n);

    arr = (Element *) calloc(n, sizeof(Element));

    srand(time(NULL));

    printf("Enter %d strings:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%s", str);
        strcpy(arr[i].str, str);
        arr[i].index = -1;
    }

    printf("Enter the string to search: ");
    scanf("%s", str);

    init_table(arr, n);

    jk_search(arr, str, n);

    free(arr);
    return 0;
}