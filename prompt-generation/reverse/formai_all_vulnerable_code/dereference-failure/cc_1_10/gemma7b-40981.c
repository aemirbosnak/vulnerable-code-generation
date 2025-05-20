//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: lively
#include <stdio.h>
#include <netdb.h>
#include <unistd.h>

#define HOST "localhost"
#define PORT_MIN 1
#define PORT_MAX 65535

void scan(char *host, int port)
{
    int sockfd, n, err, port_no;

    struct sockaddr_in sock_addr;
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(port);
    sock_addr.sin_addr.s_addr = inet_addr(host);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Error opening socket");
        return;
    }

    if (connect(sockfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) == -1)
    {
        perror("Error connecting to socket");
        close(sockfd);
        return;
    }

    printf("Port %d: ", port);

    for (n = 0; n < 10; n++)
    {
        err = write(sockfd, "Hello, world!", 13);
        if (err == -1)
        {
            perror("Error sending data");
            close(sockfd);
            return;
        }

        port_no = read(sockfd, "Reply: ", 10);
        if (port_no == -1)
        {
            perror("Error receiving data");
            close(sockfd);
            return;
        }

        printf("Reply: %s\n", port_no);
    }

    close(sockfd);
}

int main()
{
    int i;

    printf("Scanning ports on %s...\n", HOST);

    for (i = PORT_MIN; i <= PORT_MAX; i++)
    {
        scan(HOST, i);
    }

    return 0;
}