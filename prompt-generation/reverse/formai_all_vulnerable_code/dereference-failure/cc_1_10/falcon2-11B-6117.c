//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(1);
    }

    // Set up the server address struct
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));

    // Bind the socket to the address
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    listen(sockfd, 5);

    // Accept the incoming connection
    if ((portno = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&n)) < 0) {
        perror("accept failed");
        exit(1);
    }

    printf("Connected to %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

    // Send some data to the client
    write(portno, "Hello, world!\n", strlen("Hello, world!"));

    // Read the response from the client
    read(portno, buffer, sizeof(buffer));
    printf("Response: %s\n", buffer);

    // Close the socket
    close(portno);

    return 0;
}