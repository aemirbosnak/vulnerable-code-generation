//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void get_memory_usage(double *used_memory, double *total_memory) {
    FILE *file = fopen("/proc/meminfo", "r");
    char line[MAX_LINE_LENGTH];

    if (file == NULL) {
        perror("Could not open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "MemTotal:")) {
            sscanf(line, "MemTotal: %lf kB", total_memory);
        } else if (strstr(line, "MemAvailable:")) {
            double available_memory;
            sscanf(line, "MemAvailable: %lf kB", &available_memory);
            *used_memory = *total_memory - available_memory;
        }
    }
    fclose(file);
}

void print_memory_usage(double used_memory, double total_memory) {
    printf("Memory Usage:\n");
    printf("====================\n");
    printf("Total Memory:   %.2f MB\n", total_memory / 1024);
    printf("Used Memory:    %.2f MB\n", used_memory / 1024);
    printf("Available Memory: %.2f MB\n", (total_memory - used_memory) / 1024);
    printf("====================\n");
}

void interactive_mode() {
    double used_memory, total_memory;
    char command[MAX_LINE_LENGTH];

    while (1) {
        get_memory_usage(&used_memory, &total_memory);
        print_memory_usage(used_memory, total_memory);
        printf("Type 'exit' to quit, 'refresh' to update: ");
        fgets(command, sizeof(command), stdin);
        
        if (strncmp(command, "exit", 4) == 0) {
            printf("Exiting program. Goodbye!\n");
            break;
        }
        else if (strncmp(command, "refresh", 7) == 0) {
            // simply refresh by showing the usage again
            continue;
        }
        else {
            printf("Unknown command: %s", command);
        }
    }
}

int main(int argc, char *argv[]) {
    printf("Welcome to the C RAM Usage Monitor!\n");
    printf("===================================\n");
    
    if (argc == 2 && strcmp(argv[1], "--json") == 0) {
        double used_memory, total_memory;
        get_memory_usage(&used_memory, &total_memory);
        printf("{\"total_memory\": %.2f, \"used_memory\": %.2f, \"available_memory\": %.2f}\n",
                total_memory / 1024, used_memory / 1024, (total_memory - used_memory) / 1024);
    } else if (argc == 1) {
        interactive_mode();
    } else {
        fprintf(stderr, "Usage: %s [--json]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    return 0;
}