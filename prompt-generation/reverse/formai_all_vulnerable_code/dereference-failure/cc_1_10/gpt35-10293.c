//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

// Define global variables
pthread_t tid;
pthread_mutex_t lock;

// Function to convert date from natural language to standard format
void* convert_date(void *arg) {
    char *date = (char*) arg;
    char *day, *month, *year;
    char buffer[100];
    
    // Tokenize the date string and extract day, month and year
    day = strtok(date, " ");
    month = strtok(NULL, " ");
    year = strtok(NULL, " ");
    
    // Convert month from string format to integer
    int num_month;
    if (strcmp(month, "January") == 0) {
        num_month = 1;
    } else if (strcmp(month, "February") == 0) {
        num_month = 2;
    } else if (strcmp(month, "March") == 0) {
        num_month = 3;
    } else if (strcmp(month, "April") == 0) {
        num_month = 4;
    } else if (strcmp(month, "May") == 0) {
        num_month = 5;
    } else if (strcmp(month, "June") == 0) {
        num_month = 6;
    } else if (strcmp(month, "July") == 0) {
        num_month = 7;
    } else if (strcmp(month, "August") == 0) {
        num_month = 8;
    } else if (strcmp(month, "September") == 0) {
        num_month = 9;
    } else if (strcmp(month, "October") == 0) {
        num_month = 10;
    } else if (strcmp(month, "November") == 0) {
        num_month = 11;
    } else if (strcmp(month, "December") == 0) {
        num_month = 12;
    }
    
    // Construct the standard date format string
    sprintf(buffer, "%s/%d/%d", day, num_month, atoi(year));
    
    // Lock the mutex to ensure thread safety
    pthread_mutex_lock(&lock);
    
    printf("Natural language date: %s\n", date);
    printf("Standard date format: %s\n", buffer);
    
    // Unlock the mutex
    pthread_mutex_unlock(&lock);
    
    return NULL;
}

int main() {
    char input_date[100];
    
    // Initialize the mutex lock
    pthread_mutex_init(&lock, NULL);
    
    // Prompt user for input date
    printf("Please enter date in natural language format (e.g. \"3rd June 2021\"): ");
    fgets(input_date, 100, stdin);
    
    // Create new thread to convert the date
    if(pthread_create(&tid, NULL, convert_date, input_date)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }
    
    // Wait for the thread to complete
    pthread_join(tid, NULL);
    
    // Destroy the mutex lock
    pthread_mutex_destroy(&lock);
    
    return 0;
}