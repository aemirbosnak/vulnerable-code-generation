//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define TEMP_DEVICE "/sys/class/thermal/thermal_zone0/temp"

static int temp_fd = -1;

void init_temp_monitor() {
    temp_fd = open(TEMP_DEVICE, O_RDONLY);
    if (temp_fd < 0) {
        printf("Error opening temperature device: %s\n", strerror(errno));
        exit(1);
    }
}

int get_temp() {
    char buf[1024];
    ssize_t len;
    int temp;

    len = read(temp_fd, buf, sizeof(buf));
    if (len <= 0) {
        printf("Error reading temperature: %s\n", strerror(errno));
        exit(1);
    }

    temp = atoi(buf);
    return temp;
}

void print_temp() {
    int temp = get_temp();
    printf("Current temperature: %d\n", temp);
}

void close_temp_monitor() {
    close(temp_fd);
}

int main() {
    init_temp_monitor();

    while (1) {
        print_temp();
        sleep(5);
    }

    close_temp_monitor();
    return 0;
}