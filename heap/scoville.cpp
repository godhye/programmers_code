#include <string>
#include <vector>
#include <bits/stdc++.h>


using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> q ;
    
    for(int i =0 ; i< scoville.size(); i++)
        q.push(-scoville[i]);
    
    
    while(!q.empty())
    {
        
        
        //만들어지는경우
        if(-q.top() > K)
            break;
        
        if( q.size() == 1 )
        {
            answer = -1;
            break;
        }
        int a = -q.top();
        q.pop();
        
        int b = -q.top();
        q.pop();
        
        q.push(-(a + (2*b)) );
        
        
        answer++;
    }
    

    return answer;
}
