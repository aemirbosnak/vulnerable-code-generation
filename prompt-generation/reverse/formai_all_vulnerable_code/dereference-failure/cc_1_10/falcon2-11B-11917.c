//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // This is a simple C data mining example program.
    // We are going to read a CSV file containing data about students
    // and perform some basic operations on the data.

    FILE *fp;
    char line[1000];
    char *fields[100];
    int num_fields = 0;
    int num_students = 0;

    fp = fopen("students.csv", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    // Read the first line of the file to get the number of fields
    fgets(line, sizeof(line), fp);
    char *token;
    token = strtok(line, ",");
    while (token!= NULL) {
        fields[num_fields++] = token;
        token = strtok(NULL, ",");
    }

    // Allocate memory for the student records
    int *grades = malloc(num_fields * sizeof(int));
    char **names = malloc(num_fields * sizeof(char *));

    // Read the rest of the file
    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ",");
        while (token!= NULL) {
            int index = 0;
            for (int i = 0; i < num_fields; i++) {
                if (strcmp(token, fields[i]) == 0) {
                    grades[index] = atoi(strtok(NULL, ","));
                    names[index] = strtok(NULL, ",");
                    break;
                }
                index++;
            }
            token = strtok(NULL, ",");
        }
        num_students++;
    }

    // Print the results
    printf("Number of students: %d\n", num_students);
    for (int i = 0; i < num_fields; i++) {
        printf("%s: %s\n", fields[i], names[i]);
    }

    // Free the memory
    free(grades);
    free(names);
    fclose(fp);

    return 0;
}