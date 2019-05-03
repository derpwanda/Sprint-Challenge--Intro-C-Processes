#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * Main
 */
int main(int argc, char **argv) 
//argv array of char pointers aka strings
//argc is the count of cmdline arguments
{
  // Parse command line

  // printf("There are %d command line argument(s):\n", argc);

  int i;

  for (i = 0; i < argc; i++) {
      printf("   %s\n", argv[i]);
  }

  // Open directory
  DIR *dr = opendir("."); //opendir returns a pointer of DIR type
  //open dir opens path in (), the period means current directory
  struct dirent *entry; //pointer for directory entry


  if (dr == NULL) //return null if cant open
  {
    printf("dir open failed");
    exit(0); // closes the program
  }
  // Repeatly read and print entries
  while((entry = readdir(dr)) != NULL)
    printf("%s\n", entry -> d_name); 
    // d_name is built into the dirent struct

  // Close directory
  closedir(dr);
  return 0;
}