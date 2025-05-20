//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

#define PORT 8080
#define BUFFER_SIZE 4096

int main(int argc, char **argv)
{
    struct sockaddr_in server_addr;
    struct hostent *server;
    int sockfd;
    int n;
    char buffer[BUFFER_SIZE];
    char msg[BUFFER_SIZE];

    // Step 1: Resolve the server address and port number
    server = gethostbyname("www.example.com");
    if (server == NULL) {
        fprintf(stderr, "Error: Unable to resolve hostname\n");
        exit(1);
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(PORT);

    // Step 2: Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Step 3: Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Step 4: Send a message
    printf("Enter a message: ");
    fgets(msg, BUFFER_SIZE, stdin);
    n = write(sockfd, msg, strlen(msg));
    if (n < 0) {
        perror("write");
        exit(1);
    }

    // Step 5: Receive a response
    memset(buffer, 0, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("read");
        exit(1);
    }
    printf("Server response: %s\n", buffer);

    // Step 6: Close the socket
    close(sockfd);

    return 0;
}