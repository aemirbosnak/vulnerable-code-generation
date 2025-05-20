//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define MAX_URL_LENGTH 256 // maximum length of the URL

// function to get current date and time
char* getDateTime() {
    time_t now = time(NULL);
    char* dateTime = ctime(&now);
    dateTime[strlen(dateTime) - 1] = '\0'; // remove newline character
    return dateTime;
}

int main(int argc, char* argv[]) {
    char url[MAX_URL_LENGTH]; // URL to monitor
    int interval; // interval between monitoring requests
    char* dateTime;

    printf("Enter the URL to monitor: ");
    scanf("%s", url);

    printf("Enter the monitoring interval (in seconds): ");
    scanf("%d", &interval);

    while (1) {
        dateTime = getDateTime();
        printf("%s - Requesting %s...", dateTime, url);

        // create child process
        int pid = fork();
        if (pid == 0) {
            // child process
            execlp("curl", "curl", "-IsS", url, NULL);
            exit(0);
        } else {
            // parent process
            int childStatus;
            wait(&childStatus);

            if (WIFEXITED(childStatus) && WEXITSTATUS(childStatus) == 0) {
                printf("Website is up!\n");
            } else {
                printf("Website is down!\n");
            }

            sleep(interval);
        }
    }

    return 0;
}