//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_BUFFER_SIZE 100
#define MAX_ATTACKS 5

void attackCPU();
void logToFile(char *log);

char buffer[MAX_BUFFER_SIZE];
char attacks[MAX_ATTACKS][MAX_BUFFER_SIZE] = {"Buffer overflow", "SQL Injection", "Cross-site scripting", "DDoS", "Zero-day exploit"};

int main() {
    srand(time(NULL));

    int count = 0;
    while (count < MAX_ATTACKS) {
        int randIndex = rand() % MAX_ATTACKS;

        sprintf(buffer, "Possible attack detected: %s", attacks[randIndex]);
        logToFile(buffer);

        int randProbability = rand() % 100 + 1;

        if (randProbability < 70) {
            sprintf(buffer, "Probability of %s attack is low. No action needed.", attacks[randIndex]);
            logToFile(buffer);
            count++;
            continue;
        }

        sprintf(buffer, "Probability of %s attack is high. Taking action to prevent it.", attacks[randIndex]);
        logToFile(buffer);

        attackCPU();
        count++;
    }

    return 0;
}

void attackCPU() {
    int timeInterval = rand() % 5 + 1;

    for (int i = 0; i < timeInterval; i++) {
        sprintf(buffer, "CPU is under attack. Interrupting normal operation for %d seconds.", timeInterval - i);
        logToFile(buffer);
        sleep(1);
    }

    sprintf(buffer, "Attack on CPU is over. Resuming normal operation.");
    logToFile(buffer);
}

void logToFile(char *log) {
    FILE *file = fopen("intrusion_detection_system.log", "a");

    if (file == NULL) {
        printf("Error opening log file.");
        exit(1);
    }

    time_t now = time(NULL);
    char *timeString = ctime(&now);
    timeString[strlen(timeString) - 1] = '\0';

    fprintf(file, "[%s] %s\n", timeString, log);

    fclose(file);
}