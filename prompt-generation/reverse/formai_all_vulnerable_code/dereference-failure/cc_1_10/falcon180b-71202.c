//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TEMP_HISTORY 100
#define MAX_TEMP_HISTORY_SIZE 500

struct temp_history {
    time_t timestamp;
    float temperature;
};

void add_temp_history(struct temp_history *history, float temp) {
    if (history->timestamp == 0) {
        history->timestamp = time(NULL);
    }
    history->temperature = temp;
}

void print_temp_history(struct temp_history *history) {
    if (history->timestamp == 0) {
        printf("No temperature history available.\n");
        return;
    }
    printf("Temperature history:\n");
    for (int i = 0; i < MAX_TEMP_HISTORY_SIZE; i++) {
        if (i >= MAX_TEMP_HISTORY) {
            break;
        }
        if (history[i].timestamp == 0) {
            continue;
        }
        printf("%.2f @ %s\n", history[i].temperature, ctime(&history[i].timestamp));
    }
}

int main() {
    struct temp_history temp_history;
    float temp;
    char input[MAX_TEMP_HISTORY_SIZE];

    printf("Temperature Monitor\n");
    printf("--------------------\n");

    while (1) {
        printf("Enter current temperature: ");
        fgets(input, MAX_TEMP_HISTORY_SIZE, stdin);
        temp = atof(input);
        add_temp_history(&temp_history, temp);
        print_temp_history(&temp_history);
        printf("\n");
    }

    return 0;
}