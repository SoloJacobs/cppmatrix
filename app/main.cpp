#include <algorithm>
#include <numeric>
#include <iostream>

#include "matrix.hpp"
#include "indices.hpp"
#include "matrixslice.hpp"

int main()
{
	Matrix<int> mat(3,4,2);
	std::iota(mat.begin(), mat.end(), 0);
	std::cout << mat;

	MatrixSlice<int> slice(mat, 1, 1);

	std::cout << std::endl;
	for(std::size_t i{0}; i < 2; ++i) {
		for(std::size_t j{0}; j < 3; ++j) {
			std::cout << slice(i,j) << " " << std::flush;
		}
		std::cout << "\n";
	}

	Indices in(3,4);

	for(auto [i,j] : Indices(3,4))
	{
		std::cout << i << " " << j << std::endl;
	}

	for(auto [i,j] : Indices(mat))
	{
		std::cout << i << " " << j << std::endl;
	}



}
