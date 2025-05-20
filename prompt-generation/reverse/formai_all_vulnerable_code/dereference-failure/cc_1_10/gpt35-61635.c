//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: synchronous
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <signal.h>

#define CLIENT_BUFFER_SIZE 1000
#define SERVER_BUFFER_SIZE 10000

/* Global variables */
struct sockaddr_in serv_addr;
int serv_fd;

/* SIGINT signal handler function */
void signalHandler(int s) {
    printf("Caught signal %d\n", s);
    printf("Closing server connection\n");
    close(serv_fd);
    exit(EXIT_SUCCESS);
}

/* Function to set up the server connection */
void setupServer(char *ip_addr, uint16_t port) {
    /* Create socket */
    serv_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (serv_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    /* Set server connection details */
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip_addr);
    serv_addr.sin_port = htons(port);
    /* Connect to server */
    if (connect(serv_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }
}

/* Function to read data from server */
void readServer(char *buffer) {
    ssize_t recv_len;
    memset(buffer, 0, SERVER_BUFFER_SIZE);
    recv_len = recv(serv_fd, buffer, SERVER_BUFFER_SIZE-1, 0);
    if (recv_len == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("Server response: %s\n", buffer);
}

/* Function to write data to server */
void writeServer(char *buffer) {
    ssize_t send_len;
    printf("Sending: %s\n", buffer);
    send_len = send(serv_fd, buffer, strlen(buffer), 0);
    if (send_len == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }
}

/* Main function */
int main(int argc, char *argv[]) {
    /* Check for correct number of arguments */
    if (argc != 3) {
        printf("Usage: %s <IP address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    /* Set up signal handler for SIGINT */
    signal(SIGINT, signalHandler);
    /* Set up server connection */
    setupServer(argv[1], atoi(argv[2]));
    /* Main loop */
    char client_buffer[CLIENT_BUFFER_SIZE];
    char server_buffer[SERVER_BUFFER_SIZE];
    while (1) {
        /* Read user input */
        printf("Enter message: ");
        if (fgets(client_buffer, CLIENT_BUFFER_SIZE, stdin) == NULL) {
            perror("fgets");
            exit(EXIT_FAILURE);
        }
        /* Send user input to server */
        writeServer(client_buffer);
        /* Read response from server */
        readServer(server_buffer);
    }
    return 0;
}