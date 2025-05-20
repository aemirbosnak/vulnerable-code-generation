//FormAI DATASET v1.0 Category: Socket programming ; Style: Dennis Ritchie
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define BUF_SIZE 256

// helper function to handle errors
void handle_error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {

    int sockfd, port;
    char *ip_addr;
    struct sockaddr_in serv_addr;
    char buf[BUF_SIZE];

    if(argc!=3) {
        printf("Usage: %s <ip_address> <port_number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ip_addr = argv[1];
    port = atoi(argv[2]);

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        handle_error("Could not create socket");
    }

    // set server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if(inet_pton(AF_INET, ip_addr, &serv_addr.sin_addr) <= 0) {
        handle_error("Could not set server address");
    }

    // connect to server
    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        handle_error("Could not connect to server");
    }

    // loop to send/receive messages
    while(1) {
        printf("Enter message: ");
        fgets(buf, BUF_SIZE, stdin);
        // remove newline character
        buf[strlen(buf)-1] = '\0';

        // send message to server
        if(send(sockfd, buf, strlen(buf), 0) < 0) {
            handle_error("Could not send message");
        }

        // receive message from server
        memset(buf, 0, BUF_SIZE);
        if(recv(sockfd, buf, BUF_SIZE, 0) < 0) {
            handle_error("Could not receive message");
        }
        printf("Server response: %s\n", buf);
    }

    // close socket
    close(sockfd);

    return 0;
}