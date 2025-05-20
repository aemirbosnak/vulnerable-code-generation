//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

int main()
{
    // Define a list of hosts to ping
    char *hosts[] = {"localhost", "192.168.1.1", "192.168.1.2", "192.168.1.3"};

    // Set up the ping command
    char ping_cmd[256];
    sprintf(ping_cmd, "ping -c 3 -W 2 -w 1 %s", hosts);

    // Execute the ping command
    system(ping_cmd);

    // Print the results
    for (int i = 0; i < 4; i++)
    {
        printf("Host: %s, Status: ", hosts[i]);

        // Check if the host is alive
        if (ping_status(hosts[i]) == 0)
        {
            printf("Alive\n");
        }
        else
        {
            printf("Not Alive\n");
        }
    }

    return 0;
}

int ping_status(char *host)
{
    int sockfd;
    struct sockaddr_in servaddr;
    struct hostent *hp;

    // Resolve the host name
    hp = gethostbyname(host);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(80));

    // Connect to the server
    servaddr.sin_port = htons(53);
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = hp->h_addr;
    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    // Send a message
    char msg[] = "Ping!";
    send(sockfd, msg, strlen(msg), 0);

    // Receive a response
    char resp[256];
    recv(sockfd, resp, sizeof(resp), 0);

    // Close the socket
    close(sockfd);

    // Check if the response is "Alive"
    if (strcmp(resp, "Alive") == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}