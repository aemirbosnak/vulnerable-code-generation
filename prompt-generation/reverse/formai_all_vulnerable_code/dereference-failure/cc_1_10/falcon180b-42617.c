//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MEGABYTE (1024*1024)

void print_ram_usage(void) {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    double ram_usage = ((double)usage.ru_maxrss) / MEGABYTE;
    printf("RAM Usage: %.2f MB\n", ram_usage);
}

int main() {
    int i, j, k;
    char *str;
    char **strings;
    int len;
    time_t start_time, end_time;
    double duration;

    srand(time(NULL));

    strings = malloc(10 * sizeof(char*));
    for (i = 0; i < 10; i++) {
        len = rand() % 100 + 1;
        strings[i] = malloc((len + 1) * sizeof(char));
        for (j = 0; j < len; j++) {
            str[j] = rand() % 26 + 'a';
        }
        str[len] = '\0';
    }

    start_time = time(NULL);
    for (i = 0; i < 100000; i++) {
        for (j = 0; j < 10; j++) {
            strcpy(strings[j], strings[(j+1)%10]);
        }
    }
    end_time = time(NULL);
    duration = difftime(end_time, start_time);

    printf("String Manipulation Completed in %.2f seconds\n", duration);
    print_ram_usage();

    for (i = 0; i < 10; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}