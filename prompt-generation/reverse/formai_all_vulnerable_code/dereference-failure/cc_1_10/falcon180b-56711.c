//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>

// Global variables
int temperature = 0;
int threshold = 0;
char *log_file = "temperature.log";
FILE *log_fp = NULL;

// Function to initialize the log file
void init_log_file() {
    if ((log_fp = fopen(log_file, "a")) == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }
}

// Function to log temperature data
void log_temperature(int temp) {
    time_t now = time(NULL);
    char timestamp[20];
    strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));

    fprintf(log_fp, "%s: Temperature = %d\n", timestamp, temp);
    fflush(log_fp);
}

// Function to set the temperature threshold
void set_threshold(int thresh) {
    threshold = thresh;
}

// Function to check if temperature exceeds threshold
int check_threshold(int temp) {
    if (temp > threshold) {
        return 1;
    } else {
        return 0;
    }
}

// Function to get the current temperature
int get_temperature() {
    return temperature;
}

// Function to run the temperature monitor loop
void run_monitor() {
    init_log_file();

    while (1) {
        int temp = get_temperature();
        if (check_threshold(temp)) {
            log_temperature(temp);
            printf("Temperature exceeded threshold: %d\n", temp);
        }

        sleep(1);
    }
}

int main() {
    init_log_file();

    while (1) {
        int choice;
        printf("\nTemperature Monitor Menu:\n");
        printf("1. Set temperature threshold\n");
        printf("2. Get current temperature\n");
        printf("3. Start temperature monitor\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the temperature threshold: ");
            scanf("%d", &threshold);
            printf("Temperature threshold set to: %d\n", threshold);
            break;

        case 2:
            printf("Current temperature: %d\n", get_temperature());
            break;

        case 3:
            run_monitor();
            break;

        case 4:
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}