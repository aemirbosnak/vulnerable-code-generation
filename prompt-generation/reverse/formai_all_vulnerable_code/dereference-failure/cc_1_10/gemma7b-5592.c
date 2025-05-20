//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: authentic
#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

#define SERVER_PORT 8888
#define BUFFER_SIZE 1024

int main() {
    int sockfd, port, n, i, time_start, time_end;
    char buf[BUFFER_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *hp;

    // Get the host name from the user
    char host_name[256];
    printf("Enter the hostname or IP address: ");
    scanf("%s", host_name);

    // Resolve the host name
    hp = gethostbyname(host_name);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(SERVER_PORT));

    // Connect to the server
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    serv_addr.sin_addr = *(struct in_addr *)hp->h_addr;

    time_start = time(NULL);

    // Send a ping message
    buf[0] = 'P';
    sendto(sockfd, buf, 1, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    // Receive the reply
    n = recvfrom(sockfd, buf, BUFFER_SIZE, 0, (struct sockaddr *)&serv_addr, NULL);

    time_end = time(NULL);

    // Print the results
    if (n > 0) {
        printf("Reply from %s: %s\n", hp->h_name, buf);
        printf("Time taken: %d milliseconds\n", time_end - time_start);
    } else {
        printf("Error: No reply from the server.\n");
    }

    close(sockfd);

    return 0;
}