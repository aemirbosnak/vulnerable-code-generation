//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

/* Function to handle errors */
void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFSIZE];
    int bytes_received = -1;

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2])) ;

    /* Connect to server */
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    /* Receive welcome message from server */
    bytes_received = recv(sockfd, buffer, BUFSIZE-1, 0);
    if (bytes_received < 0)
        error("ERROR reading from socket");
    buffer[bytes_received]='\0';
    printf("%s",buffer);

    /* Send USER command and receive response */
    printf("Enter User Name:");
    fgets(buffer, BUFSIZE-1, stdin);
    sprintf(buffer, "USER %s", buffer);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0)
        error("ERROR writing to socket");

    bytes_received = recv(sockfd, buffer, BUFSIZE-1, 0);
    if (bytes_received < 0)
        error("ERROR reading from socket");
    buffer[bytes_received]='\0';
    printf("%s",buffer);

    /* Send PASS command and receive response */
    printf("Enter Password:");
    fgets(buffer, BUFSIZE-1, stdin);
    sprintf(buffer, "PASS %s", buffer);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0)
        error("ERROR writing to socket");

    bytes_received = recv(sockfd, buffer, BUFSIZE-1, 0);
    if (bytes_received < 0)
        error("ERROR reading from socket");
    buffer[bytes_received]='\0';
    printf("%s",buffer);

    /* Send STAT command and receive response */
    sprintf(buffer, "STAT");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0)
        error("ERROR writing to socket");

    bytes_received = recv(sockfd, buffer, BUFSIZE-1, 0);
    if (bytes_received < 0)
        error("ERROR reading from socket");
    buffer[bytes_received]='\0';
    printf("%s",buffer);

    /* Quit connection */
    sprintf(buffer, "QUIT");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0)
        error("ERROR writing to socket");

    bytes_received = recv(sockfd, buffer, BUFSIZE-1, 0);
    if (bytes_received < 0)
        error("ERROR reading from socket");
    buffer[bytes_received]='\0';
    printf("%s",buffer);

    /* Close connection */
    close(sockfd);
    return 0;
}