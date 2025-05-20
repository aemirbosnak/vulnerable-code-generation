//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set up the address struct
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Send data
    if (send(sockfd, argv[2], strlen(argv[2]), 0) < 0) {
        perror("ERROR sending data");
        exit(1);
    }

    // Receive response
    char buffer[256];
    memset(buffer, '0', sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("ERROR receiving response");
        exit(1);
    }

    // Close socket
    close(sockfd);

    printf("Received: %s\n", buffer);

    return 0;
}