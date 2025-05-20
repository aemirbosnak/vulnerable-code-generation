//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: random
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MAX_ARRAY_SIZE 100
#define CHECKSUM_SIZE 4

typedef struct {
    int size;
    int32_t nums[MAX_ARRAY_SIZE];
} Array;

void print_array(Array arr) {
    printf("Array: [");
    for (int i = 0; i < arr.size; ++i) {
        printf("%d, ", arr.nums[i]);
    }
    printf("\b\b]");
}

int32_t calculate_checksum(const int32_t* arr, int size) {
    int32_t checksum = 0;
    for (int i = 0; i < size; ++i) {
        checksum += arr[i];
    }
    return checksum;
}

void print_checksum(const int32_t* arr, int size) {
    int32_t checksum = calculate_checksum(arr, size);
    printf("Checksum: %x\n", checksum);
}

int main() {
    Array arr = {5, {1, 2, 3, 4, 5}};

    print_array(arr);
    printf("\n");
    print_checksum(arr.nums, arr.size);

    int32_t new_num = 6;
    arr.nums[4] = new_num;

    print_array(arr);
    printf("\n");
    print_checksum(arr.nums, arr.size);

    int32_t checksum_arr[CHECKSUM_SIZE];
    memcpy(checksum_arr, &arr.size, sizeof(int32_t));
    memcpy(&checksum_arr[1], &arr.nums, sizeof(int32_t) * MAX_ARRAY_SIZE);

    printf("Checksum stored as array: [");
    for (int i = 0; i < CHECKSUM_SIZE; ++i) {
        printf("%x, ", checksum_arr[i]);
    }
    printf("\b\b]\n");

    int32_t computed_checksum = calculate_checksum(arr.nums, arr.size);
    for (int i = 0; i < CHECKSUM_SIZE; ++i) {
        if (checksum_arr[i] != computed_checksum) {
            printf("Warning: checksums do not match!\n");
            break;
        }
    }

    if (checksum_arr[0] == computed_checksum && checksum_arr[1] == computed_checksum) {
        printf("Checksums match!\n");
    }

    return 0;
}