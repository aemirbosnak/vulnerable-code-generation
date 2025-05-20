//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_FIELDS 50

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: csvreader filename.csv\n");
        return 1;
    }
    
    FILE* file = fopen(argv[1], "r");
    if (!file) {
        printf("Error: File not found.\n");
        return 1;
    }
    
    // Read the first line (header)
    char line[MAX_LINE_LENGTH];
    if (!fgets(line, MAX_LINE_LENGTH, file)) {
        printf("Error: Could not read header line.\n");
        return 1;
    }
    
    // Parse the header line
    char* field_names[MAX_NUM_FIELDS];
    int num_fields = 0;
    char* token = strtok(line, ",");
    while (token != NULL && num_fields < MAX_NUM_FIELDS) {
        // Remove leading and trailing whitespace
        while (*token == ' ' || *token == '\t') token++;
        char* end = token + strlen(token) - 1;
        while (*end == ' ' || *end == '\t' || *end == '\r' || *end == '\n') {
            *end = '\0';
            end--;
        }
        // Save the field name
        field_names[num_fields] = token;
        num_fields++;
        token = strtok(NULL, ",");
    }
    
    // Print the header
    printf("Fields: ");
    for (int i = 0; i < num_fields; i++) printf("%s ", field_names[i]);
    printf("\n");
    
    // Read the data
    int num_rows = 0;
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        num_rows++;
        printf("Row %d: ", num_rows);
        token = strtok(line, ",");
        int field_index = 0;
        while (token != NULL && field_index < num_fields) {
            // Remove leading and trailing whitespace
            while (*token == ' ' || *token == '\t') token++;
            char* end = token + strlen(token) - 1;
            while (*end == ' ' || *end == '\t' || *end == '\r' || *end == '\n') {
                *end = '\0';
                end--;
            }
            // Print the field value
            printf("%s=%s ", field_names[field_index], token);
            field_index++;
            token = strtok(NULL, ",");
        }
        printf("\n");
    }
    
    fclose(file);
    return 0;
}