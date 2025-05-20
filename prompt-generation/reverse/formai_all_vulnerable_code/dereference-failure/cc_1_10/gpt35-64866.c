//FormAI DATASET v1.0 Category: Network Ping Test ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<netinet/ip_icmp.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<signal.h>
#include<unistd.h>
#include<errno.h>
#include<netdb.h>
#include<sys/time.h>
#include<fcntl.h>

#define PACKET_SIZE 4096
#define MAX_WAIT_TIME 5
#define MAX_NO_PACKETS 4

char sendpacket[PACKET_SIZE]; 
char recvpacket[PACKET_SIZE]; 

int sockfd,datalen=56; 
int nsend=0,nreceived=0;
struct sockaddr_in dest_addr;
pid_t pid; 
struct timeval tvrecv;
struct timeval tvsend;  
struct timeval tvinterval;

struct sockaddr_in from;
struct timeval timeout;

void handler(int signo){
    signal(SIGALRM,handler);
}

unsigned short cal_chksum(unsigned short *addr,int len){
    int nleft=len;
    int sum=0;
    unsigned short *w=addr;
    unsigned short answer=0;

    while(nleft>1){
        sum+=*w++;
        nleft-=2;
    }
    if(nleft==1){
        *(unsigned char *)(&answer)=*(unsigned char *)w;
        sum+=answer;
    }

    sum=(sum>>16)+(sum&0xffff);
    sum+=(sum>>16);
    answer=~sum;
    return answer;
}

int pack(int pack_no){

    int packsize;
    struct icmp *icmp;
    icmp=(struct icmp*)sendpacket;
    icmp->icmp_type=ICMP_ECHO;
    icmp->icmp_code=0;
    icmp->icmp_cksum=0;
    icmp->icmp_seq=pack_no;
    icmp->icmp_id=pid;
    packsize=8+datalen;
    icmp->icmp_cksum=cal_chksum((unsigned short*)icmp,packsize);

    gettimeofday(&tvsend,NULL);
    return packsize;
}

int send_packet(){

    int packetsize;
    packetsize=pack(nsend);
    if(sendto(sockfd,sendpacket,packetsize,0,(struct sockaddr *)&dest_addr,sizeof(dest_addr))<0){
        perror("sendto error");
        return -1;
    }

    nsend++;
    return packetsize;
}

int unpack(char *buf,int len){

    int i,iphdrlen;
    struct ip *ip;
    struct icmp *icmp;
    struct timeval *tvsend;
    double rtt;

    ip=(struct ip*)buf;
    iphdrlen=ip->ip_hl<<2; 
    icmp=(struct icmp*)(buf+iphdrlen); 
    len-=iphdrlen; 

    if(len<8){
        printf("ICMP packets\'s length is less than 8\n");
        return -1;
    }

    if((icmp->icmp_type==ICMP_ECHOREPLY) && (icmp->icmp_id==pid)){
        tvsend=(struct timeval*)icmp->icmp_data;
        gettimeofday(&tvrecv,NULL);

        rtt=(tvrecv.tv_sec-tvsend->tv_sec)*1000+(tvrecv.tv_usec-tvsend->tv_usec)*1.0/1000;
        printf("%d byte from %s: icmp_seq=%u ttl=%d rtt=%.3f ms\n",len,inet_ntoa(from.sin_addr),icmp->icmp_seq,ip->ip_ttl,rtt);

        nreceived++;
    }

    else{
        return -1; 
    }
    return 0;
}

void statistics(){

    double lost_rate;
    printf("\n----%s ping statistics----\n",inet_ntoa(dest_addr.sin_addr));
    lost_rate=((nsend-nreceived)*1.0/nsend)*100.0;
    printf("%d packets transmitted, %d received , %%%.2f lost\n",nsend,nreceived,lost_rate);
}

void send_ping(){

    while(nsend<MAX_NO_PACKETS){
        tvinterval.tv_sec = MAX_WAIT_TIME;
        tvinterval.tv_usec = 0;
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tvinterval, sizeof(tvinterval));
        send_packet();
        sleep(1);
    }
}

int main(int argc,char *argv[]){

    struct hostent *host;

    if(argc<2){
        printf("usage:%s hostname/IP address \n",argv[0]);
        exit(1);
    }

    if((host=gethostbyname(argv[1]))==NULL){
        perror("gethostbyname error");
        exit(1);
    }

    pid=getpid();
    printf("PING %s (%s): %d data bytes\n",argv[1],inet_ntoa(*((struct in_addr*)host->h_addr)),datalen);

    if((sockfd=socket(AF_INET,SOCK_RAW,IPPROTO_ICMP))<0){
        perror("socket error");
        exit(1);
    }

    const int pack_size=PACKET_SIZE;
    setsockopt(sockfd,SOL_SOCKET,SO_RCVBUF,&pack_size,sizeof(pack_size));

    struct timeval timeout={MAX_WAIT_TIME,0};
    setsockopt(sockfd,SOL_SOCKET,SO_SNDTIMEO,&timeout,sizeof(timeout));
    setsockopt(sockfd,SOL_SOCKET,SO_RCVTIMEO,&timeout,sizeof(timeout));

    bzero(&dest_addr,sizeof(dest_addr));
    dest_addr.sin_family=AF_INET;
    dest_addr.sin_addr=*((struct in_addr*)host->h_addr);

    signal(SIGALRM,handler);
    send_ping();
    statistics();
    close(sockfd);
    return 0;
}