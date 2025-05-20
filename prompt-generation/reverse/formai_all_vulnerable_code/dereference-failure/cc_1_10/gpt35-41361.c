//FormAI DATASET v1.0 Category: Database querying ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    printf("Welcome to the Funny Database Querying Program!\n");
    printf("In this program, we will search for the lost men's bathroom in our office building\n");
    
    // Connect to the database
    printf("Connecting to the database...\n");
    int* db_conn_ptr = (int*) malloc(sizeof(int));
    *db_conn_ptr = 1234;
    printf("Connected to database with connection id: %d\n", *db_conn_ptr);

    // Search for the lost bathroom
    printf("Searching for the bathroom...\n");
    int bathroom_found = 0;

    // Create a fake table of office rooms
    char* table[] = {"Reception", "Conference Room", "Kitchen", "CEO's Office", "Men's Bathroom"};

    // Loop through the table to find the bathroom
    for (int i = 0; i < 5; i++) {
        if (strcmp(table[i], "Men's Bathroom") == 0) {
            printf("Found it! The men's bathroom is in room number %d\n", i+1);
            bathroom_found = 1;
            break;
        }
    }

    // If bathroom is not found, check in the women's bathroom (just in case)
    if (!bathroom_found) {
        printf("Oops, looks like the men's bathroom is not in our database. Let's check the women's bathroom (just in case)...\n");
        for (int i = 0; i < 5; i++) {
            if (strcmp(table[i], "Women's Bathroom") == 0) {
                printf("Sorry guys, it looks like the men's bathroom was mistakenly labeled as the women's bathroom. It's in room number %d\n", i+1);
                bathroom_found = 1;
                break;
            }
        }
    }

    // If bathroom is still not found, ask the office dog
    if (!bathroom_found) {
        printf("Office dog! Do you know where the men's bathroom is? (bark once for yes, twice for no)\n");
        int dog_response;
        scanf("%d", &dog_response);
        if (dog_response == 1) {
            printf("Wow, the office dog knows more than our database! The men's bathroom is in the basement.\n");
        } else {
            printf("Looks like we have to check every room in the building to find that bathroom...\n");
        }
    }

    // Disconnect from the database
    printf("Disconnecting from database with connection id: %d\n", *db_conn_ptr);
    free(db_conn_ptr);
    printf("Goodbye!\n");

    return 0;
}