//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netinet/if_ether.h>

#define SNAP_LEN 1518

struct my_sniff_header_t {
	struct pcap_pkthdr hdr;
	char *data;
};

void process_packet(struct my_sniff_header_t *packet) {
	struct ether_header *ether_header = (struct ether_header *)packet->data;
	struct ip *ip_header = (struct ip *)(packet->data + sizeof(struct ether_header));
	unsigned short ip_header_len = (ip_header->ip_hl) * 4;
	struct tcphdr *tcp_header = (struct tcphdr *)(packet->data + sizeof(struct ether_header) + ip_header_len);
	struct udphdr *udp_header = (struct udphdr *)(packet->data + sizeof(struct ether_header) + ip_header_len);

	printf("Packet length: %d\n", packet->hdr.len);
	printf("Source MAC address: %02X:%02X:%02X:%02X:%02X:%02X\n",
		ether_header->ether_shost[0], ether_header->ether_shost[1],
		ether_header->ether_shost[2], ether_header->ether_shost[3],
		ether_header->ether_shost[4], ether_header->ether_shost[5]);
	printf("Destination MAC address: %02X:%02X:%02X:%02X:%02X:%02X\n",
		ether_header->ether_dhost[0], ether_header->ether_dhost[1],
		ether_header->ether_dhost[2], ether_header->ether_dhost[3],
		ether_header->ether_dhost[4], ether_header->ether_dhost[5]);
	printf("IP source address: %s\n", inet_ntoa(ip_header->ip_src));
	printf("IP destination address: %s\n", inet_ntoa(ip_header->ip_dst));
	printf("IP protocol: %d\n", ip_header->ip_p);
	if (ip_header->ip_p == IPPROTO_TCP) {
		printf("TCP source port: %d\n", ntohs(tcp_header->th_sport));
		printf("TCP destination port: %d\n", ntohs(tcp_header->th_dport));
	} else if (ip_header->ip_p == IPPROTO_UDP) {
		printf("UDP source port: %d\n", ntohs(udp_header->uh_sport));
		printf("UDP destination port: %d\n", ntohs(udp_header->uh_dport));
	}
	printf("\n");
}

int main() {
	pcap_t *handle;
	char *dev;
	char errbuf[PCAP_ERRBUF_SIZE];

	dev = pcap_lookupdev(errbuf);
	if (dev == NULL) {
		fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
		return -1;
	}
	printf("Using device: %s\n", dev);

	handle = pcap_open_live(dev, SNAP_LEN, 1, 1000, errbuf);
	if (handle == NULL) {
		fprintf(stderr, "Couldn't open device: %s\n", errbuf);
		return -1;
	}

	while (1) {
		struct pcap_pkthdr *header;
		const unsigned char *data;
		
		int res = pcap_next_ex(handle, &header, &data);
		if (res == 0) continue;
		if (res == -1) {
			fprintf(stderr, "Error reading packet: %s\n", pcap_geterr(handle));
			break;
		}

		struct my_sniff_header_t packet;
		packet.hdr = *header;
		packet.data = (char *)data;

		process_packet(&packet);
	}

	pcap_close(handle);
	
	return 0;
}