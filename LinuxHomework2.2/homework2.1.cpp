#include <iostream>
#include <string>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <vector>

struct Arguments{
	int index; //file i
	int x; 
	int y;
	std::string operation; // s , ss , m
};

void* CreateFiles(void* args){
	Arguments *arguments = (Arguments*) args;
	int index = arguments -> index;
	int result;
	int x = arguments -> x;
	int y = arguments -> y;
	std::string operation = arguments -> operation;

	if(operation == "s")
	{	
		result = x + y;
	}
	else if(operation == "ss")
	{
		result = (x * x) + (y * y);
	}
	else if(operation == "m")
	{
		result = x * y;
	}
	else{
		std::cout << "Operation doesn't exist!" << std::endl;
	}

	std::string res;
        res += std::to_string(x) + " " + operation + " " +  std::to_string(y) + " = " +  std::to_string(result);
	std::string file = "out_" ;
        file += std::to_string(index);
        int fd = open(file.c_str() , O_RDWR | O_CREAT , 0644);
        write(fd , res.c_str() , res.size());
        close(fd);
	

	return NULL;
	

}

int main(){
	int N;
        std::cin >> N;
	std::vector<Arguments> args(N);
	std::vector<pthread_t> threads(N);
	
	int i;
	for(i = 0 ; i < N ; ++i){
		args[i].index = i + 1;
		std::cin >> args[i].x;
	        std::cin >> args[i].y;
	        std::cin >> args[i].operation;

		if(pthread_create(&threads[i] , NULL , CreateFiles , &args[i]) != 0){
			std::cout << "Smth went wrong while creating thread" << std::endl;
		}
		
		
	}
	for(i = 0 ; i < N ; ++i){
		if(pthread_join(threads[i] ,NULL) != 0){
			std::cout << "Error! " <<std::endl;
		}
	}

	pthread_exit(NULL);

}
