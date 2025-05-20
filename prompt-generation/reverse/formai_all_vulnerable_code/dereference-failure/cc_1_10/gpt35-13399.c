//FormAI DATASET v1.0 Category: Network Ping Test ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <time.h>

#define PACKET_SIZE 64
#define ICMP_ECHO_REQUEST 8
#define ICMP_ECHO_REPLY 0
#define MAX_HOP 64
#define TIMEOUT_SEC 5

typedef struct{
        int sockfd;
        struct sockaddr_in sendaddr;
        struct sockaddr_in recvaddr;
}ping_args;

// Function to calculate checksum
unsigned short checksum(unsigned short *buf, int nwords){
        unsigned long sum;
        for(sum=0; nwords>0; nwords--){
                sum += *buf++;
        }
        sum = (sum >> 16) + (sum & 0xffff);
        sum += (sum >> 16);
        return (unsigned short)(~sum);
}

// Function to fill the packet
void fill_packet(char *buf, int packet_size){
        struct icmp *icmphdr;
        icmphdr = (struct icmp *)buf;
        icmphdr->icmp_type = ICMP_ECHO_REQUEST;
        icmphdr->icmp_code = 0;
        icmphdr->icmp_id = getpid();
        icmphdr->icmp_seq = 0;
        memset(icmphdr->icmp_data, 'b', packet_size - sizeof(struct icmp));
        icmphdr->icmp_cksum = 0;
        icmphdr->icmp_cksum = checksum((unsigned short *)icmphdr, packet_size / 2);
}

// Function to send the packet
void send_packet(ping_args *args, char *packet, int packet_size){
        int bytesend;
        if((bytesend = sendto(args->sockfd, packet, packet_size, 0, (struct sockaddr *)&args->sendaddr, sizeof(struct sockaddr))) == -1){
                perror("Sendto Error");
                exit(EXIT_FAILURE);
        }
}

// Function to receive the reply
int receive_reply(ping_args *args, struct sockaddr_in *recvaddr, struct timeval *start_time){
        char buf[PACKET_SIZE];
        int len = sizeof(struct sockaddr);
        int nbytes;
        struct timeval end_time;
        struct ip *iphdr;
        struct icmp *icmp_hdr;

        // Wait for ICMP reply
        while(1){
                fd_set read_set;
                FD_ZERO(&read_set);
                FD_SET(args->sockfd, &read_set);
                struct timeval timeout;
                timeout.tv_sec = TIMEOUT_SEC;
                timeout.tv_usec = 0;
                if((nbytes = select(args->sockfd+1, &read_set, NULL, NULL, &timeout)) <= 0){
                        return -1;
                }
                if((nbytes = recvfrom(args->sockfd, buf, sizeof(buf), 0, (struct sockaddr *)recvaddr, (socklen_t *)&len)) == -1){
                        perror("Recvfrom Error");
                        exit(EXIT_FAILURE);
                }

                gettimeofday(&end_time,NULL);

                iphdr = (struct ip *)buf;
                icmp_hdr = (struct icmp *)(buf + iphdr->ip_hl * 4);
                if(icmp_hdr->icmp_type == ICMP_ECHO_REPLY && icmp_hdr->icmp_id == getpid()){
                        int roundtrip_time = (int)((end_time.tv_sec - start_time->tv_sec) * 1000 + ((end_time.tv_usec - start_time->tv_usec + 500.0) / 1000.0));
                        printf("%d bytes from %s: icmp_seq=%u ttl=%d time=%d ms\n", nbytes, inet_ntoa(recvaddr->sin_addr), icmp_hdr->icmp_seq, iphdr->ip_ttl, roundtrip_time);
                        return 0;
                }
        }
}

// Function to set up the socket
ping_args *setup_socket(char *hostname){

        ping_args *args = (ping_args *)malloc(sizeof(ping_args));

        struct hostent *host;
        if ((host = gethostbyname(hostname)) == NULL){
                printf("Cannot Resolve the Hostname %s\n", hostname);
                exit(EXIT_FAILURE);
        }

        args->sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
        if(args->sockfd < 0){
                perror("Socket Creation Error");
                exit(EXIT_FAILURE);
        }

        args->sendaddr.sin_family = AF_INET;
        args->recvaddr.sin_family = AF_INET;
        memcpy(&args->sendaddr.sin_addr, host->h_addr, host->h_length);
        memcpy(&args->recvaddr.sin_addr, host->h_addr, host->h_length);

        return args;
}

// Function to run the ping test
void ping(char *hostname){

        int ttl=1;
        int failed=0;
        int exit_condition=0;    // 0 for max hop, 1 for exit on first failed
        struct timeval start_time;
        gettimeofday(&start_time,NULL);

        // Setup the socket
        ping_args *args = setup_socket(hostname);

        // Set TTL option of IP Header
        if(setsockopt(args->sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(int)) < 0){
            perror("setsockopt failed");
                exit(EXIT_FAILURE);
        }

        printf("PING %s:\n", hostname);

        while(1){
                char packet[PACKET_SIZE];

                // Fill the packet
                fill_packet(packet, PACKET_SIZE);

                if(failed == MAX_HOP - 1){
                        exit_condition = 1;
                }
                // Send the packet
                send_packet(args, packet, PACKET_SIZE);

                struct timeval t1,t2;
                gettimeofday(&t1, NULL);

                if(receive_reply(args, &args->recvaddr,&t1) == -1){
                        printf("* * *\n");
                        failed++;
                        if(exit_condition){
                                printf("\nExiting: Maximum Hops Reached\n");
                                exit(0);
                        }
                }
                else{
                        failed = 0;
                        int cur_ttl = ttl++;
                        if(setsockopt(args->sockfd, IPPROTO_IP, IP_TTL, &cur_ttl, sizeof(int)) < 0){
                            perror("setsockopt failed");
                                exit(EXIT_FAILURE);
                        }
                        if(args->recvaddr.sin_addr.s_addr == args->sendaddr.sin_addr.s_addr){
                                printf("\nExiting: Success\n");
                                exit(0);
                        }
                        else if(cur_ttl == MAX_HOP - 1){
                                printf("* * *\n");
                        }
                        else{
                                printf("\n");
                        }
                }
        }

}

int main(int argc, char **argv){

        if(argc != 2){
                printf("Usage: ping <hostname/IP>\n");
                exit(EXIT_FAILURE);
        }

        ping(argv[1]);

        return 0;
}