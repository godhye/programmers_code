#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
bool checked[100000];

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
     
    sort(participant.begin() , participant.end());
    sort(completion.begin() , completion.end());
    answer = participant[participant.size()- 1];
    
    for(int i =0 ; i < completion.size(); i++)
    {
        if( completion[i] !=participant[i] )
        { answer = participant[i];
        break;
        }
    }
    
     
    return answer;
}
