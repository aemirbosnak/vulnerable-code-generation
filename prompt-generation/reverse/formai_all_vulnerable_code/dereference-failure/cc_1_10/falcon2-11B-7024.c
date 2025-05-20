//Falcon2-11B DATASET v1.0 Category: Temperature monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <math.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <termios.h>
#include <signal.h>

// Global variables
volatile int fd;
int cnt = 0;
int start = 0;
int end = 0;
float temp;
float temp_read;

void signal_handler(int sig)
{
    printf("Exiting...\n");
    close(fd);
    exit(0);
}

// Function to convert the voltage to temperature in degrees Celsius
float get_temp(int voltage)
{
    float temp_c;
    temp_c = (voltage - 0.5) * 100 / 4.096;
    return temp_c;
}

// Function to open the sensor device file
int open_device()
{
    if ((fd = open("/dev/sensordev", O_RDWR)) < 0) {
        printf("Unable to open the device file: %s\n", strerror(errno));
        exit(1);
    }
    return fd;
}

// Function to read the temperature sensor data
void read_temp()
{
    if (cnt % 2 == 0) {
        int voltage = read(fd, &temp_read, sizeof(temp_read));
        if (voltage < 0) {
            printf("Error reading temperature sensor data: %s\n", strerror(errno));
            exit(1);
        }
        temp = get_temp(temp_read);
    }
    else {
        start = cnt + 1;
        end = cnt + 2;
        temp_read = 0;
    }
}

// Main program
int main()
{
    int cnt;
    char *cmd = "sudo chmod 777 /dev/sensordev";
    system(cmd);
    fd = open_device();
    if (fd < 0) {
        printf("Unable to open the device file: %s\n", strerror(errno));
        exit(1);
    }
    cnt = 0;
    signal(SIGINT, signal_handler);
    while (1) {
        read_temp();
        if (cnt >= start && cnt <= end) {
            temp_read = 0;
            printf("%f\n", temp);
            cnt = 0;
        }
        else if (cnt > end) {
            break;
        }
        cnt++;
    }
    close(fd);
    return 0;
}