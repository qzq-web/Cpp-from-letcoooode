#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//好几把难，头要炸了

class Myarray {
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
	//我就只能这么认为了，return的slow依旧指向remove_element函数里的最后一个元素？	bingo
	//回答：引用传递，形参会修饰实参
	int remove_element(vector<int>& num, int val) {
		//双指针法，一个快一个慢，如果不等于就跳过，等于就覆盖
		int slow = 0, fast;
		for (fast = 0; fast < num.size(); fast++) {
			if (num[fast] != val)
				num[slow++] = num[fast];
		}
		return slow;
	}
	//引用传递，形参会修饰实参
	int order_arry_square(vector<int>& nums) {
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
		
		return i;
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
	vector<vector<int>> generateMatrix(int n) {
		int i, j;
		//使用vector定义一个二维数组
		//首先定义二维数组的行数，有n行
		//vector <vector<int>> arr(n);
		//再定义二维数组的列数
		//vector <vector<int>>arr(n, vector<int>(n));
		//最后可以对二维数组中的元素赋值
		vector <vector<int>>arr(n, vector<int>(n, 0));
		int startx = 0, starty = 0;		//控制每一圈的起始位置
		int offset = 1;
		int count = 1;
		int loop = n / 2;
		while (loop--) {		//控制圈数
				//首先实现行的遍历
				for (j = startx; j < n - offset; j++) {
					arr[startx][j] = count;
					count++;
				}
				//再实现列的遍历
				/*for (i = starty; i < n - offset; i++) {
					arr[i][j] = count;
					count++;
				}
				for (; j > startx; j--) {
					arr[i][j] = count;
					count++;
				}
				for (; i > starty; i--) {
					arr[i][j] = count;
					count++;
				}*/


				//这是我原来写的
				for (i = starty; i < n - offset; i++) {
					arr[i][n-offset] = count;
					count++;
				}
				for (j = n - offset; j > startx; j--) {
					arr[n - offset][j] = count;
					count++;
				}
				//我写的是对的，啊啊啊啊啊啊，只是这里的列条件没有判断对，超
				for (i = n - offset; i > starty; i--) {
					arr[i][starty] = count;
					count++;
				}
				startx++;
				starty++;
				offset++;
			}
			if (n % 2 != 0) {
				arr[n / 2][n / 2] = count;
			}
			return arr;
	}

	//弊端，这种代码再面对海量数据时，时间复杂度极高
	int sectionSum(vector<int>nums,int a,int b) {
		
		int sum = 0;
		for (int i = a; i <= b; i++) {
			sum += nums[i];
		}
		return sum;
	}

	//前缀和思想，再处理大量数据时有用
	int sectionSum_improve(int n,vector<int> p, vector<int> nums) {
		int sum = 0;
		int a, b;
		cout << "请输入数组元素：" << endl;
		//使用另一个数组，一边输入一边求和
		for (int i = 0; i < n; i++) {
			cin >> nums[i];
			sum = sum + nums[i];
			p[i] = sum;
		}
		cout << "请输入区间：" << endl;
		while (cin >> a >> b) {
			if (a == 0)
				cout << p[b];
			else
				cout << p[b] - p[a - 1];
		}
		return 0;
	}

	int purchase_land() {
		//这个题目后续再做
	}
};


struct LNode {
		int data;
		LNode* next;
		LNode(int x) : data(x), next(NULL) {}	//C++要求必须要有这句话
	};	
class MyLinkList{
//private限定_dummyhead只能在此类使用
//_dummyhead是C++里的一种约定
//一定要先声明一下，再使用


public:
	LNode* dummyhead = new LNode(0);
	int size;

	MyLinkList() :size(0) {}

	LNode* createList() {
		LNode* head = nullptr;
		LNode* tail = nullptr;
		int val;
		cout << "请输入链表值：(创建链表，输入-1结束)" << endl;
		while (true) {
			cin >> val;
			if (val == -1)
				break;
			LNode* newNode = new LNode(val);
			if (head == nullptr) {
				head = newNode;
				tail = newNode;
				size++;
			}
			else {
				tail->next = newNode;
				tail = newNode;
				size++;
			}
		}
		return head;
	}
	void printList(LNode* head) {
		if (head == NULL) {
			cout << "链表为空" << endl;
		}
		else {
			LNode* cur = head;
			cout << "链表元素为：" << endl;
			while (cur != NULL) {
				cout << cur->data << ' ';
				cur = cur->next;
			}
			cout << "当前链表长度为：" << size << endl;
		}
	}

	LNode* dropList(LNode* head) {
		LNode* cur = head;
		while (cur != NULL) {
			LNode* temp = cur;
			cur = cur->next;
			delete temp;
		}
		return cur;
	}

	//使用虚拟头节点删除元素
	LNode* remove_element(LNode* head, int val) {
		//设置一个虚拟头节点
		dummyhead->next = head;
		LNode* cur = dummyhead;
		while (cur->next != NULL) {
			if (cur->next->data == val) {
				LNode* tmp = head;
				head = tmp->next;
				delete tmp;
				cur->next = head;
			}
			else {
				cur = head;
				head = head->next;
			}
		}
		head = dummyhead->next;	//复位head
		delete dummyhead;	//删除虚拟头节点
		return head;
	}
	//构造方法，创建虚拟头节点
	//MyLinkList() {
	//	_dummyhead = new LNode(0);
	//}
	LNode* addAtHead(LNode* head) {
		LNode* cur = head;
		int val;
		cout << "请输入插入的值：（头插法，逆序插入，输入-1结束）" << endl;
		while (true) {
			cin >> val;
			if (val == -1)
				break;
			if (cur == nullptr) {
				LNode* newNode = new LNode(val);
				cur = newNode;
				size++;
			}
			else {
				LNode* newNode = new LNode(val);
				dummyhead->next = newNode;
				newNode->next = cur;
				cur = newNode;
				size++;
			}
		}
		cur = dummyhead->next;
		return cur;
	}

	LNode* addAtTail(LNode* head) {
		LNode* cur = head;
		int val;
		cout << "请输入插入的值：（尾插法，顺序插入，输入-1结束）" << endl;
		while (true) {
			cin >> val;
			if (val == -1)
				break;
			if (cur == nullptr) {
				LNode* newNode = new LNode(val);
				cur = newNode;
				dummyhead->next = newNode;
				size++;
			}
			else {
				dummyhead->next = head;
				while (cur->next != NULL) {
					cur = cur->next;
				}
				LNode* newNode = new LNode(val);
				cur->next = newNode;
				size++;
			}
		}
		cur = dummyhead->next;
		return cur;
	}
		
	int get(LNode* cur) {
		int index;
		cout << "请输入查找哪一个：";
		cin >> index;
		dummyhead->next = cur;
		if (index > size || (index <= 0)) {
			cout << -1;
			return 0;
		}
		for (int i = 1; i < index; i++) {
			cur = cur->next;
		}
		cout << cur->data;
		return 0;
	}

	LNode* reverseList(LNode* head) {

	}

	
};

int main() {
	Myarray myarray;
	MyLinkList mylinklist;

	int x;

	cout << "1.二分查找" << endl;
	cout << "2.移除元素" << endl;
	cout << "3.有序数组平方" << endl;
	cout << "4.寻找最小连续子数组" << endl;
	cout << "5.螺旋矩阵" << endl;
	cout << "6.计算区间和" << endl;
	cout << "7.计算区间和(使用前缀和的思想)" << endl;
	cout << "8.开发商购买土地" << endl;
	cout << "9.移除链表元素" << endl;
	cout << "10.设计链表" << endl << "\t---get" << endl << "\t---addAtHead" << endl << "\t---addAtTail"
		<< endl << "\t---addAtIndex" << endl << "\t---deleteAtIndex" << endl;

	cout << "请选择功能：";
	cin >> x;

	switch (x) {
		case 1: {
			vector<int> arry1 = { -1, 0, 3, 5, 9, 12 };
			int target;
			cout << "请输入要查的值：";
			cin >>target;
			int result = myarray.binary_search(arry1, target);
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
			int result = myarray.remove_element(num, val);
			for (int i = 0; i < result; i++)
				cout << num[i] << ' ';
		}
			  break;
		case 3: {
			vector<int> nums = { -7,-3,2,3,11 };
			int result=myarray.order_arry_square(nums);
			for (int i = 0; i < result; i++)
				cout << nums[i] << ' ';
		}
			  break;
		case 4: {
			vector<int> nums = { 2,3,1,2,4,3};
			int s;
			cout << "请输入s:";
			cin >> s;
			int result = myarray.minSubArrayLen(nums, s);
			cout << "长度为：" << result << endl;
		}
			  break;
		case 5: {
			int n;
			cout << "请输入二维数组的大小：";
			cin >> n;
			vector<vector<int>> result = myarray.generateMatrix(n);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++)
					cout << result[i][j] << '\t';
				cout << '\n';
			}
		}
			  break;
		case 6: {
			int n;
			cout << "请输入数组的长度：";
			cin >> n;
			//c++里用（）指定数组长度
			vector<int> nums(n);
			cout << "请输入数组元素：" << endl;
			
			for (int i = 0; i < n; i++)
				cin >> nums[i];

			int a=INT16_MIN, b=INT16_MIN;
			while (1) {
				cout << "请输入计算的区间：" << endl;
				cin >> a >> b;
				int result=myarray.sectionSum(nums, a, b);
				cout << result << endl;
			}
		}
			  break;
		case 7: {
			int n;
			cout << "请输入数组的长度：";
			cin >> n;
			//c++里用（）指定数组长度
			vector<int> nums(n);
			vector<int> p(n, 0);
			myarray.sectionSum_improve(n,nums, p);	
		}
			  break;
		case 8: {
			cout << "功能正在开发中，请稍后再试" << endl;
		}
			  break;
		case 9: {
			int x;
			//现在的L指向没有头节点的单链表第一个结点
			LNode* L = mylinklist.createList();
			mylinklist.printList(L);
			cout << "请输入删除的节点：";
			cin >> x;
			LNode* Lr = mylinklist.remove_element(L, x);
			mylinklist.printList(Lr);
			mylinklist.dropList(Lr);
		}
			  break;
		case 10: {
			LNode* L = mylinklist.createList();	
			mylinklist.printList(L);
			L = mylinklist.addAtHead(L);
			mylinklist.printList(L);
			L = mylinklist.addAtTail(L);
			mylinklist.printList(L);
			mylinklist.get(L);
		}
			   break;
		case 11: {

		}
	}
}