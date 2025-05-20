//FormAI DATASET v1.0 Category: Password management ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// data structure to hold the password
struct password {
    char* username;
    char* password;
    int length;
};

// global variables
struct password* passwords;
int numberOfPasswords = 0;
pthread_mutex_t mutex;

// function to add a new password to the database
void addPassword(char* username, char* password) {
    // lock the mutex to avoid race conditions
    pthread_mutex_lock(&mutex);
    
    // allocate memory for the new password
    passwords = realloc(passwords, (numberOfPasswords + 1) * sizeof(struct password));
    passwords[numberOfPasswords].username = malloc(strlen(username) + 1);
    passwords[numberOfPasswords].password = malloc(strlen(password) + 1);
    
    // copy the values of the username and password to the new password struct
    strcpy(passwords[numberOfPasswords].username, username);
    strcpy(passwords[numberOfPasswords].password, password);
    passwords[numberOfPasswords].length = strlen(password);
    
    // increment the number of passwords
    numberOfPasswords++;
    
    // unlock the mutex
    pthread_mutex_unlock(&mutex);
}

// function to print all the passwords in the database
void printPasswords() {
    // lock the mutex to avoid race conditions
    pthread_mutex_lock(&mutex);
    
    if(numberOfPasswords == 0) {
        printf("No passwords found in the database\n");
    } else {
        printf("Username\tPassword\tLength\n");
        printf("--------\t--------\t------\n");
        
        for(int i = 0; i < numberOfPasswords; i++) {
            printf("%s\t\t%s\t\t%d\n", passwords[i].username, passwords[i].password, passwords[i].length);
        }
    }
    
    // unlock the mutex
    pthread_mutex_unlock(&mutex);
}

// function to delete a password from the database by username
void deletePassword(char* username) {
    // lock the mutex to avoid race conditions
    pthread_mutex_lock(&mutex);
    
    // find the password with the given username
    int indexToDelete = -1;
    
    for(int i = 0; i < numberOfPasswords; i++) {
        if(strcmp(username, passwords[i].username) == 0) {
            indexToDelete = i;
            break;
        }
    }
    
    if(indexToDelete == -1) {
        printf("No password found for the given username\n");
    } else {
        // free memory for the password struct and shift the elements in the array
        free(passwords[indexToDelete].username);
        free(passwords[indexToDelete].password);
        
        for(int i = indexToDelete; i < numberOfPasswords - 1; i++) {
            passwords[i] = passwords[i + 1];
        }
        
        // decrement the number of passwords
        numberOfPasswords--;
        
        printf("Password deleted successfully\n");
    }
    
    // unlock the mutex
    pthread_mutex_unlock(&mutex);
}

// thread function to continuously read user input and execute commands
void* userInputHandler(void* arg) {
    char* input = malloc(256 * sizeof(char));
    char* command;
    char* username;
    char* password;
    
    while(1) {
        printf("Enter a command (add, list, delete, exit): ");
        fgets(input, 256, stdin);
        input[strcspn(input, "\n")] = 0;
        command = strtok(input, " ");
        
        if(strcmp(command, "add") == 0) {
            username = strtok(NULL, " ");
            password = strtok(NULL, " ");
            
            if(username == NULL || password == NULL) {
                printf("Invalid command format\n");
            } else {
                addPassword(username, password);
            }
        } else if(strcmp(command, "list") == 0) {
            printPasswords();
        } else if(strcmp(command, "delete") == 0) {
            username = strtok(NULL, " ");
            
            if(username == NULL) {
                printf("Invalid command format\n");
            } else {
                deletePassword(username);
            }
        } else if(strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }
    
    free(input);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    pthread_mutex_init(&mutex, NULL);
    
    // start the user input thread
    pthread_create(&thread, NULL, userInputHandler, NULL);
    
    // wait for the user input thread to finish
    pthread_join(thread, NULL);
    
    // free memory for passwords
    for(int i = 0; i < numberOfPasswords; i++) {
        free(passwords[i].username);
        free(passwords[i].password);
    }
    free(passwords);
    
    pthread_mutex_destroy(&mutex);
    return 0;
}