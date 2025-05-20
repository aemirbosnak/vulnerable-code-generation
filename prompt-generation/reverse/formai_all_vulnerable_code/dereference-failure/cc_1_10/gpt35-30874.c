//FormAI DATASET v1.0 Category: Computer Biology ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char* name;
    int age;
    bool is_male;
} Person;

typedef struct {
    char* name;
    char* species;
    int height;
} Animal;

// Function to simulate an asynchronous API request
void fetch_data(void (*callback)(void*, void*), void* data, void* error) {
    // We simulate network latency by using sleep
    sleep(1);

    // We generate some random data
    Person person = {"John", 24, true};
    Animal animal = {"Rex", "Dog", 50};

    // We randomly decide if there was an error or not
    bool has_error = rand() % 2;

    if (has_error) {
        strcpy((char*)error, "Could not fetch data");
        callback(NULL, error);
    } else {
        // We randomly decide whether to return a person or an animal
        bool is_person = rand() % 2;

        if (is_person) {
            callback(&person, NULL);
        } else {
            callback(&animal, NULL);
        }
    }
}

void print_person(Person* person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Is male? %s\n\n", person->is_male ? "true" : "false");
}

void print_animal(Animal* animal) {
    printf("Name: %s\n", animal->name);
    printf("Species: %s\n", animal->species);
    printf("Height: %d\n\n", animal->height);
}

void fetch_data_callback(void* result, void* error) {
    if (error != NULL) {
        printf("Error: %s\n", (char*)error);
    } else {
        if (result != NULL) {
            if (strcmp(((Person*)result)->name, "John") == 0) {
                print_person((Person*)result);
            } else {
                print_animal((Animal*)result);
            }
        }
    }
}

int main() {
    srand(time(NULL));

    // Allocate memory for the error string
    void* error = malloc(sizeof(char) * 100);

    // Trigger the asynchronous API request
    fetch_data(fetch_data_callback, NULL, error);

    // Wait for the API request to finish
    printf("Waiting for API request to finish...\n");
    sleep(2);

    free(error);
    return 0;
}