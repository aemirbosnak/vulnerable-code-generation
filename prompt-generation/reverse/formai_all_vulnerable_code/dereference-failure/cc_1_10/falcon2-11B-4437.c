//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/time.h>
#include<time.h>
#include<sys/select.h>

int main()
{
    int sockfd, new_sockfd;
    struct sockaddr_in servaddr, cli_addr;
    char buffer[1024];
    socklen_t addr_size;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        printf("\n Socket creation error: %s\n", strerror(errno));
        exit(0);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(2000);

    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
    {
        printf("\n Binding error: %s\n", strerror(errno));
        exit(0);
    }

    if (listen(sockfd, 3) == -1)
    {
        printf("\n Listening error: %s\n", strerror(errno));
        exit(0);
    }

    printf("\n Listening on port 2000\n");

    addr_size = sizeof(cli_addr);
    new_sockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &addr_size);
    if (new_sockfd < 0)
    {
        printf("\n Accept error: %s\n", strerror(errno));
        exit(0);
    }

    printf("\n Connection established with client\n");

    while (1)
    {
        printf("\n Enter your choice (r/p/s): ");
        fgets(buffer, sizeof(buffer), stdin);
        if (strcmp(buffer, "r") == 0)
        {
            send(new_sockfd, "r", sizeof("r"), 0);
            break;
        }
        else if (strcmp(buffer, "p") == 0)
        {
            send(new_sockfd, "p", sizeof("p"), 0);
            break;
        }
        else if (strcmp(buffer, "s") == 0)
        {
            send(new_sockfd, "s", sizeof("s"), 0);
            break;
        }
        else
        {
            printf("\n Invalid choice\n");
        }
    }

    close(new_sockfd);
    close(sockfd);
    exit(0);
}