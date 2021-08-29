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

bool mycompare(pair<int, int >a, pair<int, int >b)
{
	if (a.first != b.first)
		return a.first > b.first;
	else
		return a.second > b.second;

}

int main()
{
	vector<int> numbers;
	numbers.push_back(999);
	numbers.push_back(998);
	numbers.push_back(9);
	numbers.push_back(90);
	
	/*numbers.push_back(30);
	numbers.push_back(7);
	numbers.push_back(77);
	numbers.push_back(34);
	numbers.push_back(5);
	numbers.push_back(9);
	 */
	//95444310

	vector<pair<int, int>> vnum;
	string answer = "";
	long long totalsum = 0;
	for (auto v : numbers)
	{
		//모든값 0인지 확인용
		totalsum += v;

		int i = 0;
		//0 1000 값 제외 3자리수로 맞춰주기
		while (v * 10 < 1000 && v != 0 && v != 1000)
		{
			v = v * 10;
			i++;
		}

		//셋자리수값 , 10 곱한 횟수
		if (v == 1000)
		{
			vnum.push_back({ 1 , i });
			continue;
		}
		vnum.push_back({ v , i });

	}

	//첫번째값 비교, 같으면 10곱해준 값으로 크기 정렬
	sort(vnum.begin(), vnum.end(), mycompare);

	//곱해준만큼 뺴서 문자열로 치환 
	for (auto v : vnum)
	{
		int nfirst = v.first;
		int nsecond = v.second;

		if (nfirst == 1)
		{
			answer.append(to_string(1000));
			continue;
		}

		if (0 != nsecond)
			nfirst = nfirst / pow(10, nsecond);

		
		answer.append(to_string(nfirst));
	}


	if (totalsum == 0)
		//return "0";
		cout << "0";
	else
		//return answer;
		cout << answer;

		return 0;
}
