//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the data structures
typedef struct {
    char *name;
    int age;
    double weight;
    double height;
    int steps;
    int calories;
    int distance;
} Person;

typedef struct {
    Person *person;
    time_t start_time;
    time_t end_time;
    int duration;
    int steps;
    int calories;
    int distance;
} Activity;

// Create a new person
Person *create_person(char *name, int age, double weight, double height) {
    Person *person = malloc(sizeof(Person));
    person->name = name;
    person->age = age;
    person->weight = weight;
    person->height = height;
    person->steps = 0;
    person->calories = 0;
    person->distance = 0;
    return person;
}

// Create a new activity
Activity *create_activity(Person *person, time_t start_time, time_t end_time) {
    Activity *activity = malloc(sizeof(Activity));
    activity->person = person;
    activity->start_time = start_time;
    activity->end_time = end_time;
    activity->duration = end_time - start_time;
    activity->steps = 0;
    activity->calories = 0;
    activity->distance = 0;
    return activity;
}

// Add steps to an activity
void add_steps(Activity *activity, int steps) {
    activity->steps += steps;
    activity->calories += steps * 0.05;
    activity->distance += steps * 0.0005;
}

// Print the details of a person
void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Weight: %.2f\n", person->weight);
    printf("Height: %.2f\n", person->height);
    printf("Steps: %d\n", person->steps);
    printf("Calories: %d\n", person->calories);
    printf("Distance: %.2f\n", person->distance);
}

// Print the details of an activity
void print_activity(Activity *activity) {
    printf("Person: %s\n", activity->person->name);
    printf("Start time: %s", ctime(&activity->start_time));
    printf("End time: %s", ctime(&activity->end_time));
    printf("Duration: %d seconds\n", activity->duration);
    printf("Steps: %d\n", activity->steps);
    printf("Calories: %d\n", activity->calories);
    printf("Distance: %.2f\n", activity->distance);
}

// Main function
int main() {
    // Create a new person
    Person *person = create_person("John Doe", 30, 75.0, 1.80);

    // Create a new activity
    Activity *activity = create_activity(person, time(NULL), time(NULL) + 3600);

    // Add steps to the activity
    add_steps(activity, 10000);

    // Print the details of the person
    print_person(person);

    // Print the details of the activity
    print_activity(activity);

    return 0;
}