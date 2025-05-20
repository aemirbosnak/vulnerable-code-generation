//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>

int main()
{
    // Set up the destination host and port for the ping command
    struct hostent* dest_host;
    dest_host = gethostbyname("www.google.com");
    if (dest_host == NULL) {
        printf("Hostname not found\n");
        exit(0);
    }

    int sockfd;
    struct sockaddr_in dest_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(80);
    dest_addr.sin_addr.s_addr = *(long*)(dest_host->h_addr);

    if (connect(sockfd, (struct sockaddr*)&dest_addr, sizeof(dest_addr)) < 0) {
        printf("Connection failed\n");
        exit(0);
    }

    char buffer[1024];
    printf("Enter message to send: ");
    fgets(buffer, sizeof(buffer), stdin);
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        printf("Write failed\n");
        exit(0);
    }

    printf("Waiting for reply...\n");
    int n;
    if ((n = read(sockfd, buffer, sizeof(buffer))) < 0) {
        printf("Read failed\n");
        exit(0);
    }

    printf("Received: %s\n", buffer);

    close(sockfd);
    return 0;
}