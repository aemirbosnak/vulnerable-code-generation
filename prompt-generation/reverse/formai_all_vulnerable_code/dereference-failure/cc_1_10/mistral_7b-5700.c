//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void print_array(int arr[], int size);
void bucket_sort(int arr[], int size);
int get_bucket(int value, int bucket_size);
void* bucket_alloc(int size);
void bucket_free(void* ptr, int size);

int main() {
    int arr[MAX];
    int size, i;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter %d integers: ", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    bucket_sort(arr, size);
    print_array(arr, size);

    return 0;
}

void print_array(int arr[], int size) {
    int i;
    printf("Sorted array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int arr[], int size) {
    int i, bucket, *temp_arr;
    int bucket_size = MAX / 3, num_buckets = (MAX + 2) / 3;

    temp_arr = (void*) malloc(num_buckets * sizeof(int*));

    for (i = 0; i < num_buckets; i++) {
        ((int**) temp_arr)[i] = (int*) bucket_alloc(bucket_size);
    }

    for (i = 0; i < size; i++) {
        bucket = get_bucket(arr[i], bucket_size);
        ((int**) temp_arr)[bucket][((int)arr[i] - (get_bucket(0, bucket_size) * bucket_size)) / bucket_size]++;
    }

    for (i = 0; i < num_buckets; i++) {
        int index = 0, j;
        for (j = 0; j < bucket_size; j++) {
            while (((int**) temp_arr)[i][j] != NULL) {
                arr[index++] = ((int*)((int**) temp_arr)[i][j++]);
            }
        }
    }

    for (i = 0; i < num_buckets; i++) {
        bucket_free(((int**) temp_arr)[i], bucket_size * sizeof(int));
    }
    free(temp_arr);
}

int get_bucket(int value, int bucket_size) {
    return (value - get_bucket(0, bucket_size)) / bucket_size;
}

void* bucket_alloc(int size) {
    void* ptr = malloc(size * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    memset(ptr, 0, size * sizeof(int));
    return ptr;
}

void bucket_free(void* ptr, int size) {
    free(ptr);
}