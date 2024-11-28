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

	cout << "1.���ֲ���" << endl;

	cout << "��ѡ���ܣ�";
	cin >> x;

	switch (x) {
	case 1: {
		vector<int> arry1 = { -1, 0, 3, 5, 9, 12 };
		int target;
		cout << "������Ҫ���ֵ��";
		cin >>target;
		int result = solution.binary_search(arry1, target);
		if (result == -1) {
			cout << result << endl;
			cout << target << "���������з���" << -1;
		}
		else {
			cout << result << endl;
			cout << target << "�������������±�Ϊ" << result << endl;
		}
	}
	}

	

}