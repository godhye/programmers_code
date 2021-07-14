#include <string>
#include <vector>

using namespace std;
 
int checked[200] = {0,};
int result0 =0;
void dfs(int idx , vector<vector<int>>computers, int n)
{
    
    checked[idx] = 1;
    for(int i =0 ; i < n ; i++)
    {
        if(computers[idx][i] == 1 && checked[i] == 0 && i != idx)
        {
            checked[i] = 1;
            dfs(i , computers , n);
            
        }
    }
    
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    
    for(int i =0 ; i < n ;i++)
    {
        
         if(!checked[i])
         {
             dfs(i , computers  , n);
             answer++;
         }
    }
    
    return answer;
}
