//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_COMMAND_LENGTH 1024

typedef struct {
    char *file_name;
    char *command;
} SynchronizerEntry;

int main(int argc, char *argv[])
{
    FILE *input_file = NULL;
    FILE *output_file = NULL;
    char line[MAX_FILE_NAME_LENGTH+MAX_COMMAND_LENGTH];
    SynchronizerEntry *entries = NULL;
    int num_entries = 0;

    // Open input file
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Read input file
    while (fgets(line, sizeof(line), input_file)!= NULL) {
        SynchronizerEntry *entry = (SynchronizerEntry*)malloc(sizeof(SynchronizerEntry));
        if (entry == NULL) {
            printf("Error allocating memory.\n");
            exit(1);
        }

        char *delimiter = strchr(line, ',');
        if (delimiter == NULL) {
            printf("Invalid input format: %s\n", line);
            exit(1);
        }

        *delimiter = '\0';
        entry->file_name = strdup(line);
        entry->command = strdup(delimiter+1);

        entries = (SynchronizerEntry*)realloc(entries, sizeof(SynchronizerEntry)*(num_entries+1));
        if (entries == NULL) {
            printf("Error allocating memory.\n");
            exit(1);
        }

        entries[num_entries++] = *entry;
    }

    // Close input file
    fclose(input_file);

    // Open output file
    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Write output file
    for (int i = 0; i < num_entries; i++) {
        fprintf(output_file, "%s,%s\n", entries[i].file_name, entries[i].command);
    }

    // Close output file
    fclose(output_file);

    // Execute commands
    for (int i = 0; i < num_entries; i++) {
        system(entries[i].command);
    }

    // Free memory
    for (int i = 0; i < num_entries; i++) {
        free(entries[i].file_name);
        free(entries[i].command);
    }
    free(entries);

    return 0;
}