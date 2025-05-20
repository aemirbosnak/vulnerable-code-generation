//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *host = argv[1];
    int port = atoi(argv[2]);

    struct hostent *server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "Error: could not resolve host %s\n", host);
        return EXIT_FAILURE;
    }

    int s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0) {
        perror("Error: could not create socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    memcpy(&serveraddr.sin_addr.s_addr, server->h_addr, server->h_length);
    if (connect(s, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("Error: could not connect to server");
        return EXIT_FAILURE;
    }

    char *message = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
    int n = write(s, message, strlen(message));
    if (n < 0) {
        perror("Error: could not send request");
        return EXIT_FAILURE;
    }

    char buffer[4096];
    n = read(s, buffer, sizeof(buffer));
    if (n < 0) {
        perror("Error: could not receive response");
        return EXIT_FAILURE;
    }
  
    printf("%s", buffer);
  
    close(s);
  
    return EXIT_SUCCESS;
}