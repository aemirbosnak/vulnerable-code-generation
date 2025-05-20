//Falcon2-11B DATASET v1.0 Category: Traffic Light Controller ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

int red_light = 1;
int green_light = 0;
int yellow_light = 0;

void *red_light_thread(void *args) {
    while (1) {
        red_light = 1;
        green_light = 0;
        yellow_light = 0;
        printf("RED LIGHT\n");
        sleep(1);
        red_light = 0;
        green_light = 1;
        yellow_light = 0;
        printf("GREEN LIGHT\n");
        sleep(1);
        red_light = 0;
        green_light = 0;
        yellow_light = 1;
        printf("YELLOW LIGHT\n");
        sleep(1);
    }
}

void *green_light_thread(void *args) {
    while (1) {
        red_light = 0;
        green_light = 1;
        yellow_light = 0;
        printf("GREEN LIGHT\n");
        sleep(1);
        red_light = 0;
        green_light = 0;
        yellow_light = 1;
        printf("YELLOW LIGHT\n");
        sleep(1);
    }
}

void *yellow_light_thread(void *args) {
    while (1) {
        red_light = 0;
        green_light = 0;
        yellow_light = 1;
        printf("YELLOW LIGHT\n");
        sleep(1);
        red_light = 0;
        green_light = 1;
        yellow_light = 0;
        printf("GREEN LIGHT\n");
        sleep(1);
    }
}

int main() {
    pthread_t red_light_thread;
    pthread_t green_light_thread;
    pthread_t yellow_light_thread;

    pthread_create(&red_light_thread, NULL, red_light_thread, NULL);
    pthread_create(&green_light_thread, NULL, green_light_thread, NULL);
    pthread_create(&yellow_light_thread, NULL, yellow_light_thread, NULL);

    pthread_join(red_light_thread, NULL);
    pthread_join(green_light_thread, NULL);
    pthread_join(yellow_light_thread, NULL);

    return 0;
}