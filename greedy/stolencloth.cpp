#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;
 
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    answer = n - lost.size();
    
    //학생 전부다 도둑 맞는 경우 여분 수 반환
    if(n == lost.size())
        return reserve.size();
        
    //번호 수 정렬 
    sort(reserve.begin() , reserve.end());
        
    for (auto v : lost)
    {
        auto it = find_if(reserve.begin(), reserve.end(), [=](int a) {
		//a 값이 v -1 ~ v+1 사이에 있으면 만족 
		if (a >= v - 1 && a <= v+1)
			return true;
		else
			return false;
	});
    if(it!= reserve.end())
    {
        answer++;
        reserve[it-reserve.begin()] =  -100;
        
    }
    }
    return answer;
}
