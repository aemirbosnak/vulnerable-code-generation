//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define THRESHOLD 5 //the threshold number of failed login attempts
#define MAX_LINE 1024 //the maximum length of each line in the logfile

struct user_attempt {
    char username[MAX_LINE];
    char date[MAX_LINE];
    char time[MAX_LINE];
    char status[MAX_LINE];
};

void count_failed_attempts(FILE *logfile, struct user_attempt *attempts, int *count) {
    char line[MAX_LINE];
    char *field;
    int i = 0;

    while (fgets(line, MAX_LINE, logfile)) {
        field = strtok(line, " "); //parse the username
        strncpy(attempts[i].username, field, MAX_LINE);
        field = strtok(NULL, " "); //parse the date
        strncpy(attempts[i].date, field, MAX_LINE);
        field = strtok(NULL, " "); //parse the time
        strncpy(attempts[i].time, field, MAX_LINE);
        field = strtok(NULL, " "); //parse the status
        strncpy(attempts[i].status, field, MAX_LINE);

        if (strncmp(attempts[i].status, "failed", 6) == 0) {
            (*count)++;
        }

        i++;
    }
}

void print_alert(char *username) {
    printf("ALERT! Possible intrusion attempt detected for user %s.\n", username);
}

int main(int argc, char *argv[]) {
    FILE *logfile;
    char *filename;
    struct user_attempt *attempts;
    int count = 0, i;

    if (argc < 2) {
        printf("Usage: %s <logfile>\n", argv[0]);
        exit(1);
    }

    filename = argv[1];
    logfile = fopen(filename, "r");
    if (!logfile) {
        printf("Error opening logfile.\n");
        exit(1);
    }

    attempts = (struct user_attempt*)malloc(sizeof(struct user_attempt) * MAX_LINE);
    if (!attempts) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    count_failed_attempts(logfile, attempts, &count);

    if (count >= THRESHOLD) {
        for (i = 0; i < MAX_LINE; i++) {
            if (strncmp(attempts[i].status, "failed", 6) == 0) {
                print_alert(attempts[i].username);
            }
        }
    }

    fclose(logfile);
    free(attempts);

    return 0;
}