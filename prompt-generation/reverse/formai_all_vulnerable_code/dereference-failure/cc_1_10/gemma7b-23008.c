//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

int main()
{
    char host[256] = "localhost";
    int port = 53000;
    int sockfd;
    struct sockaddr_in srv_addr;
    struct hostent *hp;

    // Step 1: Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Step 2: Resolve the host name
    hp = gethostbyname(host);
    if (hp == NULL)
    {
        perror("Error resolving host name");
        exit(1);
    }

    // Step 3: Fill in the server address structure
    srv_addr.sin_family = hp->h_addrtype;
    srv_addr.sin_port = htons(port);
    srv_addr.sin_addr.s_addr = *(long *)hp->h_addr;

    // Step 4: Send a ping message
    char msg[2] = "P";
    sendto(sockfd, msg, 2, 0, (struct sockaddr *)&srv_addr, sizeof(srv_addr));

    // Step 5: Receive the ping reply
    char reply[2];
    recvfrom(sockfd, reply, 2, 0, (struct sockaddr *)&srv_addr, NULL);

    // Step 6: Print the ping reply
    printf("Reply: %s\n", reply);

    // Close the socket
    close(sockfd);

    return 0;
}