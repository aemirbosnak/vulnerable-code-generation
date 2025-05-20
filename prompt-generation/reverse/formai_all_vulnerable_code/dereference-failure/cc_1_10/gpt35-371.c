//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_CHARS 100
#define MAX_FIELDS 10

//Function to check if a character is a comma
int is_comma(char c){
    return (c == ',') ? 1 : 0;
}

//Function to read a CSV file row and split it into an array of fields
void read_csv(char* filename, char fields[MAX_FIELDS][MAX_CHARS], int* num_fields) {
    FILE* fp = fopen(filename, "r");

    if(fp == NULL) {
        printf("Error: File does not exist.\n");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_CHARS];
    *num_fields = 0;

    fgets(buffer, MAX_CHARS, fp); //Read the first line of the file

    for(int i = 0; i < strlen(buffer); i++) {
        if(is_comma(buffer[i])) {
            (*num_fields)++;
        }
    }

    if(*num_fields == 0) {
        printf("Error: Invalid CSV file.\n");
        exit(EXIT_FAILURE);
    }

    rewind(fp); //Reset file pointer back to the beginning of the file

    int curr_field = 0;
    int curr_char = 0;

    //Loop through each character of each row and split it into the correct fields
    while(fgets(buffer, MAX_CHARS, fp)) {
        for(int i = 0; i < strlen(buffer); i++) {
            if(is_comma(buffer[i])) {
                fields[curr_field][curr_char] = '\0';
                curr_char = 0;
                curr_field++;
            } else {
                fields[curr_field][curr_char] = buffer[i];
                curr_char++;
            }
        }

        //Handle the last field in the row
        fields[curr_field][curr_char] = '\0';
        curr_char = 0;
        curr_field = 0;
    }

    fclose(fp);
}

int main() {
    char filename[] = "cyber_data.csv";
    char fields[MAX_FIELDS][MAX_CHARS];
    int num_fields;

    read_csv(filename, fields, &num_fields);

    //Print out the contents of the CSV file
    for(int i = 0; i < num_fields; i++) {
        printf("Field %d: %s\n", i + 1, fields[i]);
    }

    return 0;
}