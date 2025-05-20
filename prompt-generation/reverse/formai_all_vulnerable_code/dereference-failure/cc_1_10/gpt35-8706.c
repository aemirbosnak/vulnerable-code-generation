//FormAI DATASET v1.0 Category: Digital Diary ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function to write in diary
void writeDiary(FILE *fp) {
    printf("Write your thoughts: ");
    char thoughts[500];
    scanf("%[^\n]%*c", thoughts);
    
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    //writing current date and time in diary
    fprintf(fp, "%d-%02d-%02d %02d:%02d:%02d - ", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
    tm.tm_hour, tm.tm_min, tm.tm_sec);
    
    //writing thoughts in diary
    fprintf(fp, "%s\n", thoughts);
}

//function to read from diary
void readDiary(FILE *fp) {
    printf("Your Diary:\n");
    char c;
    while((c=fgetc(fp))!=EOF) {
        printf("%c", c);
    }
}

int main() {
    char choice;
    FILE *fp;
    fp = fopen("diary.txt","a+");

    if(fp == NULL) {
        printf("Error: File cannot be opened.");
        exit(1);
    }

    do {
        printf("\n***********Digital Diary***********\n");
        printf("1. Write in Diary\n2. Read Diary\n3. Exit\n");

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                writeDiary(fp);
                printf("Diary has been updated!\n");
                break;
            case '2':
                readDiary(fp);
                break;
            case '3':
                printf("Closing Digital Diary!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != '3');

    fclose(fp);
    return 0;
}