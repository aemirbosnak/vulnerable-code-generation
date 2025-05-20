//Falcon2-11B DATASET v1.0 Category: Log analysis ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <time.h>

#define BUF_SIZE 1024
#define LOG_FILE "/var/log/syslog"

void print_time(struct timeval *tv) {
    printf("%ld.%06ld\n", tv->tv_sec, tv->tv_usec);
}

int main() {
    FILE *fp;
    char buffer[BUF_SIZE];
    char *buf;
    int len;
    struct timeval start_time, end_time;
    double time_taken;
    int bytes_read;

    // Open log file for reading
    if ((fp = fopen(LOG_FILE, "r")) == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        exit(1);
    }

    // Read log entries until end of file
    while ((bytes_read = getline(&buf, &len, fp))!= -1) {
        // Skip empty lines
        if (buf[0] == '\n') {
            continue;
        }

        // Print log entry time
        gettimeofday(&start_time, NULL);
        fflush(stdout);
        fputs(buf, stdout);
        fflush(stdout);
        gettimeofday(&end_time, NULL);
        time_taken = (end_time.tv_sec - start_time.tv_sec) + ((end_time.tv_usec - start_time.tv_usec) / 1000000.0);
        printf("Time taken to print log entry: %f seconds\n", time_taken);
    }

    // Close log file
    fclose(fp);

    return 0;
}