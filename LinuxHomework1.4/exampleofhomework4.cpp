#include <unistd.h>
#include <iostream>
#include <cerrno>
#include <sys/wait.h>
#include <string>

int main() {
    std::cout << "Start pid: " << getpid() << "\n";

    pid_t pid = fork();
    if (pid == -1){
        return errno;
    }

    std::cout << "Print after fork pid: " << getpid() << "\n";

    // child process
    if(pid == 0){
        std::cout << "CHILD: Hello my pid is: " << getpid() << "\n";
        std::cout << "CHILD: my parent pid is: " << getppid() << "\n";
        std::string s = "./hello";
        execlp(s.c_str(), NULL);
    }

    // parent process
    if(pid > 0){
        std::cout << "PARENT: Hello my pid is: " << getpid() << "\n";
        std::cout << "PARENT: my child pid is: " << pid << "\n";
    }

    std::cout << "Hello from both pid: " << getpid() << "\n";

    // parent process
    if(pid > 0){
        int childStatus = -1;
        std::cout << "PARENT: Waiting for child with pid: " << pid << "\n";
        pid_t waitingChild = waitpid(pid, &childStatus, 0);
        if(waitingChild == -1){
            return errno;
        }
        std::cout << "PARENT: Child end working with status code: " << childStatus << "\n";
    }

    std::cout << "finish\n";

    return 0;

}
