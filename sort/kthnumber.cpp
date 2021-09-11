
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for(auto v : commands)
    {
        vector<int> arrays;
        for(int i = v[0]-1 ; i < v[1]; i++)
        {
            arrays.push_back(array[i]);
            cout << i << " " << array[i] <<endl;
        }
        cout << endl;
        sort(arrays.begin() , arrays.end());

        answer.push_back(arrays[v[2] -1]);
    }
    return answer;
}
