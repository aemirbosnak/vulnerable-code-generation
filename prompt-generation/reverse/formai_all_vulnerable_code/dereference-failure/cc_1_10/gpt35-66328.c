//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {

    if (argc != 3) {
        printf("Usage: %s <server address> <username>\n", argv[0]);
        exit(1);
    }

    char *server_address = argv[1];
    char *user = argv[2];
    char *pass = getpass("Enter password: ");
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Get server information
    server = gethostbyname(server_address);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host: %s\n", server_address);
        exit(1);
    }

    // Set server address
    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(110); // POP3 Port

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    // Read server response
    memset(recv_buffer, 0, BUFFER_SIZE);
    n = read(sockfd, recv_buffer, BUFFER_SIZE);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", recv_buffer);

    // Send USER command
    memset(send_buffer, 0, BUFFER_SIZE);
    sprintf(send_buffer, "USER %s\r\n", user);
    n = write(sockfd, send_buffer, strlen(send_buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Read server response
    memset(recv_buffer, 0, BUFFER_SIZE);
    n = read(sockfd, recv_buffer, BUFFER_SIZE);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", recv_buffer);

    // Send PASS command
    memset(send_buffer, 0, BUFFER_SIZE);
    sprintf(send_buffer, "PASS %s\r\n", pass);
    n = write(sockfd, send_buffer, strlen(send_buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Read server response
    memset(recv_buffer, 0, BUFFER_SIZE);
    n = read(sockfd, recv_buffer, BUFFER_SIZE);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", recv_buffer);

    // Send LIST command
    memset(send_buffer, 0, BUFFER_SIZE);
    sprintf(send_buffer, "LIST\r\n");
    n = write(sockfd, send_buffer, strlen(send_buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Read server response
    memset(recv_buffer, 0, BUFFER_SIZE);
    n = read(sockfd, recv_buffer, BUFFER_SIZE);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", recv_buffer);

    // Send QUIT command
    memset(send_buffer, 0, BUFFER_SIZE);
    sprintf(send_buffer, "QUIT\r\n");
    n = write(sockfd, send_buffer, strlen(send_buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Read server response
    memset(recv_buffer, 0, BUFFER_SIZE);
    n = read(sockfd, recv_buffer, BUFFER_SIZE);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", recv_buffer);

    // Close socket
    close(sockfd);

    return 0;
}