//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: romantic
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pcap.h>
#include <string.h>

#define IEEE80211_FSTYPE_PROBE_REQ 4
#define IEEE80211_ADDR_LEN 6
#define IEEE80211_SEQ_LEN 2
#define IEEE80211_PAYLOAD_OFFSET 24
#define IEEE80211_MAX_SSID_LEN 32

typedef uint8_t ieee80211_mac_t[IEEE80211_ADDR_LEN];
typedef uint8_t ieee80211_seq_t[IEEE80211_SEQ_LEN];

typedef struct {
    uint8_t type;
    uint8_t flags;
    uint16_t duration;
    ieee80211_mac_t da;
    ieee80211_mac_t sa;
    ieee80211_mac_t bssid;
    ieee80211_seq_t seq;
    uint8_t ssid_len;
    uint8_t ssid[IEEE80211_MAX_SSID_LEN];
} ieee80211_probe_req_t;

typedef struct {
    ieee80211_mac_t addr;
    char *ssid;
    int8_t rssi;
    uint32_t last_seen;
} ap_info_t;

typedef struct {
    ap_info_t *aps;
    uint32_t num_aps;
    uint32_t max_aps;
} ap_info_list_t;

ap_info_list_t aps;

void on_packet(const uint8_t *packet, uint32_t packet_len) {
    ieee80211_probe_req_t *probe_req = (ieee80211_probe_req_t *)(packet + IEEE80211_PAYLOAD_OFFSET);
    if (probe_req->type == IEEE80211_FSTYPE_PROBE_REQ && probe_req->ssid_len > 0 && probe_req->ssid_len <= IEEE80211_MAX_SSID_LEN) {
        bool found_ap = false;
        for (uint32_t i = 0; i < aps.num_aps; i++) {
            if (memcmp(aps.aps[i].addr, probe_req->sa, IEEE80211_ADDR_LEN) == 0 &&
                    strncmp(aps.aps[i].ssid, (char *)probe_req->ssid, probe_req->ssid_len) == 0) {
                aps.aps[i].rssi = -30;
                aps.aps[i].last_seen = time(NULL);
                found_ap = true;
                break;
            }
        }
        if (!found_ap) {
            if (aps.num_aps >= aps.max_aps) {
                aps.max_aps *= 2;
                aps.aps = (ap_info_t *)realloc(aps.aps, aps.max_aps * sizeof(ap_info_t));
            }
            ap_info_t *ap = &aps.aps[aps.num_aps++];
            memcpy(ap->addr, probe_req->sa, IEEE80211_ADDR_LEN);
            ap->ssid = (char *)malloc(probe_req->ssid_len + 1);
            strncpy(ap->ssid, (char *)probe_req->ssid, probe_req->ssid_len);
            ap->ssid[probe_req->ssid_len] = '\0';
            ap->rssi = -30;
            ap->last_seen = time(NULL);
        }
    }
}

int main(int argc, char **argv) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *pcap_handle = pcap_create(argv[1], errbuf);
    if (pcap_handle == NULL) {
        fprintf(stderr, "pcap_create(): %s\n", errbuf);
        exit(EXIT_FAILURE);
    }
    if (pcap_set_rfmon(pcap_handle, true) != 0) {
        fprintf(stderr, "pcap_set_rfmon(): %s\n", pcap_geterr(pcap_handle));
        exit(EXIT_FAILURE);
    }
    if (pcap_activate(pcap_handle) != 0) {
        fprintf(stderr, "pcap_activate(): %s\n", pcap_geterr(pcap_handle));
        exit(EXIT_FAILURE);
    }
    aps.aps = (ap_info_t *)malloc(1024 * sizeof(ap_info_t));
    aps.num_aps = 0;
    aps.max_aps = 1024;
    while (1) {
        struct pcap_pkthdr *header;
        const uint8_t *packet;
        int ret = pcap_next_ex(pcap_handle, &header, &packet);
        if (ret == 1) {
            on_packet(packet, header->caplen);
        } else if (ret == -1) {
            fprintf(stderr, "pcap_next_ex(): %s\n", pcap_geterr(pcap_handle));
            exit(EXIT_FAILURE);
        }
        for (uint32_t i = 0; i < aps.num_aps; i++) {
            if (aps.aps[i].rssi < -100) {
                free(aps.aps[i].ssid);
                memcpy(&aps.aps[i], &aps.aps[aps.num_aps - 1], sizeof(ap_info_t));
                aps.num_aps--;
                i--;
            }
        }
        printf("Scanned Wireless Networks:\n");
        for (uint32_t i = 0; i < aps.num_aps; i++) {
            printf("%s (%02x:%02x:%02x:%02x:%02x:%02x) - %ddBm - Last seen %d seconds ago\n",
                    aps.aps[i].ssid,
                    aps.aps[i].addr[0], aps.aps[i].addr[1], aps.aps[i].addr[2],
                    aps.aps[i].addr[3], aps.aps[i].addr[4], aps.aps[i].addr[5],
                    aps.aps[i].rssi, time(NULL) - aps.aps[i].last_seen);
        }
        printf("\n");
        sleep(1);
    }
}