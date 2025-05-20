//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_ARRAY_SIZE 10000
#define VALUE_TO_FIND 42

int linus_torvalds_search(int arr[], int size, int value) {
 int i, j;

 if (size <= 0) {
 printf("Array size is zero or negative\n");
 exit(EXIT_FAILURE);
 }

 i = 0;
 j = size - 1;

 while (i <= j) {
 int m = (i + j) / 2;

 if (arr[m] == value) {
 printf("Value %d found at index %d\n", value, m);
 return m;
 }

 if (arr[m] < value) {
 i = m + 1;
 } else {
 j = m - 1;
 }
 }

 printf("Value %d not found in array\n", value);
 return -1;
}

int main(int argc, char *argv[]) {
 int arr[MAX_ARRAY_SIZE];
 int size;

 if (argc < 2) {
 printf("Usage: %s <size of array>\n", argv[0]);
 exit(EXIT_FAILURE);
 }

 size = atoi(argv[1]);

 if (size > MAX_ARRAY_SIZE) {
 printf("Array size exceeds maximum allowed size\n");
 exit(EXIT_FAILURE);
 }

 for (int i = 0; i < size; i++) {
 arr[i] = rand() % 100;
 printf("Array element %d: %d\n", i, arr[i]);
 }

 printf("Finding value %d...\n", VALUE_TO_FIND);
 int index = linus_torvalds_search(arr, size, VALUE_TO_FIND);

 if (index != -1) {
 printf("Found value %d at index %d\n", VALUE_TO_FIND, index);
 } else {
 printf("Value %d not found in array\n", VALUE_TO_FIND);
 }

 return EXIT_SUCCESS;
}