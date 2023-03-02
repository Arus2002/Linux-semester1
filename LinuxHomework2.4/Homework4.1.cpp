#include <iostream>
#include <pthread.h>

int res_count = 0;
	

void* thread(void* arg){
  int n = *(int*)arg;
  int res;
  int count = 0;
  if(n < 2){
    return res_count;
  }
  for(int i = 2 ; i <= n ; ++i){
    for(int j = 1 ; j <= i ; ++j){
      if(i % j == 0){
        count++;
      }
    }
    if(count < 3){
      res = i;
      res_count++;
    }
    count = 0;
  }
  std::cout << res_count << std::endl;
  free(arg);
  return nullptr;
  
}

int main(int argc , char** argv){
	int N = argv[1];
	std::cin << N;
	pthread_t tid[2];
	
	for(int i = 0 ; i < tid.size() ; ++i){
		int* a = malloc(sizeof(int));
		*a = i * ((N + 1) / 2);
		if(pthread_create(&tid[i] , NULL , thread, a) != 0){
			std::cout << "Smth went wrong while creating thread" << std::endl;
		}
	}
	for(int i = 0 ; i < tid.size() ; ++i){
		if(pthread_join(tid[i] , NULL) != 0){
                	std::cout << "Error! " <<std::endl;
        	}
	}


}
