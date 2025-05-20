//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define MAX_SIZE 1024
#define PORT 110

typedef struct client_info {
    int sockfd;
    char *email;
    char *password;
} client_info;

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void* receive(void *arg) {
    client_info *info = (client_info*) arg;
    char buffer[MAX_SIZE];
    memset(buffer, 0, MAX_SIZE);

    int n = recv(info->sockfd, buffer, MAX_SIZE - 1, 0);
    if (n < 0) {
        error("Error reading from socket");
    }

    printf("%s\n", buffer);
    close(info->sockfd);
    return NULL;
}

int main(int argc, char *argv[]) {
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 4) {
        fprintf(stderr, "usage %s hostname email password\n", argv[0]);
        exit(0);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(0);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("Error connecting to server");
    }

    client_info info;
    info.sockfd = sockfd;
    info.email = argv[2];
    info.password = argv[3];

    char buffer[MAX_SIZE];
    memset(buffer, 0, MAX_SIZE);

    pthread_t receive_thread;

    int n = recv(sockfd, buffer, MAX_SIZE - 1, 0);
    if (n < 0) {
        error("Error reading from socket");
    }

    printf("%s\n", buffer);
    memset(buffer, 0, MAX_SIZE);

    sprintf(buffer, "USER %s\r\n", info.email);
    n = send(sockfd, buffer, strlen(buffer), 0);

    memset(buffer, 0, MAX_SIZE);
    n = recv(sockfd, buffer, MAX_SIZE - 1, 0);

    if (strncmp(buffer, "+OK", 3) != 0) {
        printf("%s\n", buffer);
        return 1;
    }

    memset(buffer, 0, MAX_SIZE);
    sprintf(buffer, "PASS %s\r\n", info.password);
    n = send(sockfd, buffer, strlen(buffer), 0);

    memset(buffer, 0, MAX_SIZE);
    n = recv(sockfd, buffer, MAX_SIZE - 1, 0);

    if (strncmp(buffer, "+OK", 3) != 0) {
        printf("%s\n", buffer);
        return 1;
    }

    memset(buffer, 0, MAX_SIZE);
    sprintf(buffer, "STAT\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);

    memset(buffer, 0, MAX_SIZE);
    n = recv(sockfd, buffer, MAX_SIZE - 1, 0);

    if (strncmp(buffer, "+OK", 3) != 0) {
        printf("%s\n", buffer);
        return 1;
    }

    char *num_messages_ptr = strchr(buffer, ' ') + 1;
    int num_messages = atoi(num_messages_ptr);

    printf("Number of messages: %d\n", num_messages);

    pthread_create(&receive_thread, NULL, receive, &info);

    memset(buffer, 0, MAX_SIZE);
    sprintf(buffer, "RETR 1\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);

    pthread_join(receive_thread, NULL);

    return 0;
}