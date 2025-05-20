//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define SIZE 1024

int main(int argc, char *argv[]) {
    int sock, nread, nbytes, portno;
    char buffer[SIZE], command[SIZE], response[SIZE];
    struct hostent *host;
    struct sockaddr_in serv_addr;

    // Check for proper arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    // Get host information
    host = gethostbyname(argv[1]);
    if (!host) {
        fprintf(stderr, "Error: %s not found.\n", argv[1]);
        exit(1);
    }

    // Set up server address details
    portno = atoi(argv[2]);
    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)host->h_addr, host->h_length);

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error: Unable to create socket");
        exit(1);
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error: Unable to connect");
        exit(1);
    }

    // Receive Server Greeting
    nread = recv(sock, buffer, SIZE -1, 0);
    if (nread == -1) {
        perror("Error: Unable to read server greeting");
        exit(1);
    }
    buffer[nread] = '\0';
    printf("%s", buffer);

    // Send Login Information
    sprintf(command, "LOGIN %s %s\r\n", "username", "password");
    nbytes = send(sock, command, strlen(command), 0);
    if (nbytes == -1) {
        perror("Error: Unable to send login info");
        exit(1);
    }

    // Receive Response to Login Information
    nread = recv(sock, response, SIZE -1, 0);
    if (nread == -1) {
        perror("Error: Unable to read login response");
        exit(1);
    }
    response[nread] = '\0';
    printf("%s", response);

    // Send Command to Get List of Mailboxes
    sprintf(command, "LIST \"\" *\r\n");
    nbytes = send(sock, command, strlen(command), 0);
    if (nbytes == -1) {
        perror("Error: Unable to send LIST command");
        exit(1);
    }

    // Receive Response to LIST Command
    nread = recv(sock, response, SIZE -1, 0);
    if (nread == -1) {
        perror("Error: Unable to read LIST response");
        exit(1);
    }
    response[nread] = '\0';
    printf("%s", response);

    // Close socket and exit program
    close(sock);
    return 0;
}