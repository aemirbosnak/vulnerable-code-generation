//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *data;
    int size;
} String;

String *create_string(char *data) {
    String *new_string = (String *)malloc(sizeof(String));
    new_string->data = data;
    new_string->size = strlen(data);
    return new_string;
}

void print_string(String *string) {
    printf("%s\n", string->data);
}

int compare_strings(String *s1, String *s2) {
    return strcmp(s1->data, s2->data);
}

int main() {
    String *array[MAX_SIZE];
    int count = 0;

    printf("Enter strings to search (press enter to finish):\n");
    while (scanf("%s", array[count]->data)!= EOF) {
        count++;
        if (count == MAX_SIZE) {
            printf("Array full. Cannot add more strings.\n");
            break;
        }
    }

    printf("Enter string to search for:\n");
    scanf("%s", array[0]->data);

    int result = binary_search(array, count, compare_strings);

    if (result == -1) {
        printf("String not found.\n");
    } else {
        printf("String found at index %d.\n", result);
    }

    return 0;
}

int binary_search(String *array, int count, int (*compare)(String *, String *)) {
    int left = 0;
    int right = count - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        int cmp_result = compare(array + mid, array);

        if (cmp_result == 0) {
            return mid;
        } else if (cmp_result < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}