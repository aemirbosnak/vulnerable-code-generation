//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: modular
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUFF_SIZE 1024

int main() {
    int sockfd, bytes_read, bytes_written;
    struct sockaddr_in server_addr, client_addr;
    struct hostent *host;
    char buffer[BUFF_SIZE];
    char *command = "USER anonymous\r\n";

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Resolve server address and port
    host = gethostbyname("ftp.example.com");
    if (host == NULL) {
        fprintf(stderr, "Error: host not found\n");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    bcopy((char *)host->h_addr, (char *)&server_addr.sin_addr.s_addr, host->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Send command
    bytes_read = write(sockfd, command, strlen(command));
    if (bytes_read < 0) {
        perror("write failed");
        exit(EXIT_FAILURE);
    }

    // Read server response
    bytes_read = read(sockfd, buffer, BUFF_SIZE);
    if (bytes_read < 0) {
        perror("read failed");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}