#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BLOCK_SZ 4094

int main(int argc, char *argv[]) 
{
	if(argc == 1) {
        printf("ERROR: no argument\n");
        return 0;
    }

	int n = atoi(argv[1]);

  	// create file
  	FILE *fp;
  	fp = fopen("p1file","a"); // created file with append
  	if(fp == NULL)
    {
        printf("Failed to create file.\n");
        exit(EXIT_FAILURE);
    }

    // write content
    char* content[n][BLOCK_SZ]; 
    for (int i = 0; i < n; ++i) 
    {
    	content[i][BLOCK_SZ] = "0";
    	fwrite(content[i], sizeof(char), BLOCK_SZ, fp);
    }

    // end program
    fclose(fp);
  	return 0;
}