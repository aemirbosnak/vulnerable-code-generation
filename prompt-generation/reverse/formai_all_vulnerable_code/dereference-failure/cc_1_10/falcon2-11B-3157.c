//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

// Function to create socket and connect to server
int create_connection(const char* hostname, const char* port) {
    int sockfd;
    struct sockaddr_in server_address;
    struct hostent* server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        return -1;
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        perror("gethostbyname failed");
        return -1;
    }

    bzero((char*) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char*) server->h_addr, (char*) &server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(atoi(port));

    if (connect(sockfd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        perror("connect failed");
        return -1;
    }

    return sockfd;
}

// Function to send data to server
void send_data(int sockfd, const char* data) {
    int sent = send(sockfd, data, strlen(data), 0);
    if (sent < 0) {
        perror("send failed");
    }
}

// Function to receive data from server
char* receive_data(int sockfd) {
    char* buffer = (char*) malloc(BUFSIZ);
    int received = recv(sockfd, buffer, BUFSIZ, 0);
    if (received < 0) {
        perror("recv failed");
        return NULL;
    }
    return buffer;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    int sockfd = create_connection(argv[1], argv[2]);
    if (sockfd < 0) {
        return -1;
    }

    printf("Connected to %s:%s\n", argv[1], argv[2]);

    // Send data
    send_data(sockfd, "USER anonymous\r\n");
    send_data(sockfd, "PASS anonymous\r\n");
    send_data(sockfd, "QUIT\r\n");

    // Receive data
    char* response = receive_data(sockfd);
    if (response!= NULL) {
        printf("%s", response);
        free(response);
    }

    close(sockfd);

    return 0;
}