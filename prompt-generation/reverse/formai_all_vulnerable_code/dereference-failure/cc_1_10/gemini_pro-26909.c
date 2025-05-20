//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>

int main() {
    int sockfd, n;
    char buffer[256];
    struct sockaddr_in serv_addr;
    struct hostent *server;
    int i = 0;
    int failedCounter = 0;
    char website[50] = "www.example.com";
    time_t startTime, endTime;
    double totalTime;

    while (1) {
        startTime = time(NULL);
        server = gethostbyname(website);
        if (server == NULL) {
            printf("ERROR: No such host\n");
            failedCounter++;
        } else {
            sockfd = socket(AF_INET, SOCK_STREAM, 0);
            if (sockfd < 0) {
                printf("ERROR: Socket creation failed\n");
                failedCounter++;
            } else {
                serv_addr.sin_family = AF_INET;
                serv_addr.sin_port = htons(80);
                serv_addr.sin_addr = *((struct in_addr *)server->h_addr);
                if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
                    printf("ERROR: Connection failed\n");
                    failedCounter++;
                } else {
                    n = read(sockfd, buffer, sizeof(buffer));
                    if (n < 0) {
                        printf("ERROR: Read failed\n");
                        failedCounter++;
                    } else {
                        close(sockfd);
                    }
                }
            }
        }

        endTime = time(NULL);
        totalTime = difftime(endTime, startTime);
        printf("Website: %s\n", website);
        printf("Status: ");
        if (failedCounter == 0) {
            printf("Online (%.2f seconds)\n", totalTime);
        } else {
            printf("Offline (%.2f seconds)\n", totalTime);
            failedCounter = 0;
        }
        i++;
        sleep(30);
    }

    return 0;
}