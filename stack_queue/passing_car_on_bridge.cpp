#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <math.h>
#include <unordered_set>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
  
 
 
int main()
{
	int answer = 0;

	//다리에 오를수있는 최대 무게
	//int weight = 10;
	////다리 길이
	//int bridge_length = 2;
	//vector<int> truck_weights;
	//truck_weights.push_back(7);
	//truck_weights.push_back(4);
	//truck_weights.push_back(5);
	//truck_weights.push_back(6);
	int weight = 10;

	//다리 길이
	int bridge_length = 100;

	vector<int> truck_weights;
	truck_weights.push_back(10);
	  


	/////////////////////////////////////////////////////


	int current_weight = 0;
	int removecnt = 0;
	//현재 다리위에 있는 가장 먼저 나간 인덱스 
	int latest_index = 0;

	int remainlength[10000];
	int vectorindex = 0;
	 
	//첫번쨰 값 꺼내기
	current_weight += truck_weights[vectorindex];
	queue<int> q;
	q.push(truck_weights[vectorindex]);
	remainlength[vectorindex] = bridge_length;
	vectorindex++;


	while (removecnt <=truck_weights.size()) {
		//anwser++ 시키기 = 초 증가

		if (removecnt == truck_weights.size())
		{
			answer++;
			break;
		}
		answer++;


		int remove = 0;
		

		//남은길이 조정
		for (int i = latest_index; i < latest_index + q.size(); i++) {
			//bridge_length -- 시켜주기 

			if (remainlength[i] <= 0)
				continue;
			else {
				//길이 1빼주기
				remainlength[i]--;
			}
		}

		//car 변수의 length가 0과 같으면 q에 뺴주기 
		for (int i = latest_index; i < latest_index + q.size(); i++)
		{
			if (remainlength[i] == 0) {
				remove = q.front();
				removecnt++;
				q.pop();
				current_weight -= remove;
				printf("--remove index = %d anwser = %d , weigth  %d\n", i, answer, remove);

				//다리위 가장오래된 인덱스 ++ 해주기 
				latest_index++;

			}
		}
		 
		//현재 다리위에 무게가 최대무게 보다 작다면
		if (vectorindex< truck_weights.size() && current_weight +/* remove +*/ truck_weights[vectorindex] <= weight)
		{

			//무게 추가해주기
			current_weight += truck_weights[vectorindex];
			//다리길이 초기화 
			remainlength[vectorindex] = bridge_length;

			printf("**add index = %d anwser = %d , weigth  %d\n", vectorindex, answer, truck_weights[vectorindex]);


			//큐에 넣어주기
			q.push(truck_weights[vectorindex]);
			vectorindex++;


		}



	}

	printf("%d", answer);
	return 0 ;
}
