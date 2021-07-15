 #include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> v;

    int dcount =0;
    int icount =0;
    for(int i =0; i < operations.size();i++)
    {
        //문자열 파싱
        string ops =  operations[i];
        string op = ops.substr(0 ,1); //문자고르기

        int vsize = v.size();
        int n = stoi(ops.substr(2, ops.size()-2));
        if(op == "I")
        {
            icount++;
            v.push_back(n);
            sort(v.begin() , v.end());
        }

        else if ( op == "D")
        {

            dcount ++;

            if( n == 1)
            {   
             if(v.size() != 0)
              v.erase(v.begin() +vsize-1);

            }
            if(n == -1)
            {
                if(v.size() != 0)
                v.erase(v.begin());
            }
        }


    }

    if(v.empty() || dcount >= icount)
    {
        answer.push_back(0);
        answer.push_back(0);

    }
    else
    {
        int vsize = v.size();
        if(vsize != 0)
         answer.push_back(v[vsize-1]);
         answer.push_back(v[0]);


    }

   return answer;
}
