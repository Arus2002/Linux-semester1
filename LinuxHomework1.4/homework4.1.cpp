#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <vector>

int main(int argc , char **argv)
{


        for(int i = 1 ; i < argc ; ++i)
	{
		char* args[] {argv[i] , nullptr};
		pid_t pid = fork();

		//child
		if (pid == 0) 
		{
			std::cout << std::endl;
			execvp(argv[i], args);
 		}	
	
		//parent
		else 
		{
			int status;
	      		wait(&status);
		}

	}
}


