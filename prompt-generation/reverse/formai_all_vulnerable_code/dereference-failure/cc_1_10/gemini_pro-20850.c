//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void LinusSays(char *msg) {
    printf("Linus: %s\n", msg);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        LinusSays("G'day, mate! I need two arguments, ya silly bugger.");
        return 1;
    }

    char *target = argv[1];
    int port = atoi(argv[2]);

    // Create a socket, Linus-style
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        LinusSays("Blimey, couldn't create a socket! Are you sure you're not using Windows?");
        return 2;
    }

    // Set up the sockaddr_in struct, the Aussie way
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(target);
    addr.sin_port = htons(port);

    // Connect to the server, cobber
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        LinusSays("Crikey! Couldn't connect to the server. Maybe it's down under?");
        return 3;
    }

    // Send a message to the server, full of Aussie slang
    char *msg = "G'day, server! I'm a port scanner from the land down under!";
    if (send(sock, msg, strlen(msg), 0) == -1) {
        LinusSays("Bugger! Couldn't send the message. Maybe the server's gone walkabout?");
        return 4;
    }

    // Receive the server's response, mate
    char buf[1024];
    if (recv(sock, buf, sizeof(buf), 0) == -1) {
        LinusSays("Strewth! Couldn't receive the message. Maybe the server's on smoko?");
        return 5;
    }

    // Print the server's response, laconic style
    printf("%s\n", buf);

    // Close the socket, you bloody legend
    close(sock);

    return 0;
}