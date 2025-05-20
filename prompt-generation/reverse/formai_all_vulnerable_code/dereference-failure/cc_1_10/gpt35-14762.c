//FormAI DATASET v1.0 Category: Network Ping Test ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/ip_icmp.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <math.h>

#define PING_PACKET_SIZE 64
#define MAX_RETRIES 2

void usage(char *program_name){
    printf("Usage: %s [ip_address]\n", program_name);
}

unsigned short compute_ip_checksum(void *data, int length){
    unsigned short *buffer = data;
    unsigned int sum = 0;
    unsigned short checksum = 0;

    for(; length > 1; length -= 2){
        sum += *buffer++;
    }

    if (length == 1){
        sum += *(unsigned char*)buffer;
    }

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);

    checksum = ~sum;

    return checksum;
}

int send_ping(int socket_fd, struct sockaddr_in *dest_addr, unsigned short sequence_num){
    struct timeval send_time;
    struct icmp ping_packet;
    double rounded_trip_time = 0.0;
    int ret_val = -1;

    ping_packet.icmp_type = ICMP_ECHO;
    ping_packet.icmp_code = 0;
    ping_packet.icmp_id = (unsigned short)getpid();
    ping_packet.icmp_seq = sequence_num;
    ping_packet.icmp_cksum = 0;
    ping_packet.icmp_cksum = compute_ip_checksum(&ping_packet, PING_PACKET_SIZE);

    if (gettimeofday(&send_time, NULL) == 0){
        ret_val = sendto(socket_fd, &ping_packet, PING_PACKET_SIZE, 0, (struct sockaddr*)dest_addr, sizeof(*dest_addr));

        if (ret_val > 0){
            rounded_trip_time = round((double)send_time.tv_usec / 1000); // round to nearest millisecond
            printf("SENT PING PACKET: sequence number = %hu, destination ip address = %s, rounded trip time = %f ms\n", sequence_num, inet_ntoa(dest_addr->sin_addr), rounded_trip_time);
        }
    }

    return ret_val;
}

int receive_ping(int socket_fd, struct sockaddr_in *received_from_addr, unsigned short sequence_num){
    struct timeval receive_time;
    struct icmp received_packet;
    socklen_t socket_len = sizeof(*received_from_addr);
    double rounded_trip_time = 0.0;
    int ret_val = -1;

    ret_val = recvfrom(socket_fd, &received_packet, PING_PACKET_SIZE, 0, (struct sockaddr*)received_from_addr, &socket_len);

    if (ret_val > 0 && received_packet.icmp_type == ICMP_ECHOREPLY && received_packet.icmp_id == getpid() && received_packet.icmp_seq == sequence_num){
        if (gettimeofday(&receive_time, NULL) == 0){
            rounded_trip_time = round((double)(receive_time.tv_usec - received_packet.icmp_otime) / 1000); // round to nearest millisecond
            printf("RECEIVED PING PACKET: sequence number = %hu, from ip address = %s, rounded trip time = %f ms\n", sequence_num, inet_ntoa(received_from_addr->sin_addr), rounded_trip_time);
        }
    }

    return ret_val;
}

int main(int argc, char *argv[]){
    int socket_fd = -1;
    char *dest_ip_address = NULL;
    struct sockaddr_in dest_addr;
    int retry_count = 0;
    unsigned short sequence_num = 0;
    int ret_val = -1;

    if (argc == 2){
        dest_ip_address = argv[1];

        socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

        if (socket_fd != -1){
            memset(&dest_addr, 0, sizeof(dest_addr));
            dest_addr.sin_family = AF_INET;
            ret_val = inet_pton(AF_INET, dest_ip_address, &dest_addr.sin_addr);

            if (ret_val == 1){
                while (retry_count <= MAX_RETRIES){
                    ret_val = send_ping(socket_fd, &dest_addr, sequence_num);

                    if (ret_val > 0){
                        ret_val = receive_ping(socket_fd, &dest_addr, sequence_num);

                        if (ret_val > 0){
                            retry_count = 0;
                        }
                        else{
                            retry_count++;
                        }

                        sequence_num++;
                    }
                    else{
                        retry_count++;
                    }
                }
            }
            else{
                printf("Invalid IP address '%s'!\n", dest_ip_address);
            }

            close(socket_fd);
        }
        else{
            printf("Could not open raw socket!\n");
        }
    }
    else{
        usage(argv[0]);
    }

    return 0;
}