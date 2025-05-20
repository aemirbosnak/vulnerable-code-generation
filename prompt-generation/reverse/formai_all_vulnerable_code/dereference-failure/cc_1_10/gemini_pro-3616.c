//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: introspective
// Embark on a journey into the depths of data, where introspection becomes the guide.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a versatile data structure to represent the essence of a database.
struct Database {
  char** table_names;
  int num_tables;
};

// Lay the groundwork for our simulated database by allocating memory for its components.
struct Database* create_database() {
  struct Database* db = malloc(sizeof(struct Database));
  db->table_names = malloc(sizeof(char*) * 100);  // Ample space for our database's future expansion.
  db->num_tables = 0;

  // Gracefully handle any allocation failures.
  if (!db || !db->table_names) {
    printf("Out of memory! Database creation thwarted.\n");
    free(db);
    free(db->table_names);
    return NULL;
  }

  printf("Database successfully materialized from the ether.\n");
  return db;
}

// Free the memory allocated for the database, ensuring a tidy exit.
void destroy_database(struct Database* db) {
  for (int i = 0; i < db->num_tables; i++) {
    free(db->table_names[i]);
  }
  free(db->table_names);
  free(db);
}

// Conjure a new table into existence within the database's domain.
void create_table(struct Database* db, char* table_name) {
  printf("Summoning a new table: %s. Prepare for data's arrival.\n", table_name);

  // Extend our database's table catalog to accommodate the newcomer.
  db->table_names[db->num_tables++] = strdup(table_name);
}

// Unweave the existence of a table, banishing it from the database's realm.
void drop_table(struct Database* db, char* table_name) {
  for (int i = 0; i < db->num_tables; i++) {
    if (strcmp(db->table_names[i], table_name) == 0) {
      printf("Vanquishing the table: %s. Data shall be no more.\n", table_name);
      free(db->table_names[i]);

      // Maintain the integrity of our table catalog.
      for (int j = i + 1; j < db->num_tables; j++) {
        db->table_names[j - 1] = db->table_names[j];
      }

      db->num_tables--;
      return;
    }
  }

  printf("No table by the name '%s' found. Vanquishing failed.\n", table_name);
}

// Introspectively reveal the database's inner workings, unveiling its tables.
void show_tables(struct Database* db) {
  printf("Behold the tables that grace this database:\n");
  for (int i = 0; i < db->num_tables; i++) {
    printf(" - %s\n", db->table_names[i]);
  }
}

int main() {
  // Embark on our database adventure by summoning a new database into being.
  struct Database* db = create_database();
  if (db == NULL) {
    return 1;
  }

  // Conjure a table to hold our data, a vessel for knowledge.
  create_table(db, "users");

  // Pause to reflect upon the database's current state, revealing its tables.
  show_tables(db);

  // Dismantle the table, erasing its data from the database's memory.
  drop_table(db, "users");

  // Once more, we unveil the database's contents, observing the absence of the vanquished table.
  show_tables(db);

  // As our journey's end draws near, we bid farewell to the database, releasing its memory.
  destroy_database(db);
  return 0;
}