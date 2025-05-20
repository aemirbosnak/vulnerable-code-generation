//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

#define SNAP_LEN 65535

pcap_t *handle;
char *interface;

void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet){
    // process packet data
}

void stop_capture(int signo){
    // cancel packet capture and free resources
    pcap_breakloop(handle);
}

int main(int argc, char *argv[]){
    char errbuf[PCAP_ERRBUF_SIZE];
    struct sigaction sa;
    sa.sa_handler = stop_capture;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    int capture_time = 60; // capture for 60 seconds
    
    if(argc < 2){
        fprintf(stderr, "Usage: %s [interface]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    interface = argv[1];
    
    handle = pcap_open_live(interface, SNAP_LEN, 1, 1000, errbuf);
    if(handle == NULL){
        fprintf(stderr, "Could not open device %s: %s\n", interface, errbuf);
        exit(EXIT_FAILURE);
    }
    
    if(pcap_datalink(handle) != DLT_EN10MB){
        fprintf(stderr, "Device %s doesn't provide Ethernet headers - not supported\n", interface);
        exit(EXIT_FAILURE);
    }
    
    if(pcap_setnonblock(handle, 1, errbuf) == -1){
        fprintf(stderr, "pcap_setnonblock() failed: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }
    
    if(pcap_activate(handle) != 0){
        fprintf(stderr, "pcap_activate() failed: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }
    
    if(pcap_loop(handle, -1, got_packet, NULL) == PCAP_ERROR){
        fprintf(stderr, "Error occurred while capturing packets: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }
    
    printf("Capturing packets on interface %s for %d seconds\n", interface, capture_time);
    
    alarm(capture_time); // set an alarm to stop the capture after capture_time seconds
    
    if(sigaction(SIGALRM, &sa, NULL) == -1){
        fprintf(stderr, "sigaction() failed\n");
        exit(EXIT_FAILURE);
    }
    
    while(1){
        int pcap_fd = pcap_get_selectable_fd(handle);
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);
        FD_SET(pcap_fd, &fds);
        int max_fd = (pcap_fd > STDIN_FILENO) ? pcap_fd : STDIN_FILENO;
        int ret = select(max_fd + 1, &fds, NULL, NULL, NULL);
        if(ret == -1){
            fprintf(stderr, "select() failed\n");
            exit(EXIT_FAILURE);
        }
        if(FD_ISSET(STDIN_FILENO, &fds)){
            // user pressed a key, exit program
            exit(EXIT_SUCCESS);
        }
        if(FD_ISSET(pcap_fd, &fds)){
            // process packet data
            if(pcap_dispatch(handle, -1, got_packet, NULL) == PCAP_ERROR){
                fprintf(stderr, "Error occurred while capturing packets: %s\n", pcap_geterr(handle));
                exit(EXIT_FAILURE);
            }
        }
    }
    
    pcap_close(handle);
    
    return 0;
}