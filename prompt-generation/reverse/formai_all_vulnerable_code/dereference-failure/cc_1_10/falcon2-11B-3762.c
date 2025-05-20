//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

// global variables
int sockfd;
struct sockaddr_in serv_addr;

// function prototypes
void send_msg(int sockfd);
void print_usage(char *program_name);

// main program
int main(int argc, char *argv[]) {
    // check for correct usage
    if (argc!= 3) {
        print_usage(argv[0]);
        exit(1);
    }

    // parse the arguments
    char *server_ip = argv[1];
    char *server_port = argv[2];

    // create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // set up the server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(server_port));
    if (inet_pton(AF_INET, server_ip, &serv_addr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    // connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // send a message to the server
    send_msg(sockfd);

    // close the socket
    close(sockfd);

    return 0;
}

// function to send a message to the server
void send_msg(int sockfd) {
    char msg[100];
    printf("Enter a message: ");
    fgets(msg, 100, stdin);

    // send the message to the server
    send(sockfd, msg, strlen(msg), 0);

    // check for errors
    if (send(sockfd, msg, strlen(msg), 0) == -1) {
        perror("send");
        exit(1);
    }

    // check for server response
    int response = 0;
    char response_buffer[100];
    recv(sockfd, response_buffer, sizeof(response_buffer), 0);
    if (response == 0) {
        perror("server did not respond");
        exit(1);
    }
}

// function to print usage information
void print_usage(char *program_name) {
    fprintf(stderr, "Usage: %s <server_ip> <server_port>\n", program_name);
    exit(1);
}