//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: mind-bending
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, port, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];

    // check for correct number of arguments
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        return 1;
    }

    // get server address
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        return 1;
    }

    // get port number
    port = atoi(argv[2]);

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR opening socket\n");
        return 1;
    }

    // set up server address struct
    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char*) server->h_addr, (char*) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    // connect to server
    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "ERROR connecting to server\n");
        return 1;
    }

    // read greeting from server
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        fprintf(stderr, "ERROR reading from socket\n");
        return 1;
    }
    printf("%s\n", buffer);

    // send user name to server
    bzero(buffer, BUFFER_SIZE);
    printf("User name: ");
    fgets(buffer, BUFFER_SIZE - 1, stdin);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "ERROR writing to socket\n");
        return 1;
    }

    // read password prompt from server
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        fprintf(stderr, "ERROR reading from socket\n");
        return 1;
    }
    printf("%s\n", buffer);

    // send password to server
    bzero(buffer, BUFFER_SIZE);
    printf("Password: ");
    fgets(buffer, BUFFER_SIZE - 1, stdin);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "ERROR writing to socket\n");
        return 1;
    }

    // read response from server
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        fprintf(stderr, "ERROR reading from socket\n");
        return 1;
    }
    printf("%s\n", buffer);

    // close socket
    close(sockfd);
    return 0;
}