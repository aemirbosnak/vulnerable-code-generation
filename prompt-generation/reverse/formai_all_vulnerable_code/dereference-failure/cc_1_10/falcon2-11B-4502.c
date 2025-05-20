//Falcon2-11B DATASET v1.0 Category: Smart home light control ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <time.h>
#include <sys/time.h>
#include <limits.h>
#include <signal.h>

#define LED_PATH "/sys/class/leds/led0/brightness"
#define MIN_BRIGHTNESS 0
#define MAX_BRIGHTNESS 255

int get_brightness(void) {
    int brightness;
    int fd = open(LED_PATH, O_RDONLY);
    if (fd == -1) {
        perror("open()");
        exit(1);
    }
    read(fd, &brightness, sizeof(int));
    close(fd);
    return brightness;
}

void set_brightness(int brightness) {
    int fd = open(LED_PATH, O_WRONLY);
    if (fd == -1) {
        perror("open()");
        exit(1);
    }
    write(fd, &brightness, sizeof(int));
    close(fd);
}

void set_led_on(void) {
    set_brightness(MAX_BRIGHTNESS);
}

void set_led_off(void) {
    set_brightness(MIN_BRIGHTNESS);
}

void* control_led(void* arg) {
    int brightness = 0;
    int sleep_time = 1;
    while (1) {
        brightness = get_brightness();
        if (brightness == MAX_BRIGHTNESS) {
            set_led_on();
        } else if (brightness == MIN_BRIGHTNESS) {
            set_led_off();
        } else {
            set_led_off();
            sleep(sleep_time);
        }
    }
    return NULL;
}

int main() {
    int ret;
    pid_t child_pid;
    pthread_t thread;
    struct termios original_settings;
    struct timeval start_time, end_time;

    tcgetattr(STDIN_FILENO, &original_settings);
    atexit(tcsetattr(STDIN_FILENO, TCSANOW, &original_settings));

    pthread_create(&thread, NULL, control_led, NULL);

    ret = gettimeofday(&start_time, NULL);
    sleep(10);
    ret = gettimeofday(&end_time, NULL);

    printf("Duration: %ld ms\n", (end_time.tv_sec - start_time.tv_sec) * 1000 + end_time.tv_usec - start_time.tv_usec);

    ret = kill(child_pid, SIGINT);
    return 0;
}