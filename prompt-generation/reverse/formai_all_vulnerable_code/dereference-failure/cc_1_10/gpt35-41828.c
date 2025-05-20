//FormAI DATASET v1.0 Category: Mailing list manager ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_EMAIL_LEN 256

// Define our Email struct
typedef struct {
    char email[MAX_EMAIL_LEN];
} Email;

// Define our List struct
typedef struct {
    Email *emails[MAX_EMAILS];
    int size;
} List;

// Create a new email and return a pointer to it
Email* new_email(char *address) {
    Email *email = malloc(sizeof(Email));
    strcpy(email->email, address);
    return email;
}

// Add a new email to the list
void add_email(List *list, char *address) {
    if (list->size < MAX_EMAILS) {
        Email *email = new_email(address);
        list->emails[list->size++] = email;
    } else {
        printf("List is full!\n");
    }
}

// Print out the email list
void print_list(List *list) {
    printf("Email List:\n");
    for (int i = 0; i < list->size; i++) {
        printf("%d: %s\n", i+1, list->emails[i]->email);
    }
}

// Free the memory associated with the list
void free_list(List *list) {
    for (int i = 0; i < list->size; i++) {
        free(list->emails[i]);
    }
}

int main() {
    List list = {0};
    add_email(&list, "test1@example.com");
    add_email(&list, "test2@example.com");
    add_email(&list, "test3@example.com");
    add_email(&list, "test4@example.com");
    print_list(&list);
    free_list(&list);
    return 0;
}