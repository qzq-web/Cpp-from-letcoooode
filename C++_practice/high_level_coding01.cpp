#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//好几把难，头要炸了

class Solution {
public:
	int binary_search(vector<int>& arry1, int target) {
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
	//双指针移除元素法
	//我就只能这么认为了，return的slow依旧指向remove_element函数里的最后一个元素？
	int remove_element(vector<int>& num, int val) {
		//双指针法，一个快一个慢，如果不等于就跳过，等于就覆盖
		int slow = 0, fast;
		for (fast = 0; fast < num.size(); fast++) {
			if (num[fast] != val)
				num[slow++] = num[fast];
		}
		return slow;
	}

	vector<int> order_arry_square(vector<int>& nums) {
		int i, len = nums.size(), e, j, t;
		for (i = 0; i < len; i++) {
			e = nums[i];
			nums[i] = e * e;
		}
		//进行冒泡排序
		/*for (i = 0; i < len-1; i++) {
			for (j = 0; j < len - 1; j++) {
				if (nums[j] > nums[j + 1]) {
					t = nums[j];
					nums[j] = nums[j + 1];
					nums[j + 1] = t;
				}
			}
		}*/

		//c++使用algorithm头文件引入快速排序,不知道头文件里还有没有其他的排序算法
		sort(nums.begin(), nums.end());
		
		return nums;
	}

	//滑动窗口，只不过是自己试着写一遍
	int minSubArrayLen(vector<int>& nums, int s) {
		int i = 0, j, len = nums.size(), sum = 0, flag1 = 0, flag2 = 0;
		//定义最长的子串长为2147483647
		int result = INT32_MAX, subLen;
		for (j = 0; j < len; j++) {
			sum = sum + nums[j];
			//当子串长度大于指定值时才滑动
			while (sum >= s) {
				//计算子字符串长度
				subLen = j - i + 1;
				result = result > subLen ? subLen : result;
				flag1 = i; flag2 = j;
				//窗口滑动怎么实现，把原来i的值减掉不就行了
				sum = sum - nums[i];
				i++;
			}
		}
		cout << "最小连续数组为：";
		for (i = flag1; i <= flag2; i++)
			cout << nums[i] << ' ';
		cout << endl;
		//如果result没有被赋值，就返回0
		//要善于利用这个条件语句，简洁
		return result == INT32_MAX ? 0 : result;
	}
	//二维数组要用俩vector
	vector<vector<int>> generateMatrix(vector<int> nums, int n) {
		int i, j;

	}

};


int main() {
	Solution solution;
	
	int x;

	cout << "1.二分查找" << endl;
	cout << "2.移除元素" << endl;
	cout << "3.有序数组平方" << endl;
	cout << "4.寻找最小连续子数组" << endl;


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
			  break;
		case 2: {
			vector <int>num = { 0,1,2,2,3,0,4,2 };
			int val;
			cout << "请输入要删的值：";
			cin >> val;
			int result = solution.remove_element(num, val);
			for (int i = 0; i < result; i++)
				cout << num[i] << ' ';
		}
			  break;
		case 3: {
			vector<int> nums = { -7,-3,2,3,11 };
			vector<int> result=solution.order_arry_square(nums);
			for (int i = 0; i < result.size(); i++)
				cout << result[i] << ' ';
		}
			  break;
		case 4: {
			vector<int> nums = { 2,3,1,2,4,3};
			int s;
			cout << "请输入s:";
			cin >> s;
			int result = solution.minSubArrayLen(nums, s);
			cout << "长度为：" << result << endl;
		}
	}
}