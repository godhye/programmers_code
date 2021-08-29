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
#include <map>
using namespace std;
  
 
int main()
{
	string anwser;
	vector<int> citations;
	citations.push_back(2);
	citations.push_back(2);
	citations.push_back(2);
 
	sort(citations.begin(), citations.end());
	// 0 1 4 5 6
	int ntotal = citations.size();
	 
	//총논몬편수보다 MIN 인용수가 큰 경우 
	if (citations[0] > citations.size())
		return citations.size();
	
	//가장크게 인용된 수 부터 시작 
	for (int i = citations[ntotal-1]; i>=0 ; i--)
	{
		//총논문편수보다 인용수가 많은경우(불가능)
		if (i > citations.size())
			continue;

		// i보다 많이 인용된 수 
		int nindex;
		for (nindex = ntotal-1; nindex>=0 ; nindex--)
		{
			if (citations[nindex] < i)
				break;
		}

		//i 와 같거나 큰값 count
		int maxcita = ntotal - (nindex + 1);
	 
		 
		if ( maxcita >=i)
		{
			return i;
		}
	}
	return 0;
}
