#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
 

int solution(vector<vector<int>> triangle) {
	 int height = triangle.size()-1;
	vector<vector<int>> copy = triangle;
	for (int i = height; i > 0; i--)
	{
		for (int j = 0; j< triangle[i].size()-1; j++) 
		{
			int upper = copy[i - 1][j];
			if (copy[i][j] > copy[i][j + 1])
				copy[i-1][j] = copy[i][j] + upper;
			else
				copy[i-1][j] = copy[i][j+1] + upper;
		}
		
	}

	return copy[0][0];
}
