#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main(){

	pid_t pid = fork();

	if(pid == -1){
		return 1;
	}
	else if(pid == 0){
		int ParentPid = getppid();
		std::cout << "We are in Child process!" << std::endl;
		kill(ParentPid , SIGKILL);
	}
	else{
		int status;
		wait(&status);
	}
}
