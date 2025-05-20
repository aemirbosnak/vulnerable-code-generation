//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct {
    char *name;
    int age;
    char *occupation;
} Person;

typedef struct {
    Person *people;
    int num_people;
} Dataset;

// Function to create a new dataset
Dataset *create_dataset() {
    Dataset *dataset = malloc(sizeof(Dataset));
    dataset->people = NULL;
    dataset->num_people = 0;
    return dataset;
}

// Function to add a person to a dataset
void add_person(Dataset *dataset, Person *person) {
    dataset->people = realloc(dataset->people, (dataset->num_people + 1) * sizeof(Person));
    dataset->people[dataset->num_people] = *person;
    dataset->num_people++;
}

// Function to print a dataset
void print_dataset(Dataset *dataset) {
    for (int i = 0; i < dataset->num_people; i++) {
        printf("Name: %s\n", dataset->people[i].name);
        printf("Age: %d\n", dataset->people[i].age);
        printf("Occupation: %s\n\n", dataset->people[i].occupation);
    }
}

// Function to find the oldest person in a dataset
Person *find_oldest_person(Dataset *dataset) {
    Person *oldest_person = NULL;
    int max_age = 0;
    for (int i = 0; i < dataset->num_people; i++) {
        if (dataset->people[i].age > max_age) {
            max_age = dataset->people[i].age;
            oldest_person = &dataset->people[i];
        }
    }
    return oldest_person;
}

// Function to find the most common occupation in a dataset
char *find_most_common_occupation(Dataset *dataset) {
    char *most_common_occupation = NULL;
    int max_count = 0;
    for (int i = 0; i < dataset->num_people; i++) {
        int count = 0;
        for (int j = 0; j < dataset->num_people; j++) {
            if (strcmp(dataset->people[i].occupation, dataset->people[j].occupation) == 0) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            most_common_occupation = dataset->people[i].occupation;
        }
    }
    return most_common_occupation;
}

// Main function
int main() {
    // Create a new dataset
    Dataset *dataset = create_dataset();

    // Add some people to the dataset
    Person person1 = {"John Doe", 30, "Software Engineer"};
    add_person(dataset, &person1);
    Person person2 = {"Jane Doe", 25, "Teacher"};
    add_person(dataset, &person2);
    Person person3 = {"Bob Smith", 40, "Doctor"};
    add_person(dataset, &person3);

    // Print the dataset
    print_dataset(dataset);

    // Find the oldest person in the dataset
    Person *oldest_person = find_oldest_person(dataset);
    printf("The oldest person in the dataset is: %s\n", oldest_person->name);

    // Find the most common occupation in the dataset
    char *most_common_occupation = find_most_common_occupation(dataset);
    printf("The most common occupation in the dataset is: %s\n", most_common_occupation);

    // Free the dataset
    free(dataset->people);
    free(dataset);

    return 0;
}