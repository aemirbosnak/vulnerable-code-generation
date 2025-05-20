//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

// Function to convert a natural language date to time_t
time_t date_to_epoch(char *date_str) {
    // Split the date into individual words
    char *words[10];
    int num_words = 0;
    char *word = strtok(date_str, " ");
    while (word != NULL) {
        words[num_words] = word;
        num_words++;
        word = strtok(NULL, " ");
    }
    
    // Map month names to numbers
    int month_num = 0;
    char *month_str = words[0];
    if (strcmp(month_str, "January") == 0) {
        month_num = 1;
    } else if (strcmp(month_str, "February") == 0) {
        month_num = 2;
    } else if (strcmp(month_str, "March") == 0) {
        month_num = 3;
    } else if (strcmp(month_str, "April") == 0) {
        month_num = 4;
    } else if (strcmp(month_str, "May") == 0) {
        month_num = 5;
    } else if (strcmp(month_str, "June") == 0) {
        month_num = 6;
    } else if (strcmp(month_str, "July") == 0) {
        month_num = 7;
    } else if (strcmp(month_str, "August") == 0) {
        month_num = 8;
    } else if (strcmp(month_str, "September") == 0) {
        month_num = 9;
    } else if (strcmp(month_str, "October") == 0) {
        month_num = 10;
    } else if (strcmp(month_str, "November") == 0) {
        month_num = 11;
    } else if (strcmp(month_str, "December") == 0) {
        month_num = 12;
    } else {
        printf("Invalid month: %s\n", month_str);
        return -1;
    }
    
    // Parse day and year
    int day_num = atoi(words[1]);
    int year_num = atoi(words[2]);
    
    struct tm time_data = {0};
    time_data.tm_year = year_num - 1900;
    time_data.tm_mon = month_num - 1;
    time_data.tm_mday = day_num;

    return mktime(&time_data);
}

// Thread function to read dates from input and convert to epoch
void *convert_dates(void *input_file) {
    char *input_filename = (char*) input_file;
    
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(input_filename, "r");
    if (fp == NULL) {
        printf("Could not open file: %s\n", input_filename);
        return NULL;
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        // Convert to epoch time
        time_t epoch_time = date_to_epoch(line);
        if (epoch_time == -1) {
            printf("Error in converting date: %s", line);
        } else {
            // Print epoch time
            printf("Epoch time for %s is %ld\n", line, epoch_time);
        }
    }

    fclose(fp);
    if (line) {
        free(line);
    }

    pthread_exit(NULL);
}

int main() {
    char *input_filename = "dates.txt";

    // Create a thread to read dates from input and convert to epoch
    pthread_t t1;
    pthread_create(&t1, NULL, convert_dates, input_filename);

    // Wait for thread to complete
    pthread_join(t1, NULL);

    return 0;
}