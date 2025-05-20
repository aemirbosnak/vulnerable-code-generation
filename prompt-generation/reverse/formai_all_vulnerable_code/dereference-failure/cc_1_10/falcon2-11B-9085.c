//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: satisfied
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in servaddr;
    struct hostent *server;
    char send_buffer[MAX_LINE], recv_buffer[MAX_LINE];

    if (argc!= 2) {
        fprintf(stderr, "usage %s hostname\n", argv[0]);
        exit(1);
    }

    if ((server = gethostbyname(argv[1])) == NULL) {
        fprintf(stderr, "No such host\n");
        exit(1);
    }

    portno = htons(80);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error opening socket\n");
        exit(1);
    }

    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = portno;

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        fprintf(stderr, "Connection failed\n");
        exit(1);
    }

    send_buffer[0] = '\0';
    sprintf(send_buffer, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
    write(sockfd, send_buffer, strlen(send_buffer));

    recv_buffer[0] = '\0';
    n = read(sockfd, recv_buffer, MAX_LINE);
    if (n < 0) {
        fprintf(stderr, "Error reading from socket\n");
        exit(1);
    }

    printf("Response from server: %s\n", recv_buffer);

    close(sockfd);
    return 0;
}