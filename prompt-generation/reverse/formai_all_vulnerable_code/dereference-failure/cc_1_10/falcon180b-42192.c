//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];
    int n;
    int portno = 8080;
    int addrlen = sizeof(cli_addr);
    char *hostname = "localhost";
    struct hostent *server;
    if ((server = gethostbyname(hostname)) == NULL) {
        fprintf(stderr, "ERROR: Host not found.\n");
        exit(1);
    }
    if (server->h_addrtype!= AF_INET) {
        fprintf(stderr, "ERROR: Host is not an IPv4 address.\n");
        exit(1);
    }
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        fprintf(stderr, "ERROR: Socket creation failed.\n");
        exit(1);
    }
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *) &portno, sizeof(portno)) < 0) {
        fprintf(stderr, "ERROR: setsockopt() failed.\n");
        exit(1);
    }
    bzero(&serv_addr, sizeof(serv_addr));
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    if ((connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr))) < 0) {
        fprintf(stderr, "ERROR: Connection failed.\n");
        exit(1);
    }
    while (1) {
        bzero(buffer, sizeof(buffer));
        if ((n = read(sockfd, buffer, sizeof(buffer))) < 0) {
            fprintf(stderr, "ERROR: Reading from socket failed.\n");
            exit(1);
        }
        if (n == 0) {
            fprintf(stderr, "ERROR: Connection closed by server.\n");
            exit(1);
        }
        printf("Received: %s", buffer);
    }
    return 0;
}