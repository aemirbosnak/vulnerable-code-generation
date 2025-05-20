//FormAI DATASET v1.0 Category: System event logger ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char* message) {
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    printf("[%02d:%02d:%02d] %s\n", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, message);
}

int main() {
    char event_message[256];
    int user_choice;
    do {
        printf("Enter event message (type 'exit' to quit):");
        fgets(event_message, sizeof(event_message), stdin);
        event_message[strcspn(event_message, "\n")] = 0; // Remove newline character
        
        if (strcmp(event_message, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }
        
        printf("Select event type:\n");
        printf("1 - Informational\n");
        printf("2 - Warning\n");
        printf("3 - Error\n");
        printf("Enter choice:");
        scanf("%d", &user_choice);
        
        switch (user_choice) {
            case 1:
                log_event("[INFO] - ");
                break;
            case 2:
                log_event("[WARNING] - ");
                break;
            case 3:
                log_event("[ERROR] - ");
                break;
            default:
                printf("Invalid choice!\n");
                continue;
        }
        
        log_event(event_message);
    } while (1);
    
    return 0;
}