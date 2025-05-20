//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 50
#define MAX_FIELDS 10
#define MAX_FIELD_LEN 20
#define MAX_LINE_LEN 200

int main() {
    // Open the CSV file
    FILE *file = fopen("data.csv", "r");

    // Initialize variables
    int record_count = 0;
    char field[MAX_FIELDS][MAX_FIELD_LEN];
    char line[MAX_LINE_LEN];

    // Read each line of the CSV file
    while (fgets(line, MAX_LINE_LEN, file)) {
        // Split the line into fields
        char *token = strtok(line, ",");
        int field_count = 0;
        while (token) {
            // Copy the field to the field array
            strncpy(field[field_count], token, MAX_FIELD_LEN);
            field[field_count][MAX_FIELD_LEN-1] = '\0';
            field_count++;

            // Get the next token
            token = strtok(NULL, ",");
        }

        // Ensure we didn't exceed the maximum number of fields per record
        if (field_count > MAX_FIELDS) {
            printf("Error: too many fields on line %d\n", record_count+1);
            return 1;
        }

        // Ensure we didn't exceed the maximum number of records
        if (record_count >= MAX_RECORDS) {
            printf("Error: too many records\n");
            return 1;
        }

        // Print the fields for this record
        printf("Record %d:\n", record_count+1);
        for (int i=0; i<field_count; i++) {
            printf("   Field %d: %s\n", i+1, field[i]);
        }
        printf("\n");

        // Increment the record count
        record_count++;
    }

    // Close the CSV file
    fclose(file);

    // Print the number of records processed
    printf("Processed %d records\n", record_count);

    return 0;
}