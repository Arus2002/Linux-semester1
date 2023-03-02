#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(int argc , char** argv)
{
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	int c = atoi(argv[3]);

	std::vector<int> vec;
	vec.push_back(a);
	vec.push_back(b);
        vec.push_back(c);

           
        std::sort(vec.begin(),vec.end());
	std::cout << "max = " << vec[2] << " " << "min = " << vec[0] << std::endl;


}

