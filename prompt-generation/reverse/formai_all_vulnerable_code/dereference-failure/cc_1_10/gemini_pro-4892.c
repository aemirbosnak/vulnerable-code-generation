//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <net/ethernet.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>

struct ethereal_frame_header {
	uint8_t destination_mac_address[6];
	uint8_t source_mac_address[6];
	uint16_t ethertype;
} __attribute__((packed));

struct ethereal_llc_header {
	uint8_t dsap;
	uint8_t ssap;
	uint8_t control;
} __attribute__((packed));

struct ethereal_snap_header {
	uint8_t protocol_id[3];
	uint8_t oui[3];
	uint16_t type;
} __attribute__((packed));

struct ethereal_ip_header {
	uint8_t version_and_header_length;
	uint8_t differentiated_services;
	uint16_t total_length;
	uint16_t identification;
	uint16_t flags_and_fragment_offset;
	uint8_t time_to_live;
	uint8_t protocol;
	uint16_t header_checksum;
	uint32_t source_ip_address;
	uint32_t destination_ip_address;
} __attribute__((packed));

struct ethereal_udp_header {
	uint16_t source_port;
	uint16_t destination_port;
	uint16_t length;
	uint16_t checksum;
} __attribute__((packed));

struct ethereal_dhcp_header {
	uint8_t op;
	uint8_t htype;
	uint8_t hlen;
	uint8_t hops;
	uint32_t transaction_id;
	uint16_t seconds_since_boot;
	uint16_t client_ip_address;
	uint32_t your_ip_address;
	uint32_t server_ip_address;
	uint32_t gateway_ip_address;
	uint8_t client_hardware_address[6];
	uint8_t server_hardware_address[6];
	uint8_t relay_agent_ip_address[4];
	uint32_t dhcp_server_identifier;
	char magic_cookie[4];
	char dhcp_options[1500];
} __attribute__((packed));

void ethereal_ip_address_to_string(uint32_t ip_address, char *buffer) {
	snprintf(buffer, 16, "%d.%d.%d.%d",
		(ip_address & 0xFF000000) >> 24,
		(ip_address & 0x00FF0000) >> 16,
		(ip_address & 0x0000FF00) >> 8,
		(ip_address & 0x000000FF)
	);
}

void ethereal_mac_address_to_string(uint8_t *mac_address, char *buffer) {
	snprintf(buffer, 18, "%02X:%02X:%02X:%02X:%02X:%02X",
		mac_address[0], mac_address[1], mac_address[2],
		mac_address[3], mac_address[4], mac_address[5]
	);
}

int main(int argc, char *argv[]) {
	char *interface = argv[1];
	int promiscuous = 1;

	char errbuf[PCAP_ERRBUF_SIZE];
	pcap_t *handle = pcap_open_live(interface, 65535, promiscuous, 1000, errbuf);
	if (handle == NULL) {
		printf("Error opening interface: %s\n", errbuf);
		return -1;
	}

	struct ethereal_frame_header *frame_header;
	struct ethereal_llc_header *llc_header;
	struct ethereal_snap_header *snap_header;
	struct ethereal_ip_header *ip_header;
	struct ethereal_udp_header *udp_header;
	struct ethereal_dhcp_header *dhcp_header;

	while (1) {
		struct pcap_pkthdr *header;
		const uint8_t *data;
		int res = pcap_next_ex(handle, &header, &data);
		if (res == -1) {
			printf("Error reading packet: %s\n", pcap_geterr(handle));
			break;
		}

		frame_header = (struct ethereal_frame_header *)data;
		if (ntohs(frame_header->ethertype) == 0x8021) {
			llc_header = (struct ethereal_llc_header *)(data + sizeof(struct ethereal_frame_header));
			if (llc_header->dsap == 0xAA && llc_header->ssap == 0xAA && llc_header->control == 0x03) {
				snap_header = (struct ethereal_snap_header *)(data + sizeof(struct ethereal_frame_header) + sizeof(struct ethereal_llc_header));
				if (snap_header->protocol_id[0] == 0x08 && snap_header->protocol_id[1] == 0x00) {
					ip_header = (struct ethereal_ip_header *)(data + sizeof(struct ethereal_frame_header) + sizeof(struct ethereal_llc_header) + sizeof(struct ethereal_snap_header));
					if (ip_header->protocol == 17) {
						udp_header = (struct ethereal_udp_header *)(data + sizeof(struct ethereal_frame_header) + sizeof(struct ethereal_llc_header) + sizeof(struct ethereal_snap_header) + sizeof(struct ethereal_ip_header));
						if (ntohs(udp_header->destination_port) == 67) {
							dhcp_header = (struct ethereal_dhcp_header *)(data + sizeof(struct ethereal_frame_header) + sizeof(struct ethereal_llc_header) + sizeof(struct ethereal_snap_header) + sizeof(struct ethereal_ip_header) + sizeof(struct ethereal_udp_header));

							char source_mac_address[18];
							ethereal_mac_address_to_string(frame_header->source_mac_address, source_mac_address);

							char destination_mac_address[18];
							ethereal_mac_address_to_string(frame_header->destination_mac_address, destination_mac_address);

							char source_ip_address[16];
							ethereal_ip_address_to_string(ip_header->source_ip_address, source_ip_address);

							char destination_ip_address[16];
							ethereal_ip_address_to_string(ip_header->destination_ip_address, destination_ip_address);

							printf("Love at first sight!  (%s -> %s)\n", source_mac_address, destination_mac_address);
							printf("Source IP: %s\n", source_ip_address);
							printf("Destination IP: %s\n", destination_ip_address);
							printf("DHCP Transaction ID: %08X\n", ntohl(dhcp_header->transaction_id));
							printf("DHCP Server IP: %s\n", destination_ip_address);
							printf("\n");
						}
					}
				}
			}
		}
	}

	pcap_close(handle);
	return 0;
}