//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netdb.h>
#include<errno.h>
#include<ctype.h>
#include<ifaddrs.h>
#include<net/if.h>

#define MAX_IF_NAME 16
#define MAX_IFACES 64
#define MAX_IP_LEN 40

struct interface{
    char if_name[MAX_IF_NAME];
    char ip_addr[MAX_IP_LEN];
};

struct interface iface_list[MAX_IFACES];
int curr_iface = 0;

int get_iface_list(){
    memset(&iface_list, 0, sizeof(iface_list));
    struct ifaddrs *addrs, *tmp_addr;
    if(getifaddrs(&addrs)<0){
        perror("getifaddrs failed");
        return -1;
    }

    tmp_addr = addrs;
    while(tmp_addr != NULL){
        if(tmp_addr->ifa_addr->sa_family == AF_INET){
            struct sockaddr_in *addr = (struct sockaddr_in *)tmp_addr->ifa_addr;
            strncpy(iface_list[curr_iface].if_name, tmp_addr->ifa_name, MAX_IF_NAME-1);
            strncpy(iface_list[curr_iface].ip_addr, inet_ntoa(addr->sin_addr), MAX_IP_LEN-1);
          curr_iface++;
        }
        tmp_addr = tmp_addr->ifa_next;
    }
    freeifaddrs(addrs);
    return 0;
}

int main(){
    if(get_iface_list()<0){
        exit(1);
    }

    int s, fd;
    struct addrinfo hints, *result;
    int status;
    char ipstr[INET6_ADDRSTRLEN];
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    for(int i=0; i<curr_iface; i++){
        printf("\nInterface: %s, IP Address: %s\n", iface_list[i].if_name, iface_list[i].ip_addr);
        if( (s = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0){
            perror("unable to create socket");
            continue;
        }
        memset(&hints, 0, sizeof(hints));
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_STREAM;
        status = getaddrinfo(iface_list[i].ip_addr, NULL, &hints, &result);
        if(status != 0){
            fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
            continue;
        }
        struct sockaddr_in *ipv4 = (struct sockaddr_in *)(result->ai_addr);
        char ip_addr[MAX_IP_LEN];
        inet_ntop(AF_INET, &(ipv4->sin_addr), ip_addr, INET_ADDRSTRLEN);
        printf("Address: %s\n", ip_addr);

        // display route
        char cmd[128];
        sprintf(cmd, "traceroute %s", ip_addr);
        printf("%s\n", cmd);
        system(cmd);
    }
    return 0;
}