//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_COMMAND_LENGTH 512
#define MAX_RESPONSE_LENGTH 1024

int sockfd;
char *server_ip;
int server_port;

void *receive_thread(void *arg);

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage:./pop3_client <server_ip> <server_port> <username>\n");
        return 1;
    }

    server_ip = argv[1];
    server_port = atoi(argv[2]);
    char *username = argv[3];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sockfd);
        return 1;
    }

    pthread_t receive_thread_id;
    pthread_create(&receive_thread_id, NULL, receive_thread, NULL);

    char *command = "USER ";
    strcat(command, username);
    send(sockfd, command, strlen(command), 0);

    char *response = (char *)malloc(MAX_RESPONSE_LENGTH);
    memset(response, 0, MAX_RESPONSE_LENGTH);
    int response_len = recv(sockfd, response, MAX_RESPONSE_LENGTH, 0);
    printf("Server response: %s\n", response);

    char *command2 = "PASS ";
    strcat(command2, username);
    strcat(command2, "\r\n");
    send(sockfd, command2, strlen(command2), 0);

    response_len = recv(sockfd, response, MAX_RESPONSE_LENGTH, 0);
    printf("Server response: %s\n", response);

    close(sockfd);
    return 0;
}

void *receive_thread(void *arg) {
    char buffer[MAX_RESPONSE_LENGTH];
    while (1) {
        memset(buffer, 0, MAX_RESPONSE_LENGTH);
        int response_len = recv(sockfd, buffer, MAX_RESPONSE_LENGTH, 0);
        if (response_len <= 0) {
            break;
        }
        printf("Server response: %s\n", buffer);
    }
}