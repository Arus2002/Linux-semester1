#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main(){

	int fd1[2];
        int fd2[2];
        if(pipe(fd1) == -1){
                return 1;
        }
        if(pipe(fd2) == -1){
                return 2;
        }

	std::cout << "Start ..." <<std::endl;

	pid_t child1 , child2;
	child1 = fork();
	if(child1 == 0){
		if(close(fd1[0]) == -1){
                        return 4;
                }

                if(close(fd2[1]) == -1){
                        return 5;
                }
                int pid1 = getpid();
                write(fd1[1] , &pid1 , sizeof(int));
                std::cout << "Child1 PID :" << pid1 << std::endl;
                if(close(fd1[1]) == -1){
                        return 6;
                }
                int pid2 = getpid();
                read(fd2[0] , &pid2 , sizeof(int));
                std::cout << "Child1 : Get Child2 PID :" << pid2 << std::endl;
                if(close(fd2[0]) == -1){
                        return 7;
                }

	}
	else{
		child2 = fork();

		if(child2 == 0){
		if(close(fd2[0]) == -1){
                        return 2;
                }

                if(close(fd1[1]) == -1){
                        return 3;
                }
                int pid3 = getpid();
                read(fd1[0] , &pid3 , sizeof(int));
                std::cout << "Child2 : Get Child1 PID :" << pid3 << std::endl;
                if(close(fd1[0]) == -1){
                        return 4;
                }
                int pid4 = getpid();
                write(fd2[1] , &pid4 , sizeof(int));
                std::cout << "Child2 PID :" << pid4 << std::endl;
                if(close(fd2[1]) == -1){
                        return 5;
                }

		}

		else{
			
			if(close(fd1[0]) == -1){
		                return 1;
	     		}
		        if(close(fd2[1]) == -1){
		                return 2;
		        }
   		        if(close(fd2[0]) == -1){
		                return 3;
      		  	}
		        if(close(fd1[1]) == -1){
		                return 4;
	        	}


		        if (wait(NULL) == -1)
		        {
		                std::cout << "Error!" << std::endl;
		        }
		        if (wait(NULL) == -1)
		        {
		                std::cout << "Error!" << std::endl;
		        }

		        std::cout << "Finished ... " <<std::endl;

		}
		
	}
}
