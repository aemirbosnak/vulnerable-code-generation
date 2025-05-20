//MISTRAL-7B DATASET v1.0 Category: Port Scanner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <time.h>
#include <errno.h>

#define PORT_START 1
#define PORT_END 65535

int main(int argc, char *argv[]) {
    int sockfd, port, i;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <target_IP>\n", argv[0]);
        exit(1);
    }

    // Seed random number generator with current time
    srand(time(NULL));

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Get target IP address
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: Unknown target IP '%s'\n", argv[1]);
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    // Start scanning ports in a surrealistic way
    for (i = PORT_START; i <= PORT_END; i += rand() % 10 + 1) {
        serv_addr.sin_port = htons(i);

        // Connect to the target IP and port
        if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            // If connection fails, print a surrealist error message
            if (errno == ECONNREFUSED) {
                printf("Port %d: The gatekeeper of the void stares at you with empty eyes, refusing entry.\n", i);
            } else if (errno == ETIMEDOUT) {
                printf("Port %d: The pendulum of the clock in the dream world keeps swinging, time seems to stand still.\n", i);
            } else if (errno == ENETDOWN) {
                printf("Port %d: The network cables have disconnected from the dream world, leaving us in the void.\n", i);
            } else {
                perror("Error connecting to port");
            }
        } else {
            // If connection succeeds, print a surrealist success message
            char response[1024];
            memset(response, 0, sizeof(response));

            if (recv(sockfd, response, sizeof(response) - 1, 0) > 0) {
                printf("Port %d: A melody echoes through the dream world, the answer to your query is: %s\n", i, response);
            } else {
                printf("Port %d: A whispering wind disturbs the stillness, but no answer is heard.\n", i);
            }

            close(sockfd);
            sockfd = socket(AF_INET, SOCK_STREAM, 0);
        }
    }

    return 0;
}