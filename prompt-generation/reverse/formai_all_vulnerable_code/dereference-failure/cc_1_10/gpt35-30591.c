//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#define MAX_URL_LENGTH 1000 // maximum length of URL to be monitored
#define SLEEP_TIME 10 // time in seconds to sleep between checking the server status

// function to check if a website is up
bool isWebsiteUp(char* url) {
    FILE* fp = NULL;
    char command[MAX_URL_LENGTH + 15];
    sprintf(command, "curl --silent --head %s | grep -q 'HTTP/1.1 200 OK'", url);
    fp = popen(command, "r");
    if (fp == NULL) {
        printf("Error: Could not execute curl command\n");
        exit(1);
    }
    char result[100];
    fgets(result, sizeof(result)/sizeof(result[0]), fp);
    pclose(fp);
    if (strcmp(result, "") == 0) {
        return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: uptime_monitor <url>\n");
        exit(1);
    }
    char* url = argv[1];
    if (strlen(url) > MAX_URL_LENGTH) {
        printf("Error: URL is too long\n");
        exit(1);
    }

    // loop to check if the website is up
    while (true) {
        if (isWebsiteUp(url)) {
            printf("%s is up\n", url);
        } else {
            printf("%s is down\n", url);
        }
        sleep(SLEEP_TIME);
    }
    return 0;
}