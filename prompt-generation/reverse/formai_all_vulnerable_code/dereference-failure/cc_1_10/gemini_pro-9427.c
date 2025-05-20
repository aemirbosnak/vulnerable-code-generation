//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    // Let's start by checking if we have enough arguments
    if (argc < 3)
    {
        printf("Oops! You didn't give me enough information.\n");
        printf("Usage: %s <hostname> <port1> [port2] ... [portN]\n", argv[0]);
        return 1;
    }

    // Yay! We have everything we need. Let's get started!
    // First, we need to figure out the IP address of the host
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL)
    {
        printf("Oh no! I couldn't find %s. Are you sure it's a valid hostname?\n", argv[1]);
        return 1;
    }

    // Now, let's get ready to send some packets!
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        printf("Aw, bummer! I couldn't create a socket. :( Let's try again later!\n");
        return 1;
    }

    // Let's loop through all the ports you gave me and check if they're open
    for (int i = 2; i < argc; i++)
    {
        // Let's parse the port number
        int port = atoi(argv[i]);
        if (port <= 0)
        {
            printf("Uh-oh! \"%s\" doesn't look like a valid port number. Let's skip it for now.\n", argv[i]);
            continue;
        }

        // Let's build the address we're going to send our packet to
        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = *((in_addr_t *)host->h_addr_list[0]);

        // Let's try to connect to the port
        int result = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
        if (result == 0)
        {
            printf("Yay! Port %d is open on %s.\n", port, argv[1]);
        }
        else
        {
            printf("Aww, bummer. Port %d on %s is closed.\n", port, argv[1]);
        }
    }

    // We're all done! Let's close the socket and say goodbye
    close(sock);
    printf("Thank you for using my port scanner! Have a wonderful day!\n");
    return 0;
}