//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_CHARS 100

struct log {
    char *line;
    struct log *next;
};

int main() {
    // Initialization of variables
    char file_name[] = "log.txt";
    char line[MAX_CHARS];
    int line_count = 0;
    struct log *head = NULL;
    struct log *current = NULL;

    // Open the log file for reading
    FILE *file = fopen(file_name, "r");

    // Read each line of the log file
    while (fgets(line, MAX_CHARS, file)) {
        // Increase the line count
        line_count++;

        // Create a new instance of the log struct
        current = malloc(sizeof(struct log));

        // Allocate enough memory to store the line
        current->line = malloc(strlen(line) + 1);

        // Copy the line into the log struct
        strcpy(current->line, line);

        // Set the next pointer to NULL
        current->next = NULL;

        // If the head is NULL, set it to the current log
        if (head == NULL) {
            head = current;
        } else {
            // Traverse the list until the last log is found
            struct log *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }

            // Set the next pointer of the last log to the current log
            temp->next = current;
        }
    }

    // Close the log file
    fclose(file);

    // If there were less than 50 lines in the log file, exit the program
    if (line_count < 50) {
        printf("Not enough lines in the log file to perform analysis.\n");
        return 0;
    }

    // Traverse the list of logs to detect intrusions
    struct log *ptr = head;
    while (ptr != NULL) {
        // Check for suspicious activity, such as SQL injection or shell command injection
        if (strstr(ptr->line, "SELECT * FROM") != NULL || strstr(ptr->line, "DROP TABLE") != NULL || strstr(ptr->line, "system(") != NULL) {
            printf("Possible intrusion detected!\n");
            printf("Line number: %d\n", line_count);
            printf("Line content: %s\n", ptr->line);
        }

        // Move to the next log
        ptr = ptr->next;
    }

    // Free all memory allocations
    ptr = head;
    while (ptr != NULL) {
        struct log *temp = ptr;
        ptr = ptr->next;
        free(temp->line);
        free(temp);
    }

    return 0;
}