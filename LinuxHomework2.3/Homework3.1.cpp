#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <fcntl.h>
#include <chrono>



class Integer{
private:
    int value;
    sem_t* semaph;
public:
    Integer(int val):value(val){
        this->semaph = new sem_t();
        sem_init(this->semaph, 0, 1);
    }

    int get_value(){
        return this->value;
    }
    void set_value(int val){
        this->value = val;
    }
    void inc(){
        sem_wait(this->semaph);
        this->value++;
        sem_post(this->semaph);
    }
    ~Integer() {
        sem_destroy(this->semaph);
        delete this->semaph;
    }
};

void* inc(void* arg){
    Integer* integ = (Integer*) arg;
    int inc_num = 10000;
    for (int i = 0; i < inc_num; i++){
       integ->inc();
    }
    return NULL;
}

int main () {
    int thread_num = 56;
    Integer* integ = new Integer(0);
    pthread_t* thrds = new pthread_t[thread_num];
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < thread_num; i++){
        if (pthread_create(&thrds[i], NULL, inc, (void*)integ) != 0){
            return 1;
        }
    }

    for (int i = 0; i < thread_num; i++){
        if (pthread_join(thrds[i], NULL) != 0){
            return 2;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    std::cout << integ->get_value() << "\n";

    delete [] thrds;
    delete integ;
    std::string time = "";
    time += "Time with Semaphores: ";
    time +=  std::to_string(duration.count()) + " ";
    std::string file = "file.txt";
    int fd = open(file.c_str() , O_WRONLY | O_CREAT | O_APPEND , 0644);
    write(fd , time.c_str() , time.size());
    close(fd);
    return 0;
}

