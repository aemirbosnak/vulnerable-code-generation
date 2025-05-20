//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define struct for holding CSV data
typedef struct {
    int id;
    char name[50];
    int age;
} CsvData;

int main() {
    // open CSV file for reading
    FILE* fp = fopen("data.csv", "r");

    // check if file was successfully opened
    if (fp == NULL) {
        printf("Could not open file!\n");
        return 1;
    }

    // define variables for processing CSV data
    char buffer[1024];
    CsvData data;
    int counter = 0;

    // print header for CSV data
    printf("%-10s%-20s%-10s\n", "ID", "NAME", "AGE");

    // read CSV data line by line
    while (fgets(buffer, 1024, fp)) {
        // tokenize CSV data
        char* id_str = strtok(buffer, ",");
        char* name = strtok(NULL, ",");
        char* age_str = strtok(NULL, ",");

        // convert CSV data from string to integer
        data.id = atoi(id_str);
        strncpy(data.name, name, sizeof(data.name));
        data.age = atoi(age_str);

        // print CSV data
        printf("%-10d%-20s%-10d\n", data.id, data.name, data.age);

        // increment counter
        counter++;
    }

    // print number of records processed
    printf("Processed %d records.\n", counter);

    // close CSV file
    fclose(fp);

    return 0;
}