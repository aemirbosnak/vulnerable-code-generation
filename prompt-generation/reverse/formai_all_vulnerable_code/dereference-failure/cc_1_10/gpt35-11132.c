//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a struct to hold a single entry in the csv file
typedef struct {
    char *name;
    int age;
    char *email;
} csv_entry;

// declare functions
void error_exit(const char *msg);
void read_csv_file(const char *filename);
void parse_csv_line(char *line, csv_entry *entry);

int main(int argc, char *argv[]) {
    if(argc != 2) error_exit("Usage: csv_reader <filename>");

    // call function to read the csv file
    read_csv_file(argv[1]);

    return 0;
}

// function to print error message and exit program if error occurs
void error_exit(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(EXIT_FAILURE);
}

// function to read and parse a csv file
void read_csv_file(const char *filename) {
    FILE *csv_file = fopen(filename, "r");
    if(csv_file == NULL) error_exit("Unable to open file");

    // read each line in the csv file and parse the data
    char line[256];
    int line_count = 0;
    while(fgets(line, sizeof(line), csv_file) != NULL) {
        // skip the header line
        if(line_count == 0) {
            line_count++;
            continue;
        }

        // create a new csv_entry struct and parse the data from the line
        csv_entry *entry = (csv_entry*) malloc(sizeof(csv_entry));
        parse_csv_line(line, entry);

        // print the data for the current entry
        printf("Name: %s\nAge: %d\nEmail: %s\n\n", entry->name, entry->age, entry->email);

        // free memory allocated for the csv_entry struct
        free(entry);

        line_count++;
    }

    // close the csv file
    fclose(csv_file);
}

// function to parse a single line of a csv file
void parse_csv_line(char *line, csv_entry *entry) {
    char *token = strtok(line, ",");
    int field_count = 0;

    while(token != NULL) {
        switch(field_count) {
            case 0: // name field
                entry->name = (char*) malloc(strlen(token) + 1);
                strcpy(entry->name, token);
                break;
            case 1: // age field
                entry->age = atoi(token);
                break;
            case 2: // email field
                entry->email = (char*) malloc(strlen(token) + 1);
                strcpy(entry->email, token);
                break;
        }

        token = strtok(NULL, ",");
        field_count++;
    }
}