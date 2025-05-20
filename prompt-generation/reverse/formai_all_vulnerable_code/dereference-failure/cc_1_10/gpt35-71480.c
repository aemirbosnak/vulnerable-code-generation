//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/wireless.h>

#define MAX_SSID 64
#define MAX_BSSID 17
#define MAX_FREQ 8
#define MAX_MODE 16
#define MAX_QUAL 8

typedef struct {
    char ssid[MAX_SSID + 1];
    char bssid[MAX_BSSID + 1];
    char freq[MAX_FREQ + 1];
    char mode[MAX_MODE + 1];
    char qual[MAX_QUAL + 1];
} wireless_network_t;

int main(int argc, char *argv[]) {
    int sockfd;
    struct iwreq wrq;
    wireless_network_t network;
    char scan_buffer[4096];
    char *scan_ptr;
    int i, j, k;
    int network_count = 0;
    int ssid_len, bssid_len, freq_len, mode_len, qual_len;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&wrq, 0, sizeof(wrq));
    strncpy(wrq.ifr_name, "wlan0", IFNAMSIZ);

    wrq.u.data.pointer = scan_buffer;
    wrq.u.data.length = sizeof(scan_buffer);
    wrq.u.data.flags = IW_SCAN_THIS_ESSID;

    if (ioctl(sockfd, SIOCSIWSCAN, &wrq) < 0) {
        perror("ioctl");
        exit(1);
    }

    scan_ptr = scan_buffer;
    while (scan_ptr < scan_buffer + wrq.u.data.length) {
        network_count++;

        ssid_len = *(scan_ptr++);
        if (ssid_len > MAX_SSID) {
            fprintf(stderr, "SSID too long\n");
            exit(1);
        }
        memcpy(network.ssid, scan_ptr, ssid_len);
        network.ssid[ssid_len] = '\0';
        scan_ptr += ssid_len;

        memcpy(network.bssid, scan_ptr, MAX_BSSID);
        network.bssid[MAX_BSSID] = '\0';
        scan_ptr += MAX_BSSID;

        freq_len = *(scan_ptr++);
        if (freq_len > MAX_FREQ) {
            fprintf(stderr, "Frequency too long\n");
            exit(1);
        }
        memcpy(network.freq, scan_ptr, freq_len);
        network.freq[freq_len] = '\0';
        scan_ptr += freq_len;

        mode_len = *(scan_ptr++);
        if (mode_len > MAX_MODE) {
            fprintf(stderr, "Mode too long\n");
            exit(1);
        }
        memcpy(network.mode, scan_ptr, mode_len);
        network.mode[mode_len] = '\0';
        scan_ptr += mode_len;

        qual_len = *(scan_ptr++);
        if (qual_len > MAX_QUAL) {
            fprintf(stderr, "Quality too long\n");
            exit(1);
        }
        memcpy(network.qual, scan_ptr, qual_len);
        network.qual[qual_len] = '\0';
        scan_ptr += qual_len;

        printf("SSID: %s\n", network.ssid);
        printf("BSSID: %s\n", network.bssid);
        printf("Frequency: %s\n", network.freq);
        printf("Mode: %s\n", network.mode);
        printf("Quality: %s\n", network.qual);
        printf("\n");
    }

    printf("Scanned %d networks\n", network_count);

    close(sockfd);

    return 0;
}