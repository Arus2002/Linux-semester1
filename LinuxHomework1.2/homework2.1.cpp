#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc , char** argv)
{
	std::string file_count = argv[1];
	unsigned long long N = stoull(file_count);
	for(int i = 1 ; i <= N ; ++i)
	{
		std::string file = "file_";
		std::string text = "Text ";
		file += std::to_string(i);
		text += std::to_string(i);
		int fd = open(file.c_str() , O_RDWR | O_CREAT , 0644);
		write(fd,text.c_str(),text.size());
		close(fd);
	}
}
