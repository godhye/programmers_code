#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string str;
bool check[7];
unordered_set<int> s;

void find_all_numbers(int depth , int limit ,string& numbers )
{
    if(depth == limit) return;
    
    for(int i =0 ; i < limit ; i++)
    {
        if(!check[i])
        {
            check[i] = true;
            str.push_back(numbers[i]);
            s.insert(stoi(str));
            find_all_numbers(depth+1 , limit , numbers);
            str.pop_back();
            check[i] = false;
        }
        
    }
    
}
    
int solution(string numbers) {
    int answer = 0;
    
     vector<int> num;
    find_all_numbers(0 ,numbers.size(), numbers);
    
     for(auto& it : s)
     {
         if(it ==1 || it == 0 ) continue;
         50-
         int num = it / 2;
         bool isDivided = false;
         
         for(int i = 2 ; i <= num ; i++)
         {
             if((it%i) == 0) isDivided = true;
             
         }
         if(!isDivided) answer++;
         
     }
 
    return answer;
}
