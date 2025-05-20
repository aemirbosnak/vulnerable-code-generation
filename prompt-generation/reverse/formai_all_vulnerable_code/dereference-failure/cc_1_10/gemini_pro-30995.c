//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1024

// Define the maximum number of diary entries
#define MAX_ENTRIES 100

// Define the structure of a diary entry
typedef struct diary_entry {
  time_t timestamp;
  char *entry;
} diary_entry;

// Define the structure of a digital diary
typedef struct digital_diary {
  diary_entry *entries;
  int num_entries;
} digital_diary;

// Create a new digital diary
digital_diary *create_digital_diary() {
  digital_diary *diary = malloc(sizeof(digital_diary));
  diary->entries = malloc(sizeof(diary_entry) * MAX_ENTRIES);
  diary->num_entries = 0;
  return diary;
}

// Add a new entry to a digital diary
void add_entry(digital_diary *diary, char *entry) {
  // Check if the diary is full
  if (diary->num_entries == MAX_ENTRIES) {
    printf("Your diary is full! You need to delete some entries before you can add any more.\n");
    return;
  }

  // Create a new diary entry
  diary_entry *new_entry = malloc(sizeof(diary_entry));
  new_entry->timestamp = time(NULL);
  new_entry->entry = strdup(entry);

  // Add the new entry to the diary
  diary->entries[diary->num_entries] = *new_entry;
  diary->num_entries++;
}

// Print the entries in a digital diary
void print_entries(digital_diary *diary) {
  for (int i = 0; i < diary->num_entries; i++) {
    printf("Entry %d:\n", i + 1);
    printf("Timestamp: %s\n", ctime(&diary->entries[i].timestamp));
    printf("Entry: %s\n\n", diary->entries[i].entry);
  }
}

// Delete an entry from a digital diary
void delete_entry(digital_diary *diary, int entry_number) {
  // Check if the entry number is valid
  if (entry_number < 1 || entry_number > diary->num_entries) {
    printf("Invalid entry number. Please enter a number between 1 and %d.\n", diary->num_entries);
    return;
  }

  // Delete the entry
  free(diary->entries[entry_number - 1].entry);
  for (int i = entry_number - 1; i < diary->num_entries - 1; i++) {
    diary->entries[i] = diary->entries[i + 1];
  }
  diary->num_entries--;
}

// Search for an entry in a digital diary
void search_entries(digital_diary *diary, char *search_term) {
  int found = 0;
  for (int i = 0; i < diary->num_entries; i++) {
    if (strstr(diary->entries[i].entry, search_term)) {
      printf("Found a match in entry %d:\n", i + 1);
      printf("Timestamp: %s\n", ctime(&diary->entries[i].timestamp));
      printf("Entry: %s\n\n", diary->entries[i].entry);
      found = 1;
    }
  }

  if (!found) {
    printf("No matches found.\n");
  }
}

// Get a random entry from a digital diary
diary_entry *get_random_entry(digital_diary *diary) {
  // Check if the diary is empty
  if (diary->num_entries == 0) {
    printf("Your diary is empty! You need to add some entries before you can get a random one.\n");
    return NULL;
  }

  // Get a random number between 0 and the number of entries in the diary
  int random_number = rand() % diary->num_entries;

  // Return the random entry
  return &diary->entries[random_number];
}

// Main function
int main() {
  // Create a new digital diary
  digital_diary *diary = create_digital_diary();

  // Add some entries to the diary
  add_entry(diary, "Dear diary,\n\nToday was a great day! I woke up feeling refreshed and ready to take on the world. I had a delicious breakfast of pancakes and bacon, and then I went for a walk in the park. The weather was beautiful, and I saw some really cute dogs. After that, I came home and worked on my novel. I'm really proud of the progress I'm making, and I can't wait to finish it. In the evening, I went out to dinner with my friends. We had a lot of fun, and I laughed so hard that my stomach hurt. I'm so grateful for my friends, and I'm so lucky to have them in my life.\n\nLove,\nMe");
  add_entry(diary, "Dear diary,\n\nToday was a tough day. I woke up feeling tired and groggy. I had a fight with my boss, and I'm worried about losing my job. I came home and ate a whole pint of ice cream. I'm so disappointed in myself. I know I shouldn't eat like that, but I just couldn't help it. I'm feeling really down, and I don't know what to do. I just want to go to sleep and forget about today.\n\nLove,\nMe");
  add_entry(diary, "Dear diary,\n\nToday was a good day. I woke up feeling happy and content. I had a great breakfast of oatmeal and fruit, and then I went for a run. The weather was perfect, and I felt so energized. After that, I came home and worked on my novel. I'm really enjoying writing it, and I'm making good progress. In the evening, I went out to dinner with my family. We had a lot of fun, and I laughed so hard that my stomach hurt. I'm so grateful for my family, and I'm so lucky to have them in my life.\n\nLove,\nMe");

  // Print the entries in the diary
  print_entries(diary);

  // Delete an entry from the diary
  delete_entry(diary, 2);

  // Search for an entry in the diary
  search_entries(diary, "ice cream");

  // Get a random entry from the diary
  diary_entry *random_entry = get_random_entry(diary);
  printf("Random entry:\n");
  printf("Timestamp: %s\n", ctime(&random_entry->timestamp));
  printf("Entry: %s\n\n", random_entry->entry);

  // Free the memory allocated for the diary
  for (int i = 0; i < diary->num_entries; i++) {
    free(diary->entries[i].entry);
  }
  free(diary->entries);
  free(diary);

  return 0;
}