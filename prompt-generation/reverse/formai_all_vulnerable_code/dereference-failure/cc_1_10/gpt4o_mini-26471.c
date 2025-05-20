//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_DATA 256

typedef struct {
    char username[50];
    char *userdata;
} UserProfile;

typedef struct {
    UserProfile *profiles;
    int userCount;
} UserDatabase;

UserDatabase* createDatabase() {
    // Allocate memory for user database
    UserDatabase *db = (UserDatabase *)malloc(sizeof(UserDatabase));
    db->profiles = (UserProfile *)malloc(MAX_USERS * sizeof(UserProfile));
    db->userCount = 0;
    return db;
}

void addUser(UserDatabase *db, const char *username, const char *data) {
    if (db->userCount < MAX_USERS) {
        // Initialize new user profile
        strcpy(db->profiles[db->userCount].username, username);
        db->profiles[db->userCount].userdata = (char *)malloc(MAX_DATA * sizeof(char));
        strcpy(db->profiles[db->userCount].userdata, data);
        db->userCount++;
        printf("User %s added successfully.\n", username);
    } else {
        printf("Database is full. Cannot add more users.\n");
    }
}

void displayUsers(UserDatabase *db) {
    printf("---- User Profiles ----\n");
    for (int i = 0; i < db->userCount; i++) {
        printf("Username: %s\nData: %s\n", db->profiles[i].username, db->profiles[i].userdata);
    }
}

void deleteUser(UserDatabase *db, const char *username) {
    int found = -1;
    // Find user index
    for (int i = 0; i < db->userCount; i++) {
        if (strcmp(db->profiles[i].username, username) == 0) {
            found = i;
            break;
        }
    }
    
    if (found != -1) {
        // Free associated user data
        free(db->profiles[found].userdata);
        // Shift profiles down to fill the gap
        for (int i = found; i < db->userCount - 1; i++) {
            db->profiles[i] = db->profiles[i + 1];
        }
        db->userCount--;
        printf("User %s deleted successfully.\n", username);
    } else {
        printf("User %s not found.\n", username);
    }
}

void cleanupDatabase(UserDatabase *db) {
    // Free all user data and database structure
    for (int i = 0; i < db->userCount; i++) {
        free(db->profiles[i].userdata);
    }
    free(db->profiles);
    free(db);
}

int main() {
    UserDatabase *db = createDatabase();
    
    // Futuristic Data Input Simulation 
    printf("Welcome to the Futuristic User Profile Manager! Please create user profiles.\n");

    addUser(db, "AI_Expert", "Expert in AI, ML and futuristic robotics.");
    addUser(db, "Quantum_Analyst", "Specialist in Quantum Computing and Cryptography.");
    addUser(db, "Virtual_Architect", "Designer of advanced virtual reality environments.");

    displayUsers(db);

    // Deleting a user based on futuristic requirements
    deleteUser(db, "AI_Expert");
    displayUsers(db);

    // Adding a user with a long data description
    addUser(db, "AstroNavigator", "Navigator of interstellar travel; proficient in astrobiology and cosmic ethics.");
   
    displayUsers(db);

    // Cleanup
    cleanupDatabase(db);
    printf("All resources have been freed. Program terminated.\n");
    
    return 0;
}