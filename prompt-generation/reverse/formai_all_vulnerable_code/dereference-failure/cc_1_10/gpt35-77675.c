//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

int main()
{
    int sockfd;
    struct addrinfo hints, *res;
    int status;
    fd_set read_fds;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags = AI_PASSIVE;

    if ((status = getaddrinfo(NULL, "8080", &hints, &res)) != 0)
    {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(1);
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    if (sockfd == -1)
    {
        perror("socket error");
        exit(1);
    }

    if (bind(sockfd, res->ai_addr, res->ai_addrlen) == -1)
    {
        perror("bind error");
        exit(1);
    }

    printf("Waiting for data...\n");

    while (1)
    {
        FD_ZERO(&read_fds);
        FD_SET(sockfd, &read_fds);

        int num_fds = sockfd + 1;
        struct timeval timeout;
        timeout.tv_sec = 5;
        timeout.tv_usec = 0;

        int ready = select(num_fds, &read_fds, NULL, NULL, &timeout);

        if (ready == -1)
        {
            perror("select error");
            exit(1);
        }
        else if (ready == 0)
        {
            printf("No data received in last 5 seconds\n");
        }
        else
        {
            char buffer[1024];
            memset(buffer,0,sizeof(buffer));

            struct sockaddr_storage client_addr;
            socklen_t client_addr_len = sizeof(client_addr);

            ssize_t len = recvfrom(sockfd, buffer, sizeof(buffer)-1, 0, (struct sockaddr *) &client_addr, &client_addr_len);

            if (len == -1)
            {
                perror("recvfrom error");
            }
            else
            {
                buffer[len] = '\0';

                printf("Received data: %s\n", buffer);
            }
        }
    }

    return 0;
}