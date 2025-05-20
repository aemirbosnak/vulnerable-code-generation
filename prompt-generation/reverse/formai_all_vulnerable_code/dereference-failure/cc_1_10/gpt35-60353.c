//FormAI DATASET v1.0 Category: Mailing list manager ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Node structure for the linked list
typedef struct node{
    char* email;
    struct node* next;
} Node;

// Global variables
Node* head = NULL;
pthread_mutex_t lock;

// Function to create a new node
Node* create_node(char* email){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->email = strdup(email);
    new_node->next = NULL;
    return new_node;
}

// Function to add a new email to the mailing list
void add_email(char* email){
    pthread_mutex_lock(&lock);
    if(head == NULL){
        head = create_node(email);
    }
    else{
        Node* curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = create_node(email);
    }
    pthread_mutex_unlock(&lock);
}

// Function to remove an email from the mailing list
void remove_email(char* email){
    pthread_mutex_lock(&lock);
    Node* curr = head;
    Node* prev = NULL;
    while(curr != NULL){
        if(strcmp(curr->email, email) == 0){
            if(prev == NULL){
                head = curr->next;
            }
            else{
                prev->next = curr->next;
            }
            free(curr->email);
            free(curr);
            pthread_mutex_unlock(&lock);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    pthread_mutex_unlock(&lock);
}

// Function to print the entire mailing list
void print_list(){
    pthread_mutex_lock(&lock);
    if(head == NULL){
        printf("Mailing list is empty.\n");
    }
    else{
        printf("Mailing list:\n");
        Node* curr = head;
        while(curr != NULL){
            printf("%s\n", curr->email);
            curr = curr->next;
        }
    }
    pthread_mutex_unlock(&lock);
}

// Thread function to continuously read user input and execute commands
void* input_thread(void* arg){
    while(1){
        printf("Enter a command (add, remove, print, exit):\n");
        char input[100];
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = '\0'; // to remove trailing newline

        if(strcmp(input, "add") == 0){
            char email[100];
            printf("Enter email address to add:\n");
            fgets(email, 100, stdin);
            email[strcspn(email, "\n")] = '\0';
            add_email(email);
        }
        else if(strcmp(input, "remove") == 0){
            char email[100];
            printf("Enter email address to remove:\n");
            fgets(email, 100, stdin);
            email[strcspn(email, "\n")] = '\0';
            remove_email(email);
        }
        else if(strcmp(input, "print") == 0){
            print_list();
        }
        else if(strcmp(input, "exit") == 0){
            pthread_exit(NULL);
        }
        else{
            printf("Invalid command.\n");
        }
    }
}

int main(){
    // Initialize mutex lock
    pthread_mutex_init(&lock, NULL);

    // Create input thread
    pthread_t input_t;
    int input_rc = pthread_create(&input_t, NULL, input_thread, NULL);
    if(input_rc){
        printf("Error: could not create input thread. Exiting.\n");
        return 1;
    }

    // Wait for input thread to complete
    pthread_join(input_t, NULL);

    // Free memory and destroy lock
    Node* curr = head;
    while(curr != NULL){
        Node* temp = curr;
        curr = curr->next;
        free(temp->email);
        free(temp);
    }
    pthread_mutex_destroy(&lock);

    return 0;
}