#include <iostream>
#include <pthread.h>
#include <vector>

class PrimeNumbers{
private:
	int n;
	pthread_mutex_t* mut;


public:
	PrimeNumbers(int N):n(N){
        	this -> mut = new pthread_mutex_t();
        	pthread_mutex_init(this -> mut , NULL);
    	}
	int get_n(){
        	return this -> n;
	}
        void set_n(int N){
		this -> n = N;
        }
	int isPrime(int n){
		pthread_mutex_lock(this -> mut);
        	int res;
        	int count{};
        	if(n < 2){
                	return 0;
        	}
	        for(int i = 0 ; i <= n ; ++i){
        	        for(int j = 1 ; j <= n ; ++j){
                	        if(i % j ==0){
                        	        count++;
                        	}
                	}
                	if(count < 3){
                        	res = i;
                        	return res;
	                }
	                count = 0;
        	}
		pthread_mutex_unlock(this -> mut);

	}
	~PrimeNumbers() {
        	pthread_mutex_destroy(this -> mut);
        	delete this -> mut;
        }



	
};


void* thread(void* arg){
	PrimeNumbers* n = (PrimeNumbers*) arg;
	n -> isPrime(n);
	free(arg);
	return nullptr;
}

int main(){
	int N;
	std::cin >> N;
	pthread_t threads[2];
	for(int i = 0 ; i < 2 ; ++i){
		int* a = malloc(sizeof(int));
		*a = i * ((N + 1) / 2);
		if (pthread_create(&threads[i], NULL, thread, a) != 0){
	            return 1;
	        }
	}
	for (int i = 0; i < 2 ; ++i){
        	if (pthread_join(threads[i], NULL) != 0){
           	    return 2;
        	}
	}

}
