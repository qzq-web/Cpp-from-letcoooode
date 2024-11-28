#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	int binary_search(vector<int>& arry1,int target) {
		int low, mid, high;
		low = 0;
		high = arry1.size() - 1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (arry1[mid] > target)
				high = mid - 1;
			else if (arry1[mid] < target)
				low = mid + 1;
			else if (arry1[mid] == target) {
				return mid;
			}
		}
		return -1;
	}
};



int main() {
	Solution solution;
	
	int x;

	cout << "1.二分查找" << endl;

	cout << "请选择功能：";
	cin >> x;

	switch (x) {
	case 1: {
		vector<int> arry1 = { -1, 0, 3, 5, 9, 12 };
		int target;
		cout << "请输入要查的值：";
		cin >>target;
		int result = solution.binary_search(arry1, target);
		if (result == -1) {
			cout << result << endl;
			cout << target << "不在数组中返回" << -1;
		}
		else {
			cout << result << endl;
			cout << target << "出现在数组中下标为" << result << endl;
		}
	}
	}

	

}