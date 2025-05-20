//FormAI DATASET v1.0 Category: Data mining ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_ROWS 100

/* Struct to store information on a person */
typedef struct Person {
    char name[MAX_LENGTH];
    int age;
    char gender[MAX_LENGTH];
    float income;
} Person;

/* Function to read in data from a file */
int read_data(FILE* file, Person** people) {
    int num_people = 0;
    char buffer[MAX_LENGTH];
    
    while (fgets(buffer, MAX_LENGTH, file) != NULL) {
        if (num_people >= MAX_ROWS) {
            printf("Error: Maximum number of rows exceeded\n");
            return -1;
        }
        
        /* Create a new person struct to store information */
        Person* person = malloc(sizeof(Person));
        
        /* Parse the line from the file */
        char* token = strtok(buffer, ",");
        strcpy(person->name, token);
        
        /* Continue parsing data and storing it in the person struct */
        token = strtok(NULL, ",");
        person->age = atoi(token);
        
        token = strtok(NULL, ",");
        strcpy(person->gender, token);
        
        token = strtok(NULL, ",");
        person->income = atof(token);
        
        people[num_people] = person;
        num_people++;
    }
    
    return num_people;
}

/* Function to find the average income of people in a certain age range */
float avg_income_by_age(Person** people, int num_people, int min_age, int max_age) {
    int num_people_in_range = 0;
    float total_income = 0.0;
    
    for (int i = 0; i < num_people; i++) {
        Person* person = people[i];
        if (person->age >= min_age && person->age <= max_age) {
            num_people_in_range++;
            total_income += person->income;
        }
    }
    
    return total_income / num_people_in_range;
}

/* Main function */
int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    char* filename = argv[1];
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return 1;
    }
    
    /* Read in data from file */
    Person* people[MAX_ROWS];
    int num_people = read_data(file, people);
    fclose(file);
    
    if (num_people < 0) {
        /* Error occurred */
        return 1;
    }
    
    /* Find the average income of people aged 20-30 */
    float avg_income = avg_income_by_age(people, num_people, 20, 30);
    printf("Average income for people aged 20-30: %.2f\n", avg_income);
    
    /* Free memory allocated for person structs */
    for (int i = 0; i < num_people; i++) {
        free(people[i]);
    }
    
    return 0;
}