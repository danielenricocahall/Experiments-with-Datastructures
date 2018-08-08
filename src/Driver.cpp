#include <iostream>
#include "RangeSumArray.h"
#include <chrono>
#include <thread>
#include <algorithm>
#include <stdlib.h>     /* srand, rand */


int main()
{
	unsigned int N = 1000;

	RangeSumArray<int> * updater = new RangeSumArray<int>();
	std::vector<int> * temp = new std::vector<int>();

	for(unsigned int ii = 0; ii<N; ++ii)
	{
		unsigned int random = rand() % N + 1;
		updater->add(random);
		temp->push_back(random);

	}
	auto t1 = std::chrono::high_resolution_clock::now();
	unsigned int sum = updater->sum(0, N-1);
	auto t2 = std::chrono::high_resolution_clock::now();

	std::cout << "The sum is " << 	sum << std::endl;


	std::cout << "Computing sum took "
	              << std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count()
	              << " microseconds" << std::endl;



	unsigned int acc = 0;
	t1 = std::chrono::high_resolution_clock::now();
	std::for_each(temp->begin(), temp->end(), [&] (int n) {
	    acc += n;
	});
	t2 = std::chrono::high_resolution_clock::now();
	std::cout << "The sum is " << 	acc << std::endl;

	std::cout << "Computing sum took "
		              << std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count()
		              << " microseconds" << std::endl;
}
