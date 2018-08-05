#include <vector>

class UpdateSumArray
{
	std::vector<unsigned int> A;
	std::vector<unsigned int> S;
	unsigned int k;
public:
	UpdateSumArray(unsigned int k);
	void update(const unsigned int i, const unsigned int x);
	unsigned int sum(const unsigned int lo, const unsigned int hi) const;
	void add(const unsigned int x);
	void computePartialSums(const unsigned int start);
	void recomputePartialSums();

};


