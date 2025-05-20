//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_ENTRIES 1024

typedef struct Entry {
    char name[256];
    struct Entry* next;
} Entry;

Entry* head = NULL;

int main() {
    int fd;
    struct stat sb;
    char buf[1024];
    Entry* entry = NULL;
    Entry* prev = NULL;

    // Open the database file in read-write mode
    if ((fd = open("database.db", O_RDWR)) == -1) {
        perror("Error opening database file");
        exit(1);
    }

    // Get the size of the database file
    if (fstat(fd, &sb) == -1) {
        perror("Error getting file size");
        exit(1);
    }

    // Allocate memory for the database entries
    head = malloc(sb.st_size);

    // Read the database file into memory
    if (read(fd, head, sb.st_size) == -1) {
        perror("Error reading database file");
        exit(1);
    }

    // Close the database file
    close(fd);

    // Create a new entry
    entry = malloc(sizeof(Entry));
    entry->next = NULL;

    // Get the user's input
    printf("Enter a name: ");
    scanf("%s", entry->name);

    // Add the new entry to the database
    if (prev) {
        prev->next = entry;
    } else {
        head = entry;
    }

    // Write the database file to disk
    if (write(fd, head, sb.st_size) == -1) {
        perror("Error writing database file");
        exit(1);
    }

    // Close the database file
    close(fd);

    // Print a confirmation message
    printf("Entry added.\n");

    return 0;
}