#include <iostream>
#include <vector>

int main(int argc , char** argv )
{
  std::vector<std::string> vec(argc);
	for(int i = 0 ; i < argc ; ++i)
	{
		vec[argc - i - 1] = argv[i];
	}
	for(int i = 0 ; i < argc ; ++i)
	{
		std::cout << vec[i] << " " ;
	}

}

