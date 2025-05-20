//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Dennis Ritchie
#include <arpa/inet.h>
#include <err.h>
#include <net/if.h>
#include <netdb.h>
#include <netinet/in.h>
#include <poll.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/time.h>

static unsigned short checksum(unsigned short *buf, int size)
{
	unsigned long sum;
	for (sum = 0; size > 0; size--)
		sum += *buf++;
	sum = (sum >> 16) + (sum & 0xFFFF);
	sum += (sum >> 16);
	return (unsigned short)(~sum);
}

typedef struct ip_header
{
	unsigned char ip_hl:4, ip_v:4;
	unsigned char ip_tos;
	unsigned short ip_len;
	unsigned short ip_id;
	unsigned short ip_off;
	unsigned char ip_ttl;
	unsigned char ip_p;
	unsigned short ip_sum;
	unsigned int ip_src;
	unsigned int ip_dst;
} ip_header;

typedef struct icmp_header
{
	unsigned char icmp_type;
	unsigned char icmp_code;
	unsigned short icmp_cksum;
	union
	{
		struct
		{
			unsigned long icmp_id;
			unsigned long icmp_seq;
		} echo;
		unsigned int timestamp;
	} icmp_un;
} icmp_header;

static ip_header *make_ip_header(unsigned int src, unsigned int dst)
{
	ip_header *ip = malloc(sizeof(ip_header));
	if (!ip)
		err(1, "malloc");
	ip->ip_hl = 5;
	ip->ip_v = 4;
	ip->ip_tos = 0;
	ip->ip_len = htons(sizeof(ip_header) + sizeof(icmp_header));
	ip->ip_id = htons(random());
	ip->ip_off = htons(0);
	ip->ip_ttl = 64;
	ip->ip_p = IPPROTO_ICMP;
	ip->ip_src = src;
	ip->ip_dst = dst;
	ip->ip_sum = checksum((unsigned short *)ip, sizeof(ip_header));
	return ip;
}

static icmp_header *make_icmp_header(unsigned char type, unsigned char code)
{
	icmp_header *icmp = malloc(sizeof(icmp_header));
	if (!icmp)
		err(1, "malloc");
	icmp->icmp_type = type;
	icmp->icmp_code = code;
	icmp->icmp_cksum = 0;
	icmp->icmp_un.echo.icmp_id = htons(random());
	icmp->icmp_un.echo.icmp_seq = htons(random());
	icmp->icmp_cksum = checksum((unsigned short *)icmp, sizeof(icmp_header));
	return icmp;
}

static void send_icmp_packet(int sock, unsigned int src, unsigned int dst, unsigned char type, unsigned char code)
{
	ip_header *ip = make_ip_header(src, dst);
	icmp_header *icmp = make_icmp_header(type, code);
	int len = sizeof(ip_header) + sizeof(icmp_header);
	char *buf = malloc(len);
	if (!buf)
		err(1, "malloc");
	memcpy(buf, ip, sizeof(ip_header));
	memcpy(buf + sizeof(ip_header), icmp, sizeof(icmp_header));
	if (sendto(sock, buf, len, 0, (struct sockaddr *)&(struct sockaddr_in){.sin_family = AF_INET, .sin_addr.s_addr = dst}, sizeof(struct sockaddr_in)) < 0)
		err(1, "sendto");
	free(buf);
	free(ip);
	free(icmp);
}

static void recv_icmp_packet(int sock, unsigned int src, unsigned int dst)
{
	char buf[1024];
	struct sockaddr_in from;
	socklen_t fromlen = sizeof(from);
	int len = recvfrom(sock, buf, sizeof(buf), 0, (struct sockaddr *)&from, &fromlen);
	if (len < 0)
		err(1, "recvfrom");
	ip_header *ip = (ip_header *)buf;
	icmp_header *icmp = (icmp_header *)(buf + sizeof(ip_header));
	if (ip->ip_p != IPPROTO_ICMP || icmp->icmp_type != 0 || icmp->icmp_code != 0 || icmp->icmp_un.echo.icmp_id != htons(random()) || icmp->icmp_un.echo.icmp_seq != htons(random()))
		return;
	if (ip->ip_src != dst || ip->ip_dst != src)
		return;
	printf("Recv: %d bytes\n", len);
	free(ip);
	free(icmp);
}

static void qos_monitor(unsigned int src, unsigned int dst)
{
	int sock = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
	if (sock < 0)
		err(1, "socket");
	for (;;)
	{
		send_icmp_packet(sock, src, dst, 8, 0);
		struct pollfd pfd = {sock, POLLIN, 0};
		if (poll(&pfd, 1, 1000) > 0 && pfd.revents & POLLIN)
			recv_icmp_packet(sock, src, dst);
	}
}

int main(int argc, char *argv[])
{
	if (argc != 3)
		errx(1, "Usage: %s src dst", argv[0]);
	unsigned int src = inet_addr(argv[1]);
	if (src == INADDR_NONE)
		errx(1, "Invalid src address");
	unsigned int dst = inet_addr(argv[2]);
	if (dst == INADDR_NONE)
		errx(1, "Invalid dst address");
	qos_monitor(src, dst);
	return 0;
}