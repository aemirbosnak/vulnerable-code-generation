//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_FIELDS 10
#define MAX_FIELD_LEN 50

struct resume{
    char name[50], dob[20], email[30], phone[15], address[100], skills[200];
    int experience, education, projects;
};

struct field{
    char name[MAX_FIELD_LEN];
    int weight;
};

struct field_field{
    struct field field[MAX_FIELDS];
    int num_fields;
};

struct field_field field_weight = {
    .num_fields = 6, 
    .field = {{"name", 20}, {"dob", 10}, {"email", 10}, {"phone", 10}, {"address", 15}, {"skills", 35}}
};

int num_resumes = 0;
struct resume resumes[MAX_RESUMES];

void parse_resume(char* str, struct resume* r){
    char* token;
    token = strtok(str, "|");
    strcpy(r->name, token);
    token = strtok(NULL, "|");
    strcpy(r->dob, token);
    token = strtok(NULL, "|");
    strcpy(r->email, token);
    token = strtok(NULL, "|");
    strcpy(r->phone, token);
    token = strtok(NULL, "|");
    strcpy(r->address, token);
    token = strtok(NULL, "|");
    strcpy(r->skills, token);
    token = strtok(NULL, "|");
    r->experience = atoi(token);
    token = strtok(NULL, "|");
    r->education = atoi(token);
    token = strtok(NULL, "|");
    r->projects = atoi(token);
}

int calculate_score(struct resume* r, struct field_field* fw){
    int score = 0;
    int i;
    for(i=0;i<fw->num_fields;i++){
        char* ptr = strstr((char*) r, fw->field[i].name);
        if(ptr){
            int len = strlen(fw->field[i].name);
            int weight = fw->field[i].weight;
            while(*ptr != '|') ptr++;
            ptr++;
            char temp_str[MAX_FIELD_LEN];
            int temp_len = 0;
            while(*ptr != '|' && *ptr != '\0'){
                temp_str[temp_len] = *ptr;
                temp_len++;
                ptr++;
            }
            temp_str[temp_len] = '\0';
            score += weight*temp_len;
        }
    }
    return score;
}

void add_resume(){
    printf("\nEnter details of the resume in the following format:\n");
    printf("Name|DOB|Email|Phone|Address|Skills|Experience|Education|Projects\n");
    char str[MAX_FIELD_LEN*MAX_FIELDS];
    scanf("%s", str);
    struct resume r;
    parse_resume(str, &r);
    int score = calculate_score(&r, &field_weight);
    resumes[num_resumes] = r;
    printf("\nScore of the resume: %d", score);
    num_resumes++;
}

void list_resumes(){
    printf("\nList of resumes:\n");
    int i;
    for(i=0;i<num_resumes;i++){
        printf("\nResume #%d:\n", i+1);
        printf("Name: %s\n", resumes[i].name);
        printf("DOB: %s\n", resumes[i].dob);
        printf("Email: %s\n", resumes[i].email);
        printf("Phone: %s\n", resumes[i].phone);
        printf("Address: %s\n", resumes[i].address);
        printf("Skills: %s\n", resumes[i].skills);
        printf("Experience: %d\n", resumes[i].experience);
        printf("Education: %d\n", resumes[i].education);
        printf("Projects: %d\n", resumes[i].projects);
    }
}

int main(){
    int choice;
    do{
        printf("\nMenu: \n");
        printf("1. Add Resume\n");
        printf("2. List Resumes\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_resume();
                break;
            case 2:
                list_resumes();
                break;
            case 3:
                break;
            default:
                printf("\nInvalid choice, try again.\n");
        }
    }while(choice != 3);

    return 0;
}