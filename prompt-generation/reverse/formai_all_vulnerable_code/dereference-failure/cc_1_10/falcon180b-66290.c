//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    time_t timestamp;
    int value;
} TimestampValue;

void travel_to_time(int target_time) {
    time_t current_time = time(NULL);
    while (current_time < target_time) {
        sleep(1);
        current_time = time(NULL);
    }
}

int main() {
    srand(time(NULL));

    TimestampValue* history = NULL;
    int history_size = 0;

    int choice;
    do {
        printf("Choose an option:\n");
        printf("1. Add a timestamp\n");
        printf("2. Travel to a timestamp\n");
        printf("3. View history\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                TimestampValue* new_entry = malloc(sizeof(TimestampValue));
                new_entry->timestamp = time(NULL);
                new_entry->value = rand() % 100;
                history = realloc(history, sizeof(TimestampValue) * ++history_size);
                history[history_size - 1] = *new_entry;
                break;
            }
            case 2: {
                int target_time;
                printf("Enter target time (seconds since epoch): ");
                scanf("%d", &target_time);
                travel_to_time(target_time);
                break;
            }
            case 3: {
                for (int i = 0; i < history_size; i++) {
                    TimestampValue entry = history[i];
                    printf("%d: %d (%ld)\n", i, entry.value, entry.timestamp);
                }
                break;
            }
            case 4:
                free(history);
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}