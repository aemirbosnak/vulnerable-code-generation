//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAX_INPUTS 10
#define LINE_LENGTH 100
#define INPUT_FILE "inputs.txt"
#define BUFFER_SIZE 4096

typedef struct {
    int id;
    char name[LINE_LENGTH];
} Person;

void read_inputs(Person inputs[MAX_INPUTS]) {
    int fd = open(INPUT_FILE, O_RDONLY);
    if (fd < 0) {
        perror("Error opening input file");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    int i = 0;
    while (fgets(buffer, BUFFER_SIZE, fd) != NULL) {
        sscanf(buffer, "%d %s", &inputs[i].id, inputs[i].name);
        i++;
        if (i == MAX_INPUTS) break;
    }

    close(fd);
}

void print_people(Person people[MAX_INPUTS]) {
    for (int i = 0; i < MAX_INPUTS; i++) {
        printf("%d %s\n", people[i].id, people[i].name);
    }
}

void merge(Person left[], int l_size, Person right[], int r_size, Person output[]) {
    int i = 0, j = 0, k = 0;

    while (i < l_size && j < r_size) {
        if (left[i].id <= right[j].id) {
            output[k++] = left[i++];
        } else {
            output[k++] = right[j++];
        }
    }

    while (i < l_size) {
        output[k++] = left[i++];
    }

    while (j < r_size) {
        output[k++] = right[j++];
    }
}

void merge_sort(Person people[], int size) {
    if (size <= 1) return;

    int mid = size / 2;
    Person left[mid], right[size - mid];

    for (int i = 0; i < mid; i++) left[i] = people[i];
    for (int i = mid; i < size; i++) right[i - mid] = people[i];

    merge_sort(left, mid);
    merge_sort(right, size - mid);
    merge(left, mid, right, size - mid, people);
}

int main() {
    Person inputs[MAX_INPUTS];
    read_inputs(inputs);

    printf("Unsorted:\n");
    print_people(inputs);

    merge_sort(inputs, MAX_INPUTS);

    printf("\nSorted:\n");
    print_people(inputs);

    return 0;
}