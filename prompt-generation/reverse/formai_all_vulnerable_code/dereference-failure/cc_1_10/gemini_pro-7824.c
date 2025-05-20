//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

struct net_range {
    unsigned long long int first;
    unsigned long long int last;
};

struct net_info {
    struct net_range range;
    char ssid[33];
    unsigned char channel;
    unsigned char signal;
    unsigned char security;
};

void parse_iwlist(char *line, struct net_info *ni) {
    char *start, *end;
    
    start = strstr(line, "Address: ");
    if (!start) {
        return;
    }
    start += strlen("Address: ");
    end = strchr(start, '\n');
    if (!end) {
        return;
    }
    *end = '\0';
    inet_aton(start, (struct in_addr *)&ni->range.first);
    
    start = strstr(line, "ESSID:");
    if (!start) {
        return;
    }
    start += strlen("ESSID:");
    end = strchr(start, '\n');
    if (!end) {
        return;
    }
    *end = '\0';
    strncpy(ni->ssid, start, sizeof(ni->ssid)-1);
    
    start = strstr(line, "Channel:");
    if (!start) {
        return;
    }
    start += strlen("Channel:");
    end = strchr(start, '\n');
    if (!end) {
        return;
    }
    *end = '\0';
    ni->channel = atoi(start);
    
    start = strstr(line, "Signal level:");
    if (!start) {
        return;
    }
    start += strlen("Signal level:");
    end = strchr(start, '\n');
    if (!end) {
        return;
    }
    *end = '\0';
    ni->signal = atoi(start);
    
    start = strstr(line, "Encryption key:");
    if (!start) {
        return;
    }
    start += strlen("Encryption key:");
    end = strchr(start, '\n');
    if (!end) {
        return;
    }
    *end = '\0';
    if (strstr(start, "on")) {
        ni->security = 1;
    } else {
        ni->security = 0;
    }
}

void scan_network(struct net_range range, struct net_info **nis) {
    int i, sockfd;
    struct sockaddr_in addr;
    char *command, *line, *p;
    unsigned int len;
    struct net_info *ni;
    
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }
    
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("192.168.1.1");
    addr.sin_port = htons(80);
    
    command = malloc(1024);
    if (!command) {
        perror("malloc");
        exit(1);
    }
    
    line = malloc(1024);
    if (!line) {
        perror("malloc");
        exit(1);
    }
    
    for (i = 0; i < 255; i++) {
        addr.sin_addr.s_addr = htonl((range.first & 0xFFFFFF00) | i);
        
        snprintf(command, 1024, "iwlist %s scan", inet_ntoa(addr.sin_addr));
        
        if (sendto(sockfd, command, strlen(command), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
            perror("sendto");
            continue;
        }
        
        usleep(100000);
        
        len = recvfrom(sockfd, line, 1024, 0, NULL, NULL);
        if (len < 0) {
            perror("recvfrom");
            continue;
        }
        
        p = line;
        while (p < line + len) {
            ni = malloc(sizeof(struct net_info));
            if (!ni) {
                perror("malloc");
                exit(1);
            }
            
            parse_iwlist(p, ni);
            
            nis[i] = ni;
            
            while (*p != '\n' && p < line + len) {
                p++;
            }
            p++;
        }
    }
    
    close(sockfd);
    
    free(command);
    free(line);
}

void print_networks(struct net_info **nis) {
    int i;
    char *security;
    
    for (i = 0; i < 255; i++) {
        if (!nis[i]) {
            continue;
        }
        
        if (nis[i]->security) {
            security = "WPA/WPA2";
        } else {
            security = "Open";
        }
        
        printf("%-32s %-32s %-8s %-8s %-8s\n", nis[i]->ssid, inet_ntoa(*(struct in_addr *)&nis[i]->range.first), nis[i]->channel, nis[i]->signal, security);
    }
}

int main() {
    struct net_range range;
    struct net_info *nis[255] = {0};
    
    range.first = 0xC0A80101;
    range.last = 0xC0A801FF;
    
    scan_network(range, nis);
    
    print_networks(nis);
    
    return 0;
}