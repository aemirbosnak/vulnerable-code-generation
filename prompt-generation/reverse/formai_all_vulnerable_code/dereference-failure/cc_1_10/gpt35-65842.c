//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define MAX_URLS 100
#define MAX_TIMEOUT 5000000
#define MAX_RETRIES 3

int running = 1;

void stop(int sig) {
    running = 0;
}

void check_url(char *url) {
    int timeout = MAX_TIMEOUT;
    int retries = MAX_RETRIES;
    int success = 0;

    while (retries > 0 && !success) {
        if (system(NULL) == 0) {
            printf("Command processor is not available\n");
            exit(1);
        }

        char command[256];
        sprintf(command, "ping -c 5 -w %d %s > /dev/null 2>&1", timeout/1000, url);

        int result = system(command);

        if (result == 0) {
            printf("%s is up\n", url);
            success = 1;
        } else {
            printf("%s is down\n", url);
            retries--;

            if (retries == 0) {
                printf("%s is still down after %d retries\n", url, MAX_RETRIES);
            } else {
                printf("%s will be rechecked in %d seconds\n", url, timeout/1000000);
                usleep(timeout);
                timeout *= 2;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    signal(SIGINT, stop);

    char urls[MAX_URLS][100];
    int num_urls = 0;

    for (int i = 1; i < argc; i++) {
        if (num_urls == MAX_URLS) {
            printf("Maximum number of URLs reached\n");
            break;
        }

        strcpy(urls[num_urls], argv[i]);
        num_urls++;
    }

    printf("Website Uptime Monitor started\n");

    while (running) {
        for (int i = 0; i < num_urls; i++) {
            check_url(urls[i]);
        }

        time_t t = time(NULL);
        struct tm *time_info = localtime(&t);
        printf("Last checked URLs at %s\n", asctime(time_info));

        sleep(60);
    }

    printf("Website Uptime Monitor stopped\n");

    return 0;
}