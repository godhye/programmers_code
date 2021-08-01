#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <math.h>
#include <unordered_set>
#include <string>
#include <vector>
 
using namespace std;
 
int main()
{

	int k = 6;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(10);
	v.push_back(9);
	v.push_back(4);
	v.push_back(44);
	v.push_back(2);
	v.push_back(1);
	v.push_back(33);
	v.push_back(4);
	v.push_back(445);
	v.push_back(2);
	v.push_back(10);
	v.push_back(33);
	v.push_back(4); v.push_back(44);
	v.push_back(2);
	v.push_back(10);
	v.push_back(555);
	v.push_back(4);
	 
	int sum = 0;
	int presum = 0;

	for (int i = 0; i < k; i++)
	{
		sum += v[i];
		presum += v[i];

	}

	
	for (int i = 0; i < v.size()-k; i++)
	{
		sum -= v[i];
		sum += v[i + k];
 

		if (sum >presum)
			presum = sum;
		
	}
	cout << presum;
	return 0;

}
