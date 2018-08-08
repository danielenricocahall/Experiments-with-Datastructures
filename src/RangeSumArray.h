#include <vector>
#include <cmath>
#include <algorithm>
template<class T> class RangeSumArray
{
public:
	RangeSumArray()
	{

	}
	void update(const unsigned int i, const T x)
	{
		T temp = A.at(i);
		A[i] = x;
		if(S.size() > i/k)
		{
			S[std::floor(i/k)] -= temp;
			S[std::floor(i/k)] += A[i];
		}
	}
	unsigned int sum(const unsigned int lo, const unsigned int hi) const
	{
		unsigned int acc = 0;
		unsigned int ii = lo;
		for(; (ii%k != 0 && ii != hi); ++ii)
		{
			acc+=A[ii];
		}
		for(; ii+k <= hi; ii+=k)
		{
			acc += S[ii/k];
		}
		for(;ii<=hi;++ii)
		{
			acc += A[ii];
		}
		return acc;

	}

	void add(const T x)
	{
		unsigned int k_prev = k;
		A.push_back(x);
		k = std::floor(sqrt(A.size()));
		if(k != k_prev)
		{
			S.clear();
			computePartialSums(0);
		}
		else
		{
			if(A.size()%k == 0)
			{
				computePartialSums(A.size()-k);
			}
		}
	}
	void computePartialSums(const unsigned int start)
	{
		unsigned int s = 0;
		for(unsigned int ii = start, end = A.size(); ii < end; )
		{
			s+=A[ii];
			if((++ii)%k == 0)
			{
				S.push_back(s);
				s = 0;
			}
		}
	}

private:
	std::vector<T> A;
	std::vector<T> S;
	unsigned int k;

};


