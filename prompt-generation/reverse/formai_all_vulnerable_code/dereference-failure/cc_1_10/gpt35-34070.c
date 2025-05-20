//FormAI DATASET v1.0 Category: Temperature monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define TEMP_PATH "/sys/class/thermal/thermal_zone0/temp"
#define LOG_FILE "temperature_log.txt"
#define LOG_INTERVAL 10 // Log interval in seconds
#define WARNING_TEMP 80000 // Temperature in millidegrees Celsius after which warning will be issued

int running = 1;

void sigint_handler(int sig)
{
    running = 0;
}

double read_temperature()
{
    int fd = open(TEMP_PATH, O_RDONLY);
    if (fd < 0)
    {
        fprintf(stderr, "Failed to open thermal zone file: %s\n", strerror(errno));
        return -1.0;
    }

    char buf[10];
    ssize_t len = read(fd, buf, 9);
    if (len < 0)
    {
        fprintf(stderr, "Failed to read from thermal zone file: %s\n", strerror(errno));
        close(fd);
        return -1.0;
    }

    buf[len] = '\0';
    double temp = atoi(buf) / 1000.0;

    close(fd);
    return temp;
}

void log_temperature(double temp)
{
    time_t now = time(NULL);
    struct tm *local = localtime(&now);

    char buf[50];
    strftime(buf, sizeof(buf), "%F %T", local);

    FILE *log_file = fopen(LOG_FILE, "a");
    if (!log_file)
    {
        fprintf(stderr, "Failed to open log file: %s\n", strerror(errno));
        return;
    }

    fprintf(log_file, "[%s] Temperature: %.2lfC\n", buf, temp);
    fclose(log_file);
}

void warn_if_high_temperature(double temp)
{
    if (temp >= WARNING_TEMP)
    {
        printf("WARNING: Temperature is too high! Current temperature is %.2lfC\n", temp);
    }
}

int main()
{
    // Register SIGINT handler to gracefully exit on CTRL+C
    signal(SIGINT, sigint_handler);

    while (running)
    {
        double temp = read_temperature();
        if (temp < 0)
        {
            usleep(LOG_INTERVAL * 1000000); // Wait for log interval before trying again
            continue;
        }

        log_temperature(temp);
        warn_if_high_temperature(temp);

        sleep(LOG_INTERVAL);
    }

    printf("Exiting...\n");
    return 0;
}