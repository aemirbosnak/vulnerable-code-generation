//Falcon2-11B DATASET v1.0 Category: Website Uptime Monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>

int is_website_accessible(char* url);
void log_results(int result);
void version();

int main() {
    version();

    while (1) {
        sleep(30);
        if (is_website_accessible("www.google.com")) {
            log_results(1);
        } else {
            log_results(0);
        }
    }
}

int is_website_accessible(char* url) {
    char command[256];
    sprintf(command, "curl -s %s 2>&1", url);
    FILE* pipe = popen(command, "r");
    int error_code = 0;

    if (!pipe) {
        perror("popen");
        error_code = errno;
    }

    char buffer[1024];
    fgets(buffer, sizeof(buffer), pipe);
    pclose(pipe);

    if (error_code) {
        return error_code;
    }

    return (strcmp(buffer, "HTTP/1.1 200 OK") == 0);
}

void log_results(int result) {
    printf("%s\n", result? "Website is accessible" : "Website is not accessible");
}

void version() {
    printf("Website Uptime Monitor v1.0\n");
    printf("A program to monitor the uptime of a website.\n");
}