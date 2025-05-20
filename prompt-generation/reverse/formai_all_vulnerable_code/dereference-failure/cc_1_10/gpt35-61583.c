//FormAI DATASET v1.0 Category: Port Scanner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

//Function to scan a range of ports on a given IP address
void scan_ports(char* ip_address, int start_port, int end_port) {
    struct sockaddr_in server;
    int sock;

    //Loop through the given range of ports
    for(int port = start_port; port <= end_port; port++) {
        //Create a socket for the port
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if(sock < 0) {
            printf("Error creating socket\n");
            continue;
        }

        //Set up the socket parameters
        server.sin_addr.s_addr = inet_addr(ip_address);
        server.sin_family = AF_INET;
        server.sin_port = htons(port);

        //Attempt to connect to the port
        if(connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
            //Connection failed, port is closed
            printf("Port %d is closed\n", port);
        } else {
            //Connection successful, port is open
            printf("Port %d is open\n", port);

            //Close the socket
            close(sock);
        }
    }
}

int main(int argc, char** argv) {
    //Check if IP address and port range are provided as arguments
    if(argc < 4) {
        printf("Usage: %s <ip_address> <start_port> <end_port>\n", argv[0]);
        return 0;
    }

    char* ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    //Check if arguments are valid
    if(start_port >= end_port || start_port < 1 || end_port > 65535) {
        printf("Invalid port range\n");
        return 0;
    } else if(inet_addr(ip_address) == -1) {
        printf("Invalid IP address\n");
        return 0;
    }

    //Scan the ports
    scan_ports(ip_address, start_port, end_port);

    return 0;
}