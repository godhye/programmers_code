#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int compare(int current_heigh /*현재층*/, int current_point /*현재 위치*/, vector<vector<int>> tria, int *answer)
{
	int next = -1;
	vector<int> com = { -1,-1,-1,-1 };

	//왼쪽 위 아래 오른쪽 값 넣을 거임
	if (current_heigh == 0)
	{
		//위아래
		com[1] = tria[current_heigh + 1][current_point];

		com[2] = tria[current_heigh + 1][current_point + 1];
	}
	else if (current_heigh == 1)
	{
		//옆위아래
		if (current_point == 0)
		{

			com[1] = tria[current_heigh + 1][current_point];

			com[2] = tria[current_heigh + 1][current_point + 1];
			com[3] = tria[current_heigh][current_point + 1];
		}
		else
		{
			com[0] = tria[current_heigh][current_point - 1];
			com[1] = tria[current_heigh + 1][current_point];

			com[2] = tria[current_heigh + 1][current_point + 1];
		}
	}
	else
	{
		//왼쪽 위 아래 오른쪽
		com[0] = tria[current_heigh][current_point - 1];
		com[1] = tria[current_heigh + 1][current_point];

		com[2] = tria[current_heigh + 1][current_point + 1];
		com[3] = tria[current_heigh][current_point + 1];
	}

	next = max_element(com.begin(), com.end()) - com.begin();
    //printf("%d \n",com[next]);
	*answer += com[next];
    
	return next;
}

int solution(vector<vector<int>> triangle) {
	int answer = triangle[0][0];
	int cur_height = 0; //현재 높이
	int cur_point = 0;
	//현재높이 벡터 최대높이일때까지 반복

	//printf("cur_height %d cur_point %d answer %d\n", cur_height, cur_point, answer);
	int result = compare(cur_height, cur_point, triangle, &answer);
	//printf("cur_height %d cur_point %d answer %d\n", cur_height, cur_point, answer);
	while (cur_height <triangle.size()-1)
	{
		
		{
			
			if (result == 0)
			{
				cur_point--;
				result = compare(cur_height, cur_point, triangle, &answer);
			}
			else if (result == 1)
			{
				cur_height++;
				if (cur_height == triangle.size() - 1)
					break;
				result = compare(cur_height, cur_point, triangle, &answer);
			}

			else if (result == 2)
			{
				cur_height++;
				cur_point++;
				if (cur_height == triangle.size() - 1)
					break;
				result = compare(cur_height, cur_point, triangle, &answer);
			}

			else
			{
				cur_point++;
				result = compare(cur_height, cur_point, triangle, &answer);
			}
			
		}
	}
    printf("cur_height %d cur_point %d answer %d\n", cur_height, cur_point, answer);
	return answer;
}
