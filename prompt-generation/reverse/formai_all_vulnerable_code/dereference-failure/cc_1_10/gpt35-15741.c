//FormAI DATASET v1.0 Category: System event logger ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// define the maximum length of message
#define MAX_MSG_LEN 100

// function to get the current date and time
char* getCurrentTime() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char *time_str = (char*)malloc(sizeof(char)*50);
    sprintf(time_str, "%d-%02d-%02d %02d:%02d:%02d", tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday,  tm.tm_hour, tm.tm_min, tm.tm_sec);
    return time_str;
}

// function to log the event
void logEvent(char *event_type, char *message) {
    // open the log file in append mode
    FILE *fp = fopen("system_event_log.txt", "a");

    // get the current time
    char *current_time = getCurrentTime();

    // write the log message
    fprintf(fp, "[%s]\t%s\t%s\n", current_time, event_type, message);

    // close the file
    fclose(fp);
}

int main() {
    char message[MAX_MSG_LEN];
    int choice;

    // infinite loop to log events
    while(1) {
        // display the menu
        printf("\nEnter your choice:\n");
        printf("1. Log Error\n");
        printf("2. Log Warning\n");
        printf("3. Log Information\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the error message: ");
                scanf(" %[^\n]s", message);
                logEvent("ERROR", message);
                break;
            case 2:
                printf("\nEnter the warning message: ");
                scanf(" %[^\n]s", message);
                logEvent("WARNING", message);
                break;
            case 3:
                printf("\nEnter the information message: ");
                scanf(" %[^\n]s", message);
                logEvent("INFO", message);
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice\n");
        }
    }
    return 0;
}