//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// A simple network topology mapper
// by Linus Torvalds

int main(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s host1 host2 ...\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Resolve the hostnames
    struct hostent **hosts = malloc(sizeof(struct hostent *) * argc);
    for (int i = 1; i < argc; i++) {
        hosts[i - 1] = gethostbyname(argv[i]);
        if (!hosts[i - 1]) {
            perror("gethostbyname");
            return EXIT_FAILURE;
        }
    }

    // Connect to each host
    for (int i = 1; i < argc; i++) {
        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(80);
        addr.sin_addr = *(struct in_addr *)hosts[i - 1]->h_addr;

        if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
            perror("connect");
            return EXIT_FAILURE;
        }

        // Send a request to each host
        const char *request = "GET / HTTP/1.1\r\nHost: ";
        write(sockfd, request, strlen(request));
        write(sockfd, argv[i], strlen(argv[i]));
        write(sockfd, "\r\n\r\n", 4);

        // Receive the response from each host
        char buffer[4096];
        int n = read(sockfd, buffer, sizeof(buffer) - 1);
        if (n < 0) {
            perror("read");
            return EXIT_FAILURE;
        }

        // Print the response from each host
        buffer[n] = '\0';
        printf("%s: %s", argv[i], buffer);
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}