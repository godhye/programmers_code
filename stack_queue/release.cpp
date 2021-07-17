include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


vector<int> solution(vector<int> p, vector<int> s) {

    vector<int> answer;
    int n = 0;

    while (1)
    {
        if (p.empty())
            break;

        else
        {
            if (p[0] >= 100)
            {
                for (int i = 0; i < p.size(); i++)
                {
                    if (p[i] >= 100)
                    {
                        n++;
                    }
                    else
                        break;
                }
                p.erase(p.begin(), p.begin() + n);
                s.erase(s.begin(), s.begin() + n);
                answer.push_back(n);
                n = 0;
            }
            else
            {
                for (int i = 0; i < p.size(); i++)
                {
                    p[i] += s[i];
                    //c//out << p[i] << endl;
                }
                //cout << endl;
            }
        }
    }

    return answer;
}
