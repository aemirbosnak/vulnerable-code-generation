//Falcon2-11B DATASET v1.0 Category: Database querying ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main() {
    // Funny C Database Querying Program
    printf("--------------------------------------\n");
    printf("| I am a funny C Database Querying |\n");
    printf("| Program, what else could I be? |\n");
    printf("--------------------------------------\n");

    // Connecting to the database
    FILE *db_file = fopen("database.txt", "r");
    if (db_file == NULL) {
        printf("Error: Unable to connect to the database\n");
        return 1;
    }

    // Reading the data from the database
    char line[100];
    while (fgets(line, sizeof(line), db_file)) {
        // Parsing the data from the line
        char* name = strtok(line, ", ");
        char* age = strtok(NULL, ", ");
        char* gender = strtok(NULL, ", ");
        char* hobby = strtok(NULL, ", ");

        // Printing the parsed data in a funny way
        printf("--------------------------------------\n");
        printf("| Name: %s\n", name);
        printf("| Age: %s\n", age);
        printf("| Gender: %s\n", gender);
        printf("| Hobby: %s\n", hobby);
        printf("--------------------------------------\n");

        // Freeing the allocated memory
        free(name);
        free(age);
        free(gender);
        free(hobby);
    }

    // Closing the database connection
    fclose(db_file);

    printf("--------------------------------------\n");
    printf("| That's all folks! Thanks for reading |\n");
    printf("--------------------------------------\n");

    return 0;
}