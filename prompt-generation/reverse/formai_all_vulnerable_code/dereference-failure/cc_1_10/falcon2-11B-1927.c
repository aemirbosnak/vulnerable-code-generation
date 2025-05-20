//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

int main()
{
    int sockfd, portno, nbytes, bytes_sent;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("www.google.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    portno = htons(80);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = portno;

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    printf("Enter the file size (in KB): ");
    scanf("%d", &nbytes);

    bytes_sent = send(sockfd, "", 1, 0);
    printf("Sending file size = %d bytes\n", nbytes);

    printf("Receiving file size = %d bytes\n", nbytes);

    bytes_sent = send(sockfd, "", 1, 0);
    printf("Received file size = %d bytes\n", nbytes);

    close(sockfd);

    return 0;
}