//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main()
{
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Get the IP address of the FTP server
    struct hostent *host = gethostbyname("ftp.example.com");
    if (host == NULL) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    // Connect to the FTP server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21);
    server_addr.sin_addr = *(struct in_addr *)host->h_addr;
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the USER command
    char buf[1024];
    sprintf(buf, "USER anonymous\r\n");
    send(sock, buf, strlen(buf), 0);

    // Receive the response from the FTP server
    recv(sock, buf, sizeof(buf), 0);

    // Send the PASS command
    sprintf(buf, "PASS example@example.com\r\n");
    send(sock, buf, strlen(buf), 0);

    // Receive the response from the FTP server
    recv(sock, buf, sizeof(buf), 0);

    // Send the CWD command
    sprintf(buf, "CWD /pub\r\n");
    send(sock, buf, strlen(buf), 0);

    // Receive the response from the FTP server
    recv(sock, buf, sizeof(buf), 0);

    // Send the LIST command
    sprintf(buf, "LIST\r\n");
    send(sock, buf, strlen(buf), 0);

    // Receive the response from the FTP server
    recv(sock, buf, sizeof(buf), 0);

    // Print the response from the FTP server
    printf("%s", buf);

    // Close the socket
    close(sock);

    return EXIT_SUCCESS;
}