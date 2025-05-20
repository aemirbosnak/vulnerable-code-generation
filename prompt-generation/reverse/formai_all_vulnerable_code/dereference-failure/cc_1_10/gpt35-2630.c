//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LEN 1024

int main(int argc, char *argv[]) {
    int sock_fd, ret;
    struct sockaddr_in serv_addr;
    char buf[MAX_LEN];
    int num_bytes_read;

    if (argc != 3) {
        printf("Usage: %s <server_ip_address> <port_num>\n", argv[0]);
        return 1;
    }

    // create a socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Error: failed to create socket");
        return 1;
    }

    //memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    // connect to the server
    ret = connect(sock_fd, (struct sockaddr*) &serv_addr, sizeof(serv_addr));
    if (ret < 0) {
        perror("Error: failed to connect to server");
        return 1;
    }

    // read the welcome message from the server
    memset(buf, 0, MAX_LEN);
    num_bytes_read = read(sock_fd, buf, MAX_LEN);
    if (num_bytes_read < 0) {
        perror("Error: failed to read from socket");
        return 1;
    }
    printf("Server says: %s\n", buf);

    // send the IMAP command to the server
    memset(buf, 0, MAX_LEN);
    printf("Enter your IMAP command: ");
    fgets(buf, MAX_LEN, stdin);
    printf("Sending the following command: %s\n", buf);
    ret = write(sock_fd, buf, strlen(buf));
    if (ret < 0) {
        perror("Error: failed to write to socket");
        return 1;
    }

    // read the reply from the server
    memset(buf, 0, MAX_LEN);
    num_bytes_read = read(sock_fd, buf, MAX_LEN);
    if (num_bytes_read < 0) {
        perror("Error: failed to read from socket");
        return 1;
    }
    printf("Server replies: %s\n", buf);

    // close the socket
    close(sock_fd);

    return 0;
}