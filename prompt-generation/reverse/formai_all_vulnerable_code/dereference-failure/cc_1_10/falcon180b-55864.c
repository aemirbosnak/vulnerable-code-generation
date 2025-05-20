//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1024

// Function to remove leading and trailing whitespace from a string
void trim(char *str) {
    char *end;

    // Trim leading space
    while (isspace(*str)) str++;

    if (*str == 0) {
        *str = '\0';
        return;
    }

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (isspace(*end)) end--;
    *(end + 1) = '\0';
}

// Function to split a line into fields based on comma delimiter
int split_line(char *line, char **fields) {
    char *token;
    int num_fields = 0;

    token = strtok(line, ",");
    while (token!= NULL) {
        fields[num_fields] = token;
        num_fields++;
        token = strtok(NULL, ",");
    }

    return num_fields;
}

// Function to read a CSV file and print its contents
void read_csv_file(FILE *fp) {
    char line[MAX_LINE_LEN];
    char **fields;
    int num_fields;

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        trim(line);
        if (line[0] == '#' || line[0] == '\0') continue; // Skip comment lines and empty lines

        num_fields = split_line(line, fields);
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", fields[i]);
        }
        printf("\n");

        free(fields);
    }
}

// Main function
int main(int argc, char *argv[]) {
    FILE *fp;

    if (argc!= 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    read_csv_file(fp);

    fclose(fp);

    return 0;
}