#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int nLimit) {
    int anwser = 0;
    
    	sort(people.begin(), people.end(), [](int a , int b ) {
		if (a > b)
			return true;
		else
			return false;

	});

	for (int nindex = 0; nindex < people.size(); nindex++) {
	
		bool issented = false;
		for (int i = 1; i < people.size(); i++) {

			//printf("%d %d ", people[nindex], people[nindex + i]);

			if (people.size() == 1)
			{
				people.erase(people.begin() + nindex);
				anwser++;

				nindex--;
				issented = true;
				break;
			}

			if (people[nindex] + people[nindex + i] <= nLimit) {
				people.erase(people.begin() + nindex+i);
				people.erase(people.begin() + nindex);

				nindex--;
				issented = true;
				anwser++;
				break;
			}

		}
	 
		if (!issented)
		{
			people.erase(people.begin() + nindex);
			nindex--;
			anwser++;
			continue;
		}
			 
	}
    return anwser;
}
