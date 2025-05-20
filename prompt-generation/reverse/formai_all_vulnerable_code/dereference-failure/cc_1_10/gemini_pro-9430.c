//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    int sfd, cfd, len;
    struct sockaddr_in saddr, caddr;
    char buf[1024];

    // 1. Create the server socket.
    sfd = socket(AF_INET, SOCK_STREAM, 0);

    // 2. Bind the server socket to the specified IP address and port.
    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    saddr.sin_port = htons(atoi(argv[1]));
    bind(sfd, (struct sockaddr *) &saddr, sizeof(saddr));

    // 3. Listen for incoming client connections.
    listen(sfd, 5);

    // 4. Accept incoming client connections.
    while (1) {
        len = sizeof(caddr);
        cfd = accept(sfd, (struct sockaddr *) &caddr, &len);

        // 5. Read data from the client socket.
        memset(buf, 0, sizeof(buf));
        read(cfd, buf, sizeof(buf));

        // 6. Process the data received from the client.
        printf("Received data from client: %s\n", buf);

        // 7. Send data to the client socket.
        memset(buf, 0, sizeof(buf));
        snprintf(buf, sizeof(buf), "Hello from server!");
        write(cfd, buf, strlen(buf));

        // 8. Close the client socket.
        close(cfd);

    }

    // 9. Close the server socket.
    close(sfd);

    return 0;
}