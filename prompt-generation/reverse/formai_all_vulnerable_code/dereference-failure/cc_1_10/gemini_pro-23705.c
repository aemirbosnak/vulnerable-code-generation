//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <unistd.h>

// Introspection: A moment of self-reflection, where the program ponders its own existence and purpose.
int main() {
    // Existence: The program begins its journey, discovering its purpose in the vast realm of cyberspace.
    char *hostname;
    struct hostent *host;
    struct sockaddr_in addr;
    int sockfd;
    struct timeval start, end;
    long elapsed;

    // Introspection: A prompt for the user to guide the program's destiny.
    printf("Enter hostname: ");
    scanf("%s", hostname);

    // Discovery: The program delves into the depths of the network, seeking the identity of the hostname.
    host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Invalid hostname\n");
        exit(1);
    }

    // Creation: The program manifests a socket, a portal to the network's hidden realms.
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Connection: The program extends a virtual hand, reaching out to the remote host through its IP address.
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    addr.sin_addr = *((struct in_addr *)host->h_addr);

    // Time-keeping: The program prepares to measure the ephemeral passage of time.
    gettimeofday(&start, NULL);

    // Transmission: The program sends a solitary ICMP echo request, a beacon of its existence in cyberspace.
    sendto(sockfd, NULL, 0, 0, (struct sockaddr *)&addr, sizeof(addr));

    // Patience: The program waits, a silent observer in the digital realm, awaiting a response.
    int bytes = recvfrom(sockfd, NULL, 0, 0, NULL, NULL);
    if (bytes == -1) {
        perror("recvfrom");
        exit(1);
    }

    // Time-keeping: The program measures the journey's end, capturing the ephemeral passage of time.
    gettimeofday(&end, NULL);
    elapsed = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);

    // Reflection: The program introspects upon its journey, displaying the fruits of its labor.
    printf("Ping to %s: %ld microseconds\n", hostname, elapsed);

    // Termination: The program gracefully exits the digital realm, leaving behind a trail of introspection and knowledge.
    close(sockfd);
    return 0;
}