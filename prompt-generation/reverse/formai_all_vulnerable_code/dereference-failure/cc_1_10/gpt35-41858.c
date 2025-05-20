//FormAI DATASET v1.0 Category: Port Scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 1024
#define BUFFER_SIZE 250

void *scan_port(void *arg);

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: %s <ip address> <port range>\n", argv[0]);
        printf("Example: %s 127.0.0.1 1-65535\n", argv[0]);
        exit(1);
    }

    char *ip = argv[1];
    char *port_range = argv[2];
    char *token = NULL;
    char *delimiter = "-";

    int start_port, end_port;
    int i, thread_num = 0;
    int listenfd = 0, sockfd = 0;
    int *new_sock = NULL;

    pthread_t tids[MAX_THREADS];

    struct sockaddr_in serv_addr;

    printf("Scanning %s...\n", ip);

    // Parse port range arguments
    token = strtok(port_range, delimiter);
    start_port = atoi(token);
    token = strtok(NULL, delimiter);
    end_port = atoi(token);

    for(i = start_port; i <= end_port; i++) {
        // Create a new thread to scan each port
        new_sock = malloc(sizeof(int));
        *new_sock = i;

        // Create socket
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if(sockfd < 0) {
            perror("Error creating socket\n");
            exit(1);
        }

        // Set socket options
        int optval = 1;
        setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

        // Set server address
        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(i);
        serv_addr.sin_addr.s_addr = inet_addr(ip);

        // Connect socket to server
        if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            // Port is closed
            close(sockfd);
            free(new_sock);
        }
        else {
            // Port is open
            char port_info[BUFFER_SIZE];
            sprintf(port_info, "Port %d is open\n", i);
            printf("%s", port_info);

            // Create thread to handle connection
            pthread_create(&tids[thread_num], NULL, scan_port, (void *)new_sock);

            thread_num++;
            if(thread_num >= MAX_THREADS) {
                // Maximum number of threads reached, wait for some of them to finish before continuing
                while(thread_num >= MAX_THREADS) {
                    void *status = NULL;
                    pthread_join(tids[thread_num - MAX_THREADS], &status);
                }
            }
        }
    }

    // Wait for remaining threads to finish
    for(i = 0; i < thread_num; i++) {
        pthread_join(tids[i], NULL);
    }

    return 0;
}

void *scan_port(void *arg) {
    int port = *(int *)arg;
    char buffer[BUFFER_SIZE];

    sprintf(buffer, "Hello, port %d!\r\n", port);
    printf("Sending \"%s\" to port %d...\n", buffer, port);

    // Initialize socket and server address
    int sockfd = 0;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error creating socket\n");
        return NULL;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    // Connect socket to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to socket\n");
        return NULL;
    }

    // Send message to port
    if(send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message\n");
        return NULL;
    }

    // Receive response from port
    ssize_t n = 0;
    char recvBuff[BUFFER_SIZE];
    memset(recvBuff, '0', sizeof(recvBuff));

    if((n = recv(sockfd, recvBuff, sizeof(recvBuff) - 1, 0)) < 0) {
        perror("Error receiving data\n");
        return NULL;
    }

    recvBuff[n] = 0;
    printf("Response from port %d: %s\n", port, recvBuff);

    close(sockfd);

    return NULL;
}