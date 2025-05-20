//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

// function to check if a file exists
int file_exists(const char* filename) {
    struct stat buffer;
    return stat(filename, &buffer) == 0;
}

// function to read CSV file in asynchronous style
void async_csv_reader(const char* filename) {
    if (file_exists(filename) == 0) {
        fprintf(stderr, "Error: File '%s' does not exist\n", filename);
        return;
    }

    // create a structure to hold the CSV data
    struct {
        char* line;
        char* delimiter;
        int row;
    } csv_data;

    // open the file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Failed to open file '%s'\n", filename);
        return;
    }

    // set the delimiter based on the first line
    char* line = NULL;
    int delimiter_found = 0;
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "\\n")!= NULL) {
            line[strlen(line) - 1] = '\0';
        }
        if (delimiter_found == 0 && strstr(line, ",")!= NULL) {
            csv_data.delimiter = ",";
            delimiter_found = 1;
        }
        if (delimiter_found == 0 && strstr(line, ";")!= NULL) {
            csv_data.delimiter = ";";
            delimiter_found = 1;
        }
        if (delimiter_found == 0 && strstr(line, "|")!= NULL) {
            csv_data.delimiter = "|";
            delimiter_found = 1;
        }
        if (delimiter_found == 0 && strstr(line, "\t")!= NULL) {
            csv_data.delimiter = "\t";
            delimiter_found = 1;
        }
    }

    // set the number of rows
    csv_data.row = 0;
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "\\n")!= NULL) {
            line[strlen(line) - 1] = '\0';
        }
        if (csv_data.delimiter!= NULL) {
            char* token = strtok(line, csv_data.delimiter);
            while (token!= NULL) {
                if (csv_data.row == 0) {
                    csv_data.row++;
                }
                printf("%s\n", token);
                token = strtok(NULL, csv_data.delimiter);
            }
        } else {
            printf("Invalid delimiter\n");
        }
    }

    // close the file
    fclose(file);
}

int main() {
    const char* filename = "data.csv";
    async_csv_reader(filename);
    return 0;
}