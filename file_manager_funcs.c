#include "file_manager.h"

void process_path(char *path) {
  int len = strlen(path);

  if (len == 0) {
    perror("Invalid input");
    exit(EXIT_FAILURE);
  }

  int start = 0, end = len - 1;

  // strip the quotes that accompany paths that are copied as path
  if (path[start] == '\'' || path[start] == '"') {
    start++;
  }

  // strip ending quotes and newline character
  while (end >= start && (path[end] == '\'' || path[end] == '"' || path[end] == '\n' || path[end] == '\r')) {
    end--;
  }

  int j = 0;
  for (int i = start; i <= end; i++) {
    // for windows computers
    if (path[i] == '\\') {
      path[i] = '/';
    }
    path[j++] = path[i];
  }
  path[j] = '\0';
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
    perror("Error moving file");
    exit(EXIT_FAILURE);
  }

  printf("\n\nFile moved successfully\n\n");
}

void delete_handler(const char *path) {
  // returns 0 if successful
  int success = remove(path);

  if (success == 0) {
    printf("\n\nFile deleted successfully\n\n");
  } else {
    perror("Error deleting file");
    exit(EXIT_FAILURE);
  }
}

void rename_handler(const char *path, const char *new_name) {
  char new_path[MAX_PATH_LEN];

  char *last_slash = strrchr(path, '/');

  // same directory
  if (last_slash == NULL) {
    strcpy(new_path, new_name);
  } else {
    // calculate the length of the directory part, +1 because strcpy isn't 0
    // indexed
    int directory_part_len = (int)(last_slash - path) + 1;

    // copy path up to the last slash
    strncpy(new_path, path, directory_part_len);
    new_path[directory_part_len] = '\0';

    strcat(new_path, new_name);
  }

  printf("Path: %s\nNew Path: %s\n", path, new_path);

  int success = rename(path, new_path);

  if (success != 0) {
    perror("Rename failed");
    exit(EXIT_FAILURE);
  }

  printf("\n\nFile renamed successfully\n\n");
}