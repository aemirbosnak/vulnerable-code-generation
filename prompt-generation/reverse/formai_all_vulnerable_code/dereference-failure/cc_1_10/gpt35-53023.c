//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <ctype.h>
#include <sys/time.h>
#include <errno.h>
#include <signal.h>

#define MAX_BUF_SIZE 1024
#define TIMEOUT 5 // in seconds

// Function to handle errors
void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE); 
}

// Function to convert hostname to IP address
int hostname_to_ip(const char *hostname, char *ip) {
    struct hostent *he;
    struct in_addr **addr_list;
    int i;
         
    if ((he = gethostbyname(hostname)) == NULL) {  
        herror("gethostbyname");
        return -1;
    }
     
    addr_list = (struct in_addr **) he->h_addr_list;
     
    for(i = 0; addr_list[i] != NULL; i++) {
        // Return the first one we find
        strcpy(ip, inet_ntoa(*addr_list[i]));
        return 0;
    }
 
    return -1;
}

// Function to measure RTT of a request
double measure_rtt(int sockfd, struct sockaddr_in *server_addr) {
    char buf[MAX_BUF_SIZE];
    struct timeval start, end;
    
    // Send request to server
    sendto(sockfd, "PING", 4, MSG_CONFIRM, (const struct sockaddr *) server_addr, sizeof(*server_addr));
    
    // Record start time
    gettimeofday(&start, NULL);
    
    // Wait for response from server or timeout
    fd_set set;
    FD_ZERO(&set);
    FD_SET(sockfd, &set);
    struct timeval timeout = { TIMEOUT, 0 };
    int rv = select(sockfd + 1, &set, NULL, NULL, &timeout);
    
    // Record end time
    gettimeofday(&end, NULL);
    
    // Check if there was a timeout or error
    if (rv == -1) {
        if (errno == EINTR) {
            return -1; // Interrupted by signal, so return -1 to retry
        }
        handle_error("select");
    }
    else if (rv == 0) {
        return -1; // Timed out without receiving response
    }
    
    // Receive response from server
    int len = sizeof(*server_addr);
    int n = recvfrom(sockfd, (char *) buf, MAX_BUF_SIZE, MSG_WAITALL, (struct sockaddr *) server_addr, &len);
    if (n < 0) {
        handle_error("recvfrom");
    }
    
    // Calculate RTT and return
    double rtt = ((double) (end.tv_usec - start.tv_usec) / 1000 + (double) (end.tv_sec - start.tv_sec) * 1000);
    return rtt;
}

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        fprintf(stderr,"Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    const char *hostname = argv[1];
    char ip[INET_ADDRSTRLEN];
    int sockfd;
    struct sockaddr_in server_addr;
    
    // Convert hostname to IP address
    if (hostname_to_ip(hostname, ip) < 0) {
        handle_error("hostname_to_ip");
    }
    printf("%s resolved to %s\n", hostname, ip);
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sockfd < 0) {
        handle_error("socket");
    }
    
    // Set socket options for QoS
    int dscp_value = 46; // Expedited Forwarding (EF)
    if (setsockopt(sockfd, IPPROTO_IP, IP_TOS, &dscp_value, sizeof(dscp_value)) < 0) {
        handle_error("setsockopt");
    }
    
    // Set server address parameters
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(3000);
    if (inet_pton(AF_INET, ip, &server_addr.sin_addr) <= 0) {
        handle_error("inet_pton");
    }
    
    // Send 10 requests and measure RTT for each
    double total_rtt = 0;
    int num_requests = 10;
    for (int i = 0; i < num_requests; i++) {
        double rtt = measure_rtt(sockfd, &server_addr);
        if (rtt < 0) {
            i--; // Retry failed requests
            continue;
        }
        total_rtt += rtt;
        printf("Received PING response from %s in %.3f ms\n", ip, rtt);
        sleep(1); // Wait between requests
    }
    
    // Calculate and print average RTT
    double avg_rtt = total_rtt / num_requests;
    printf("Average RTT is %.3f ms\n", avg_rtt);
    
    // Close socket
    if (close(sockfd) < 0) {
        handle_error("close");
    }
    
    return 0;
}