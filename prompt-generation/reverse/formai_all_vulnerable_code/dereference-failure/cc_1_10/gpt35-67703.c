//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Sherlock Holmes
/*******************************************************
* "The Mystery of Network Performance"
* A C Network Quality of Service (QoS) Monitor Example Program
* By Sherlock Holmes
********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define BUFSIZE 1024     // buffer size for sending and receiving data
#define TIMEOUT 5        // time limit for response in seconds
#define MAX_RETRIES 3    // maximum number of retries for failed connections
#define MAX_PACKET_LOSS 10 // maximum allowed percentage of packet loss

int sockfd;              // socket file descriptor
struct sockaddr_in servaddr;  // server socket address
struct sockaddr_in cliaddr;  // client socket address
int packets_sent = 0;      // number of packets sent
int packets_received = 0;  // number of packets received
int packets_lost = 0;      // number of packets lost
int prev_seq_num = -1;     // previous sequence number
int curr_seq_num = 0;      // current sequence number
char buf[BUFSIZE];         // buffer for receiving data

// function to handle timeout
void timeout_handler(int sig)
{
    if (packets_sent > 0 && packets_received == 0) {
        printf("Connection Timeout. No response received after %d seconds.\n", TIMEOUT);
        printf("QoS: 0\n");
        exit(0);
    }
}

// function to calculate the packet loss percentage
int calculate_packet_loss()
{
    return (packets_lost * 100) / packets_sent;
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        printf("Usage: %s <Server IP Address> <Port>\n", argv[0]);
        exit(1);
    }

    // assign signal handler for timeout
    signal(SIGALRM, timeout_handler);

    // create a UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // initialize server socket address
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(atoi(argv[2]));

    // initialize client socket address
    bzero(&cliaddr, sizeof(cliaddr));
    cliaddr.sin_family = AF_INET;
    cliaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    cliaddr.sin_port = htons(0);

    // bind socket to client address
    if (bind(sockfd, (struct sockaddr *) &cliaddr, sizeof(cliaddr)) < 0) {
        perror("Error binding socket to client address");
        exit(1);
    }

    // initialize buffer to all zeros
    bzero(buf, BUFSIZE);

    // send the first packet with sequence number 0
    curr_seq_num = 0;
    sprintf(buf, "%d", curr_seq_num);
    sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *) &servaddr, sizeof(servaddr));
    packets_sent++;

    // start the timer for the response
    alarm(TIMEOUT);

    while (1) {
        // wait for a response from the server
        socklen_t len = sizeof(servaddr);
        int n = recvfrom(sockfd, buf, BUFSIZE, 0, (struct sockaddr *) &servaddr, &len);

        // reset the timer for the next response
        alarm(0);

        // check if the packet is valid
        if (n > 0) {
            buf[n] = 0;
            sscanf(buf, "%d", &curr_seq_num);

            // check if the sequence number is valid
            if (curr_seq_num == prev_seq_num + 1) {
                packets_received++;
                prev_seq_num = curr_seq_num;

                // send the next packet with the new sequence number
                curr_seq_num++;
                sprintf(buf, "%d", curr_seq_num);
                sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *) &servaddr, sizeof(servaddr));
                packets_sent++;

                // start the timer for the next response
                alarm(TIMEOUT);
            }
        }

        // check if the maximum number of retries has been reached
        if (packets_sent >= MAX_RETRIES) {
            printf("Failed to establish a connection after %d attempts.\n", MAX_RETRIES);
            printf("QoS: 0\n");
            exit(0);
        }

        // check if the maximum allowed packet loss has been reached
        if (calculate_packet_loss() >= MAX_PACKET_LOSS) {
            printf("The network is experiencing high packet loss.\n");
            printf("QoS: %d\n", calculate_packet_loss());
            exit(0);
        }
    }

    close(sockfd);
    return 0;
}