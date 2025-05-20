//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[MAX_SIZE];
    int age;
} Person;

int compare(const void *a, const void *b) {
    Person *personA = (Person *) a;
    Person *personB = (Person *) b;

    if (personA->age > personB->age) {
        return 1;
    } else if (personA->age < personB->age) {
        return -1;
    } else {
        return 0;
    }
}

void swap(void *a, void *b, size_t size) {
    char *ptrA = (char *) a;
    char *ptrB = (char *) b;

    for (int i = 0; i < size; i++) {
        char temp = *ptrA;
        *ptrA = *ptrB;
        *ptrB = temp;

        ptrA++;
        ptrB++;
    }
}

void quickSort(Person *array, int left, int right) {
    int i = left;
    int j = right;
    Person pivot = array[(left + right) / 2];

    while (i <= j) {
        while (array[i].age < pivot.age) {
            i++;
        }
        while (array[j].age > pivot.age) {
            j--;
        }
        if (i <= j) {
            swap(array + i, array + j, sizeof(Person));
            i++;
            j--;
        }
    }

    if (left < j) {
        quickSort(array, left, j);
    }
    if (i < right) {
        quickSort(array, i, right);
    }
}

int main() {
    Person array[MAX_SIZE];
    int size;

    printf("Enter the number of people: ");
    scanf("%d", &size);

    printf("Enter the name and age of each person:\n");
    for (int i = 0; i < size; i++) {
        scanf("%s %d", array[i].name, &array[i].age);
    }

    quickSort(array, 0, size - 1);

    printf("Sorted by age:\n");
    for (int i = 0; i < size; i++) {
        printf("%s %d\n", array[i].name, array[i].age);
    }

    return 0;
}