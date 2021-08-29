#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

bool mycompare(pair<int  , int >a , pair<int, int >b)
{
	if (a.first != b.first)
		return a.first > b.first;
	else
		return a.second > b.second;
	
}


string solution(vector<int> numbers) {
   
	string anwser;
	vector<pair<int, int>> nums;

	//vec안에 숫자 네자리수로 맞춰주기
	for (auto v : numbers)
	{
		string str = to_string(v);

		 
		int nindex = 0;
		for (int i = 4 - str.length(); i > 0; i--, nindex++)
		{
			string s = to_string(str[nindex] -48);
			str.append(s);
		}

		nums.push_back({ -stoi(str), v });
	}

	//정렬하기
	sort(nums.begin(), nums.end()  );

	for (auto v : nums)
		anwser.append(to_string(v.second));
	

	if (nums[0].second == 0)
		return "0";
        
    return anwser;
}
