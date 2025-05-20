//FormAI DATASET v1.0 Category: Data mining ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

/* Define a struct to represent a person */
struct Person {
    int age;
    char gender;
    float height;
};

/* Define a function to generate random data */
void generateData(struct Person* people, int size) {
    for (int i = 0; i < size; i++) {
        people[i].age = rand() % 80 + 18;
        people[i].gender = rand() % 2 == 0 ? 'M' : 'F';
        people[i].height = ((float)(rand() % 200) + 100) / 100;
    }
}

/* Define a function to print one person's data */
void printPerson(struct Person person) {
    printf("Age: %d, Gender: %c, Height: %.2f\n", person.age, person.gender, person.height);
}

/* Define a function to find the oldest person */
void findOldest(struct Person* people, int size) {
    int maxAgeIndex = 0;
    for (int i = 1; i < size; i++) {
        if (people[i].age > people[maxAgeIndex].age) {
            maxAgeIndex = i;
        }
    }
    printf("The oldest person is:\n");
    printPerson(people[maxAgeIndex]);
}

/* Define a function to find the tallest person of a given gender */
void findTallest(struct Person* people, int size, char gender) {
    int maxHeightIndex = -1;
    for (int i = 0; i < size; i++) {
        if (people[i].gender == gender && (maxHeightIndex == -1 || people[i].height > people[maxHeightIndex].height)) {
            maxHeightIndex = i;
        }
    }
    if (maxHeightIndex == -1) {
        printf("No people of gender %c found\n", gender);
    } else {
        printf("The tallest person of gender %c is:\n", gender);
        printPerson(people[maxHeightIndex]);
    }
}

int main() {
    int size = 100;
    struct Person* people = malloc(size * sizeof(struct Person));

    generateData(people, size);

    findOldest(people, size);

    findTallest(people, size, 'M');
    findTallest(people, size, 'F');

    free(people);
    return 0;
}