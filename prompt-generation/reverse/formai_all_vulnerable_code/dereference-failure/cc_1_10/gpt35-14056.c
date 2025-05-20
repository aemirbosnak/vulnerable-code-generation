//FormAI DATASET v1.0 Category: Database querying ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a structure to hold the data from the database
typedef struct {
    int id;
    char name[50];
    int age;
    float weight;
} Person;

// define a function to query the database given multiple variables
Person* queryDatabase(int id, char* name, int age, float weight) {

    // open the database file
    FILE *databaseFile;
    databaseFile = fopen("database.txt", "r");

    // check if the file was successfully opened
    if (databaseFile == NULL) {
        printf("Error: could not open database file\n");
        return NULL;
    }

    // allocate memory for the result array
    Person* result = (Person*) malloc(sizeof(Person));

    // read from the file line by line
    char line[100];
    int index = 0;
    while (fgets(line, sizeof(line), databaseFile)) {

        // tokenize the line and store the values in a new Person struct
        Person* tempPerson = (Person*) malloc(sizeof(Person));

        char* token = strtok(line, ",");
        tempPerson->id = atoi(token);

        token = strtok(NULL, ",");
        strcpy(tempPerson->name, token);

        token = strtok(NULL, ",");
        tempPerson->age = atoi(token);

        token = strtok(NULL, ",");
        tempPerson->weight = atof(token);

        // check if the values match the query
        if ((id == -1 || id == tempPerson->id) &&
            (name == NULL || strcmp(name, tempPerson->name) == 0) &&
            (age == -1 || age == tempPerson->age) &&
            (weight == -1.0 || weight == tempPerson->weight)) {

            // add the Person to the result array
            result = (Person*) realloc(result, (index + 1) * sizeof(Person));
            result[index] = *tempPerson;
            index++;
        }

        free(tempPerson);
    }

    // close the file and return the results
    fclose(databaseFile);

    if (index == 0) {
        printf("No results found\n");
        return NULL;
    } else {
        return result;
    }
}

// sample usage
int main() {

    // query the database for people named "John" who are 25 years old and weigh 160.5
    Person* result = queryDatabase(-1, "John", 25, 160.5);

    // print the results
    if(result != NULL){
        for (int i = 0; i < sizeof(result); i++) {
            printf("ID: %d, Name: %s, Age: %d, Weight: %.2f\n",
                result[i].id, result[i].name, result[i].age, result[i].weight);
        }
    }

    return 0;
}