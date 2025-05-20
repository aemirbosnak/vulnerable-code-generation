//FormAI DATASET v1.0 Category: System event logger ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_SIZE 1000

typedef enum {
    INFO,
    WARN,
    ERROR
} LogLevel;

typedef struct {
    time_t timestamp;
    char *message;
    LogLevel level;
} LogRecord;

void log_event(LogLevel level, const char *message);
void print_log(LogLevel level);

LogRecord log_history[MAX_LOG_SIZE]; // circular buffer
int curr_idx = 0;
int num_logs = 0;

int main()
{
    printf("Welcome to the configurable event logger!\n");
    char message[100];
    int choice = 0;
    do {
        printf("Enter 1 to log an INFO event, 2 to log a WARN event, 3 to log an ERROR event, or 4 to print logs:\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter message:\n");
            scanf("%s", message);
            log_event(INFO, message);
            break;
        case 2:
            printf("Enter message:\n");
            scanf("%s", message);
            log_event(WARN, message);
            break;
        case 3:
            printf("Enter message:\n");
            scanf("%s", message);
            log_event(ERROR, message);
            break;
        case 4:
            printf("Enter 1 to print INFO logs, 2 to print WARN logs, 3 to print ERROR logs, or 4 to print all logs:\n");
            scanf("%d", &choice);
            switch (choice) {
            case 1:
                print_log(INFO);
                break;
            case 2:
                print_log(WARN);
                break;
            case 3:
                print_log(ERROR);
                break;
            case 4:
                print_log(INFO);
                print_log(WARN);
                print_log(ERROR);
                break;
            default:
                printf("Invalid choice!\n");
            }
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}

void log_event(LogLevel level, const char *message)
{
    LogRecord log;
    log.timestamp = time(NULL);
    log.message = malloc(strlen(message) + 1);
    strcpy(log.message, message);
    log.level = level;

    log_history[curr_idx++] = log;
    curr_idx = curr_idx % MAX_LOG_SIZE;
    if (num_logs < MAX_LOG_SIZE) {
        num_logs++;
    }
}

void print_log(LogLevel level)
{
    printf("------------\n");
    if (level == INFO) {
        printf("INFO LOGS:\n");
    } else if (level == WARN) {
        printf("WARN LOGS:\n");
    } else if (level == ERROR) {
        printf("ERROR LOGS:\n");
    }

    int i, j;
    for (i = 0, j = curr_idx; i < num_logs; i++, j = (j + 1) % MAX_LOG_SIZE) {
        if (log_history[j].level == level || level == 0) {
            printf("%s", ctime(&log_history[j].timestamp));
            printf("Level: ");
            switch (log_history[j].level) {
            case INFO:
                printf("INFO\n");
                break;
            case WARN:
                printf("WARN\n");
                break;
            case ERROR:
                printf("ERROR\n");
                break;
            }
            printf("Message: %s\n", log_history[j].message);
            printf("------------\n");
        }
    }
}