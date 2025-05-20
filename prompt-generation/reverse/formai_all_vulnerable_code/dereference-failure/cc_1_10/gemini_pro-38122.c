//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Magic metadata extraction incantations.
#define EXORCISE_METADATA(str)                   \
  {                                               \
    char *meta_ptr = strchr(str, '/');           \
    if (meta_ptr) *meta_ptr = '\0';               \
  }
#define EXTRACT_TITLE(str)                        \
  {                                               \
    char *title_ptr = strstr(str, "title=\"");     \
    if (title_ptr) {                             \
      title_ptr += 7;                           \
      char *end_ptr = strstr(title_ptr, "\"");   \
      if (end_ptr) *end_ptr = '\0';              \
      printf("Title: %s\n", title_ptr);         \
    }                                             \
  }
#define EXTRACT_DESCRIPTION(str)                   \
  {                                               \
    char *desc_ptr = strstr(str, "description=\""); \
    if (desc_ptr) {                              \
      desc_ptr += 13;                            \
      char *end_ptr = strstr(desc_ptr, "\"");     \
      if (end_ptr) *end_ptr = '\0';              \
      printf("Description: %s\n", desc_ptr);     \
    }                                             \
  }

int main(void) {
  // A spooky HTML document with enchanted metadata.
  char *html_document =
      "<html><head><title>Bewitched Metadata</title><meta name=\"description\""
      " content=\"Unveiling the hidden secrets within\"></head><body><h1>Abracadabra!</h1>"
      "</body></html>";

  // Banish the evil spirits of metadata.
  EXORCISE_METADATA(html_document);

  // Summon the title from the depths of the document.
  EXTRACT_TITLE(html_document);

  // Unveil the description from its spectral shroud.
  EXTRACT_DESCRIPTION(html_document);

  // The exorcism is complete. The metadata has been extracted.
  printf("Exorcism successful! Metadata revealed!");
  return 0;
}