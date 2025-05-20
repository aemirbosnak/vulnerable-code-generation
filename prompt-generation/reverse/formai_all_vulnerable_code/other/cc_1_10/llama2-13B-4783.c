//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <assert.h>

#define PHONE_BOOK_FILE "phone_book.dat"

typedef struct phone_book_entry {
    char name[50];
    char number[20];
} phone_book_entry_t;

// Structure to store the phone book entries
typedef struct phone_book {
    int num_entries;
    phone_book_entry_t entries[10];
} phone_book_t;

// Function to read the phone book from the file
phone_book_t *read_phone_book(void) {
    phone_book_t *pb = malloc(sizeof(phone_book_t));
    char line[100];
    int fd;

    // Open the phone book file in read mode
    fd = open(PHONE_BOOK_FILE, O_RDONLY);
    assert(fd != -1);

    // Read the file line by line
    while (read(fd, line, 100) > 0) {
        // Check if the line is a valid entry
        if (sscanf(line, "%49s %19s", pb->entries[pb->num_entries].name, pb->entries[pb->num_entries].number) == 2) {
            pb->num_entries++;
        }
    }

    // Close the file
    close(fd);

    return pb;
}

// Function to add a new entry to the phone book
void add_entry(phone_book_t *pb, char *name, char *number) {
    // Check if the phone book is full
    if (pb->num_entries >= 10) {
        printf("Phone book is full, cannot add more entries\n");
        return;
    }

    // Add the new entry to the end of the phone book
    strcpy(pb->entries[pb->num_entries].name, name);
    strcpy(pb->entries[pb->num_entries].number, number);
    pb->num_entries++;
}

// Function to search the phone book for a specific name
int search_phone_book(phone_book_t *pb, char *name) {
    int i;

    for (i = 0; i < pb->num_entries; i++) {
        if (strcmp(name, pb->entries[i].name) == 0) {
            return i;
        }
    }

    return -1;
}

// Function to delete an entry from the phone book
void delete_entry(phone_book_t *pb, int index) {
    // Check if the index is valid
    if (index < 0 || index >= pb->num_entries) {
        printf("Invalid index\n");
        return;
    }

    // Delete the entry at the specified index
    memmove(pb->entries + index, pb->entries + index + 1,
             (pb->num_entries - index - 1) * sizeof(phone_book_entry_t));
    pb->num_entries--;
}

// Example program
int main(void) {
    phone_book_t *pb;
    char name[50];
    char number[20];

    // Read the phone book from the file
    pb = read_phone_book();

    // Add some entries to the phone book
    add_entry(pb, "John", "555-1234");
    add_entry(pb, "Jane", "555-5678");
    add_entry(pb, "Bob", "555-9012");

    // Search for an entry
    int index = search_phone_book(pb, "Jane");
    if (index != -1) {
        printf("Jane's number is %s\n", pb->entries[index].number);
    }

    // Delete an entry
    delete_entry(pb, 1);

    // Print the updated phone book
    for (int i = 0; i < pb->num_entries; i++) {
        printf("%d: %s %s\n", i, pb->entries[i].name, pb->entries[i].number);
    }

    // Free the phone book memory
    free(pb);

    return 0;
}