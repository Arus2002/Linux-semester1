#include "str.h"

int string_length(const char* str){
    int length = 0;
    int i = 0;
    while(str[i++] != '\0'){
      length++;
    }

    return length;
  
}


int num_digits(const char* str){
    int count{};
    for(int i = 0 ; i < string_length(str) ; i++){
        if(str[i] >= '0' && str[i] <= '9')
        {
            ++count;
        }
    }
    return count;
}


