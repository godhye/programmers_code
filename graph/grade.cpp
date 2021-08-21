#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    int map[101][101] = {0,};
 
    for(auto v : results)
    {
        map[v[0]][v[1]] = 1;
    }
    
  //거쳐가는 노드🤦‍♀
    for(int k =1; k <= n; k ++)
    {//출발   노드🤦‍♀
        for(int i =1 ; i <= n ; i++)
        {//도착  노드🤦‍♀
            for(int j =1; j <= n; j++ )
            {
                //승패 결정된 경우 i> k >j
                if(map[i][k] && map[k][j]) 
                     {
                
                    map[i][j] = 1;
                    }
            }
        }
    }
    
    for(int i =1 ; i <= n ;i++)
    {
        int count =0;
        for(int j =1 ; j <= n; j++)
        {
            
            if(map[i][j] || map[j][i])
            {
              
                count++;
            }
        }
        if(count == (n-1))
                answer++;
    }
     
        return answer;
}
