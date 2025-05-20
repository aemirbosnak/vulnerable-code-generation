//FormAI DATASET v1.0 Category: System boot optimizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFSIZE 1024

void print_header() {
    printf("=============================================\n");
    printf("         C System Boot Optimizer\n");
    printf("=============================================\n");
}

void print_time() {
    time_t raw_time;
    struct tm *time_info;

    time(&raw_time);
    time_info = localtime(&raw_time);

    printf("\n[%02d:%02d:%02d] ", time_info->tm_hour, time_info->tm_min, time_info->tm_sec);
}

void optimize_boot() {
    int boot_time = rand() % 60;

    print_time();
    printf("Optimizing system boot...\n");

    for (int i = 0; i < boot_time; i++) {
        print_time();
        printf("Loading module %d...\n", i);
    }

    print_time();
    printf("System boot optimized!\n");
}

void read_input(char *input) {
    print_time();
    printf("Enter Y to optimize system boot: ");
    fgets(input, BUFFSIZE, stdin);

    input[strcspn(input, "\r\n")] = '\0';
}

int main() {
    char input[BUFFSIZE];

    srand(time(NULL));
    print_header();
    read_input(input);

    if (strcmp(input, "Y") == 0 || strcmp(input, "y") == 0) {
        optimize_boot();
    }

    return 0;
}