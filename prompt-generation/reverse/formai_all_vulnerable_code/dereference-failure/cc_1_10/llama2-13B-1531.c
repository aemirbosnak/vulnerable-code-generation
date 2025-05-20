//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: invasive
// Invasive Phone Book v1.0

// This program will take over your phone book and make it fun!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables
const int MAX_NAME_LENGTH = 50;
const int MAX_PHONE_NUMBER_LENGTH = 20;

// Function prototypes
void add_entry(char *name, char *phone_number);
void list_entries(void);

// Main function
int main(void)
{
    // Welcome message
    printf("Welcome to Invasive Phone Book v1.0\n");

    // Add some fun entries to the phone book
    add_entry("John Doe", "555-1234");
    add_entry("Jane Doe", "555-5678");
    add_entry("Bob Smith", "555-9012");

    // Print out the phone book
    list_entries();

    return 0;
}

// Function to add an entry to the phone book
void add_entry(char *name, char *phone_number)
{
    // Check if the name is too long
    if (strlen(name) > MAX_NAME_LENGTH)
    {
        printf("Name too long! Maximum length is %d\n", MAX_NAME_LENGTH);
        return;
    }

    // Check if the phone number is too long
    if (strlen(phone_number) > MAX_PHONE_NUMBER_LENGTH)
    {
        printf("Phone number too long! Maximum length is %d\n", MAX_PHONE_NUMBER_LENGTH);
        return;
    }

    // Add the entry to the phone book
    char *phone_book = (char *)malloc(100 * sizeof(char));
    strcpy(phone_book, name);
    strcat(phone_book, " ");
    strcat(phone_book, phone_number);
    printf("Added %s %s to phone book\n", name, phone_number);
}

// Function to list all entries in the phone book
void list_entries(void)
{
    // Iterate through the phone book and print out each entry
    char *phone_book = (char *)malloc(100 * sizeof(char));
    strcpy(phone_book, "Phone Book:");
    printf("%s\n", phone_book);
    char *current = phone_book;
    char *next = phone_book;
    while (next != NULL)
    {
        current = next;
        next = strchr(current, ' ');
        if (next != NULL)
        {
            *next = '\0';
            printf("%s %s\n", current, next + 1);
        }
        else
        {
            printf("%s\n", current);
        }
    }
    free(phone_book);
}