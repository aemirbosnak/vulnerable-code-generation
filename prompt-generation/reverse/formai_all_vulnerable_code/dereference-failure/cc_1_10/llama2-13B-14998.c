//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_USERS 1000
#define MAX_ITEMS 10000
#define MAX_RATINGS 5

// Structure to store user and item data
typedef struct {
    char name[50];
    int age;
    int gender;
    int ratings[MAX_ITEMS];
} user_item_data_t;

// Function to generate random data
void generate_data(user_item_data_t** users, int* num_users, int* num_items, int* num_ratings) {
    int i, j, k;
    for (i = 0; i < *num_users; i++) {
        // Generate random user data
        for (j = 0; j < MAX_ITEMS; j++) {
            users[i][j].ratings[j] = rand() % 5;
        }
        // Generate random item data
        for (j = 0; j < MAX_ITEMS; j++) {
            int item_id = rand() % MAX_ITEMS;
            users[i][j].ratings[item_id] = rand() % 5;
        }
    }
    *num_items = MAX_ITEMS;
    *num_ratings = MAX_RATINGS;
}

// Function to calculate similarity between two users
double calculate_similarity(user_item_data_t** users, int u1, int u2) {
    int i, j;
    double similarity = 0;
    for (i = 0; i < MAX_ITEMS; i++) {
        similarity += users[u1][i].ratings[i] * users[u2][i].ratings[i];
    }
    return similarity / (MAX_ITEMS * MAX_ITEMS);
}

// Function to find the most similar user
int find_most_similar_user(user_item_data_t** users, int num_users) {
    int i, j, max_similarity = 0, most_similar_user = -1;
    for (i = 0; i < num_users; i++) {
        for (j = i + 1; j < num_users; j++) {
            double similarity = calculate_similarity(users, i, j);
            if (similarity > max_similarity) {
                max_similarity = similarity;
                most_similar_user = j;
            }
        }
    }
    return most_similar_user;
}

int main() {
    srand(time(NULL));

    // Generate random data
    user_item_data_t** users = calloc(MAX_USERS, sizeof(user_item_data_t));
    int num_users = 0;
    int num_items = 0;
    int num_ratings = 0;
    generate_data(users, &num_users, &num_items, &num_ratings);

    // Find the most similar user
    int most_similar_user = find_most_similar_user(users, num_users);

    // Print the results
    printf("Most similar user: %d\n", most_similar_user);

    return 0;
}