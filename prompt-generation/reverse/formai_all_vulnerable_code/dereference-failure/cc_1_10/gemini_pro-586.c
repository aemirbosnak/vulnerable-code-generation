//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define HOST "ftp.example.com"
#define PORT 21

int main() {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    /* Create a socket. */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Get the server's IP address. */
    server = gethostbyname(HOST);

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    /* Fill in the server's address. */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(PORT);

    /* Connect to the server. */
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    /* Send a message to the server. */
    char buffer[256];
    strcpy(buffer, "USER anonymous\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }

    /* Receive a response from the server. */
    bzero(buffer, 256);
    if (recv(sockfd, buffer, 255, 0) < 0) {
        perror("ERROR receiving response");
        exit(1);
    }

    /* Print the response. */
    printf("%s", buffer);

    /* Close the socket. */
    close(sockfd);

    return 0;
}