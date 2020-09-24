#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
	if(argc == 1) 
	{
        printf("ERROR: no argument\n");
        return 0;
    }

    // get path as string
    char* path = argv[1];
    char* subentry;
    char* command = "stat ";
    char cmd[1024];

  	struct dirent *directory_entry;
    DIR *directory_ptr;

    // open directory
    directory_ptr = opendir(path);

    // check the directroy path
    if (directory_ptr == NULL)
    {
    	printf("ERROR: wrong path\n");
        return 0;
    }

    // list subentries within directory 
    while ((directory_entry = readdir(directory_ptr)) != NULL)
    {
    	memset(cmd, 0, sizeof(cmd));
    	subentry = directory_entry->d_name;
    	printf("SUBENTRY: %s\n", subentry);
    	// stat
    	strcat(cmd, command);
    	strcat(cmd, subentry);
    	system(cmd);
    	printf("\n");
    }

    closedir( directory_ptr);
	return 0;
}