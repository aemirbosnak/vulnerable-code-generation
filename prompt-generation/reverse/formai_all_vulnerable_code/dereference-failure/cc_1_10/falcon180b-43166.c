//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[1025];
    int n;

    if (argc!= 2) {
        printf("Usage: %s <port number>\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[1]);

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(1);
    }

    puts("Socket created");

    // Set server address
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind to local address
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    puts("Bind complete");

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    puts("Listening for connections...");

    // Accept a connection
    if ((newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, sizeof(cli_addr))) < 0) {
        perror("accept");
        exit(1);
    }

    puts("Connection accepted");

    // Get name of remote machine
    server = gethostbyaddr(&cli_addr.sin_addr, sizeof(cli_addr.sin_addr), AF_INET);

    // Send data to remote machine
    send(newsockfd, "Hello, remote machine!", strlen("Hello, remote machine!"), 0);

    // Receive data from remote machine
    while (1) {
        bzero(buffer, 1025);
        n = recv(newsockfd, buffer, 1024, 0);
        if (n <= 0)
            break;

        buffer[n] = '\0';
        printf("Received string: %s\n", buffer);
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}