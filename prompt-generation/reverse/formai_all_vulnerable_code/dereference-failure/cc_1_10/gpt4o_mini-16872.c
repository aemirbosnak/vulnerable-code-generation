//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>

#define MAX_STRINGS 100
#define MAX_LENGTH 256

// Structure for thread arguments
typedef struct {
    char *string;
    int index;
} ThreadData;

// Mutex for output
pthread_mutex_t outputMutex;

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        while (left < right && !isalnum(str[left])) left++;
        while (left < right && !isalnum(str[right])) right--;
        
        if (tolower(str[left]) != tolower(str[right])) {
            return 0; // Not a palindrome
        }
        left++;
        right--;
    }
    return 1; // Is a palindrome
}

// Thread function
void *checkPalindrome(void *arg) {
    ThreadData *data = (ThreadData *)arg;

    // Check if the string is a palindrome
    int result = isPalindrome(data->string);

    // Lock the output mutex
    pthread_mutex_lock(&outputMutex);
    if (result) {
        printf("String %d: \"%s\" is a palindrome.\n", data->index, data->string);
    } else {
        printf("String %d: \"%s\" is not a palindrome.\n", data->index, data->string);
    }
    pthread_mutex_unlock(&outputMutex);

    free(data); // Free allocated memory for thread data
    return NULL;
}

int main() {
    char *strings[MAX_STRINGS];
    int count = 0;
    pthread_t threads[MAX_STRINGS];

    // Initialize mutex
    pthread_mutex_init(&outputMutex, NULL);

    // Input strings from user
    printf("Enter strings (type 'END' to finish):\n");
    while (count < MAX_STRINGS) {
        strings[count] = (char *)malloc(MAX_LENGTH * sizeof(char));
        fgets(strings[count], MAX_LENGTH, stdin);
        strings[count][strcspn(strings[count], "\n")] = 0; // Remove the newline character

        if (strcmp(strings[count], "END") == 0) {
            free(strings[count]);
            break;
        }

        // Create a new thread to check this string
        ThreadData *data = (ThreadData *)malloc(sizeof(ThreadData));
        data->string = strings[count];
        data->index = count;

        if (pthread_create(&threads[count], NULL, checkPalindrome, data) != 0) {
            perror("Failed to create thread");
            free(data);
            break;
        }
        count++;
    }

    // Wait for all threads to finish
    for (int i = 0; i < count; i++) {
        pthread_join(threads[i], NULL);
    }

    // Clean up
    for (int i = 0; i < count; i++) {
        free(strings[i]);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&outputMutex);
    
    return 0;
}