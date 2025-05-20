//Falcon2-11B DATASET v1.0 Category: Networking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>

// Function to send data to the server
void send_data(int sockfd, char *data, int len) {
    int sent = send(sockfd, data, len, 0);
    if (sent < 0) {
        perror("send error");
        exit(1);
    }
}

// Function to receive data from the server
int receive_data(int sockfd, char *buffer, int len) {
    int received = recv(sockfd, buffer, len, 0);
    if (received < 0) {
        perror("recv error");
        exit(1);
    }
    return received;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <host>\n", argv[0]);
        exit(1);
    }

    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: Unknown host\n");
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket error");
        exit(1);
    }

    struct sockaddr_in serv_addr;
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);

    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    // Send request
    char request[100] = "GET /index.html HTTP/1.1\r\nHost: example.com\r\n\r\n";
    send_data(sockfd, request, strlen(request));

    // Receive response
    char response[4096];
    int bytes_received = receive_data(sockfd, response, sizeof(response));
    if (bytes_received < 0) {
        perror("receive error");
        exit(1);
    }

    printf("Response:\n");
    printf("%s", response);

    close(sockfd);
    return 0;
}