//FormAI DATASET v1.0 Category: Database querying ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_USERNAME 20
#define MAX_PASSWORD 20

struct UserInfo {
  char username[MAX_USERNAME];
  char password[MAX_PASSWORD];
};

struct Database {
  struct UserInfo entries[MAX_ENTRIES];
  int num_entries;
};

struct Database* createDatabase() {
  struct Database* db = malloc(sizeof(struct Database));
  db->num_entries = 0;
  return db;
}

void addEntry(struct UserInfo entry, struct Database* db) {
  if (db->num_entries < MAX_ENTRIES) {
    db->entries[db->num_entries] = entry;
    db->num_entries++;
  } else {
    printf("Database is full, unable to add entry\n");
  }
}

void displayEntries(struct Database* db) {
  printf("Username\tPassword\n");
  for (int i = 0; i < db->num_entries; i++) {
    printf("%s\t\t%s\n", db->entries[i].username, db->entries[i].password);
  }
}

int findEntryByUserName(char* username, struct Database* db) {
  for (int i = 0; i < db->num_entries; i++) {
    if (strcmp(db->entries[i].username, username) == 0) {
      return i;
    }
  }
  return -1;
}

void removeEntryByUserName(char* username, struct Database* db) {
  int index = findEntryByUserName(username, db);
  if (index >= 0) {
    for (int i = index; i < db->num_entries - 1; i++) {
      db->entries[i] = db->entries[i + 1];
    }
    db->num_entries--;
  }
}

int main() {
  struct UserInfo user1 = {"user1", "password1"};
  struct UserInfo user2 = {"user2", "password2"};
  struct UserInfo user3 = {"user3", "password3"};

  struct Database* db = createDatabase();

  addEntry(user1, db);
  addEntry(user2, db);
  addEntry(user3, db);

  printf("Initial entries:\n");
  displayEntries(db);

  printf("\nRemoving user2:\n");
  removeEntryByUserName("user2", db);
  displayEntries(db);

  printf("\nFinding user1:\n");
  int user1_index = findEntryByUserName("user1", db);
  if (user1_index >= 0) {
    printf("User1 found at index %d\n", user1_index);
  } else {
    printf("User1 not found in database\n");
  }

  free(db);
  return 0;
}