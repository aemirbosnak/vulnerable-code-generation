//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the data structures
typedef struct {
    int age;
    char gender;
    char occupation[50];
    float salary;
} Person;

typedef struct {
    int num_people;
    Person *people;
} Dataset;

// Create a new dataset
Dataset* create_dataset() {
    Dataset *dataset = malloc(sizeof(Dataset));
    dataset->num_people = 0;
    dataset->people = NULL;
    return dataset;
}

// Add a person to the dataset
void add_person(Dataset *dataset, Person person) {
    dataset->num_people++;
    dataset->people = realloc(dataset->people, dataset->num_people * sizeof(Person));
    dataset->people[dataset->num_people - 1] = person;
}

// Print the dataset
void print_dataset(Dataset *dataset) {
    for (int i = 0; i < dataset->num_people; i++) {
        Person person = dataset->people[i];
        printf("Person %d:\n", i + 1);
        printf("    Age: %d\n", person.age);
        printf("    Gender: %c\n", person.gender);
        printf("    Occupation: %s\n", person.occupation);
        printf("    Salary: %.2f\n", person.salary);
        printf("\n");
    }
}

// Find the average age of the people in the dataset
float average_age(Dataset *dataset) {
    float sum = 0;
    for (int i = 0; i < dataset->num_people; i++) {
        sum += dataset->people[i].age;
    }
    return sum / dataset->num_people;
}

// Find the most common occupation in the dataset
char* most_common_occupation(Dataset *dataset) {
    int counts[50] = {0};
    for (int i = 0; i < dataset->num_people; i++) {
        counts[i] = 0;
        for (int j = 0; j < dataset->num_people; j++) {
            if (strcmp(dataset->people[i].occupation, dataset->people[j].occupation) == 0) {
                counts[i]++;
            }
        }
    }

    int max_count = 0;
    int max_index = 0;
    for (int i = 0; i < 50; i++) {
        if (counts[i] > max_count) {
            max_count = counts[i];
            max_index = i;
        }
    }

    return dataset->people[max_index].occupation;
}

// Find the highest salary in the dataset
float highest_salary(Dataset *dataset) {
    float max_salary = 0;
    for (int i = 0; i < dataset->num_people; i++) {
        if (dataset->people[i].salary > max_salary) {
            max_salary = dataset->people[i].salary;
        }
    }
    return max_salary;
}

// Find the lowest salary in the dataset
float lowest_salary(Dataset *dataset) {
    float min_salary = 100000000;
    for (int i = 0; i < dataset->num_people; i++) {
        if (dataset->people[i].salary < min_salary) {
            min_salary = dataset->people[i].salary;
        }
    }
    return min_salary;
}

// Main function
int main() {
    // Create a new dataset
    Dataset *dataset = create_dataset();

    // Add some people to the dataset
    Person person1 = {25, 'M', "Software Engineer", 100000};
    add_person(dataset, person1);
    Person person2 = {30, 'F', "Doctor", 120000};
    add_person(dataset, person2);
    Person person3 = {35, 'M', "Lawyer", 150000};
    add_person(dataset, person3);
    Person person4 = {40, 'F', "Teacher", 80000};
    add_person(dataset, person4);
    Person person5 = {45, 'M', "Engineer", 110000};
    add_person(dataset, person5);

    // Print the dataset
    printf("Dataset:\n");
    print_dataset(dataset);

    // Find the average age of the people in the dataset
    float average_age_result = average_age(dataset);
    printf("Average age: %.2f\n", average_age_result);

    // Find the most common occupation in the dataset
    char *most_common_occupation_result = most_common_occupation(dataset);
    printf("Most common occupation: %s\n", most_common_occupation_result);

    // Find the highest salary in the dataset
    float highest_salary_result = highest_salary(dataset);
    printf("Highest salary: %.2f\n", highest_salary_result);

    // Find the lowest salary in the dataset
    float lowest_salary_result = lowest_salary(dataset);
    printf("Lowest salary: %.2f\n", lowest_salary_result);

    // Free the dataset
    free(dataset->people);
    free(dataset);

    return 0;
}