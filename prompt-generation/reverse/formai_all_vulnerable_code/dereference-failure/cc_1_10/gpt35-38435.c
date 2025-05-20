//FormAI DATASET v1.0 Category: Phone Book ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a phone book entry
struct phone_book_entry {
    char name[50];
    char number[20];
    struct phone_book_entry *next;
};

// Function to add an entry to the phone book
void add_entry(struct phone_book_entry **pb, char *name, char *number) {
    struct phone_book_entry *newEntry = (struct phone_book_entry*)malloc(sizeof(struct phone_book_entry));
    strcpy(newEntry->name, name);
    strcpy(newEntry->number, number);
    newEntry->next = (*pb);
    (*pb) = newEntry;
}

// Function to remove an entry from the phone book
void remove_entry(struct phone_book_entry **pb, char *name) {
    struct phone_book_entry *current = (*pb);
    struct phone_book_entry *prev = NULL;

    while(current != NULL) {
        if(strcmp(current->name, name) == 0) {
            if(prev == NULL) {
                (*pb) = current->next;
            }
            else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Function to print the phone book
void print_phone_book(struct phone_book_entry *pb) {
    printf("\nPhone Book:\n\n"); 
    while(pb != NULL) {
        printf("%s\t%s\n", pb->name, pb->number);
        pb = pb->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct phone_book_entry *pb = NULL;
    char name[50], number[20];
    char choice;

    while(1) {
        printf("Enter the choice:\n");
        printf("a) Add entry\n");
        printf("b) Remove entry\n");
        printf("c) View phone book\n");
        printf("d) Exit\n");
        scanf("\n%c", &choice);

        switch(choice) {
            case 'a':
                printf("Enter name: ");
                scanf("\n%s", name);
                printf("Enter number: ");
                scanf("\n%s", number);
                add_entry(&pb, name, number);
                break;
            case 'b':
                printf("Enter name: ");
                scanf("\n%s", name);
                remove_entry(&pb, name);
                break;
            case 'c':
                print_phone_book(pb);
                break;
            case 'd':
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}