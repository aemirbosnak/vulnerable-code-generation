//FormAI DATASET v1.0 Category: System event logger ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EVENT_SIZE 50

int main() {
    FILE *fp;
    struct tm *event_time;
    time_t current_time;
    char event[EVENT_SIZE], file_name[50];
    int choice, event_count = 0;

    printf("Welcome to the System Event Logger\n");
    printf("Please enter a name for the log file: ");
    fgets(file_name, 50, stdin);
    strtok(file_name, "\n"); // Remove newline character from the end of the string

    fp = fopen(file_name, "a");
    if(fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    while(1) {
        printf("\nChoose an option (1-4):\n");
        printf("1. Add an event\n");
        printf("2. View events\n");
        printf("3. Clear all events\n");
        printf("4. Exit program\n");

        scanf("%d", &choice);
        fflush(stdin);

        switch(choice) {
            case 1:
                printf("Enter event description: ");
                fgets(event, EVENT_SIZE, stdin);
                strtok(event, "\n"); // Remove newline character from the end of the string

                current_time = time(NULL);
                event_time = localtime(&current_time);
                fprintf(fp, "%02d:%02d:%02d - %s\n", event_time->tm_hour, event_time->tm_min, event_time->tm_sec, event);
                printf("Event added successfully.\n");
                event_count++;
                break;

            case 2:
                printf("Events:\n\n");
                rewind(fp); // Move file pointer to the beginning of the file
                while(fgets(event, EVENT_SIZE, fp) != NULL) {
                    printf("%s", event);
                }

                if(event_count == 0) {
                    printf("No events recorded.\n");
                }
                break;

            case 3:
                fp = freopen(file_name, "w", fp); // Clear file without closing it
                event_count = 0;
                printf("All events cleared.\n");
                break;

            case 4:
                fclose(fp);
                printf("Thank you for using the System Event Logger.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}