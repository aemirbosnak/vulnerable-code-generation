//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    char name[20];
    char email[50];
    char skills[100];
    int experience;
    int education;
    struct node* next;
} *head = NULL;

void insert(char name[], char email[], char skills[], int experience, int education) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    strcpy(new_node->name, name);
    strcpy(new_node->email, email);
    strcpy(new_node->skills, skills);
    new_node->experience = experience;
    new_node->education = education;
    new_node->next = head;
    head = new_node;
}

void parse_resume(char file_name[]) {
    FILE* fp = fopen(file_name, "r");
    if(fp == NULL) {
        printf("\nFile not found!");
        return;
    }
    char name[20], email[50], skills[100]; 
    int experience, education;

    fscanf(fp, "%s", name);
    fscanf(fp, "%s", email);
    fscanf(fp, "%d", &experience);
    fscanf(fp, "%d", &education);
    fgets(skills, 100, fp);
    insert(name, email, skills, experience, education);
    fclose(fp);
}

void display() {
    struct node* temp = head;
    while(temp != NULL) {
        printf("\nName: %s", temp->name);
        printf("\nEmail: %s", temp->email);
        printf("\nExperience: %d years(s)", temp->experience);
        printf("\nEducation: %d", temp->education);
        printf("\nSkills: %s", temp->skills);
        printf("\n");
        temp = temp->next;
    }
}

int main() {
    parse_resume("resume1.txt");
    parse_resume("resume2.txt");
    parse_resume("resume3.txt");
    display();
    return 0;
}