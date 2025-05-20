//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 256
#define FILENAME "data.txt"

void clear_buffer() {
    while (getchar() != '\n') {}
}

void check_file_open(FILE *file) {
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
}

void read_file_content(FILE *file) {
    char buffer[MAX_BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    if (ferror(file)) {
        fprintf(stderr, "Error reading from file: %s\n", strerror(errno));
        fclose(file);
        exit(EXIT_FAILURE);
    }
}

void write_to_file(FILE *file, const char *data) {
    if (fputs(data, file) == EOF) {
        fprintf(stderr, "Error writing to file: %s\n", strerror(errno));
        fclose(file);
        exit(EXIT_FAILURE);
    }
}

void create_file() {
    FILE *file = fopen(FILENAME, "w");
    check_file_open(file);

    char buffer[MAX_BUFFER_SIZE];

    printf("Enter data to write to file (type 'exit' to stop):\n");
    while (1) {
        printf("> ");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            fprintf(stderr, "Error reading input: %s\n", strerror(errno));
            clear_buffer();
            continue;
        }

        if (strncmp(buffer, "exit", 4) == 0) {
            break;
        }

        write_to_file(file, buffer);
    }

    fclose(file);
    printf("Data written to %s successfully.\n", FILENAME);
}

void display_menu() {
    printf("File Operations Menu:\n");
    printf("1. Create File\n");
    printf("2. Read File\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

void read_from_file() {
    FILE *file = fopen(FILENAME, "r");
    check_file_open(file);
    
    printf("Contents of %s:\n", FILENAME);
    read_file_content(file);
    fclose(file);
}

int main() {
    int choice;
    do {
        display_menu();
        while (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter a number.\n");
            clear_buffer();
            display_menu();
        }
        clear_buffer();  // Flush the input buffer

        switch (choice) {
            case 1:
                create_file();
                break;
            case 2:
                read_from_file();
                break;
            case 3:
                printf("Exiting the program. Have a great day!\n");
                break;
            default:
                fprintf(stderr, "Invalid choice. Please select 1, 2, or 3.\n");
        }
    } while (choice != 3);

    return EXIT_SUCCESS;
}