//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

// Watson, I presume?
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Elementary, my dear Watson! Usage: %s <target IP> <start port>-<end port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Initialise the magnifying glass
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("The game's afoot! Socket creation failed.\n");
        return EXIT_FAILURE;
    }

    // Set the target's coordinates
    struct sockaddr_in target;
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(argv[1]);

    // Specify the range of ports to investigate
    unsigned short start_port, end_port;
    char *dash = strchr(argv[2], '-');
    if (dash == NULL) {
        printf("Elementary, my dear Watson! Invalid port range.\n");
        return EXIT_FAILURE;
    }
    *dash = '\0';
    start_port = atoi(argv[2]);
    end_port = atoi(dash + 1);

    // Commence the investigation
    printf("Searching for open ports, my dear Watson...\n");
    for (unsigned short port = start_port; port <= end_port; port++) {
        target.sin_port = htons(port);

        // Knock on the door
        int connect_status = connect(sockfd, (struct sockaddr *) &target, sizeof(target));

        // Examine the response
        if (connect_status == 0) {
            printf("Port %hu: Open, my dear Watson!\n", port);
        } else if (connect_status == -1) {
            printf("Port %hu: Closed, my dear Watson.\n", port);
        }
    }

    // Conclude the investigation
    printf("Elementary, my dear Watson! The investigation is complete.\n");

    // Pack up the magnifying glass
    close(sockfd);

    return EXIT_SUCCESS;
}