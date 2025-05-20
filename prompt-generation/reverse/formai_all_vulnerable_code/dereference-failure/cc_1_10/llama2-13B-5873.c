//LLAMA2-13B DATASET v1.0 Category: Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_STRING_LENGTH 1024
#define MAX_INT 2147483647

// Structure to store information about a person
typedef struct {
    char name[MAX_STRING_LENGTH];
    int age;
    float height;
    double salary;
} person_t;

// Function to create a new person
person_t* create_person(char* name, int age, float height, double salary) {
    person_t* new_person = (person_t*) malloc(sizeof(person_t));
    strcpy(new_person->name, name);
    new_person->age = age;
    new_person->height = height;
    new_person->salary = salary;
    return new_person;
}

// Function to print information about a person
void print_person(person_t* person) {
    printf("Name: %s\nAge: %d\nHeight: %f\nSalary: %lf\n", person->name, person->age, person->height, person->salary);
}

// Function to calculate the area of a circle
double calculate_circle_area(float radius) {
    return 3.14159 * radius * radius;
}

// Function to calculate the perimeter of a circle
double calculate_circle_perimeter(float radius) {
    return 2 * 3.14159 * radius;
}

int main() {
    // Create a new person
    person_t* john = create_person("John Doe", 35, 1.8, 50000.0);

    // Print information about John
    print_person(john);

    // Calculate the area of a circle with a radius of 5
    double circle_area = calculate_circle_area(5.0);
    printf("Circle area: %f\n", circle_area);

    // Calculate the perimeter of a circle with a radius of 5
    double circle_perimeter = calculate_circle_perimeter(5.0);
    printf("Circle perimeter: %f\n", circle_perimeter);

    // Free the memory allocated for John
    free(john);

    return 0;
}