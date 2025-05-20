//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: inquisitive
// Let's dive into the world of database querying!

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

// Our trusty database
static sqlite3 *db;

// A versatile query executor
static char *executeQuery(const char *query) {
    // Prepare the query
    sqlite3_stmt *statement;
    sqlite3_prepare_v2(db, query, -1, &statement, NULL);

    // Allocate space for the result
    int bufferSize = 1024;
    char *result = malloc(bufferSize);

    // Loop through the query results
    while (sqlite3_step(statement) == SQLITE_ROW) {
        // Build the result string
        int numColumns = sqlite3_column_count(statement);
        for (int i = 0; i < numColumns; i++) {
            char *value = (char *)sqlite3_column_text(statement, i);
            if (value) {
                int size = strlen(result) + strlen(value) + 2;
                if (size > bufferSize) {
                    bufferSize *= 2;
                    result = realloc(result, bufferSize);
                }
                strcat(result, ", ");
                strcat(result, value);
            }
        }
    }

    // Clean up
    sqlite3_finalize(statement);

    // Strip leading comma and spaces
    if (result[0] == ',') {
        memmove(result, result + 2, strlen(result) - 1);
    }

    // Return the result
    return result;
}

// Main function where the inquisitive journey begins
int main() {
    // Open the database
    if (sqlite3_open("my_database.db", &db)) {
        printf("Oops! Couldn't open the database!\n");
        return 1;
    }

    printf("Let's explore the database...\n\n");

    // Let's find out how many tables we have
    char *query = "SELECT COUNT(*) FROM sqlite_master WHERE type='table'";
    int numTables = atoi(executeQuery(query));
    printf("Hmm, we have %d tables in this database.\n\n", numTables);

    // Now, let's peek inside a table called 'users'
    query = "SELECT * FROM users";
    char *users = executeQuery(query);
    if (users[0] == '\0') {
        printf("Hmm, seems like the 'users' table is empty.\n\n");
    } else {
        printf("Let's see what's inside the 'users' table:\n%s\n\n", users);
    }

    // Let's search for a specific user
    printf("Who are we looking for? (Enter their name): ");
    char name[255];
    scanf("%s", name);
    query = sqlite3_mprintf("SELECT * FROM users WHERE name='%s'", name);
    char *user = executeQuery(query);
    sqlite3_free(query);
    if (user[0] == '\0') {
        printf("Sorry, couldn't find anyone named %s.\n", name);
    } else {
        printf("Here's the information about %s:\n%s\n\n", name, user);
    }

    // Let's filter out users by age
    printf("What age range are we interested in? (Enter minimum and maximum ages separated by a space): ");
    int minAge, maxAge;
    scanf("%d %d", &minAge, &maxAge);
    query = sqlite3_mprintf("SELECT * FROM users WHERE age BETWEEN %d AND %d", minAge, maxAge);
    char *usersByAge = executeQuery(query);
    sqlite3_free(query);
    if (usersByAge[0] == '\0') {
        printf("Hmm, no users in that age range.\n\n");
    } else {
        printf("Here are the users within the specified age range:\n%s\n\n", usersByAge);
    }

    // We're done exploring, let's close the database
    sqlite3_close(db);

    printf("That's all for now! Come back anytime to explore more.\n");
    return 0;
}