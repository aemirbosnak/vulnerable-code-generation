//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIMESTAMPS 1000
#define TIME_TRAVEL_THRESHOLD 500

typedef struct {
    int timestamp;
    int value;
} TimestampValue;

int main() {
    srand(time(NULL));
    TimestampValue* timestamps = malloc(sizeof(TimestampValue) * MAX_TIMESTAMPS);
    int num_timestamps = 0;

    int current_timestamp = rand() % MAX_TIMESTAMPS;
    timestamps[current_timestamp].timestamp = current_timestamp;
    timestamps[current_timestamp].value = rand() % 100;

    int previous_timestamp = -1;
    int future_timestamp = -1;

    while (num_timestamps < MAX_TIMESTAMPS) {
        int new_timestamp = rand() % MAX_TIMESTAMPS;

        if (new_timestamp < current_timestamp - TIME_TRAVEL_THRESHOLD) {
            if (previous_timestamp!= -1 && new_timestamp > previous_timestamp) {
                timestamps[new_timestamp].timestamp = new_timestamp;
                timestamps[new_timestamp].value = timestamps[previous_timestamp].value;
                previous_timestamp = new_timestamp;
            }
        } else if (new_timestamp > current_timestamp + TIME_TRAVEL_THRESHOLD) {
            if (future_timestamp!= -1 && new_timestamp < future_timestamp) {
                timestamps[new_timestamp].timestamp = new_timestamp;
                timestamps[new_timestamp].value = timestamps[future_timestamp].value;
                future_timestamp = new_timestamp;
            }
        } else {
            current_timestamp = new_timestamp;
            timestamps[current_timestamp].value = rand() % 100;
        }

        num_timestamps++;
    }

    for (int i = 0; i < MAX_TIMESTAMPS; i++) {
        printf("%d: %d\n", timestamps[i].timestamp, timestamps[i].value);
    }

    free(timestamps);
    return 0;
}