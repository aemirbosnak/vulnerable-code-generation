//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<pcap.h>

/* Define the structure of packet */
struct packet
{
   struct radiotap_header 
   {
      u_int8_t it_version;
      u_int8_t it_pad;
      u_int16_t it_len;
   } rthdr;

   struct ieee80211_header 
   {
      u_int16_t fc;
      u_int16_t duration;
      u_int8_t da[6];
      u_int8_t sa[6];
      u_int8_t bssid[6];
      u_int16_t seq_ctrl;
   } ieeehdr;

   struct ieee80211_probe_request 
   {
      u_int8_t probe_req[256]; 
   } ieeeprobereq;
};

/* Main Function */
int main()
{
   pcap_t *handle;       //to handle packets
   char *errbuf;
   struct pcap_pkthdr header;
   const u_char *packet;
   int pktCount = 0;     //count packet received
   struct packet *pckt;  //declare packet which we will use as structure
   int pktlen = sizeof(struct packet);  // use it to check if our packet is of right size

   /* Define the device to capture packets */ 
   char *dev = "wlan0mon"; //capturing wifi traffic on this wireless adapter name 

   /* Open the session in promiscuous mode */
     handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
     if (handle == NULL) {
           fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
           return(2);
     }

   /* Loop through packets and print out details */
   while(pktCount < 10)  // capture 10 packets
   {
      packet = pcap_next(handle,&header);

      if(packet == NULL)
         continue;
      
      /* We will now start decoding the packets */
      
      pckt = (struct packet*)packet;

      printf("Packet %d:\n", pktCount+1);

      /* Check if the packet size is correct */
      if(header.len != pktlen)
      {
         printf("Incorrect packet size\n");
         pktCount++;
         continue;
      }

      /* Display radiotap header fields */
      printf("Radiotap Header:\n");
      printf("\tVersion: %d\n", pckt->rthdr.it_version);
      printf("\tLength: %d\n", pckt->rthdr.it_len);

      /* Display IEEE 802.11 header fields */
      printf("IEEE 802.11 Header:\n");
      printf("\tDestination Address: %02x:%02x:%02x:%02x:%02x:%02x\n", pckt->ieeehdr.da[0], pckt->ieeehdr.da[1], pckt->ieeehdr.da[2], pckt->ieeehdr.da[3], pckt->ieeehdr.da[4], pckt->ieeehdr.da[5]);
      printf("\tSource Address: %02x:%02x:%02x:%02x:%02x:%02x\n", pckt->ieeehdr.sa[0], pckt->ieeehdr.sa[1], pckt->ieeehdr.sa[2], pckt->ieeehdr.sa[3], pckt->ieeehdr.sa[4], pckt->ieeehdr.sa[5]);
      printf("\tBSSID: %02x:%02x:%02x:%02x:%02x:%02x\n", pckt->ieeehdr.bssid[0], pckt->ieeehdr.bssid[1], pckt->ieeehdr.bssid[2], pckt->ieeehdr.bssid[3], pckt->ieeehdr.bssid[4], pckt->ieeehdr.bssid[5]);
      printf("\tSequence Control: %04x\n", pckt->ieeehdr.seq_ctrl);

      /* Display Probe Request fields */
      printf("Probe Request:\n");
      printf("\t%s\n", pckt->ieeeprobereq.probe_req);

      pktCount++;
   }

   /* Close the handle */
   pcap_close(handle);

   return 0;
}