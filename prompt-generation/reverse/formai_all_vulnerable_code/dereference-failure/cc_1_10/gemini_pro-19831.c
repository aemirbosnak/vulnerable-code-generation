//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: medieval
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define BUFF_SIZE 1024
#define MAX_HOSTS 10

typedef struct {
    char *hostname;
    int port;
    int sockfd;
    struct sockaddr_in serv_addr;
    struct timeval start_time;
    struct timeval end_time;
    int elapsed_time;
} host_info;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    host_info hosts[MAX_HOSTS];
    int num_hosts = 0;

    // Create a socket and connect to the server
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if (num_hosts >= MAX_HOSTS) {
        printf("Too many hosts specified\n");
        return 1;
    }

    hosts[num_hosts].hostname = hostname;
    hosts[num_hosts].port = port;
    hosts[num_hosts].sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (hosts[num_hosts].sockfd < 0) {
        perror("socket");
        return 1;
    }

    if (connect(hosts[num_hosts].sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return 1;
    }

    num_hosts++;

    // Send a message to the server
    char *message = "Hello world!";
    int len = strlen(message);
    if (send(hosts[0].sockfd, message, len, 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive a message from the server
    char buffer[BUFF_SIZE];
    int recvlen = recv(hosts[0].sockfd, buffer, BUFF_SIZE, 0);
    if (recvlen < 0) {
        perror("recv");
        return 1;
    }

    buffer[recvlen] = '\0';
    printf("Received: %s\n", buffer);

    // Close the socket
    close(hosts[0].sockfd);

    return 0;
}