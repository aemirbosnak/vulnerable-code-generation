//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL));
    int num_messages = rand() % 10;
    printf("Welcome to the random POP3 client! You have %d new messages.\n", num_messages);

    if(num_messages == 0){
        printf("No new messages. Have a nice day!\n");
        return 0;
    }

    char* senders[num_messages];
    char* subjects[num_messages];
    char* messages[num_messages];

    for(int i=0; i<num_messages; i++){
        int sender_len = rand() % 20 + 10;
        senders[i] = malloc(sizeof(char) * sender_len);
        for(int j=0; j<sender_len-1; j++){
            senders[i][j] = (rand() % 26) + 65;
        }
        senders[i][sender_len-1] = '\0';

        int subject_len = rand() % 40 + 10;
        subjects[i] = malloc(sizeof(char) * subject_len);
        for(int j=0; j<subject_len-1; j++){
            subjects[i][j] = (rand() % 26) + 97;
        }
        subjects[i][subject_len-1] = '\0';

        int message_len = rand() % 200 + 50;
        messages[i] = malloc(sizeof(char) * message_len);
        for(int j=0; j<message_len-1; j++){
            messages[i][j] = (rand() % 94) + 32;
        }
        messages[i][message_len-1] = '\0';
    }

    printf("Here are your messages:\n");
    for(int i=0; i<num_messages; i++){
        printf("Message %d\nFrom: %s\nSubject: %s\n%s\n\n", i+1, senders[i], subjects[i], messages[i]);
        free(senders[i]);
        free(subjects[i]);
        free(messages[i]);
    }

    return 0;
}