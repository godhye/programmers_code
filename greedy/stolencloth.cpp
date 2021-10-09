#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;
 
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    answer = n - lost.size();
     
    for (auto &v : lost)
    {
        //본인이 잃어버린 경우 
        auto it1 = find(reserve.begin() , reserve.end() , v);
        if(it1 != reserve.end())
        {
         answer++;
            //본인이 잃어버린경우 lost에서도 삭제해줘야 아래에서 중복으로 안찾음!!
         v = -100;
         reserve[it1-reserve.begin()] =  -100;
        }  
     }
    
    sort(lost.begin() , lost.end());
    sort(reserve.begin() , reserve.end());
        
    for (auto v : lost)
    {
        
            auto it = find_if(reserve.begin(), reserve.end(), [=](int reservevalue) {
            //a 값이 v -1 ~ v+1 사이에 있으면 만족    
		    if (reservevalue == v - 1 || reservevalue == v+1 )
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
