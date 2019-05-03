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
  int i;
  char *filename;
  if (argc == 1) //if there is only one argument dr = "."
  {
    filename = ".";

  } else if (argc == 2)  
  {
    filename = argv[1];
  } else
  {
    fprintf(stderr, "not working.");
    return 1;
  }
  
  for (i = 1; i < argc; i++) {
      printf("   %s\n", argv[i]);
  }

  printf("is %s passing?\n", filename);

  // struct stat sb;
  // if (stat(filename, &sb) != 1)
  // {
  //   printf("%s is %10ld\n", filename, sb.st_size);
  // }

  // Open directory
  DIR *dr = opendir(filename); //opendir returns a pointer of DIR type
  //open dir opens path in (), the period means current directory
  struct dirent *entry; //pointer for directory entry
  //size
  struct stat sb;
  
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

  // while((entry = readdir(dr)) != NULL)
  //   if (stat(filename, &sb) != 1)
  //   {
  //     printf("%s is %10ld\n", filename, sb.st_size);      
  //   }