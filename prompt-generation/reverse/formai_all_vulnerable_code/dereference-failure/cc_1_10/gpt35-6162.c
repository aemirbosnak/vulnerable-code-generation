//FormAI DATASET v1.0 Category: Music Library Management System ; Style: shocked
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Album {
  char albumName[50];
  char artist[50];
  int numSongs;
};

void display(struct Album *albums, int numAlbums)
{
  int i;
  printf("Albums currently in the library:\n");
  printf("-----------------------------------\n");
  for(i=0; i<numAlbums; i++)
  {
    printf("Album Name: %s\n", albums[i].albumName);
    printf("Artist Name: %s\n", albums[i].artist);
    printf("Number of Songs: %d\n", albums[i].numSongs);
    printf("-----------------------------------\n");
  }
}

void addAlbum(struct Album *albums, int *numAlbums)
{
  printf("Enter Album Name: ");
  getchar();
  fgets(albums[*numAlbums].albumName, 50, stdin);
  albums[*numAlbums].albumName[strlen(albums[*numAlbums].albumName)-1] = '\0';
  printf("Enter Artist Name: ");
  fgets(albums[*numAlbums].artist, 50, stdin);
  albums[*numAlbums].artist[strlen(albums[*numAlbums].artist)-1] = '\0';
  printf("Enter Number of Songs: ");
  scanf("%d", &albums[*numAlbums].numSongs);
  *numAlbums = *numAlbums + 1;
}

void searchAlbum(struct Album *albums, int numAlbums)
{
  char albumName[50];
  int flag = 0, i;
  printf("Enter album name to search: ");
  getchar();
  fgets(albumName, 50, stdin);
  albumName[strlen(albumName)-1] = '\0';
  for(i=0; i<numAlbums; i++)
  {
    if(strcmp(albums[i].albumName, albumName) == 0)
    {
      printf("Album Name: %s\n", albums[i].albumName);
      printf("Artist Name: %s\n", albums[i].artist);
      printf("Number of Songs: %d\n", albums[i].numSongs);
      printf("-----------------------------------\n");
      flag = 1;
    }
  }
  if(flag == 0)
    printf("Album not found.\n");
}

void updateAlbum(struct Album *albums, int numAlbums)
{
  char albumName[50];
  int choice, flag = 0, i;
  printf("Enter album name to update: ");
  getchar();
  fgets(albumName, 50, stdin);
  albumName[strlen(albumName)-1] = '\0';
  for(i=0; i<numAlbums; i++)
  {
    if(strcmp(albums[i].albumName, albumName) == 0)
    {
      printf("Album found. What do you want to update?\n");
      printf("1. Album Name\n2. Artist Name\n3. Number of Songs\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);
      switch(choice)
      {
        case 1:
          printf("Enter new album name: ");
          getchar();
          fgets(albums[i].albumName, 50, stdin);
          albums[i].albumName[strlen(albums[i].albumName)-1] = '\0';
          printf("Album name updated.\n");
          break;
        case 2:
          printf("Enter new artist name: ");
          getchar();
          fgets(albums[i].artist, 50, stdin);
          albums[i].artist[strlen(albums[i].artist)-1] = '\0';
          printf("Artist name updated.\n");
          break;
        case 3:
          printf("Enter new number of songs: ");
          scanf("%d", &albums[i].numSongs);
          printf("Number of songs updated.\n");
          break;
        default:
          printf("Invalid input.\n");
      }
      flag = 1;
    }
  }
  if(flag == 0)
    printf("Album not found.\n");
}

int main()
{
  int numAlbums = 0, choice;
  struct Album albums[100];

  while(1)
  {
    printf("---------------Music Library Management System---------------\n");
    printf("1. Display Albums\n2. Add Album\n3. Search Album\n4. Update Album\n5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
      case 1:
        display(albums, numAlbums);
        break;
      case 2:
        addAlbum(albums, &numAlbums);
        printf("Album added.\n");
        break;
      case 3:
        searchAlbum(albums, numAlbums);
        break;
      case 4:
        updateAlbum(albums, numAlbums);
        break;
      case 5:
        printf("Thank you for using Music Library Management System.\n");
        exit(0);
      default:
        printf("Invalid input. Please try again.\n");
    }
  }
  return 0;
}