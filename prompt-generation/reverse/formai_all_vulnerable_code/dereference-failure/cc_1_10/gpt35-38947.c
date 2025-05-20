//FormAI DATASET v1.0 Category: Log analysis ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char** events;
    int* event_counts;
    int size;
} log_data;

void read_log(log_data* data, char* filename) {
    FILE* file = fopen(filename, "r");
    char buffer[512];

    while(fgets(buffer, sizeof(buffer), file)) {
        // extract event name
        char* event = strtok(buffer, " \r\n\t");
        // check if event is in array
        int event_index = -1;
        for(int i = 0; i < data->size; i++) {
            if(strcmp(data->events[i], event) == 0) {
                event_index = i;
                break;
            }
        }

        // add new event to array if not already present
        if(event_index == -1) {
            data->size++;
            data->events = realloc(data->events, data->size * sizeof(char*));
            data->events[data->size - 1] = strdup(event);
            data->event_counts = realloc(data->event_counts, data->size * sizeof(int));
            data->event_counts[data->size - 1] = 0;
            event_index = data->size - 1;
        }

        data->event_counts[event_index]++;
    }

    fclose(file);
}

void print_results(log_data data) {
    printf("|----------------------|\n");
    printf("| Event       | Count |\n");
    printf("|----------------------|\n");
    for(int i = 0; i < data.size; i++) {
        printf("| %-11s | %-5d |\n", data.events[i], data.event_counts[i]);
    }
    printf("|----------------------|\n");
}

int main(int argc, char** argv) {
    if(argc != 2) {
        printf("Usage: log_analysis <file>\n");
        return 1;
    }

    log_data data = {NULL, NULL, 0};
    read_log(&data, argv[1]);
    print_results(data);

    for(int i = 0; i < data.size; i++) {
        free(data.events[i]);
    }
    free(data.events);
    free(data.event_counts);

    return 0;
}