//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    // Get the hostname and port number from the command line arguments
    char* hostname = argv[1];
    int port = atoi(argv[2]);

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    // Resolve the hostname to an IP address
    struct hostent* host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    // Create a sockaddr_in structure
    struct sockaddr_in sockaddr;
    memset(&sockaddr, 0, sizeof(sockaddr));
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(port);
    sockaddr.sin_addr = *(struct in_addr*)host->h_addr;

    // Connect to the FTP server
    if (connect(sock, (struct sockaddr*)&sockaddr, sizeof(sockaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Send the FTP command to the server
    char* command = "USER anonymous\n";
    if (send(sock, command, strlen(command), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive the response from the server
    char response[1024];
    int response_len = recv(sock, response, sizeof(response) - 1, 0);
    if (response_len == -1) {
        perror("recv");
        exit(1);
    }
    response[response_len] = '\0';

    // Print the response to the console
    printf("%s", response);

    // Close the socket
    close(sock);

    return 0;
}