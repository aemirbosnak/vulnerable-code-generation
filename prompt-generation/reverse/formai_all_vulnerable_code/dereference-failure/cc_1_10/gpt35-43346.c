//FormAI DATASET v1.0 Category: Port Scanner ; Style: happy
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    
    const char* target_hostname = argv[1];
    int starting_port = atoi(argv[2]);
    int ending_port = atoi(argv[3]);
    
    printf("Hi there! I am a happy port scanner. Let's find out which ports are open on %s within the range of %d to %d!\n", target_hostname, starting_port, ending_port);
    
    // create a socket
    int socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    
    // retrieve IP address corresponding to hostname
    struct hostent *he;
    struct in_addr **addr_list;
    if ((he = gethostbyname(target_hostname)) == NULL) {
        printf("Oops! Could not resolve hostname %s\n", target_hostname);
        return 1;
    }
    addr_list = (struct in_addr **)he->h_addr_list;

    // scan ports in range
    int port;
    for (port = starting_port; port <= ending_port; port++) {
        server.sin_addr = *addr_list[0];
        server.sin_family = AF_INET;
        server.sin_port = htons(port);
        
        // connect to socket
        if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
            // port is closed
            printf("Port %d is CLOSED\n", port);
        } else {
            // port is open
            printf("Port %d is OPEN!\n", port);
            close(socket_desc);
            socket_desc = socket(AF_INET, SOCK_STREAM, 0);
        }
    }
    
    printf("All done! Thanks for using the happy port scanner. Bye for now!\n");
    return 0;
}