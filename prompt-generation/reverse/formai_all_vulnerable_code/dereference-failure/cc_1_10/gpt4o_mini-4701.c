//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold data for each entry
typedef struct {
    char name[50];
    int age;
    char gender[10];
    float height;
    float weight;
} Person;

// Function to compute the BMI of a person
float computeBMI(float weight, float height) {
    return weight / (height * height);
}

// Function to sort persons based on BMI
void sortPersonsByBMI(Person *persons, int count) {
    for(int i = 0; i < count - 1; i++) {
        for(int j = i + 1; j < count; j++) {
            float bmi1 = computeBMI(persons[i].weight, persons[i].height);
            float bmi2 = computeBMI(persons[j].weight, persons[j].height);
            if(bmi1 > bmi2) {
                // Swap persons
                Person temp = persons[i];
                persons[i] = persons[j];
                persons[j] = temp;
            }
        }
    }
}

// Function to display person details
void displayPersons(const Person *persons, int count) {
    printf("\nName\t\tAge\tGender\tHeight\tWeight\tBMI\n");
    printf("-------------------------------------------------------\n");
    for(int i = 0; i < count; i++) {
        float bmi = computeBMI(persons[i].weight, persons[i].height);
        printf("%s\t\t%d\t%s\t%.2f\t%.2f\t%.2f\n", 
                persons[i].name, 
                persons[i].age, 
                persons[i].gender, 
                persons[i].height, 
                persons[i].weight, 
                bmi);
    }
}

int main() {
    int n = 5; // Number of persons
    Person *persons = malloc(n * sizeof(Person));
    
    // Sample data entry
    strcpy(persons[0].name, "Alice Johnson");
    persons[0].age = 25;
    strcpy(persons[0].gender, "Female");
    persons[0].height = 1.65;
    persons[0].weight = 55.0;

    strcpy(persons[1].name, "Bob Smith");
    persons[1].age = 30;
    strcpy(persons[1].gender, "Male");
    persons[1].height = 1.80;
    persons[1].weight = 85.0;

    strcpy(persons[2].name, "Charlie Brown");
    persons[2].age = 22;
    strcpy(persons[2].gender, "Male");
    persons[2].height = 1.70;
    persons[2].weight = 70.0;

    strcpy(persons[3].name, "Diana Prince");
    persons[3].age = 28;
    strcpy(persons[3].gender, "Female");
    persons[3].height = 1.60;
    persons[3].weight = 50.0;

    strcpy(persons[4].name, "Ethan Hunt");
    persons[4].age = 35;
    strcpy(persons[4].gender, "Male");
    persons[4].height = 1.75;
    persons[4].weight = 80.0;

    printf("Persons Before Sorting by BMI:");
    displayPersons(persons, n);
    
    // Sort based on BMI
    sortPersonsByBMI(persons, n);
    
    printf("\nPersons After Sorting by BMI:");
    displayPersons(persons, n);
    
    free(persons); // Free the dynamically allocated memory
    return 0;
}