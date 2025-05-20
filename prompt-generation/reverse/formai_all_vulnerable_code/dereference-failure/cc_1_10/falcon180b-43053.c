//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 200

struct mailing_list {
    char email[MAX_EMAIL_LENGTH];
    char name[MAX_EMAIL_LENGTH];
};

int main() {
    FILE *file;
    char line[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char delimiter = ',';
    int count = 0;
    struct mailing_list list[100];

    // Open file for reading
    file = fopen("mailing_list.csv", "r");

    // Check if file was opened successfully
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    // Read header line
    fgets(line, MAX_EMAIL_LENGTH, file);

    // Loop through each line in the file
    while (fgets(line, MAX_EMAIL_LENGTH, file)!= NULL) {
        // Check if line is empty
        if (line[0] == '\n') {
            continue;
        }

        // Find delimiter
        char *token = strtok(line, &delimiter);

        // Extract email
        strcpy(list[count].email, token);

        // Extract name
        token = strtok(NULL, &delimiter);
        strcpy(list[count].name, token);

        // Increment count
        count++;
    }

    // Close file
    fclose(file);

    // Print mailing list
    printf("Mailing List:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - %s\n", list[i].email, list[i].name);
    }

    return 0;
}