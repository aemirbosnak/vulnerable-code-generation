//GEMINI-pro DATASET v1.0 Category: Networking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    // Parameters
    if (argc < 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Network
    struct hostent *host = gethostbyname(hostname);
    if (!host) {
        printf("Error: Invalid hostname.\n");
        return EXIT_FAILURE;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = *(struct in_addr *)host->h_addr;

    // Socket
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
        printf("Error: Cannot create a socket.\n");
        return EXIT_FAILURE;
    }

    // Connection
    if (connect(fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        printf("Error: Cannot connect to the server.\n");
        return EXIT_FAILURE;
    }

    // Introspective
    printf("Connected to %s:%d (fd=%d).\n", hostname, port, fd);
    printf("Type 'exit' to terminate the connection.\n");

    // Communication
    char buffer[1024];
    while (1) {
        printf("> ");
        fgets(buffer, sizeof(buffer), stdin);

        if (!strcmp(buffer, "exit\n")) {
            break;
        }

        int n = write(fd, buffer, strlen(buffer));
        if (n < 0) {
            printf("Error: Cannot send data to the server.\n");
            break;
        }

        n = read(fd, buffer, sizeof(buffer));
        if (n < 0) {
            printf("Error: Cannot receive data from the server.\n");
            break;
        }

        printf("%s", buffer);
    }

    // Cleanup
    close(fd);
    return EXIT_SUCCESS;
}