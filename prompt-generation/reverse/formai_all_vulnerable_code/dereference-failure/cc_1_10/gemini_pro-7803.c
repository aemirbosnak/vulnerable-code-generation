//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: introspective
// A Cerebral Network Ping Test

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// This program probes the network like a thoughtful observer, introspecting on its findings.

int main(int argc, char *argv[])
{
    // Begin with a reflective greeting.
    printf("Hello, network! I come as an introspective inquirer.\n");

    // Establish a socket like a wise socket-ologist.
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed: ");
        return EXIT_FAILURE;
    }

    // Configure the introspection destination with precision.
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_port = htons(atoi(argv[2]));

    // Construct a probing packet with an inquisitive payload.
    char buf[1024];
    memset(buf, 0, sizeof(buf));
    sprintf(buf, "Introspective ping to %s:%s", argv[1], argv[2]);

    // Send the packet like an ethereal thought.
    int sent = sendto(sockfd, buf, strlen(buf), 0, (const struct sockaddr *)&server, sizeof(server));
    if (sent < 0) {
        perror("Send failed: ");
        return EXIT_FAILURE;
    }

    // Await a response with patient anticipation.
    struct sockaddr_in from;
    socklen_t fromlen = sizeof(from);
    int bytes_received = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&from, &fromlen);

    // Analyze the response like a discerning scholar.
    if (bytes_received < 0) {
        perror("Receive failed: ");
        return EXIT_FAILURE;
    } else if (bytes_received == 0) {
        printf("No response received from %s:%s\n", argv[1], argv[2]);
    } else {
        buf[bytes_received] = '\0';
        printf("Response: %s\n", buf);
    }

    // Reflect on the journey like a contemplative traveler.
    printf("Introspection complete. Network, thank you for sharing your secrets.\n");

    // Close the socket like a satisfied sage.
    close(sockfd);

    return EXIT_SUCCESS;
}