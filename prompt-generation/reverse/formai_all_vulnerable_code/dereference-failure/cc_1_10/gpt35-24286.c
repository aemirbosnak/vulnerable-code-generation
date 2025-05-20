//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>

#define MAX_CPU_USAGE_STRING 256
#define MAX_IDLE_TIME 5

#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_BLUE "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN "\033[36m"
#define COLOR_RESET "\033[0m"

char* get_cpu_usage_string(double usage) {
    char* usage_str = malloc(MAX_CPU_USAGE_STRING);
    if (usage < 50) {
        sprintf(usage_str, "The CPU usage is %f%%. It seems to be running smoothly.", usage);
        strcat(usage_str, COLOR_GREEN);
    } else if (usage < 80) {
        sprintf(usage_str, "The CPU usage is %f%%. It seems to be running at full capacity.", usage);
        strcat(usage_str, COLOR_YELLOW);
    } else {
        sprintf(usage_str, "The CPU usage is %f%%. It seems to be overloaded!", usage);
        strcat(usage_str, COLOR_RED);
    }
    strcat(usage_str, COLOR_RESET);
    return usage_str;
}

int main() {
    double idle_time = 0;
    time_t start_time;

    while (1) {
        double cpu_usage = 0;
        FILE* fp = fopen("/proc/stat", "r");

        if (fp == NULL) {
            fprintf(stderr, "Error opening /proc/stat: %s\n", strerror(errno));
            return -1;
        }
        
        char buffer[1024];
        fgets(buffer, sizeof(buffer), fp);
        char* line = strtok(buffer, " ");

        while (line != NULL) {
            if (strncmp(line, "cpu", 3) == 0) {
                line += 3;
                int i;
                for (i = 0; i < 10; i++) {
                    if (*line && *line != ' ') {
                        cpu_usage += atof(line);
                    }
                    while (*line && *line != ' ') {
                        line++;
                    }
                    line++;
                }
                break;
            }
            line = strtok(NULL, " ");
        }
        
        fclose(fp);

        time_t current_time = time(NULL);
        if (start_time == 0) {
            start_time = current_time;
            continue;
        }

        double elapsed_time = difftime(current_time, start_time);
        double total_time = cpu_usage + idle_time;

        printf("\033[2J\033[1;1H"); // clear console
        printf("%s\n", get_cpu_usage_string(cpu_usage / total_time * 100));
        printf("Idle time: %d seconds\n", (int)idle_time);
        
        if (idle_time > MAX_IDLE_TIME) {
            printf(COLOR_BLUE "The system seems to be idle for more than %d seconds. Exiting...\n" COLOR_RESET, MAX_IDLE_TIME);
            return 0;
        }

        if (cpu_usage == 0) {
            idle_time += elapsed_time;
        } else {
            idle_time = 0;
        }

        start_time = current_time;
        sleep(1);
    }

    return 0;
}