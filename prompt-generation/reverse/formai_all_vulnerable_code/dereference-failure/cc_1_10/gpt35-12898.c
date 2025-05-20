//FormAI DATASET v1.0 Category: System event logger ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//function to generate random event types
char* generateEventType(){
    char* eventType= (char*)malloc(sizeof(char)*10);
    int num=rand()%3;
    switch(num){
        case 0:
            strcpy(eventType,"INFO");
            break;
        case 1:
            strcpy(eventType,"WARNING");
            break;
        case 2:
            strcpy(eventType,"ERROR");
            break;
    }
    return eventType;
}

//function to generate random event messages
char* generateEventMessage(){
    char* eventMessage= (char*)malloc(sizeof(char)*50);
    int num=rand()%10;
    switch(num){
        case 0:
            strcpy(eventMessage,"An event occurred");
            break;
        case 1:
            strcpy(eventMessage,"Successfully completed the operation");
            break;
        case 2:
            strcpy(eventMessage,"The program encountered an issue");
            break;
        case 3:
            strcpy(eventMessage,"Unable to perform the requested action");
            break;
        case 4:
            strcpy(eventMessage,"An unexpected error occurred");
            break;
        case 5:
            strcpy(eventMessage,"This action is not permitted");
            break;
        case 6:
            strcpy(eventMessage,"Please input valid data");
            break;
        case 7:
            strcpy(eventMessage,"Unable to save changes");
            break;
        case 8:
            strcpy(eventMessage,"Incorrect username / password");
            break;
        case 9:
            strcpy(eventMessage,"Please try again later");
            break;
    }
    return eventMessage;
}

//function to generate timestamp
char* generateTimestamp(){
    char* timestamp= (char*)malloc(sizeof(char)*30);
    time_t rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime (&rawtime);
    strftime(timestamp,30,"%Y-%m-%d %H:%M:%S",timeinfo);
    return timestamp;
}

//function to log event
void logEvent(){
    FILE *fp;
    fp=fopen("eventLog.txt","a");
    if(fp==NULL){
        printf("Error opening file");
        exit(1);
    }
    char* eventType=generateEventType();
    char* eventMessage=generateEventMessage();
    char* timestamp=generateTimestamp();
    printf("%s | %s: %s\n",timestamp,eventType,eventMessage);
    fprintf(fp,"%s | %s: %s\n",timestamp,eventType,eventMessage);
    fclose(fp);
}

int main(){
    int numEvents,i;
    printf("Enter the number of events to generate: ");
    scanf("%d",&numEvents);
    srand(time(NULL));
    for(i=1;i<=numEvents;i++){
        logEvent();
    }
    return 0;
}