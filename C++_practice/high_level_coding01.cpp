#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//�ü����ѣ�ͷҪը��

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
	//˫ָ���Ƴ�Ԫ�ط�
	//�Ҿ�ֻ����ô��Ϊ�ˣ�return��slow����ָ��remove_element����������һ��Ԫ�أ�	bingo
	//�ش����ô��ݣ��βλ�����ʵ��
	int remove_element(vector<int>& num, int val) {
		//˫ָ�뷨��һ����һ��������������ھ����������ھ͸���
		int slow = 0, fast;
		for (fast = 0; fast < num.size(); fast++) {
			if (num[fast] != val)
				num[slow++] = num[fast];
		}
		return slow;
	}
	//���ô��ݣ��βλ�����ʵ��
	int order_arry_square(vector<int>& nums) {
		int i, len = nums.size(), e, j, t;
		for (i = 0; i < len; i++) {
			e = nums[i];
			nums[i] = e * e;
		}
		//����ð������
		/*for (i = 0; i < len-1; i++) {
			for (j = 0; j < len - 1; j++) {
				if (nums[j] > nums[j + 1]) {
					t = nums[j];
					nums[j] = nums[j + 1];
					nums[j + 1] = t;
				}
			}
		}*/

		//c++ʹ��algorithmͷ�ļ������������,��֪��ͷ�ļ��ﻹ��û�������������㷨
		sort(nums.begin(), nums.end());
		
		return i;
	}

	//�������ڣ�ֻ�������Լ�����дһ��
	int minSubArrayLen(vector<int>& nums, int s) {
		int i = 0, j, len = nums.size(), sum = 0, flag1 = 0, flag2 = 0;
		//��������Ӵ���Ϊ2147483647
		int result = INT32_MAX, subLen;
		for (j = 0; j < len; j++) {
			sum = sum + nums[j];
			//���Ӵ����ȴ���ָ��ֵʱ�Ż���
			while (sum >= s) {
				//�������ַ�������
				subLen = j - i + 1;
				result = result > subLen ? subLen : result;
				flag1 = i; flag2 = j;
				//���ڻ�����ôʵ�֣���ԭ��i��ֵ������������
				sum = sum - nums[i];
				i++;
			}
		}
		cout << "��С��������Ϊ��";
		for (i = flag1; i <= flag2; i++)
			cout << nums[i] << ' ';
		cout << endl;
		//���resultû�б���ֵ���ͷ���0
		//Ҫ�����������������䣬���
		return result == INT32_MAX ? 0 : result;
	}
	//��ά����Ҫ����vector
	vector<vector<int>> generateMatrix(int n) {
		int i, j;
		//ʹ��vector����һ����ά����
		//���ȶ����ά�������������n��
		//vector <vector<int>> arr(n);
		//�ٶ����ά���������
		//vector <vector<int>>arr(n, vector<int>(n));
		//�����ԶԶ�ά�����е�Ԫ�ظ�ֵ
		vector <vector<int>>arr(n, vector<int>(n, 0));
		int startx = 0, starty = 0;		//����ÿһȦ����ʼλ��
		int offset = 1;
		int count = 1;
		int loop = n / 2;
		while (loop--) {		//����Ȧ��
				//����ʵ���еı���
				for (j = startx; j < n - offset; j++) {
					arr[startx][j] = count;
					count++;
				}
				//��ʵ���еı���
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


				//������ԭ��д��
				for (i = starty; i < n - offset; i++) {
					arr[i][n-offset] = count;
					count++;
				}
				for (j = n - offset; j > startx; j--) {
					arr[n - offset][j] = count;
					count++;
				}
				//��д���ǶԵģ���������������ֻ�������������û���ж϶ԣ���
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

	//�׶ˣ����ִ�������Ժ�������ʱ��ʱ�临�Ӷȼ���
	int sectionSum(vector<int>nums,int a,int b) {
		
		int sum = 0;
		for (int i = a; i <= b; i++) {
			sum += nums[i];
		}
		return sum;
	}

	//ǰ׺��˼�룬�ٴ����������ʱ����
	int sectionSum_improve(int n,vector<int> p, vector<int> nums) {
		int sum = 0;
		int a, b;
		cout << "����������Ԫ�أ�" << endl;
		//ʹ����һ�����飬һ������һ�����
		for (int i = 0; i < n; i++) {
			cin >> nums[i];
			sum = sum + nums[i];
			p[i] = sum;
		}
		cout << "���������䣺" << endl;
		while (cin >> a >> b) {
			if (a == 0)
				cout << p[b];
			else
				cout << p[b] - p[a - 1];
		}
		return 0;
	}

	int purchase_land() {
		//�����Ŀ��������
	}
};


struct LNode {
		int data;
		LNode* next;
		LNode(int x) : data(x), next(NULL) {}	//C++Ҫ�����Ҫ����仰
	};	
class MyLinkList{
//private�޶�_dummyheadֻ���ڴ���ʹ��
//_dummyhead��C++���һ��Լ��
//һ��Ҫ������һ�£���ʹ��


public:
	LNode* dummyhead = new LNode(0);
	int size;

	MyLinkList() :size(0) {}

	LNode* createList() {
		LNode* head = nullptr;
		LNode* tail = nullptr;
		int val;
		cout << "����������ֵ��(������������-1����)" << endl;
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
			cout << "����Ϊ��" << endl;
		}
		else {
			LNode* cur = head;
			cout << "����Ԫ��Ϊ��" << endl;
			while (cur != NULL) {
				cout << cur->data << ' ';
				cur = cur->next;
			}
			cout << "��ǰ������Ϊ��" << size << endl;
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

	//ʹ������ͷ�ڵ�ɾ��Ԫ��
	LNode* remove_element(LNode* head, int val) {
		//����һ������ͷ�ڵ�
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
		head = dummyhead->next;	//��λhead
		delete dummyhead;	//ɾ������ͷ�ڵ�
		return head;
	}
	//���췽������������ͷ�ڵ�
	//MyLinkList() {
	//	_dummyhead = new LNode(0);
	//}
	LNode* addAtHead(LNode* head) {
		LNode* cur = head;
		int val;
		cout << "����������ֵ����ͷ�巨��������룬����-1������" << endl;
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
		cout << "����������ֵ����β�巨��˳����룬����-1������" << endl;
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
		cout << "�����������һ����";
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

	cout << "1.���ֲ���" << endl;
	cout << "2.�Ƴ�Ԫ��" << endl;
	cout << "3.��������ƽ��" << endl;
	cout << "4.Ѱ����С����������" << endl;
	cout << "5.��������" << endl;
	cout << "6.���������" << endl;
	cout << "7.���������(ʹ��ǰ׺�͵�˼��)" << endl;
	cout << "8.�����̹�������" << endl;
	cout << "9.�Ƴ�����Ԫ��" << endl;
	cout << "10.�������" << endl << "\t---get" << endl << "\t---addAtHead" << endl << "\t---addAtTail"
		<< endl << "\t---addAtIndex" << endl << "\t---deleteAtIndex" << endl;

	cout << "��ѡ���ܣ�";
	cin >> x;

	switch (x) {
		case 1: {
			vector<int> arry1 = { -1, 0, 3, 5, 9, 12 };
			int target;
			cout << "������Ҫ���ֵ��";
			cin >>target;
			int result = myarray.binary_search(arry1, target);
			if (result == -1) {
				cout << result << endl;
				cout << target << "���������з���" << -1;
			}
			else {
				cout << result << endl;
				cout << target << "�������������±�Ϊ" << result << endl;
			}
		}
			  break;
		case 2: {
			vector <int>num = { 0,1,2,2,3,0,4,2 };
			int val;
			cout << "������Ҫɾ��ֵ��";
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
			cout << "������s:";
			cin >> s;
			int result = myarray.minSubArrayLen(nums, s);
			cout << "����Ϊ��" << result << endl;
		}
			  break;
		case 5: {
			int n;
			cout << "�������ά����Ĵ�С��";
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
			cout << "����������ĳ��ȣ�";
			cin >> n;
			//c++���ã���ָ�����鳤��
			vector<int> nums(n);
			cout << "����������Ԫ�أ�" << endl;
			
			for (int i = 0; i < n; i++)
				cin >> nums[i];

			int a=INT16_MIN, b=INT16_MIN;
			while (1) {
				cout << "�������������䣺" << endl;
				cin >> a >> b;
				int result=myarray.sectionSum(nums, a, b);
				cout << result << endl;
			}
		}
			  break;
		case 7: {
			int n;
			cout << "����������ĳ��ȣ�";
			cin >> n;
			//c++���ã���ָ�����鳤��
			vector<int> nums(n);
			vector<int> p(n, 0);
			myarray.sectionSum_improve(n,nums, p);	
		}
			  break;
		case 8: {
			cout << "�������ڿ����У����Ժ�����" << endl;
		}
			  break;
		case 9: {
			int x;
			//���ڵ�Lָ��û��ͷ�ڵ�ĵ������һ�����
			LNode* L = mylinklist.createList();
			mylinklist.printList(L);
			cout << "������ɾ���Ľڵ㣺";
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