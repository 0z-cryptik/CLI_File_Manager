#ifndef file_manager_h
#define file_manager_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PATH_LEN 350

// strips away '"', '\'', '\r', '\n' and changes '\' to '/'
void process_path(char *path);

// copies the file in path, pastes it in dest
void copy_handler(const char *path, const char *dest);

// moves the file in path to dest
void move_handler(const char *path, const char *dest);

// renames the file in path to new_name
void rename_handler(const char *path, const char *new_name);

// deletes the file in path
void delete_handler(const char *path);
#endif