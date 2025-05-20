//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Struct for storing XML tags
struct tag{
    char name[50];
    struct tag* children;
};

//Function to parse XML file
void parseXML(char* filename){
    FILE* fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Error opening file!\n");
        return;
    }

    char line[500];
    struct tag* head = NULL, *current = NULL;

    while(fgets(line, sizeof(line), fp) != NULL){

        //If line is an opening tag
        if(line[0] == '<' && line[1] != '/'){
            char* name = strtok(&line[1], ">");
            if(head == NULL){
                head = malloc(sizeof(struct tag));
                head->children = NULL;
                strcpy(head->name, name);
                current = head;
            }else{
                struct tag* t = malloc(sizeof(struct tag));
                t->children = NULL;
                strcpy(t->name, name);
                current->children = t;
                current = t;
            }
        }

        //If line is a closing tag
        if(line[0] == '<' && line[1] == '/'){
            current = head;
            while(current->children != NULL){
                current = current->children;
            }
        }
    }

    fclose(fp);
}

int main(){
    char* filename = "example.xml";
    parseXML(filename);
    return 0;
}