//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void ftp_client(const char *hostname, const char *username, const char *password, const char *remote_file) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    
    // Step 1: Resolve host name to IP
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    // Step 2: Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("ERROR opening socket");

    // Step 3: Prepare the server address struct
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(21); // FTP default port

    // Step 4: Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    // Step 5: Read server response
    char response[BUFFER_SIZE];
    bzero(response, BUFFER_SIZE);
    read(sockfd, response, sizeof(response) - 1);
    printf("Server: %s", response);

    // Step 6: Send login information
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    write(sockfd, command, strlen(command));
    bzero(response, BUFFER_SIZE);
    read(sockfd, response, sizeof(response) - 1);
    printf("Server: %s", response);

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    write(sockfd, command, strlen(command));
    bzero(response, BUFFER_SIZE);
    read(sockfd, response, sizeof(response) - 1);
    printf("Server: %s", response);

    // Step 7: Request to download the remote file
    snprintf(command, sizeof(command), "RETR %s\r\n", remote_file);
    write(sockfd, command, strlen(command));
    bzero(response, BUFFER_SIZE);
    read(sockfd, response, sizeof(response) - 1);
    printf("Server: %s", response);

    // Step 8: Prepare to receive the file
    int data_sockfd;
    struct sockaddr_in data_serv_addr;
    data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sockfd < 0) error("ERROR opening data socket");

    // Step 9: Setup passive mode for data transfer
    write(sockfd, "PASV\r\n", 6);
    bzero(response, BUFFER_SIZE);
    read(sockfd, response, sizeof(response) - 1);
    printf("Server: %s", response);
    
    // Step 10: Parse the response to get port
    int p1, p2;
    sscanf(response, "227 Entering Passive Mode (%*d,%*d,%*d,%*d,%d,%d)", &p1, &p2);
    int data_port = p1 * 256 + p2;

    // Step 11: Prepare data socket address
    bzero((char *)&data_serv_addr, sizeof(data_serv_addr));
    data_serv_addr.sin_family = AF_INET;
    data_serv_addr.sin_addr.s_addr = ((struct in_addr *)(server->h_addr))->s_addr;
    data_serv_addr.sin_port = htons(data_port);

    // Step 12: Connect the data socket
    if (connect(data_sockfd, (struct sockaddr *)&data_serv_addr, sizeof(data_serv_addr)) < 0)
        error("ERROR connecting to data socket");

    // Step 13: Receive the file data
    int file_desc = open(remote_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file_desc < 0) error("ERROR opening file");

    while ((n = read(data_sockfd, response, BUFFER_SIZE)) > 0) {
        write(file_desc, response, n);
    }

    close(file_desc);
    close(data_sockfd);
    bzero(response, BUFFER_SIZE);
    read(sockfd, response, sizeof(response) - 1);
    printf("Server: %s", response);

    // Step 14: Logout and close connection
    write(sockfd, "QUIT\r\n", 6);
    bzero(response, BUFFER_SIZE);
    read(sockfd, response, sizeof(response) - 1);
    printf("Server: %s", response);

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password> <remote_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    ftp_client(argv[1], argv[2], argv[3], argv[4]);

    return EXIT_SUCCESS;
}