//Falcon-180B DATASET v1.0 Category: Memory management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
} Person;

void *my_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: Out of memory!\n");
        exit(1);
    }
    return ptr;
}

void my_free(void *ptr) {
    free(ptr);
}

int main() {
    char *str1 = my_malloc(10);
    char *str2 = my_malloc(20);
    int *arr1 = my_malloc(sizeof(int) * 5);
    int *arr2 = my_malloc(sizeof(int) * 10);
    Person *person1 = my_malloc(sizeof(Person));
    Person *person2 = my_malloc(sizeof(Person));

    strcpy(str1, "Hello");
    strcpy(str2, "World");
    for (int i = 0; i < 5; i++) {
        arr1[i] = i;
    }
    for (int i = 0; i < 10; i++) {
        arr2[i] = i;
    }
    person1->name = my_malloc(10);
    strcpy(person1->name, "Alice");
    person1->age = 25;
    person2->name = my_malloc(10);
    strcpy(person2->name, "Bob");
    person2->age = 30;

    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    printf("Name 1: %s\n", person1->name);
    printf("Age 1: %d\n", person1->age);
    printf("Name 2: %s\n", person2->name);
    printf("Age 2: %d\n", person2->age);

    my_free(str1);
    my_free(str2);
    my_free(arr1);
    my_free(arr2);
    my_free(person1->name);
    my_free(person1);
    my_free(person2->name);
    my_free(person2);

    return 0;
}