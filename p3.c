#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
	if(argc == 1) 
	{
        printf("ERROR: no argument\n");
        return 0;
    }
	
	// variables
	int k = atoi(argv[1]);
    char* path = argv[2];
    int* buffer;
	struct timeval tvs;
	struct timeval tve;
	unsigned long averageTime = 0;

	// random access on file
	int file = open(path, O_RDONLY); 

	gettimeofday(&tvs, NULL);
	for (int i = 0; i < 600; ++i)
	{
		if (lseek(file, k, 0) >= 0) 
	    {
	        read(file, buffer, k);
	    }
	    else
	    {
	    	printf("ERROR: failed to read\n");
	        return 0;
		}
	}
	gettimeofday(&tve, NULL);
	
	// report average random access time
	averageTime = (tve.tv_usec - tvs.tv_usec) / 600;
	printf("Average random access time in usecs: %lu \n", averageTime);
	
	close(file);
  	return 0;
}