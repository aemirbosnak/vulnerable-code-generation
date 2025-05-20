//Falcon-180B DATASET v1.0 Category: Chat server ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX 100
#define PORT 8080

int main()
{
    int sd, client_sd, valread, sd2;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];

    sd = socket(AF_INET, SOCK_STREAM, 0);

    if (sd < 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sd, 5) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        printf("\nWaiting for connection...\n");
        valread = sizeof(cli_addr);
        client_sd = accept(sd, (struct sockaddr *)&cli_addr, &valread);
        printf("\nConnection with client established\n");

        while (1)
        {
            bzero(buffer, MAX);
            sd2 = client_sd;
            send(sd2, "Enter your message : ", strlen("Enter your message : "), 0);
            recv(sd2, buffer, MAX, 0);
            send(sd2, buffer, strlen(buffer), 0);
        }
        close(client_sd);
    }

    close(sd);
    return 0;
}