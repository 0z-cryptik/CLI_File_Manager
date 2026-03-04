#include "file_manager.h"

int main(void) {
  printf("Which operation do you want to perform?\n");
  printf("Enter 'C' for Copy\n");
  printf("Enter 'M' for Move\n");
  printf("Enter 'R' for rename\n");
  printf("Enter 'D' for delete\n");

  char command;
collect_command:
  scanf(" %c", &command);
  getchar(); // clear residue newline

  if (command != 'C' && command != 'M' && command != 'R' && command != 'D') {
    printf("Invalid input try again: ");
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
    printf("Enter the path (include desired filename and ext) you want it to be moved to: ");
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

  if (command == 'R') {
    printf("Enter the path of the file you want to rename: ");
    fgets(path, sizeof(path), stdin);
    char new_name[30];
    printf("Enter the new name(include the file extension e.g 'new name.txt'): ");
    fgets(new_name, sizeof(new_name), stdin);
    process_path(path);
    process_path(new_name);
    rename_handler(path, new_name);
  }

  return 0;
}