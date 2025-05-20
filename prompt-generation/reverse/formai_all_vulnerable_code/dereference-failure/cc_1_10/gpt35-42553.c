//FormAI DATASET v1.0 Category: Data recovery tool ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
    char id[10];
    char name[50];
    char grade[3];
};

void display_data(struct data *d, int count){
    printf("\nDATA RECOVERY:\n");

    for(int i=0; i<count; i++){
        printf("\nStudent ID: %s\n", d[i].id);
        printf("Name: %s\n", d[i].name);
        printf("Grade: %s\n", d[i].grade);
    }
}

int main(){
    FILE *fileptr;
    struct data *d;
    int count = 0, temp_size = 0;

    fileptr = fopen("data.txt", "r");

    if(fileptr == NULL){
        printf("Error! File could not be opened.\n");
        return 0;
    }

    char temp[300];

    while(fgets(temp, 300, fileptr) != NULL){
        if(count == 0){
            d = malloc(sizeof(struct data));
            temp_size++;
        }
        else{
            d = realloc(d, sizeof(struct data) * (temp_size+1));
            temp_size++;
        }

        char *token = strtok(temp, ", ");
        strcpy(d[count].id, token);

        token = strtok(NULL, ", ");
        strcpy(d[count].name, token);

        token = strtok(NULL, ", ");
        strcpy(d[count].grade, token);

        count++;
    }

    fclose(fileptr);
    display_data(d, count);
    free(d);

    printf("\nData recovery successful!\n");
    return 0;
}