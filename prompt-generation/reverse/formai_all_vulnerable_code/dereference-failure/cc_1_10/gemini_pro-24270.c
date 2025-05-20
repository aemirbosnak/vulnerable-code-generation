//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Cryptic
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define BUF_SIZE 1024

/*
 * This structure stores the QoS parameters for a particular socket.
 */
typedef struct {
    int sockfd;
    int tos;
    int priority;
} qos_params;

/*
 * This function creates a new socket with the specified QoS parameters.
 */
int create_socket(qos_params *qos) {
    int sockfd;
    int optval;

    /* Create a new socket. */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    /* Set the socket's QoS parameters. */
    optval = qos->tos;
    if (setsockopt(sockfd, IPPROTO_IP, IP_TOS, &optval, sizeof(optval)) == -1) {
        perror("setsockopt");
        close(sockfd);
        return -1;
    }

    optval = qos->priority;
    if (setsockopt(sockfd, SOL_SOCKET, SO_PRIORITY, &optval, sizeof(optval)) == -1) {
        perror("setsockopt");
        close(sockfd);
        return -1;
    }

    return sockfd;
}

/*
 * This function sends a message to the specified socket using the specified QoS parameters.
 */
int send_message(int sockfd, qos_params *qos, char *message) {
    int len;

    /* Send the message. */
    len = send(sockfd, message, strlen(message), 0);
    if (len == -1) {
        perror("send");
        return -1;
    }

    return len;
}

/*
 * This function receives a message from the specified socket using the specified QoS parameters.
 */
int receive_message(int sockfd, qos_params *qos, char *buffer) {
    int len;

    /* Receive the message. */
    len = recv(sockfd, buffer, BUF_SIZE, 0);
    if (len == -1) {
        perror("recv");
        return -1;
    }

    return len;
}

/*
 * This function closes the specified socket.
 */
void close_socket(int sockfd) {
    close(sockfd);
}

int main(int argc, char **argv) {
    int sockfd;
    qos_params qos;
    char buffer[BUF_SIZE];
    char message[BUF_SIZE];
    int len;

    /* Parse the command-line arguments. */
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <host> <port> <tos> <priority>\n", argv[0]);
        return 1;
    }

    /* Create a new socket with the specified QoS parameters. */
    qos.tos = atoi(argv[3]);
    qos.priority = atoi(argv[4]);
    sockfd = create_socket(&qos);
    if (sockfd == -1) {
        return 1;
    }

    /* Connect to the specified host and port. */
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        close_socket(sockfd);
        return 1;
    }

    /* Send a message to the server. */
    strcpy(message, "Hello, world!");
    len = send_message(sockfd, &qos, message);
    if (len == -1) {
        close_socket(sockfd);
        return 1;
    }

    printf("Sent %d bytes: %s\n", len, message);

    /* Receive a message from the server. */
    len = receive_message(sockfd, &qos, buffer);
    if (len == -1) {
        close_socket(sockfd);
        return 1;
    }

    printf("Received %d bytes: %s\n", len, buffer);

    /* Close the socket. */
    close_socket(sockfd);

    return 0;
}