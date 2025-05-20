//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFSIZE];

    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(1);
    }

    portno = atoi(argv[2]);

    /* Translate hostname to IP address */
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"Error: No such host\n");
        exit(1);
    }

    /* Configure server address */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr_list[0],
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(portno);

    /* Create socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: Socket creation failed");
        exit(1);
    }

    /* Connect to server */
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("Error: Connection failed");
        exit(1);
    }

    /* Send IMAP commands */
    printf("Connecting to server: %s:%d...\n", argv[1], portno);

    n = read(sockfd, buffer, BUFSIZE - 1); // read server hello
    if (n < 0) {
        perror("Error: Failed to read server hello");
        exit(1);
    }

    printf("%s\n", buffer);

    bzero(buffer, BUFSIZE);
    strcpy(buffer, "a001 LOGIN user1@example.com password123\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error: Failed to write to socket");
        exit(1);
    }

    printf("Sent: %s", buffer);

    bzero(buffer, BUFSIZE);
    n = read(sockfd, buffer, BUFSIZE - 1);
    if (n < 0) {
        perror("Error: Failed to read from socket");
        exit(1);
    }

    printf("Received: %s\n", buffer);

    close(sockfd);

    return 0;
}