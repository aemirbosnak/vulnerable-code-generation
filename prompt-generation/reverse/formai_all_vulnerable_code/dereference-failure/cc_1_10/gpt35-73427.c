//FormAI DATASET v1.0 Category: Network Ping Test ; Style: intelligent
/*
 * C Network Ping Test Example Program
 * By [Your Name]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>

#define PING_TIMEOUT 2000

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <hostname or IP address>\n", argv[0]);
        return 1;
    }

    struct addrinfo hints;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC; // use IPv4 or IPv6, whichever is available
    hints.ai_socktype = SOCK_DGRAM; // use UDP for ping

    struct addrinfo *result;
    int status = getaddrinfo(argv[1], NULL, &hints, &result);
    if (status != 0)
    {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        return 1;
    }

    // loop through all the results and find the first suitable address
    int sockfd;
    for (struct addrinfo *p = result; p != NULL; p = p->ai_next)
    {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1)
        {
            perror("socket");
            continue;
        }

        // set timeout for receive operation
        struct timeval timeout;
        timeout.tv_sec = PING_TIMEOUT / 1000;
        timeout.tv_usec = (PING_TIMEOUT % 1000) * 1000;
        if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof timeout) == -1)
            perror("setsockopt");

        // send ping packet
        const char *ping_payload = "Hello, world!";
        ssize_t bytes_sent = sendto(sockfd, ping_payload, strlen(ping_payload), 0,
                                    p->ai_addr, p->ai_addrlen);
        if (bytes_sent == -1)
        {
            perror("sendto");
            continue;
        }

        // receive ping response
        char recv_buffer[100];
        struct sockaddr_storage sender_addr;
        socklen_t sender_addrlen = sizeof sender_addr;
        ssize_t bytes_received = recvfrom(sockfd, recv_buffer, sizeof recv_buffer, 0,
                                          (struct sockaddr *) &sender_addr, &sender_addrlen);
        if (bytes_received == -1)
        {
            if (errno == EAGAIN)
                printf("Ping timed out for %s\n", argv[1]);
            else
                perror("recvfrom");
        }
        else
        {
            // calculate round trip time
            struct timeval t1, t2;
            gettimeofday(&t1, NULL);
            gettimeofday(&t2, NULL);
            long elapsed_time = (t2.tv_sec - t1.tv_sec) * 1000 + (t2.tv_usec - t1.tv_usec) / 1000;

            // output ping result
            char sender_ip_str[INET6_ADDRSTRLEN];
            getnameinfo((struct sockaddr *) &sender_addr, sender_addrlen,
                        sender_ip_str, sizeof sender_ip_str, NULL, 0, NI_NUMERICHOST);
            printf("Ping reply from %s: bytes=%ld time=%ldms\n", sender_ip_str,
                   (long) bytes_received, elapsed_time);
        }

        break; // we got a suitable address, so stop here
    }

    freeaddrinfo(result);
    close(sockfd);

    return 0;
}