//Falcon2-11B DATASET v1.0 Category: Interprocess communication ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Connect to server
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(5000);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        perror("ERROR connecting");
        exit(1);
    }

    // Send message
    char message[] = "Hello, World!";
    send(sockfd, message, strlen(message), 0);

    // Receive message
    bzero(message, sizeof(message));
    n = recv(sockfd, message, sizeof(message), 0);
    if (n < 0) {
        perror("ERROR receiving");
        exit(1);
    }
    printf("Received: %s\n", message);

    // Close socket
    close(sockfd);

    return 0;
}