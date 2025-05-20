//MISTRAL-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <time.h>

#define MAX_RETRIES 5
#define TIMEOUT 5000
#define CHECK_INTERVAL 60
#define SERVER_PORT 80
#define SERVER_IP "google.com"

int main() {
    int sockfd, i, retries = 0;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];

    while (1) {
        printf("Checking uptime of %s... ", SERVER_IP);
        fflush(stdout);

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("socket creation error");
            printf("Failed\n");
            sleep(CHECK_INTERVAL);
            continue;
        }

        server = gethostbyname(SERVER_IP);
        if (server == NULL) {
            fprintf(stderr, "ERROR, unknown hostname %s\n", SERVER_IP);
            close(sockfd);
            printf("Failed\n");
            sleep(CHECK_INTERVAL);
            continue;
        }

        bzero((char *) &serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        bcopy((char *)server->h_addr,
             (char *)&serv_addr.sin_addr.s_addr,
             server->h_length);
        serv_addr.sin_port = htons(SERVER_PORT);

        if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            perror("connection failed");
            retries++;
            if (retries >= MAX_RETRIES) {
                printf("Failed\n");
                close(sockfd);
                sleep(CHECK_INTERVAL);
                continue;
            }
            printf("Retrying in %d seconds... ", CHECK_INTERVAL/1000);
            fflush(stdout);
            sleep(TIMEOUT/1000);
            continue;
        }

        close(sockfd);
        printf("Success\n");

        time_t current_time = time(NULL);
        printf("Uptime: %s\n", ctime(&current_time));

        sleep(CHECK_INTERVAL);
    }

    return 0;
}