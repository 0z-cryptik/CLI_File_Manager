#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rename_handler(const char *str, const char *new_name) {
  char new_path[350];

  char *last_slash = strrchr(str, '\\');

  // same directory
  if (last_slash == NULL) {
    strcpy(new_path, new_name);
  }

  // calculate the length of the directory part, +1 because strcpy isn't 0 indexed
  int directory_part_len = (int)(last_slash - new_path) + 1;
  
}