//FormAI DATASET v1.0 Category: System boot optimizer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_FILE_NAME_SIZE 256
#define BOOT_TIME_FILE "/var/log/boot.time"
#define BOOT_OPTIMIZER_LOG_FILE "/var/log/boot.optimizer.log"

/* function to get current time in human-readable format */
void getCurrentTime(char* curr_time) {
    time_t rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(curr_time, 80, "%Y-%m-%d %H:%M:%S", timeinfo); 
}

/* function to write log in Boot Optimizer Log file */
void writeLog(char* log) {
    int fd, count;
    char curr_time[80];
    getCurrentTime(curr_time);
    fd = open(BOOT_OPTIMIZER_LOG_FILE, O_CREAT | O_APPEND | O_WRONLY, 0664);
    if (fd == -1) {
        perror("Error: Failed to open log file");
        exit(1);
    }
    count = write(fd, curr_time, strlen(curr_time));
    if (count == -1) {
        perror("Error: Failed to write log");
        close(fd);
        exit(1);
    }
    count = write(fd, " ", 1);
    if (count == -1) {
        perror("Error: Failed to write log");
        close(fd);
        exit(1);
    }
    count = write(fd, log, strlen(log));
    if (count == -1) {
        perror("Error: Failed to write log");
        close(fd);
        exit(1);
    }
    count = write(fd, "\n", 1);
    if (count == -1) {
        perror("Error: Failed to write log");
        close(fd);
        exit(1);
    }
    close(fd);
}

/* function to read boot time from Boot Time file */
unsigned long long int readBootTime() {
    int fd, count;
    unsigned long long int boot_time = 0;
    char buffer[MAX_BUFFER_SIZE];
    char* token;
    fd = open(BOOT_TIME_FILE, O_RDONLY, 0664);
    if (fd == -1) {
        perror("Error: Failed to open boot time file");
        exit(1);
    }
    count = read(fd, buffer, MAX_BUFFER_SIZE);
    if (count == -1) {
        perror("Error: Failed to read boot time");
        close(fd);
        exit(1);
    }
    token = strtok(buffer, " ");
    boot_time = atoll(token);
    close(fd);
    return boot_time;
}

/* function to calculate system boot time */
unsigned long long int calculateBootTime() {
    FILE *fp;
    unsigned long long int boot_time;
    char* token;
    char buffer[MAX_BUFFER_SIZE];
    fp = popen("systemd-analyze", "r");
    if (fp == NULL) {
        perror("Error: Failed to execute systemd-analyze command");
        exit(1);
    }
    while (fgets(buffer, MAX_BUFFER_SIZE, fp) != NULL) {
        if (strstr(buffer, "Startup finished") != NULL) {
            token = strtok(buffer, " ");
            token = strtok(NULL, " ");
            token = strtok(NULL, " ");
            boot_time = atoll(token);
            break;
        }
    }
    pclose(fp);
    return boot_time;
}

/* function to optimize system boot time */
void optimizeBootTime() {
    unsigned long long int boot_time, curr_boot_time;
    char log[MAX_BUFFER_SIZE];
    boot_time = readBootTime();
    curr_boot_time = calculateBootTime();
    if (curr_boot_time < boot_time) {
        snprintf(log, MAX_BUFFER_SIZE, "System boot time reduced from %llu ms to %llu ms", boot_time, curr_boot_time);   
        writeLog(log);
        /* update Boot Time file with new boot time */
        int fd = open(BOOT_TIME_FILE, O_CREAT | O_WRONLY | O_TRUNC, 0664);
        if (fd == -1) {
            perror("Error: Failed to open boot time file");
            exit(1);
        }
        char boot_time_str[MAX_BUFFER_SIZE];
        snprintf(boot_time_str, MAX_BUFFER_SIZE, "%llu\n", curr_boot_time);
        int count = write(fd, boot_time_str, strlen(boot_time_str));
        if (count == -1) {
            perror("Error: Failed to write boot time");
            close(fd);
            exit(1);
        }
        close(fd);
    }
    else {
        snprintf(log, MAX_BUFFER_SIZE, "System boot time is already optimized at %llu ms", boot_time);
        writeLog(log);
    }
}

int main() {
    /* check if Boot Time file exists, if not create it */
    struct stat buffer;
    int ret = stat(BOOT_TIME_FILE, &buffer);
    if (ret == -1) {
        if (errno == ENOENT) {
            /* Boot Time file does not exist, create it */
            int fd = open(BOOT_TIME_FILE, O_CREAT | O_WRONLY | O_TRUNC, 0664);
            if (fd == -1) {
                perror("Error: Failed to create boot time file");
                exit(1);
            }
            char boot_time_str[MAX_BUFFER_SIZE];
            /* set current boot time as boot time in Boot Time file */
            unsigned long long int boot_time = calculateBootTime();
            snprintf(boot_time_str, MAX_BUFFER_SIZE, "%llu\n", boot_time);
            int count = write(fd, boot_time_str, strlen(boot_time_str));
            if (count == -1) {
                perror("Error: Failed to write boot time");
                close(fd);
                exit(1);
            }
            close(fd);
        }
        else {
            perror("Error: Failed to get stat of boot time file");
            exit(1);
        }
    }
    optimizeBootTime();
    return 0;
}