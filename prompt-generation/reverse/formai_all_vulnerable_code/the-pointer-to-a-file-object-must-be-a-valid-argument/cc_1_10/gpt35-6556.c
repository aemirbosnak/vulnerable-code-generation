//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct packet{
    int id;
    char* source_ip;
    char* destination_ip;
    char* payload;
    int payload_size;
};

void log_packet(struct packet* p){
    FILE* log_file = fopen("log.txt", "a");
    fprintf(log_file, "Packet ID: %d\n", p->id);
    fprintf(log_file, "Source IP: %s\n", p->source_ip);
    fprintf(log_file, "Destination IP: %s\n", p->destination_ip);
    fprintf(log_file, "Payload:\n%s\n", p->payload);
    fprintf(log_file, "Payload size: %d\n", p->payload_size);
    fclose(log_file);
}

int main(){

    printf("Welcome to the Shape Shifting Intrusion Detection System!\n");

    struct packet p1 = {
        .id = 1,
        .source_ip = "192.168.0.1",
        .destination_ip = "10.0.0.1",
        .payload = "Hello, World!",
        .payload_size = 13
    };
    struct packet p2 = {
        .id = 2,
        .source_ip = "192.168.0.2",
        .destination_ip = "10.0.0.2",
        .payload = "This is a test payload.",
        .payload_size = 25
    };
    struct packet p3 = {
        .id = 3,
        .source_ip = "192.168.0.3",
        .destination_ip = "10.0.0.3",
        .payload = "This payload shouldn't be logged.",
        .payload_size = 34
    };

    log_packet(&p1);
    log_packet(&p2);
    //log_packet(&p3); //Uncomment to test intrusion detection

    //Intrusion detection 
    FILE* log_file = fopen("log.txt", "r");
    char line[256];
    int intrusions = 0;
    while(fgets(line, sizeof(line), log_file)){
        if(strstr(line, "This is a test payload.")){
            intrusions++;
        }
    }
    fclose(log_file);

    if(intrusions > 0){
        printf("%d intrusions detected!\n", intrusions);
    }else{
        printf("No intrusions detected.\n");
    }

    return 0;
}