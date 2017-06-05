/*寻找0~n-1数组中重复的数
*/

#include <iostream>
using namespace std;

bool duplicate(int numbers[], int length, int* duplication)
{
	if (numbers == nullptr || length <= 0){
		return false;
	}

	for (int i = 0; i < length; i++){
		if (numbers[i] < 0 || numbers[i] > length - 1){
			return false;
		}
	}

	for (int i = 0; i < length; i++){
		while(numbers[i] != i){
			if (numbers[i] == numbers[numbers[i]]){
				*duplication = numbers[i];
				return true;
			}

			//swap numbers[i] & numbers[numbers[i]]
			int tmp = numbers[i];
			numbers[i] = numbers[tmp];
			numbers[tmp] = tmp;
		}
	}
}


int main()
{
	int data[] = {2, 3, 1, 0, 2, 5, 3};
	int dumplication = -1;
	if (duplicate(data, 7, &dumplication)){
		cout<<dumplication<<endl;
	}else{
		cout<<"no duplication"<<endl;
	}
	return 0;
}
