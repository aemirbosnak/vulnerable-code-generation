//Falcon-180B DATASET v1.0 Category: Email Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

#define MAX_LINE 1024
#define PORT "110"
#define USER "username"
#define PASS "password"

// Function prototypes
void *receive_thread(void *socket);

int main() {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[MAX_LINE];
    int n;
    char *username = USER;
    char *password = PASS;
    char *date_time;
    pthread_t thread_id;

    // Connect to server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    portno = atoi(PORT);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Authenticate user
    send(sockfd, username, strlen(username), 0);
    send(sockfd, password, strlen(password), 0);

    // Start receive thread
    pthread_create(&thread_id, NULL, receive_thread, sockfd);

    // Main loop
    while (1) {
        memset(buffer, 0, MAX_LINE);
        n = read(sockfd, buffer, MAX_LINE);
        if (n <= 0) {
            printf("Error reading from server\n");
            exit(1);
        }
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}

void *receive_thread(void *socket) {
    int sockfd = *((int *)socket);
    char buffer[MAX_LINE];
    int n;

    // Receive messages from server
    while (1) {
        memset(buffer, 0, MAX_LINE);
        n = read(sockfd, buffer, MAX_LINE);
        if (n <= 0) {
            printf("Error reading from server\n");
            exit(1);
        }

        // Display message with date and time
        time_t now = time(NULL);
        char *date_time = ctime(&now);
        printf("%s - %s", date_time, buffer);
    }

    return NULL;
}