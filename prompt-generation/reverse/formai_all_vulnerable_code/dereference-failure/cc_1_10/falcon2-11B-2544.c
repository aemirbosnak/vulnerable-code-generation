//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: enthusiastic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//define a struct for storing data
struct data
{
    char name[50];
    int age;
    char gender;
};

//function to search for a particular data based on name
struct data* searchData(struct data* data, char* name)
{
    for(int i = 0; i < 50; i++)
    {
        if(strcmp(data->name, name) == 0)
            return data;
    }
    return NULL;
}

//function to insert new data
void insertData(struct data* data, char* name, int age, char gender)
{
    strcpy(data->name, name);
    data->age = age;
    data->gender = gender;
}

//function to update existing data
void updateData(struct data* data, char* name, int age, char gender)
{
    struct data* foundData = searchData(data, name);
    if(foundData == NULL)
        printf("Data not found!\n");
    else
    {
        strcpy(foundData->name, name);
        foundData->age = age;
        foundData->gender = gender;
    }
}

//function to delete existing data
void deleteData(struct data* data, char* name)
{
    struct data* foundData = searchData(data, name);
    if(foundData == NULL)
        printf("Data not found!\n");
    else
    {
        free(foundData);
    }
}

//main function
int main()
{
    struct data* data;
    data = (struct data*)malloc(sizeof(struct data));
    printf("Enter name: ");
    scanf("%s", data->name);
    printf("Enter age: ");
    scanf("%d", &data->age);
    printf("Enter gender: ");
    scanf("%c", &data->gender);
    insertData(data, data->name, data->age, data->gender);

    printf("Enter name to search: ");
    char name[50];
    scanf("%s", name);
    struct data* foundData = searchData(data, name);
    if(foundData!= NULL)
    {
        printf("Data found!\n");
        printf("Name: %s\n", foundData->name);
        printf("Age: %d\n", foundData->age);
        printf("Gender: %c\n", foundData->gender);
    }
    else
        printf("Data not found!\n");

    printf("Enter name to update: ");
    scanf("%s", name);
    char newName[50];
    scanf("%s", newName);
    int newAge;
    scanf("%d", &newAge);
    char newGender;
    scanf("%c", &newGender);
    updateData(data, name, newAge, newGender);

    printf("Enter name to delete: ");
    scanf("%s", name);
    deleteData(data, name);

    return 0;
}