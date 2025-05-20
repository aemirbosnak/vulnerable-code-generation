//FormAI DATASET v1.0 Category: Port Scanner ; Style: relaxed
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    int socket_desc;
    struct sockaddr_in server;
    char *hostname;
    int start_port, end_port, current_port;

    // check for command line arguments
    if(argc != 4)
    {
        printf("Usage: %s <hostname> <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    // get hostname and port range from command line arguments
    hostname = argv[1];
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    // create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1)
    {
        printf("Error: Could not create socket\n");
        return 1;
    }

    // prepare server struct
    server.sin_addr.s_addr = inet_addr(hostname);
    server.sin_family = AF_INET;

    // loop through all ports and check which ones are open
    for (current_port = start_port; current_port <= end_port; current_port++)
    {
        server.sin_port = htons(current_port);

        // try to connect to the port
        if (connect(socket_desc, (struct sockaddr *)&server , sizeof(server)) < 0)
        {
            printf("Port %d: Closed\n", current_port);
        }
        else
        {
            printf("Port %d: Open\n", current_port);
            close(socket_desc);
            // create a new socket for the next iteration
            socket_desc = socket(AF_INET, SOCK_STREAM, 0);
        }
    }

    return 0;
}