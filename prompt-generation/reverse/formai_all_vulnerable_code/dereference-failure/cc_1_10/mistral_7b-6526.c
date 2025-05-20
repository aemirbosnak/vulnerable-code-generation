//MISTRAL-7B DATASET v1.0 Category: Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_ARRAY_SIZE 1000
#define BUFFER_SIZE 1024

void torvalds_sort(int *arr, int size) {
    int i, j, tmp;
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int main(int argc, char **argv) {
    int arr[MAX_ARRAY_SIZE];
    int size, i;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <integer_values_separated_by_spaces>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    size = 0;
    for (i = 1; i < argc; i++) {
        arr[size++] = atoi(strtok(argv[i], " "));
    }

    torvalds_sort(arr, size);

    printf("Sorted array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    for (i = 0; i < size; i++) {
        write(fd, &arr[i], sizeof(int));
    }
    close(fd);

    return EXIT_SUCCESS;
}