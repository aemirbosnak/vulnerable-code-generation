//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 80

int main()
{
    int sockfd, valread, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[100];

    /* Create a socket */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    /* Initialize the structure with the address of the server */
    server = gethostbyname("www.google.com");
    if (server == NULL) {
        perror("gethostbyname failed");
        exit(EXIT_FAILURE);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    /* Connect to the server */
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Enter the URL you want to ping: ");
    scanf("%s", buffer);

    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    valread = recv(sockfd, buffer, sizeof(buffer), 0);
    if (valread < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    printf("Response from %s: %s\n", buffer, buffer);

    close(sockfd);
    return 0;
}