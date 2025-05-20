//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sock_fd, port, buflen;
    char *host, buf[BUFSIZE + 1];
    struct hostent *he;
    struct sockaddr_in server_addr;

    if (argc != 4) {
        printf("Usage: %s <hostname> <port> <message>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    port = atoi(argv[2]);
    strncpy(buf, argv[3], BUFSIZE);

    // Create socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        perror("socket");
        exit(1);
    }

    // Get host by name
    if ((he = gethostbyname(host)) == NULL) {
        herror("gethostbyname");
        exit(1);
    }

    // Set up server address
    memset((char *) &server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr *) he->h_addr);

    // Connect to server
    if (connect(sock_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Send message
    buflen = strlen(buf);
    if (send(sock_fd, buf, buflen, 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive response
    if (recv(sock_fd, buf, BUFSIZE, 0) == -1) {
        perror("recv");
        exit(1);
    }

    // Display response
    printf("%s\n", buf);

    // Close socket
    close(sock_fd);

    return 0;
}