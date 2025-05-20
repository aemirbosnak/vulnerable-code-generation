//FormAI DATASET v1.0 Category: Digital Diary ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct entry{
    char date[11];
    char time[6];
    char content[500];
    struct entry *next;
} entry_t;

entry_t *head = NULL;
entry_t *current = NULL;

void add_entry(char date[11], char time[6], char content[500]){
    entry_t *new_entry = (entry_t*)malloc(sizeof(entry_t));
    strcpy(new_entry->date, date);
    strcpy(new_entry->time, time);
    strcpy(new_entry->content, content);
    new_entry->next = NULL;
    
    if(head == NULL){
        head = new_entry;
        current = new_entry;
    }
    else{
        current->next = new_entry;
        current = new_entry;
    }
}

void display_all_entries(){
    entry_t *ptr = head;
    
    while(ptr != NULL){
        printf("\nDate: %s \t Time: %s \nContent: %s\n", ptr->date, ptr->time, ptr->content);
        ptr = ptr->next;
    }
}

void display_entry(char date[11]){
    entry_t *ptr = head;
    int found = 0;
    
    while(ptr != NULL){
        if(strcmp(ptr->date, date) == 0){
            printf("\nDate: %s \t Time: %s \nContent: %s\n", ptr->date, ptr->time, ptr->content);
            found = 1;
        }
        ptr = ptr->next;
    }
    
    if(found == 0){
        printf("\nNo entries found for the given date.\n");
    }
}

int main(){
    char date[11];
    char time[6];
    char content[500];
    int choice;
    
    while(1){
        printf("\n********** Digital Diary **********\n");
        printf("\n1.Add Entry \n2.Display all Entries \n3.Display Entries of a Date \n4.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:{
                printf("\nEnter Date(DD/MM/YYYY): ");
                scanf("%s", date);
                
                printf("Enter Time(HH:MM 24-hour format): ");
                scanf("%s", time);
                
                printf("Enter your Entry(max 500 characters): \n");
                fflush(stdin);
                fgets(content, 500, stdin);
                content[strcspn(content, "\n")] = 0;
                
                add_entry(date, time, content);
                break;
            }
            case 2:{
                if(head == NULL){
                    printf("\nNo entries found.\n");
                }
                else{
                    printf("\n********** All Entries **********\n");
                    display_all_entries();
                }
                break;
            }
            case 3:{
                if(head == NULL){
                    printf("\nNo entries found.\n");
                }
                else{
                    printf("\nEnter date(DD/MM/YYYY) to display entries: ");
                    scanf("%s", date);
                    display_entry(date);
                }
                break;
            }
            case 4:{
                exit(0);
            }
            default:{
                printf("\nInvalid choice.\n");
            }
        }
    }
    return 0;
}