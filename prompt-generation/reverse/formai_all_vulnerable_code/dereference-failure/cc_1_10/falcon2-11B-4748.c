//Falcon2-11B DATASET v1.0 Category: Networking ; Style: Cyberpunk
#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Creating a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Resolving the server's address
    server = gethostbyname("www.google.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    // Extracting the port number from the server's address
    portno = ntohs(*((u_short *)server->h_addr_list[0]));

    // Filling in the server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr_list[0],
        (char *)&serv_addr.sin_addr.s_addr,
        server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connecting to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Sending a request
    char request[100];
    printf("Enter your request: ");
    fgets(request, sizeof(request), stdin);
    n = strlen(request);
    write(sockfd, request, n);

    // Receiving a response
    bzero(request, 100);
    n = read(sockfd, request, 100);
    printf("%s", request);

    return 0;
}