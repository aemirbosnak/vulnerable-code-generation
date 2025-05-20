//FormAI DATASET v1.0 Category: Mailing list manager ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct node {
    char* email;
    struct node* next;
} node;

node* head = NULL;
pthread_rwlock_t lock;

// Function to add a new email to the mailing list
void add_email(char* new_email) {
    node* current = head;
    node* new_node = (node*) malloc(sizeof(node));
    new_node->email = strdup(new_email);
    new_node->next = NULL;
    
    // Lock the linked list to avoid race condition
    pthread_rwlock_wrlock(&lock);
    
    if (head == NULL) {
        head = new_node;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    
    // Release the lock
    pthread_rwlock_unlock(&lock);
}

// Function to delete an email from the mailing list
void delete_email(char* email_to_delete) {
    node* current = head;
    node* previous = NULL;
    
    // Lock the linked list to avoid race condition
    pthread_rwlock_wrlock(&lock);
    
    while (current != NULL) {
        if (strcmp(current->email, email_to_delete) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->email);
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
    
    // Release the lock
    pthread_rwlock_unlock(&lock);
}

// Function to print all the emails in the mailing list
void print_emails() {
    node* current = head;
    
    // Lock the linked list to avoid race condition
    pthread_rwlock_rdlock(&lock);
    
    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
    
    // Release the lock
    pthread_rwlock_unlock(&lock);
}

int main() {
    // Initialize the read-write lock
    pthread_rwlock_init(&lock, NULL);
    
    // Add some test emails
    add_email("john.doe@example.com");
    add_email("jane.doe@example.com");
    add_email("bob.smith@example.com");
    
    // Print all the emails
    print_emails();
    
    // Delete an email
    delete_email("jane.doe@example.com");
    
    // Print all the emails again
    print_emails();
    
    // Clean up the linked list and the lock
    node* current = head;
    node* temp = NULL;
    while (current != NULL) {
        temp = current->next;
        free(current->email);
        free(current);
        current = temp;
    }
    pthread_rwlock_destroy(&lock);
    
    return 0;
}