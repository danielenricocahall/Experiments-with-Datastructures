#include <iostream>
#include "RangeSumArray.h"


int main()
{
	int N = 100;

	UpdateSumArray<int> * updater = new UpdateSumArray<int>(std::floor(sqrt(N)));
	for(int ii = 0; ii<N; ++ii)
	{
		updater->add(ii);
	}
	std::cout << "The sum is " << 	updater->sum(0,99);
	//the total sum should be N(N+1)/2 in this situation
}
