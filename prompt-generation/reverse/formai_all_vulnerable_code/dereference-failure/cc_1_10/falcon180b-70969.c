//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define RED "\e[1;31m"
#define GREEN "\e[1;32m"
#define YELLOW "\e[1;33m"
#define RESET "\e[0m"

#define DELAY 3 // in seconds

void traffic_light(int duration) {
    printf("Traffic Light:\n");
    printf("=============\n");
    for (int i = 0; i < duration; i++) {
        if (i % 2 == 0) {
            printf(RED);
        } else if (i % 3 == 1) {
            printf(YELLOW);
        } else {
            printf(GREEN);
        }
        printf(" %d ", i + 1);
        fflush(stdout);
        usleep(DELAY * 1000000);
        printf(RESET);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int duration;

    if (argc < 2) {
        printf("Usage: %s <duration>\n", argv[0]);
        return 1;
    }

    duration = atoi(argv[1]);

    if (duration <= 0) {
        printf("Invalid duration.\n");
        return 1;
    }

    srand(time(NULL));
    int random_duration = rand() % (duration / 2) + 1;

    printf("The traffic light will run for %d seconds.\n", duration);
    traffic_light(duration);

    printf("But wait! There's a surprise!\n");
    usleep(random_duration * 1000000);
    traffic_light(random_duration);

    return 0;
}