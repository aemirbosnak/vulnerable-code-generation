//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define PORT 110

void display_error(const char *error_message) {
    printf("[ERROR]: %s\n", error_message);
    exit(1);
}

void send_request(int sockfd, const char *request) {
    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);
    sprintf(buffer, "%s\r\n", request);
    send(sockfd, buffer, strlen(buffer), 0);
    printf("SENT: %s\n", buffer);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("RECEIVED: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    int sockfd, portnum;
    char buffer[BUFFER_SIZE];
    struct hostent *server;
    struct sockaddr_in serv_addr;

    if(argc != 3) {
        display_error("Usage: ./pop3_client <server_address> <username>");
    }

    server = gethostbyname(argv[1]);
    if(!server) {
        display_error("The server was not found!");
    }

    portnum = PORT;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        display_error("Could not create socket!");
    }

    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char*) server->h_addr, (char*) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portnum);

    if(connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        display_error("Failed to connect to server!");
    }

    receive_response(sockfd);
    send_request(sockfd, "USER");
    receive_response(sockfd);
    sprintf(buffer, "PASS %s", "********");
    send_request(sockfd, buffer);
    receive_response(sockfd);
    send_request(sockfd, "STAT");
    receive_response(sockfd);
    send_request(sockfd, "LIST");
    receive_response(sockfd);

    return 0;
}