//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: surprised
/* ! Woah, Socket Programming with a Twist! */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    // Step 1: Open our virtual window into the network world
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Surprise! No virtual window for us?");
        return EXIT_FAILURE;
    }

    // Step 2: Let's give our window an address to reach us at
    struct sockaddr_in serv_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[1]));
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    // Step 3: Bind our window to that address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Oops! Couldn't bind that address?");
        return EXIT_FAILURE;
    }

    // Step 4: Listen for visitors!
    if (listen(sockfd, 5) < 0) {
        perror("Oh no! Visitors aren't coming?");
        return EXIT_FAILURE;
    }

    // Step 5: Wait for visitors and say hello!
    int newsockfd;
    struct sockaddr_in cli_addr;
    socklen_t clilen;
    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("Ack! Visitor slipped through the cracks?");
            return EXIT_FAILURE;
        }

        char buffer[256];
        bzero(buffer, 256);
        recv(newsockfd, buffer, 255, 0);
        printf("Message from our visitor: %s\n", buffer);

        char response[] = "Thank you for visiting! Have a magical day!";
        send(newsockfd, response, strlen(response), 0);
        close(newsockfd);
    }

    // Step 6: Close our virtual window when we're done
    close(sockfd);
    return EXIT_SUCCESS;
}