#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PATH_LEN 350

// for windows computers
void change_backslash(char *path) {
  for (int i = 0; i < strlen(path); i++) {
    if (path[i] == '\\') {
      path[i] = '/';
    }
  }
}

void remove_this_char(char *str, char character) {
  int i, j = 0;

  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] != character) {
      str[j++] = str[i];
    }
  }

  str[j] = '\0';
}

void process_path(char *path) {
  change_backslash(path);
  remove_this_char(path, '"');
  remove_this_char(path, '\n');
}

void copy_handler(const char *path, const char *dest) {
  FILE *origin_file, *destination_file;

  origin_file = fopen(path, "rb");
  if (origin_file == NULL) {
    perror("Origin file couldn't be opened");
    exit(EXIT_FAILURE);
  }

  destination_file = fopen(dest, "wb");
  if (destination_file == NULL) {
    perror("Destination file couldn't be created");
    fclose(origin_file);
    exit(EXIT_FAILURE);
  }

  int ch;
  while ((ch = getc(origin_file)) != EOF) {
    putc(ch, destination_file);
  }

  printf("\n\nFile copied successfully\n\n");

  fclose(origin_file);
  fclose(destination_file);
}

void move_handler(const char *path, const char *dest) {
  // returns 0 if successful
  int success = rename(path, dest);

  if (success != 0) {
    perror("Move not successful");
    exit(EXIT_FAILURE);
  }

  printf("\n\nFile moved successfully\n\n");
}

void delete_handler(const char *path) {
  // returns 0 if successful
  int success = remove(path);

  if (success != 0) {
    printf("\n\nFile deleted successfully\n\n");
  } else {
    perror("Error deleting file");
    exit(EXIT_FAILURE);
  }
}



int main(int argc, char *argv[]) {
  printf("Which operation do you want to perform?\n");
  printf("Enter 'C' for Copy\n");
  printf("Enter 'M' for Move\n");
  printf("Enter 'D' for delete\n");

  char command;
collect_command:
  scanf(" %c", &command);
  getchar(); // clear residue newline

  if (command != 'C' && command != 'M' && command != 'D') {
    printf("Invalid input try again\n");
    goto collect_command;
  }

  char path[MAX_PATH_LEN], dest[MAX_PATH_LEN];

  if (command == 'C') {
    printf("Enter the path of the file you want to copy: ");
    fgets(path, sizeof(path), stdin);
    printf("Enter the path(include desired filename and ext) you want it to be copied to: ");
    fgets(dest, sizeof(dest), stdin);
    process_path(path);
    process_path(dest);
    copy_handler(path, dest);
  }

  if (command == 'M') {
    printf("Enter the path of the file you want to move: ");
    fgets(path, sizeof(path), stdin);
    printf("Enter the path you want it to be moved to: ");
    fgets(dest, sizeof(dest), stdin);
    process_path(path);
    process_path(dest);
    move_handler(path, dest);
  }

  if (command == 'D') {
    printf("Enter the path of the file you want to delete: ");
    fgets(path, sizeof(path), stdin);
    process_path(path);
    delete_handler(path);
  }

  return 0;
}