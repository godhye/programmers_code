#include <string>
#include <vector>
#include <iostream>
using namespace std;


int map[101][101]={0,};
int d[101][101] = {0,};

int solution(int m, int n, vector<vector<int>> puddles) {
  
    for(auto v : puddles)
    {
        cout<<v[1] << v[0]<<endl;
        map[v[1]][v[0]] = -1;
    }
    
    d[0][1] =1;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j=1 ; j <=m ; j++)
        {
            if(map[i][j] == -1)
                d[i][j] = 0;
            else
            {
            d[i][j] =  d[i-1][j] + d[i][j-1];
            cout<<d[i-1][j] << d[i][j-1]<<endl;
            }
        }
    }
    return d[n][m];
}
