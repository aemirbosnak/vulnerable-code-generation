//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to read a single line of CSV data
int readCSVLine(FILE *fp, char *line[], int *len) {
    char c;
    int i;

    // Skip leading whitespace
    while ((c = fgetc(fp))!= EOF && isspace(c));

    // Read up to 100 characters of data
    for (i = 0; i < 100 && (c = fgetc(fp))!= EOF; ++i) {
        line[i] = c;
    }

    // Terminate the string
    line[i] = '\0';

    if (i == 0) {
        return 0; // No data read
    } else {
        *len = i;
        return 1; // Successfully read data
    }
}

// Function to read all lines of a CSV file
int readCSVFile(const char *filename, char *line[], int *len) {
    FILE *fp;
    int n, m;

    // Open the file
    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Couldn't open '%s'\n", filename);
        return 0; // Failed to open file
    }

    // Read first line (header)
    if (readCSVLine(fp, line, &m)!= 1) {
        printf("Failed to read header\n");
        return 0; // Failed to read header
    }

    // Read remaining lines
    for (n = 1; n < m; ++n) {
        if (readCSVLine(fp, line, &m)!= 1) {
            printf("Failed to read line %d\n", n);
            return 0; // Failed to read line
        }
    }

    // Close file
    fclose(fp);

    return 1; // Successfully read all lines
}

int main() {
    const char *filename = "example.csv";
    char line[100];
    int len;

    // Open file
    FILE *fp;
    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Couldn't open '%s'\n", filename);
        return 0; // Failed to open file
    }

    // Read CSV data
    if (readCSVFile(filename, line, &len) == 0) {
        fclose(fp);
        return 1; // Failed to read CSV data
    }

    // Display results
    printf("CSV data:\n");
    for (int i = 0; i < len; ++i) {
        printf("%s\n", line);
    }

    // Close file
    fclose(fp);

    return 0;
}