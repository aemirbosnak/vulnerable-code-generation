//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL)
    {
        printf("Error: %s is not a valid hostname\n", hostname);
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = *(struct in_addr *)host->h_addr;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("Error: socket() failed");
        return 1;
    }

    int status = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
    if (status < 0)
    {
        perror("Error: connect() failed");
        close(sock);
        return 1;
    }

    char buf[1024];
    memset(buf, 0, sizeof(buf));
    status = read(sock, buf, sizeof(buf) - 1);
    if (status < 0)
    {
        perror("Error: read() failed");
        close(sock);
        return 1;
    }

    close(sock);

    if (status == 0)
    {
        printf("%s is down\n", hostname);
        return 1;
    }
    else
    {
        printf("%s is up\n", hostname);
        return 0;
    }
}