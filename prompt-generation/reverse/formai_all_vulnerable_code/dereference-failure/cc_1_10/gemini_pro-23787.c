//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_EMAIL_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server> <port> <email>\n", argv[0]);
        return 1;
    }

    char *server = argv[1];
    int port = atoi(argv[2]);
    char *email = argv[3];

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Get the server's address
    struct hostent *host = gethostbyname(server);
    if (host == NULL) {
        fprintf(stderr, "gethostbyname: %s\n", server);
        return 1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    memcpy(&serv_addr.sin_addr, host->h_addr_list[0], host->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect");
        return 1;
    }

    // Send the email
    if (write(sockfd, email, strlen(email) + 1) == -1) {
        perror("write");
        return 1;
    }

    // Close the socket
    close(sockfd);

    return 0;
}