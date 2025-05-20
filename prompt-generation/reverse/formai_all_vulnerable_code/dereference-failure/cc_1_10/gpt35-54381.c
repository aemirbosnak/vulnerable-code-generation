//FormAI DATASET v1.0 Category: Network Ping Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <time.h>



/* function to calculate the time difference from start to end*/
double time_diff(struct timeval x , struct timeval y)
{
    double x_ms, y_ms, diff;

    x_ms = (double)x.tv_sec*1000000 + (double)x.tv_usec;
    y_ms = (double)y.tv_sec*1000000 + (double)y.tv_usec;

    diff = (double)y_ms - (double)x_ms;

    return diff;
}

int main(int argc, char *argv[])
{

    int optval;
    int sockfd;
    struct sockaddr_in dest_addr;
    struct addrinfo hints, *result;
    int num_packets_sent = 0;
    int num_packets_recv = 0;
    int max_ttl = 30;
    int msg_count = 0;
    int ttl_val = 64;
    double total_time_taken = 0;
    char *hostname;
    struct timeval start_time, end_time;

    //parse hostname and maximum TTL from command line arguments
    if(argc != 3)
    {
        printf("Usage: ./ping <hostname> <max_ttl>\n");
        exit(1);
    }
    else
    {
        hostname = argv[1];
        max_ttl = atoi(argv[2]);
    }

    //initialize hints for getaddrinfo()
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_RAW;
    hints.ai_protocol = IPPROTO_ICMP;

    //get list of address structures
    if (getaddrinfo(hostname, NULL, &hints, &result) != 0) 
    {
        perror("getaddrinfo");
        exit(1);
    }

    //create a socket
    sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

    //set socket options
    optval = 1;
    if (setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl_val, sizeof(ttl_val)) != 0) 
    {
        perror("setsockopt");
        exit(1);
    }

    //loop over TTL values and send ping packets
    for(int ttl = 1; ttl <= max_ttl; ttl++)
    {
        num_packets_sent = 0;
        num_packets_recv = 0;
        total_time_taken = 0;

        printf("TTL: %d\n", ttl);

        //set TTL for socket
        if (setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) != 0) 
        {
            perror("setsockopt");
            exit(1);
        }

        //set recv timeout for socket
        struct timeval timeout;      
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;
        if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0)
        {
            perror("setsockopt");
            exit(1);
        }

        //loop over messages and send ping packets
        for(msg_count = 0; msg_count < 3; msg_count++)
        {
            memset(&dest_addr, 0, sizeof(dest_addr));
            dest_addr.sin_family = AF_INET;
            dest_addr.sin_addr.s_addr = ((struct sockaddr_in *)(result->ai_addr))->sin_addr.s_addr;
            dest_addr.sin_port = htons(0);

            //get start time
            gettimeofday(&start_time, NULL);

            //send ping packet
            if(sendto(sockfd, "PING", 4, 0, (struct sockaddr*)&dest_addr, sizeof(dest_addr)) <= 0)
            {
                perror("sendto");
                exit(1);
            }

            //receive ping reply
            char buf[1024];
            socklen_t len;
            struct timeval tval;
            memset(&tval, 0, sizeof(struct timeval));
            len = sizeof(dest_addr);
            int n = recvfrom(sockfd, buf, 1024, 0, (struct sockaddr*)&dest_addr, &len);

            //get end time
            gettimeofday(&end_time, NULL);

            if(n <= 0)
            {
                printf("Recvfrom error: %s\n", strerror(errno));
            }
            else
            {
                num_packets_recv++;
                double time_taken = time_diff(start_time, end_time);
                total_time_taken += time_taken;
                printf("Packet received from: %s, seq=%d, rt=%f\n", inet_ntoa(dest_addr.sin_addr), msg_count, time_taken);
            }

            num_packets_sent++;

            //sleep
            usleep(1000000);
        }

        if(num_packets_recv == 0)
        {
            printf("No packets received.\n");
        }
        else
        {
            double avg_time_taken = total_time_taken / num_packets_recv;
            printf("Average round trip time: %f ms\n", avg_time_taken);
        }

        printf("%d packets sent, %d packets received\n", num_packets_sent, num_packets_recv);
    }

    close(sockfd);

    return 0;
}