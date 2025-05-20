//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main() {
    // Let's start our cheerful ping test!
    printf("Hello there, let's have a jolly good time pinging some hosts!\n");

    // Let's gather the IP address of the host we want to ping.
    char host[BUFFER_SIZE];
    printf("Enter the IP address or hostname of the destination: ");
    scanf("%s", host);

    // Time to create a socket, the door to our communication highway.
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("Oops, socket creation failed!");
        return EXIT_FAILURE;
    }

    // Now, let's find out the IP address of the host.
    struct hostent *host_info = gethostbyname(host);
    if (host_info == NULL) {
        perror("Couldn't find that host! Are you sure it exists?");
        return EXIT_FAILURE;
    }

    // Prepare our ping message, a cheerful "Hello!"
    char message[] = "Hello, world!";

    // Let's send off our ping message!
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(3000);  // Using port 3000 for our ping messages.
    memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);
    if (sendto(sockfd, message, sizeof(message), 0, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Oops, failed to send our ping message!");
        return EXIT_FAILURE;
    }

    // Time to wait for a reply!
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];
    if (recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, &client_addr_len) == -1) {
        perror("Oh no, didn't receive anything!");
        return EXIT_FAILURE;
    }

    // Yay! We got a reply! Let's check it out.
    printf("Yay! We got a reply from %s!\nMessage: %s\n", inet_ntoa(client_addr.sin_addr), buffer);

    // Let's close our socket door, we're done here.
    close(sockfd);

    // And there we go, a successful ping test!
    printf("Hooray! We pinged successfully! :)\n");

    return EXIT_SUCCESS;
}