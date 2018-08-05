#include "UpdateSumArray.h"
#include <cmath>
#include <iostream>

//dynamically sized range sum data structure
//replete with poorly named variables
//also, I need to generalize (make this templated or something)


//Note: bit implementation = unsigned char array, navigate into each byte
//Original thought was booleans, but I think they're a byte each and we don't need that much
UpdateSumArray::UpdateSumArray(unsigned int k)
{
	this->k = k;
}

void UpdateSumArray::update(const unsigned int i, const unsigned int x)
{
	unsigned int temp = A.at(i);
	A[i] = x;
	if(S.size() > i/k)
	{
		S[std::floor(i/k)] -= temp;
		S[std::floor(i/k)] += A.at(i);
	}
}

void UpdateSumArray::add(const unsigned int x)
{
	unsigned int k_prev = k;
	A.push_back(x);
	k = std::floor(sqrt(A.size()));
	if(k != k_prev)
	{
		S.clear();
		computePartialSums(0);//recursive implementation
		//recomputePartialSums(); original sequential implementation
	}
	else
	{
		if(A.size()%k == 0)
		{
				computePartialSums(A.size()-k);
		}
	}
}


unsigned int UpdateSumArray::sum(const unsigned int lo, const unsigned int hi) const
{
	unsigned int acc = 0;
	unsigned int ii = lo;
	for(; (ii%k != 0 && ii != hi); ++ii)
	{
		acc+=A.at(ii);
	}
	for(; ii+k <= hi; ii+=k)
	{
		acc += S.at(ii/k);
	}
	for(;ii<=hi;++ii)
	{
		acc += A.at(ii);
	}
	return acc;

}

void UpdateSumArray::computePartialSums(const unsigned int start)
{
	unsigned int s = 0;
	for(unsigned int ii = start; ii < A.size(); ++ii)
	{
		s+=A.at(ii);
		if((ii+1)%k == 0)
		{
			S.push_back(s);
			s = 0;
		}
	}
}

int main()
{
	UpdateSumArray * updater;
	int N = 100;
	updater = new UpdateSumArray(std::floor(sqrt(N)));
	for(int ii = 0; ii<N; ++ii)
	{
		updater->add(ii);
	}
	std::cout << "The sum is " << 	updater->sum(0,99);
	//the total sum should be N(N+1)/2 in this situation
}
