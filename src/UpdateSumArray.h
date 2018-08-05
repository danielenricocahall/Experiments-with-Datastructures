#include <vector>
#include <cmath>
template<class T> class UpdateSumArray
{
public:
	UpdateSumArray(unsigned int k)
	{
		this->k = k;
	}
	void update(const unsigned int i, const T x)
	{
		T temp = A.at(i);
		A[i] = x;
		if(S.size() > i/k)
		{
			S[std::floor(i/k)] -= temp;
			S[std::floor(i/k)] += A.at(i);
		}
	}
	unsigned int sum(const unsigned int lo, const unsigned int hi) const
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

	void add(const T x)
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
	void computePartialSums(const unsigned int start)
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
	//void recomputePartialSums();

private:
	std::vector<T> A;
	std::vector<T> S;
	unsigned int k;

};


