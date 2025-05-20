//FormAI DATASET v1.0 Category: System event logger ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char* event) {
    FILE* logfile = fopen("event_log.txt", "a");

    if (logfile == NULL) {
        printf("ERROR: Could not open log file!\n");
        return;
    }

    time_t curr_time;
    time(&curr_time);

    char* time_str = ctime(&curr_time);
    char* formatted_str = malloc(sizeof(char) * (strlen(time_str) + strlen(event) + 6));
    sprintf(formatted_str, "[%s] %s\n", time_str, event);

    fputs(formatted_str, logfile);
    fclose(logfile);
    free(formatted_str);

    printf("%s", event);
}

int main() {
    log_event("You have entered the kingdom.");

    int bad_event_chance = 25;
    int event_chance = rand() % 101;
    char* event;

    if (event_chance >= bad_event_chance) {
        int type_chance = rand() % 3;

        if (type_chance == 0) {
            event = "A dragon has been spotted in the kingdom!";
        }
        else if (type_chance == 1) {
            event = "The castle walls have been breached by an enemy army!";
        }
        else {
            event = "A plague has swept through the kingdom!";
        }

        log_event(event);
    }
    else {
        event = "The kingdom experienced a peaceful day.";
        log_event(event);
    }

    return 0;
}