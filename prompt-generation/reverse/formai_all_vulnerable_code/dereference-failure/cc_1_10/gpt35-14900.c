//FormAI DATASET v1.0 Category: Network Ping Test ; Style: portable
#include <stdio.h> 
#include <stdlib.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h> 

#define PING_PACKET_SIZE 64 

/* This function is used to calculate the Checksum */
unsigned short calc_checksum(unsigned short *buf, int len) 
{ 
    unsigned long sum = 0; 

    while (len > 1) 
    { 
        sum += *buf++; 
        len -= 2; 
    } 

    if (len == 1) 
        sum += *(unsigned char*)buf; 

    sum = (sum >> 16) + (sum & 0xffff); 
    sum += (sum >> 16); 

    return (unsigned short)(~sum); 
}

/* This function is used to send the Ping request */
void send_ping_request(int sockfd, struct sockaddr_in *dest_addr) 
{ 
    /* Define the Ping request packet */
    char ping_packet[PING_PACKET_SIZE]; 

    /* Set the Packet Length */
    int packet_len = PING_PACKET_SIZE; 

    /* Clear the Ping Packet */
    bzero(ping_packet, sizeof(ping_packet)); 

    /* Set the Type of Request */
    ping_packet[0] = 8; 

    /* Set the Type of Code */
    ping_packet[1] = 0; 

    /* Set the Identifier */
    ping_packet[4] = 1; 

    /* Calculate the Check Sum */
    unsigned short *checksum = (unsigned short*)(ping_packet + 2); 
    *checksum = calc_checksum((unsigned short*)ping_packet, packet_len); 

    /* Send the Ping Request */
    if (sendto(sockfd, ping_packet, packet_len, 0, (struct sockaddr*) dest_addr, sizeof(*dest_addr)) <= 0) 
        printf("Error in Sending the Ping Request!\n"); 
} 

/* This function is used to receive the Ping response */
void receive_ping_response(int sockfd, struct sockaddr_in *dest_addr) 
{ 
    /* Define the Ping Response Packet */
    char ping_response_packet[PING_PACKET_SIZE]; 

    /* Set the Packet Length */
    int packet_len = PING_PACKET_SIZE; 

    /* Clear the Ping Response Packet */
    bzero(&ping_response_packet, sizeof(ping_response_packet)); 

    /* Receive the Ping Response */
    if (recvfrom(sockfd, ping_response_packet, packet_len, 0, (struct sockaddr*)dest_addr, &packet_len) <= 0) 
        printf("Error in Receiving the Ping Response!\n"); 
} 

/* Main function */
int main(int argc, char *argv[]) 
{ 
    /* Check if the Input is Entered Properly */
    if (argc != 2) 
    { 
        printf("Usage: ./ping <hostname>\n"); 
        exit(1); 
    } 

    int sockfd; 
    struct hostent *host; 
    struct sockaddr_in dest_addr; 

    /* Set the Host */
    host = gethostbyname(argv[1]); 

    /* Check if the Host is Valid */
    if (!host) 
    { 
        printf("Unknown Host!\n"); 
        exit(1); 
    } 

    /* Create the Socket */
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP); 

    /* Check if the Socket is Valid */
    if(sockfd < 0) 
    { 
        printf("Error in Creating the Socket!\n"); 
        exit(1); 
    } 

    /* Set the Destination Address */
    dest_addr.sin_family = AF_INET; 
    dest_addr.sin_port = htons(0); 
    dest_addr.sin_addr = *((struct in_addr*)(host->h_addr)); 

    /* Send the Ping Request */
    send_ping_request(sockfd, &dest_addr); 

    /* Receive the Ping Response */
    receive_ping_response(sockfd, &dest_addr); 

    return 0; 
}