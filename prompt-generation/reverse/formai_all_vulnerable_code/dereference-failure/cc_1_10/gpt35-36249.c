//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc != 4) {
        printf("Usage: %s server_address username password\n", argv[0]);
        return 1;
    }

    char buffer[MAX_SIZE];
    int socket_fd, nbytes;
    struct sockaddr_in server_address;
    struct hostent *server_info;

    // get server info
    if((server_info = gethostbyname(argv[1])) == NULL) {
        perror("Error getting host by name\n");
        return 1;
    }

    // create socket
    if((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating socket\n");
        return 1;
    }

    // set up server address
    memset((char *)&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(993); // default IMAP port
    memcpy((char *)&server_address.sin_addr.s_addr, (char *)server_info->h_addr, server_info->h_length);

    // connect to server
    if(connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Error connecting to server\n");
        return 1;
    }

    // read initial server greeting
    memset(buffer, 0, MAX_SIZE);
    nbytes = read(socket_fd, buffer, MAX_SIZE);
    if(nbytes < 0) {
        perror("Error reading from server\n");
        return 1;
    }
    printf("%s\n", buffer);

    // send login command
    sprintf(buffer, "a001 LOGIN %s %s\r\n", argv[2], argv[3]);
    nbytes = write(socket_fd, buffer, strlen(buffer));
    if(nbytes < 0) {
        perror("Error writing to server\n");
        return 1;
    }

    // read login response
    memset(buffer, 0, MAX_SIZE);
    nbytes = read(socket_fd, buffer, MAX_SIZE);
    if(nbytes < 0) {
        perror("Error reading from server\n");
        return 1;
    }
    printf("%s\n", buffer);

    // send logout command
    sprintf(buffer, "a002 LOGOUT\r\n");
    nbytes = write(socket_fd, buffer, strlen(buffer));
    if(nbytes < 0) {
        perror("Error writing to server\n");
        return 1;
    }

    // read logout response
    memset(buffer, 0, MAX_SIZE);
    nbytes = read(socket_fd, buffer, MAX_SIZE);
    if(nbytes < 0) {
        perror("Error reading from server\n");
        return 1;
    }
    printf("%s\n", buffer);

    // close connection
    close(socket_fd);

    return 0;
}