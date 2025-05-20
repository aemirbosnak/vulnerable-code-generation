//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>

#define MAX_LENGTH 256

pthread_mutex_t lock;

typedef struct {
    char str[MAX_LENGTH];
    int result; // 1 if palindrome, 0 otherwise
} PalindromeData;

void* check_palindrome(void* arg) {
    PalindromeData* data = (PalindromeData*)arg;
    int len = strlen(data->str);
    
    // Remove spaces and convert to lowercase
    char* filtered_str = malloc(len + 1);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (isalpha(data->str[i])) {
            filtered_str[j++] = tolower(data->str[i]);
        }
    }
    filtered_str[j] = '\0';
    
    // Check if the filtered string is a palindrome
    int is_palindrome = 1;
    len = strlen(filtered_str);
    for (int i = 0; i < len / 2; i++) {
        if (filtered_str[i] != filtered_str[len - i - 1]) {
            is_palindrome = 0;
            break;
        }
    }
    
    pthread_mutex_lock(&lock);
    data->result = is_palindrome;
    pthread_mutex_unlock(&lock);
    
    free(filtered_str);
    return NULL;
}

int main() {
    pthread_t thread;
    PalindromeData data;
    
    // Initialize the mutex
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("Mutex initialization failed\n");
        return 1;
    }
    
    printf("Enter a string to check if it is a palindrome: ");
    fgets(data.str, MAX_LENGTH, stdin);
    
    // Remove newline character from string if present
    size_t len = strlen(data.str);
    if (len > 0 && data.str[len - 1] == '\n') {
        data.str[len - 1] = '\0';
    }

    // Create a new thread to check for palindrome
    if (pthread_create(&thread, NULL, check_palindrome, (void*)&data) != 0) {
        printf("Error creating thread\n");
        return 1;
    }
    
    // Wait for the thread to finish
    pthread_join(thread, NULL);

    // Output the result
    pthread_mutex_lock(&lock);
    if (data.result) {
        printf("The given string is a palindrome.\n");
    } else {
        printf("The given string is not a palindrome.\n");
    }
    pthread_mutex_unlock(&lock);

    // Destroy the mutex
    pthread_mutex_destroy(&lock);
    
    return 0;
}