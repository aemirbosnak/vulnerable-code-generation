//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

#define CLEAR_SCREEN "\e[1;1H\e[2J"
#define MOVE_TO(x, y) "\e[" #y ";" #x "H"

int main() {
    long long int idle_ticks, total_ticks;
    FILE *fp;
    char buff[1024];
    char *p;
    int i;

    printf(CLEAR_SCREEN);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("    o       o       o      o       o       o       o      o       o       o       o\n");
    printf("   o o     o o     o o    o o     o o     o o     o o    o o     o o     o o    o o\n");
    printf("  o   o   o   o   o   o  o   o   o   o   o   o   o   o  o   o   o   o   o   o   o   o\n");
    printf(" o     o o     o o     o o     o o     o o     o o     o o     o o     o o     o o\n");
    printf("o       o       o       o       o       o       o       o       o       o       o\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    while (1) {
        fp = fopen("/proc/stat", "r");
        fgets(buff, sizeof(buff), fp);
        fclose(fp);

        p = strstr(buff, "cpu ");
        if (p == NULL) {
            printf("Error: Could not find CPU statistics.\n");
            return 1;
        }

        sscanf(p, "cpu %llu %llu", &idle_ticks, &total_ticks);

        printf(CLEAR_SCREEN);
        printf("CPU Usage:\n\n");

        for (i = 0; i < 100; i++) {
            if (i < (idle_ticks * 100) / total_ticks) {
                printf(" ");
            } else {
                printf("#");
            }
        }

        printf("\n\n");
        usleep(500000);
    }

    return 0;
}