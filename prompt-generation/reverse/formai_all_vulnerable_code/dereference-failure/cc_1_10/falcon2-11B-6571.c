//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 21
#define MAX_RECV_SIZE 1024

int main() {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_RECV_SIZE], recv_buffer[MAX_RECV_SIZE], send_buffer[MAX_RECV_SIZE], temp_buffer[MAX_RECV_SIZE];
    char command[MAX_RECV_SIZE], file_name[MAX_RECV_SIZE];
    char *ptr;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Assign server IP address and port number to struct sockaddr_in
    server = gethostbyname("ftp.server.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    portno = htons(PORT);

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = portno;

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    printf("Connected to %s:%d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

    // Send a command to server
    strcpy(command, "USER anonymous\r\n");
    write(sockfd, command, strlen(command));
    printf("USER command sent\n");

    strcpy(command, "PASS anonymous\r\n");
    write(sockfd, command, strlen(command));
    printf("PASS command sent\n");

    strcpy(command, "QUIT\r\n");
    write(sockfd, command, strlen(command));
    printf("QUIT command sent\n");

    // Read the response from server
    bzero(buffer, MAX_RECV_SIZE);
    read(sockfd, buffer, MAX_RECV_SIZE);
    printf("Server response: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}