//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100
#define MIN_VALUE 1
#define MAX_VALUE 100

typedef struct {
    int value;
    char name[MAX_LENGTH];
} person;

person createPerson(void) {
    person p;
    p.value = rand() % (MAX_VALUE - MIN_VALUE) + MIN_VALUE;
    srand(time(NULL));
    strcpy(p.name, "Person ");
    p.name[sizeof(p.name) - 1] = '\0';
    return p;
}

void addPerson(person **array, int *size, int index) {
    if (*size == MAX_LENGTH) {
        printf("Array is full, cannot add more people!\n");
        return;
    }
    person p = createPerson();
    strcpy(array[index]->name, p.name);
    array[index]->value = p.value;
    (*size)++;
}

void printArray(person *array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d - %s\n", array[i].value, array[i].name);
    }
}

int main() {
    person *array = (person *)malloc(MAX_LENGTH * sizeof(person));
    int size = 0;

    while (1) {
        int index = rand() % (MAX_LENGTH - size);
        addPerson(&array, &size, index);
        if (size == MAX_LENGTH) {
            break;
        }
    }

    printArray(array, size);

    free(array);

    return 0;
}