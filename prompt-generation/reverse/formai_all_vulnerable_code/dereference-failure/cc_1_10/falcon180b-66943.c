//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // maximum size of the array
#define MAX_CHARS 100 // maximum number of characters in a string
#define MAX_KEYS 100 // maximum number of keys to search for

int search(char **arr, int n, char *key);

int main() {
    int n;
    char *key;

    printf("Enter the number of strings: ");
    scanf("%d", &n);

    char **arr = (char **)malloc(n * sizeof(char *));
    if (arr == NULL) {
        printf("Memory error\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        arr[i] = (char *)malloc(MAX_SIZE * sizeof(char));
        if (arr[i] == NULL) {
            printf("Memory error\n");
            exit(1);
        }
        printf("Enter string %d: ", i+1);
        scanf("%s", arr[i]);
    }

    printf("Enter the key: ");
    scanf("%s", key);

    int result = search(arr, n, key);

    if (result == -1) {
        printf("Key not found\n");
    } else {
        printf("Key found at position %d\n", result + 1);
    }

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}

int search(char **arr, int n, char *key) {
    int result = -1;

    for (int i = 0; i < n; i++) {
        int j = 0;
        int k = 0;
        while (arr[i][j]!= '\0' && k < MAX_KEYS) {
            if (arr[i][j] == key[k]) {
                k++;
            } else {
                break;
            }
            j++;
        }
        if (k == strlen(key)) {
            result = i;
            break;
        }
    }

    return result;
}