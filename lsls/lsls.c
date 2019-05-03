#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  // Open directory
  struct dirent *entry; //pointer for directory entry

  DIR *dr = opendir("."); //opendir returns a pointer of DIR type
  //open dir opens path in (), the period means current directory

  if (dr == NULL) //return null if cant open
  {
    printf("dir open failed");
    return 0;
  }
  // Repeatly read and print entries
  while((entry = readdir(dr)) != NULL)
    printf("%s\n", entry -> d_name); 
    // d_name is built into the dirent struct

  // Close directory
  closedir(dr);
  return 0;
}