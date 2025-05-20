//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Watson's case file
char *case_file = "case_file.txt";

// Function to parse the case file and extract relevant information
void parse_case_file() {
    // Open the case file
    FILE *file = fopen(case_file, "r");
    if (file == NULL) {
        printf("Error opening case file: %s\n", case_file);
        exit(1);
    }

    // Read the contents of the file into a buffer
    char *buffer = malloc(1000);
    fread(buffer, 1, 1000, file);

    // Close the file
    fclose(file);

    // Parse the buffer to extract relevant information
    char *suspect_name = strtok(buffer, ",");
    char *crime_scene = strtok(NULL, ",");
    char *time_of_crime = strtok(NULL, ",");
    char *evidence = strtok(NULL, ",");

    // Print the extracted information
    printf("Suspect: %s\n", suspect_name);
    printf("Crime scene: %s\n", crime_scene);
    printf("Time of crime: %s\n", time_of_crime);
    printf("Evidence: %s\n", evidence);

    // Free the allocated memory
    free(buffer);
}

int main() {
    // The butler did it!
    char *butler = "John the Butler";

    // Parse the case file
    parse_case_file();

    // Check if the butler is a suspect
    char *suspect_name;
    FILE *file = fopen(case_file, "r");
    if (file == NULL) {
        printf("Error opening case file: %s\n", case_file);
        exit(1);
    }
    fscanf(file, "%s", suspect_name);
    fclose(file);

    if (strcmp(suspect_name, butler) == 0) {
        printf("Elementary, my dear Watson! The butler is the killer.\n");
    } else {
        printf("The butler is innocent. We must continue our investigation.\n");
    }

    return 0;
}