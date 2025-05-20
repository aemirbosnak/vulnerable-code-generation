//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <arpa/inet.h>

#define MAX_BUFF_LEN 1024
#define MAX_SCAN_TIME 10 // seconds
#define DEFAULT_RSSI_THRESHOLD -70 // dbm

int getWiFiSignalStrength(char *target_ssid, int rssi_threshold){

    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char s[INET6_ADDRSTRLEN];
    char command[MAX_BUFF_LEN];
    char result[MAX_BUFF_LEN];
    char *token;
    int curr_rssi, max_rssi=-100;
    time_t start_time, curr_time;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(NULL, "80", &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return -1;
    }

    // loop through all the results and connect to the first one we can
    for(p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "failed to connect\n");
        return -1;
    }

    inet_ntop(p->ai_family, &(((struct sockaddr_in*)p->ai_addr)->sin_addr),
            s, sizeof s);
    printf("connected to %s\n", s);

    freeaddrinfo(servinfo); // all done with this structure

    sprintf(command, "iwlist wlan0 scan | grep '%s'", target_ssid);
    start_time = time(NULL);

    while(time(NULL) - start_time < MAX_SCAN_TIME){
        curr_time = time(NULL);
        if(curr_time == start_time || curr_time % 5 == 0){ // only scan every 5 seconds
            if(system(command) < 0){
                perror("system");
                return -1;
            }
        }

        FILE *fp = popen("iwconfig wlan0", "r");

        if(fp == NULL){
            perror("popen");
            return -1;
        }

        if(fgets(result, MAX_BUFF_LEN, fp) == NULL){
            perror("fgets");
            return -1;
        }

        token = strtok(result, "\n");

        while(token != NULL){
            if(strstr(token, "Signal level") != NULL){
                sscanf(token, "%*s %*s %d", &curr_rssi);
                if(curr_rssi > max_rssi) max_rssi = curr_rssi;
                printf("Current RSSI: %d dBm (Max: %d dBm)\n", curr_rssi, max_rssi);
            }
            token = strtok(NULL, "\n");
        }

        pclose(fp);
        sleep(1);
    }

    if(max_rssi >= rssi_threshold){
        printf("WiFi signal strength is strong enough!\n");
        return max_rssi;
    }
    else{
        printf("WiFi signal strength is too weak!\n");
        return max_rssi;
    }

    close(sockfd);
}

int main(){
    int rssi_thresh = DEFAULT_RSSI_THRESHOLD;
    int strength;
    char target_ssid[64] = "MyWiFi";

    strength = getWiFiSignalStrength(target_ssid, rssi_thresh);

    return 0;
}