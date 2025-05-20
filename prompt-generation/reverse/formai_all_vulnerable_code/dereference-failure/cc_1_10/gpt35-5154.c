//FormAI DATASET v1.0 Category: Database Indexing System ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defining the structure of student record
struct Student{
    int roll_no;
    char name[50];
    char department[20];
    float cgpa;
};

// Defining the structure of index record
struct Index{
    char keyword[20];
    int offset;
};

// Function to compare two strings
int str_compare(char* str1, char* str2){
    int i = 0;
    while(str1[i] != '\0' && str2[i] != '\0'){
        if(str1[i] != str2[i]){
            return str1[i] - str2[i];
        }
        i++;
    }
    if(str1[i] == '\0' && str2[i] != '\0'){
        return -1;
    }
    else if(str1[i] != '\0' && str2[i] == '\0'){
        return 1;
    }
    else{
        return 0;
    }
}

// Function to search for a keyword in index
int search_index(char* keyword, struct Index* index, int n){
    int start = 0, end = n-1, mid;
    while(start <= end){
        mid = (start + end)/2;
        if(str_compare(index[mid].keyword, keyword) == 0){
            return index[mid].offset;
        }
        else if(str_compare(index[mid].keyword, keyword) < 0){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}

// Function to populate the index
void populate_index(FILE* fp1, FILE* fp2, struct Index* index, int* n){
    int o = 0;
    while(!feof(fp1)){
        struct Student s;
        int offset = ftell(fp1);
        fread(&s, sizeof(s), 1, fp1);
        fseek(fp2, o*sizeof(struct Index), SEEK_SET);
        strcpy(index[o].keyword, s.department);
        index[o].offset = offset;
        (*n)++;
        o++;
    }
}

int main(){
    // Opening the data file and index file
    FILE* fp1 = fopen("data.dat", "rb");
    FILE* fp2 = fopen("index.dat", "wb+");
    if(fp1 == NULL || fp2 == NULL){
        printf("Error opening files!\n");
        exit(1);
    }

    // Populating the index
    struct Index index[100];
    int n = 0;
    populate_index(fp1, fp2, index, &n);

    // Querying the index
    char keyword[20];
    printf("Enter department name: ");
    scanf("%s", keyword);
    int offset = search_index(keyword, index, n);
    if(offset == -1){
        printf("Record not found!\n");
    }
    else{
        struct Student s;
        fseek(fp1, offset, SEEK_SET);
        fread(&s, sizeof(s), 1, fp1);
        printf("Roll Number: %d\nName: %s\nDepartment: %s\nCGPA: %.2f\n", s.roll_no, s.name, s.department, s.cgpa);
    }

    // Closing the files
    fclose(fp1);
    fclose(fp2);
    return 0;
}