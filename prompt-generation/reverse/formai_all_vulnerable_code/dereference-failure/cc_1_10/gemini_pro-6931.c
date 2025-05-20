//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct hostent *host = gethostbyname(argv[1]);

    if (host == NULL)
    {
        fprintf(stderr, "Error: %s\n", hstrerror(h_errno));
        return EXIT_FAILURE;
    }

    struct sockaddr_in saddr;
    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_addr = *(struct in_addr *)host->h_addr;
    saddr.sin_port = htons(atoi(argv[2]));

    int s = socket(AF_INET, SOCK_STREAM, 0);

    if (s == -1)
    {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    if (connect(s, (struct sockaddr *)&saddr, sizeof(saddr)) == -1)
    {
        if (errno == ECONNREFUSED)
        {
            printf("%s:%s is closed\n", argv[1], argv[2]);
        }
        else
        {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            return EXIT_FAILURE;
        }
    }
    else
    {
        printf("%s:%s is open\n", argv[1], argv[2]);
    }

    close(s);

    return EXIT_SUCCESS;
}