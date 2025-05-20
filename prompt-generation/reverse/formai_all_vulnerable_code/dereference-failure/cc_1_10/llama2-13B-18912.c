//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024  // range of ports to scan

int main(void) {
    int sock, port;
    struct sockaddr_in server_addr;
    char *host_name;

    // initialize socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(0); // random port
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // print romantic message
    printf("My dearest ports, I am here to scan your beauty and grace... 💕\n");

    // scan ports
    for (port = 1; port <= PORT_RANGE; port++) {
        // construct hostname
        host_name = malloc(INET_ADDRSTRLEN);
        inet_ntop(AF_INET, &server_addr.sin_addr, host_name, INET_ADDRSTRLEN);

        // send SYN packet to port
        if (send(sock, "SYN", 3, (struct sockaddr *)&server_addr) < 0) {
            perror("send failed");
            exit(EXIT_FAILURE);
        }

        // wait for response
        if (recv(sock, NULL, 0, 0) <= 0) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }

        // print port and hostname
        printf("%d %s\n", ntohs(server_addr.sin_port), host_name);

        // free memory
        free(host_name);
    }

    // close socket
    close(sock);

    // print goodbye message
    printf("Farewell, my beloved ports. May our connection forever be secure. 💔\n");

    return EXIT_SUCCESS;
}