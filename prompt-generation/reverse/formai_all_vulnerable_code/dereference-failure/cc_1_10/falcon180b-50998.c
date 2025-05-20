//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct hostent *server;
    char *ip;
    int n;
    char buffer[1024];

    if (argc < 3) {
        printf("Usage:./ftp_client <server_ip> <port_number>\n");
        return 0;
    }

    ip = argv[1];
    portno = atoi(argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        return 0;
    }

    // Connect to server
    server = gethostbyname(ip);
    if (server == NULL) {
        printf("No such host\n");
        return 0;
    }

    bzero((char *) &server->h_addr, sizeof(server->h_addr));

    if (connect(sockfd, (struct sockaddr *) server, sizeof(struct sockaddr)) < 0) {
        printf("Error connecting\n");
        return 0;
    }

    printf("Connected to %s on port %d\n", ip, portno);

    // Login to server
    send(sockfd, "USER anonymous\r\n", strlen("USER anonymous\r\n"), 0);
    send(sockfd, "PASS anonymous@anonymous.com\r\n", strlen("PASS anonymous@anonymous.com\r\n"), 0);

    // Change directory
    send(sockfd, "CWD /\r\n", strlen("CWD /\r\n"), 0);

    // Get directory listing
    send(sockfd, "LIST\r\n", strlen("LIST\r\n"), 0);

    while ((n = read(sockfd, buffer, sizeof(buffer))) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}