//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_csv_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        char* token;
        char* field;
        char* value;

        // Split the line into fields and values
        token = strtok_r(buffer, ",", &field);
        while (token!= NULL) {
            // Skip the first field
            if (strcmp(token, "") == 0) {
                token = strtok_r(NULL, ",", &field);
                continue;
            }

            // Remove any leading or trailing whitespace from the value
            value = strdup(token);
            value[strcspn(value, "\r\n")] = '\0';

            // Print the field and value to stdout
            printf("%s = %s\n", token, value);

            // Free the memory allocated for the value
            free(value);

            // Get the next field and value
            token = strtok_r(NULL, ",", &field);
        }
    }

    // Close the file
    fclose(file);
}

int main() {
    const char* filename = "example.csv";
    read_csv_file(filename);
    return 0;
}