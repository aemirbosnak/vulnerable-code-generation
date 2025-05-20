//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_STR_LEN 100
#define NUM_THREADS 3

typedef struct {
    char *inputString;
    char *outputString;
    int thread_id;
} ThreadData;

// Function to reverse a string
void reverseString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; ++i) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Function to convert a string to uppercase
void toUpperCase(char *str) {
    for (int i = 0; str[i]; ++i) {
        str[i] = (str[i] >= 'a' && str[i] <= 'z') ? str[i] - 32 : str[i];
    }
}

// Function to calculate the length of the string
int stringLength(char *str) {
    return strlen(str);
}

// Thread function
void* manipulateString(void *threadData) {
    ThreadData *data = (ThreadData *)threadData;

    if (data->thread_id == 0) {
        reverseString(data->inputString);
        strcpy(data->outputString, data->inputString);
    } else if (data->thread_id == 1) {
        toUpperCase(data->inputString);
        strcpy(data->outputString, data->inputString);
    } else if (data->thread_id == 2) {
        int length = stringLength(data->inputString);
        snprintf(data->outputString, MAX_STR_LEN, "Length: %d", length);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadData threadData[NUM_THREADS];

    char *inputString = (char *)malloc(MAX_STR_LEN * sizeof(char));
    char *outputStrings[NUM_THREADS] = {malloc(MAX_STR_LEN * sizeof(char)), 
                                         malloc(MAX_STR_LEN * sizeof(char)), 
                                         malloc(MAX_STR_LEN * sizeof(char))};

    printf("Enter a string (max %d characters): ", MAX_STR_LEN - 1);
    fgets(inputString, MAX_STR_LEN, stdin);
    
    // Remove trailing newline character, if present
    size_t len = strlen(inputString);
    if (len > 0 && inputString[len - 1] == '\n') {
        inputString[len - 1] = '\0';
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        threadData[i].inputString = inputString;
        threadData[i].outputString = outputStrings[i];
        threadData[i].thread_id = i;

        if (pthread_create(&threads[i], NULL, manipulateString, &threadData[i])) {
            fprintf(stderr, "Error creating thread %d\n", i);
            return 1;
        }
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    printf("Reversed String: %s\n", outputStrings[0]);
    printf("Uppercase String: %s\n", outputStrings[1]);
    printf("%s\n", outputStrings[2]);

    free(inputString);
    for (int i = 0; i < NUM_THREADS; ++i) {
        free(outputStrings[i]);
    }

    return 0;
}