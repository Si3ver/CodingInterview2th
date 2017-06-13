/*题目一：找出数组中重复的数字。
数组长度为n，所有数字在0~n-1范围内。可能存在某些数字重复，若有重复的数字，返回true，并找出任意一个重复的数字，否则，返回false。
思路：扫描一遍，把每个数字放入该放的位置（交换）~
测试用例：numbers[7] = {3, 1, 2, 0, 2, 5, 3}, length = 7, 函数应返回true, 重复的数字为2or3;
*/

#include <iostream>
using namespace std;

bool duplicate(int numbers[], int length, int* duplication)
{
	//检查数组长度
	if (numbers == nullptr || length <= 0){
		return false;
	}

	//检查数组合法性
	for (int i = 0; i < length; i++){
		if (numbers[i] < 0 || numbers[i] > length - 1){
			return false;
		}
	}

	//遍历一遍数组，把元素放入“合理位置”
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
