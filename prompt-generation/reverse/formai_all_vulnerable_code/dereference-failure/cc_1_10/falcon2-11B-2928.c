//Falcon2-11B DATASET v1.0 Category: String manipulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char name[50];
    char gender[10];
    char city[50];
    char love[50];
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    printf("Enter your gender: ");
    fgets(gender, sizeof(gender), stdin);
    printf("Enter your city: ");
    fgets(city, sizeof(city), stdin);
    printf("Enter your love: ");
    fgets(love, sizeof(love), stdin);
    char* name_copy = strdup(name);
    char* gender_copy = strdup(gender);
    char* city_copy = strdup(city);
    char* love_copy = strdup(love);
    int name_len = strlen(name);
    int gender_len = strlen(gender);
    int city_len = strlen(city);
    int love_len = strlen(love);
    char* new_name = (char*)malloc(name_len * sizeof(char));
    char* new_gender = (char*)malloc(gender_len * sizeof(char));
    char* new_city = (char*)malloc(city_len * sizeof(char));
    char* new_love = (char*)malloc(love_len * sizeof(char));
    int i;
    for (i = 0; i < name_len; i++)
    {
        new_name[i] = tolower(name_copy[i]);
    }
    for (i = 0; i < gender_len; i++)
    {
        new_gender[i] = tolower(gender_copy[i]);
    }
    for (i = 0; i < city_len; i++)
    {
        new_city[i] = tolower(city_copy[i]);
    }
    for (i = 0; i < love_len; i++)
    {
        new_love[i] = tolower(love_copy[i]);
    }
    printf("Romeo: %s\n", new_name);
    printf("Romeo: %s\n", new_gender);
    printf("Romeo: %s\n", new_city);
    printf("Romeo: %s\n", new_love);
    free(name_copy);
    free(gender_copy);
    free(city_copy);
    free(love_copy);
    free(new_name);
    free(new_gender);
    free(new_city);
    free(new_love);
    return 0;
}