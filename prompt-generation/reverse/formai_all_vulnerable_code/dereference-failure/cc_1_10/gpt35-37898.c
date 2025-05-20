//FormAI DATASET v1.0 Category: Data recovery tool ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure definition for the lost data recovery
struct Data{
    char name[50];
    int age;
    char profession[50];
};

// Function to recover lost data from file
void recover_data(){
    FILE *fp;
    struct Data *data;
    int count = 0;
    
    // Open file in read binary mode
    fp = fopen("lost_data.dat", "rb");
    
    // Check if file exists
    if(fp == NULL){
        printf("\n Error: File not found! Unable to recover lost Data...\n");
    }else{
        printf("\n Looking for lost data...\n");
        
        // Loop through the file
        while(fread(data, sizeof(struct Data), 1, fp) == 1){
            // Print the lost data
            printf("\n***************************************************");
            printf("\n Name: %s \n Age: %d \n Profession: %s ", data->name, data->age, data->profession);
            printf("\n***************************************************");
            count++;
        }
        
        // Close the file
        fclose(fp);
        
        // Check if lost data has been recovered
        if(count != 0){
            printf("\n Data recovery successful! Found %d lost data.", count);
        }else{
            printf("\n Error: No lost data found in the file.");
        }
    }
}

int main(){
    char key;
    printf("\n Welcome to Data Recovery...");
    
    // Get user input
    printf("\n Press 'R' to recover lost data... ");
    scanf("%c", &key);
    
    // Trigger data recovery
    if(key == 'R' || key == 'r'){
        recover_data();
    }else{
        printf("\n Invalid input! Exiting program...");
    }
    
    return 0;
}