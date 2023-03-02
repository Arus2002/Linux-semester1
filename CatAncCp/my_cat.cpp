#include <fcntl.h> 
#include <stdio.h> 
#include <unistd.h> 
#include <errno.h> 
#include <stdlib.h> 
#define BUFFER_SIZE 16 
 
 
int main(int argc, char** argv){ 
    if(argc != 2){ 
        printf("set argument."); 
        exit(1); 
    } 
 
    // open the file 
    int fd = open(argv[1], O_RDONLY); 
    if(fd == -1){ 
        printf("something went wrong while opening file.. %s\n", strerror(errno)); 
        exit(errno); 
    } 
 
 
    char* buf = malloc(BUFFER_SIZE + 1); 
    long long read_bytes = 0; 
    long long all_bytes = 0; 
    // read  
    while(1){ 
        read_bytes = read(fd, buf, BUFFER_SIZE); 
 
        if(read_bytes == 0){ 
            break; 
        } 
 
        if(read_bytes == -1){ 
            printf("Something went wrong while reading from file.. %s\n", strerror(errno)); 
            exit(errno); 
        } 
 
        buf[read_bytes] = '\0'; 
 
        all_bytes += read_bytes; 
        // print 
        printf("%s", buf); 
    } 
 
    // close 
    if(close(fd) == -1){ 
        printf("Something went wrong while closing file.. %s\n", strerror(errno)); 
        exit(errno); 
    } 
 
    free(buf); 
}
