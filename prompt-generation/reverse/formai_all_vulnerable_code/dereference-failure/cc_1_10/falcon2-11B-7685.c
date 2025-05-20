//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <pthread.h>

#define BUFF_SIZE 1024
#define PORT 993

void *imap_client(void *data) {
    int sockfd, n;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buf[BUFF_SIZE];
    char command[BUFF_SIZE];

    memset(command, 0, BUFF_SIZE);
    memset(buf, 0, BUFF_SIZE);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("imap.example.com");
    if (server == NULL) {
        fprintf(stderr, "Host not found\n");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connection error");
        exit(EXIT_FAILURE);
    }

    sprintf(command, "LOGIN user1 password");
    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("Send error");
        exit(EXIT_FAILURE);
    }

    if (recv(sockfd, buf, BUFF_SIZE, 0) == -1) {
        perror("Recv error");
        exit(EXIT_FAILURE);
    }

    if (strcmp(buf, "OK LOGIN completed")!= 0) {
        fprintf(stderr, "Login failed: %s\n", buf);
        exit(EXIT_FAILURE);
    }

    sprintf(command, "LIST \"*\"");
    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("Send error");
        exit(EXIT_FAILURE);
    }

    if (recv(sockfd, buf, BUFF_SIZE, 0) == -1) {
        perror("Recv error");
        exit(EXIT_FAILURE);
    }

    printf("IMAP Client:\n");
    printf("%s", buf);

    close(sockfd);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;

    if (pthread_create(&thread, NULL, imap_client, NULL)!= 0) {
        perror("Thread creation error");
        exit(EXIT_FAILURE);
    }

    pthread_join(thread, NULL);

    return 0;
}