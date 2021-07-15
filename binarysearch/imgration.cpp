#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    long long mintime =1;
    long long maxtime = (long long)n * times[times.size()-1];
    
     
    while(mintime <= maxtime)
    {
        long long mid = (mintime + maxtime) / 2;
        long long count =0;
        for(int i =0 ; i < times.size(); i++)
        {
            if(mid>times[i])
            count += (mid / times[i]);
            
        }
        
          
        if(count >= n)
        { 
            if(mid <= maxtime)
                answer= mid;
            
            maxtime = mid -1;
            
            
        }
        else
            mintime = mid +1;
        
     
       
    }
    return answer;
}
