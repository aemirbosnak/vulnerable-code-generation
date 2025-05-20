//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/types.h>
#include <netinet/tcp.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <fcntl.h>

#define MAX_BUFF_SIZE 65535
#define PORT_NUMBER 80
#define DESTINATION_IP "www.google.com"

int main(int argc, char *argv[]) {
    int sockfd, ret, bytes_sent, bytes_recv;
    struct sockaddr_in dest_addr;
    char *send_buffer = (char*) malloc(MAX_BUFF_SIZE);
    char *recv_buffer = (char*) malloc(MAX_BUFF_SIZE);
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("Error Opening Socket");
        return -1;
    }

    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(PORT_NUMBER);
    dest_addr.sin_addr.s_addr = inet_addr(DESTINATION_IP);

    ret = connect(sockfd, (struct sockaddr*) &dest_addr, sizeof(dest_addr));
    if (ret < 0) {
        perror("Error Connecting");
        return -1;
    }

    sprintf(send_buffer, "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n");
    bytes_sent = send(sockfd, send_buffer, strlen(send_buffer), 0);
    if (bytes_sent < 0) {
        perror("Error sending request message");
    }

    ret = setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (struct timeval*) &timeout, sizeof(timeout));
    if (ret < 0) {
        perror("Error setting receive timeout");
    }

    bytes_recv = recv(sockfd, recv_buffer, MAX_BUFF_SIZE, 0);

    if (bytes_recv < 0) {
        perror("Error receiving response message");
    }
    else {
        printf("Received message:\n %s\n", recv_buffer);
    }

    close(sockfd);

    return 0;
}