//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the cyberpunk theme
#define THEME "neon_city"

// Define the examination structure
typedef struct Examination
{
    char* name;
    int score;
    struct Examination* next;
} Examination;

// Function to create an examination
Examination* create_examination(char* name, int score)
{
    Examination* examination = malloc(sizeof(Examination));
    examination->name = strdup(name);
    examination->score = score;
    examination->next = NULL;

    return examination;
}

// Function to add an examination to the list
void add_examination(Examination* head, Examination* new_examination)
{
    if (head == NULL)
    {
        head = new_examination;
    }
    else
    {
        head->next = new_examination;
        head = new_examination;
    }
}

// Function to display the examination list
void display_examinations(Examination* head)
{
    Examination* current = head;

    printf("Examinations:\n");
    while (current)
    {
        printf("Name: %s, Score: %d\n", current->name, current->score);
        current = current->next;
    }
}

// Main function
int main()
{
    // Create a cyberpunk-themed examination system
    Examination* head = create_examination("John Doe", 90);
    add_examination(head, create_examination("Jane Doe", 80));
    add_examination(head, create_examination("Peter Pan", 70));

    // Display the examination list
    display_examinations(head);

    return 0;
}