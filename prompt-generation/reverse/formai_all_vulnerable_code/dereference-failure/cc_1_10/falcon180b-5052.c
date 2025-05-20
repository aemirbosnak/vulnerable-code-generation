//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining structure for log entry
struct log_entry{
    char ip[20];
    char date[20];
    char time[20];
    char method[10];
    char url[100];
    int status_code;
};

//Function to parse log entry
void parse_log_entry(char* line, struct log_entry* entry){
    int i,j;
    char* token;

    //Extracting IP address
    token = strtok(line," ");
    strcpy(entry->ip,token);

    //Extracting date and time
    token = strtok(NULL," ");
    strcpy(entry->date,token);
    token = strtok(NULL," ");
    strcpy(entry->time,token);

    //Extracting HTTP method and URL
    token = strtok(NULL," ");
    strcpy(entry->method,token);
    token = strtok(NULL," ");
    strcpy(entry->url,token);

    //Extracting status code
    token = strtok(NULL," ");
    entry->status_code = atoi(token);
}

//Function to print log entry
void print_log_entry(struct log_entry entry){
    printf("IP address: %s\n",entry.ip);
    printf("Date: %s\n",entry.date);
    printf("Time: %s\n",entry.time);
    printf("Method: %s\n",entry.method);
    printf("URL: %s\n",entry.url);
    printf("Status code: %d\n\n",entry.status_code);
}

//Function to analyze log file
void analyze_log_file(FILE* log_file){
    char line[1000];
    struct log_entry entry;

    while(fgets(line,sizeof(line),log_file)!=NULL){
        parse_log_entry(line,&entry);
        print_log_entry(entry);
    }
}

int main(){
    FILE* log_file = fopen("logfile.txt","r");

    if(log_file==NULL){
        printf("Error opening log file!\n");
        exit(1);
    }

    analyze_log_file(log_file);

    fclose(log_file);
    return 0;
}