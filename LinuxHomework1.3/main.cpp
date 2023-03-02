#include "ComplexNum.h"
#include <vector>
#include <algorithm>
#include <iostream>


int main()
{

	ComplexNum a{3 , 6};
	ComplexNum b{1 , 2};
        ComplexNum c{4 , 5};

	std::vector<ComplexNum>vec;

	vec.push_back(a);
	vec.push_back(b);
	vec.push_back(c);

	for(int i = 0 ; i < vec.size() - 1 ; ++i)
	{
		for(int j = 0 ; j < vec.size() - 1 - i ; ++j)
		{
			if(vec[j].getModuls() > vec[j+1].getModuls())
			{
			std::swap(vec[j] , vec[j+1]);
			}
 	        }

	}

	for(int i = 0 ; i < vec.size()  ; ++i)
        {
          std::cout << vec[i] ;
	}




}
