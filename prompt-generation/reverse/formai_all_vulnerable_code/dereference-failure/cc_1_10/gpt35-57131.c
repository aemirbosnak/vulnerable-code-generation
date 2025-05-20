//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAX_BUFFER_SIZE 4096
#define DEFAULT_PORT 80

// main function
int main(int argc, char *argv[]) {
    // variables
    int fd, port, n;
    struct hostent *he;
    struct sockaddr_in serv_addr;
    char buffer[MAX_BUFFER_SIZE], *host, *dir, *message;
    char get_request[MAX_BUFFER_SIZE];

    // command line argument validation
    if (argc != 2) {
        printf("Usage: %s <url>\nExample: %s www.google.com\n", argv[0], argv[0]);
        exit(1);
    }

    // parse host & directory from URL
    host = strtok(argv[1], "/");
    dir = strtok(NULL, "/");
    if (dir == NULL) dir = "";

    // get IP address of host
    if ((he = gethostbyname(host)) == NULL) {
        printf("[ERROR] Cannot get IP address for host: %s\n", host);
        exit(1);
    }

    // create socket
    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("[ERROR] Cannot create socket. Error code: %s\n", strerror(errno));
        exit(1);
    }

    // initialize socket parameters
    memset(&serv_addr, 0, sizeof(serv_addr));
    port = DEFAULT_PORT;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr = *((struct in_addr *) he->h_addr);

    // connect to server via socket
    if (connect(fd, (struct sockaddr *) &serv_addr, sizeof(struct sockaddr)) == -1) {
        printf("[ERROR] Cannot connect to server. Error code: %s\n", strerror(errno));
        close(fd);
        exit(1);
    }

    // create GET request message
    sprintf(get_request, "GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n", dir, host);
    message = get_request;

    // send GET request message to server
    if (send(fd, message, strlen(message), 0) == -1) {
        printf("[ERROR] Cannot send GET request. Error code: %s\n", strerror(errno));
        close(fd);
        exit(1);
    }

    printf("----- HTTP Response -----\n\n");

    // read & print response from server
    while ((n = recv(fd, buffer, MAX_BUFFER_SIZE-1, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    // close socket
    close(fd);

    return EXIT_SUCCESS;
}