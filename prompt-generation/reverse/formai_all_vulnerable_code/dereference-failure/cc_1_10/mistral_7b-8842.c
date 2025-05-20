//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_ARRAY_SIZE 1000
#define MAX_STRING_SIZE 256
#define MAX_FILES 10

typedef struct {
    int id;
    char name[MAX_STRING_SIZE];
    int age;
} Person;

void readFile(char *filename, char *buffer, int *size) {
    int fileDescriptor = open(filename, O_RDONLY);
    if (fileDescriptor < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    ssize_t bytesRead = read(fileDescriptor, buffer, *size);
    if (bytesRead < 0) {
        perror("Error reading file");
        exit(EXIT_FAILURE);
    }

    close(fileDescriptor);
    buffer[bytesRead] = '\0';
}

void printArray(Person array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Person %d: id=%d, name=%s, age=%d\n", i, array[i].id, array[i].name, array[i].age);
    }
}

void sortArray(Person array[], int size, int (*comparator)(const void *, const void *)) {
    qsort(array, size, sizeof(Person), comparator);
}

int comparePersons(const void *person1, const void *person2) {
    Person *person1Ptr = (Person *)person1;
    Person *person2Ptr = (Person *)person2;

    if (person1Ptr->age < person2Ptr->age) {
        return -1;
    } else if (person1Ptr->age > person2Ptr->age) {
        return 1;
    } else {
        return strcmp(person1Ptr->name, person2Ptr->name);
    }
}

int main() {
    Person people[MAX_ARRAY_SIZE];
    int numPeople = 0;

    for (int i = 0; i < MAX_FILES; i++) {
        char filename[MAX_STRING_SIZE];
        sprintf(filename, "input%d.txt", i + 1);

        char buffer[MAX_STRING_SIZE];
        int size = sizeof(buffer);

        readFile(filename, buffer, &size);

        sscanf(buffer, "%d%s%d", &people[numPeople].id, people[numPeople].name, &people[numPeople].age);

        numPeople++;
    }

    sortArray(people, numPeople, comparePersons);
    printArray(people, numPeople);

    return EXIT_SUCCESS;
}