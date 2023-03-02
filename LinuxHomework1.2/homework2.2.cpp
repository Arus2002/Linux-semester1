#include <iostream>
#include <ostream>
#include <dirent.h>
#include <string.h>
#include <string>
#include <fcntl.h>
#include <unistd.h>

static const std::size_t size = 10000;

void print(std::string fileName)
{
 int fd = open(fileName.c_str() , O_RDWR);
 char buf[size+1];
 read(fd,buf,size);
 std::cout << fileName << std::endl;
 std::cout << buf << std::endl;
 close(fd);

}

void listFiles(const char* dir_name)
{
	
	DIR* dir = opendir(dir_name);
	if(dir == NULL)
	{
		return;
	}
	struct dirent* entity;
	entity = readdir(dir);
	while(entity != NULL)
	{
		

		if(entity -> d_type == DT_DIR && strcmp(entity -> d_name,".") != 0 && strcmp(entity -> d_name,"..") != 0)
		{
			char buff[100] = {0};
			strcat(buff, dir_name);
			strcat(buff,"/");
			strcat(buff, entity -> d_name);
			listFiles(buff);
			print(buff);

         	
	        }

	       entity = readdir(dir);

        }
        
	

	closedir(dir);

}

int main(int argc, char** argv)
{
	
	listFiles(".");
}

