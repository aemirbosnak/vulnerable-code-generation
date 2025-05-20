//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_BUCKET_SIZE 100
#define MAX_STRING_LENGTH 100

typedef struct {
    char *name;
    int age;
} Person;

void swap(Person *a, Person *b) {
    Person temp = *a;
    *a = *b;
    *b = temp;
}

int compare(Person *a, Person *b) {
    return strcmp(a->name, b->name);
}

void print_person(Person *p) {
    printf("%s (%d)\n", p->name, p->age);
}

void bucket_sort(Person *people, int num_people) {
    Person *buckets[MAX_BUCKET_SIZE];
    int bucket_sizes[MAX_BUCKET_SIZE] = {0};

    for (int i = 0; i < num_people; i++) {
        int index = strlen(people[i].name) % MAX_BUCKET_SIZE;
        buckets[index] = &people[i];
        bucket_sizes[index]++;
    }

    for (int i = 0; i < MAX_BUCKET_SIZE; i++) {
        if (bucket_sizes[i] > 0) {
            qsort(buckets[i], bucket_sizes[i], sizeof(Person), compare);
        }
    }

    int index = 0;
    for (int i = 0; i < MAX_BUCKET_SIZE; i++) {
        if (bucket_sizes[i] > 0) {
            for (int j = 0; j < bucket_sizes[i]; j++) {
                people[index++] = *(buckets[i] + j);
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int num_people = rand() % 100 + 1;
    Person *people = malloc(num_people * sizeof(Person));

    for (int i = 0; i < num_people; i++) {
        people[i].name = malloc((rand() % MAX_STRING_LENGTH + 1) * sizeof(char));
        sprintf(people[i].name, "Person %d", i);
        people[i].age = rand() % 100;
    }

    printf("Before sorting:\n");
    for (int i = 0; i < num_people; i++) {
        print_person(&people[i]);
    }

    bucket_sort(people, num_people);

    printf("\nAfter sorting:\n");
    for (int i = 0; i < num_people; i++) {
        print_person(&people[i]);
    }

    for (int i = 0; i < num_people; i++) {
        free(people[i].name);
    }
    free(people);

    return 0;
}