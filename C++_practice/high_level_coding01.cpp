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
	///
	LNode* reverseList(LNode* head) {
		//����һ��ָ��洢λ�ã���ָ���ͷ�ڵ㿪ʼ
		//ʹ������ָ��������
		LNode* left = NULL;
		LNode* right = head;
		LNode* temp;
		while (right != NULL) {
			temp = right->next;
			//left->next = NULL;
			right->next = left;
			left = right;
			right = temp;
		}
		return left;
	}
	/// <summary>
	/// ��ĺü����Ѱ�������һ������һ����
	/// </summary>
	LNode* swapPairs(LNode* head) {
		
		dummyhead->next = head;
		LNode* cur = dummyhead;
		while (cur->next != NULL && cur->next->next != NULL) {
			//cur->next != NULL����Ҫ��cur->next->next != NULLǰ�棬������п�ָ�뱨��
			//ʹ�ö��ָ����Ȼ�ܲ������㣬���Ǽ�Ϊ���������׻�������ָ���λ��
			//���ڵ���Ϊż����������ʱ����ֹ����
			//��ǰ���ڽڵ�ĺ����������ǿ�
			//temp1����洢�ڵ�
			LNode* temp1 = cur->next;
			//temp2���������ڵ�
			LNode* temp2 = cur->next->next->next;

			//������δ��룬�������ֽ�ϻ�һ���������������
			cur->next = cur->next->next;
			cur->next->next = temp1;
			temp1->next = temp2;
			cur = cur->next->next;
		}
		head = dummyhead->next;
		return head;
	}

	LNode* removeNthFromEnd(LNode* head, int val) {
		//ɾ��������val���ڵ����ɾ����  length-val+1 ���ڵ�
		//��ʱ֪������ĳ���
		//�����֪�����ȵĻ����һ�����һ�������ȣ�����ʱ�临�ӶȺܸ���
		/*
		int count = size - val + 1;
		dummyhead->next = head;
		LNode* cur = dummyhead;
		if (head == NULL|| head->next == NULL) {
			head = NULL;
			return head;
		}

		for (int i = 1; i < count; i++) {
			cur = cur->next;
		}
		cur->next = cur->next->next;
		cur = dummyhead->next;
		return cur;
		*/

		//��ʱ��֪������ĳ���
		//ʹ����ָ���ߵ�Ҫɾ��Ԫ�صĶԳ�λ��
		//�ǳ�����
		dummyhead->next = head;
		LNode* left = dummyhead;
		LNode* right = dummyhead;
		if (head == NULL)
			return head;

		while (val-- && right != NULL)	//����ָ���ƶ�����ɾ��Ԫ�صĶԳ�λ��
			right = right->next;

		right = right->next;	//��ʱҪ�ټ����ƶ�һ�Σ�������ָ���ƶ���Ҫɾ��Ԫ�ص�ǰһ��λ��

		while (right != NULL) {
			left = left->next;
			right = right->next;
		}

		left->next = left->next->next;	//ɾ��Ԫ��

		return dummyhead->next;
	}

	int getIntersectionNode(LNode* headA, LNode* headB) {
		//���������������ܵ���createlist��������������Ϊ�����������ڴ治��ͬ����Զ�������ཻ
	
		int lenA = 0, lenB = 0;
		LNode* curA = headA;
		LNode* curB = headB;

		//������һ����������ĳ���
		while (curA != NULL) {
			lenA++;
			curA = curA->next;
		}
		while (curB != NULL) {
			lenB++;
			curB = curB->next;
		}

		curA = headA;
		curB = headB;

		//����̫������
		/*if (lenA == lenB) {
			while (curA != NULL) {
				if (curA == curB) {
					return curA->data;
				}
				curA = curA->next;
				curB = curB->next;
			}
			return NULL;
		}
		
		if (lenA > lenB) {
			for (int i = 1; i <= lenA - lenB; i++) {
				curA = curA->next;
			}
			while (curA != NULL) {
				if (curA == curB) {
					return curA->data;
				}
				curA = curA->next;
				curB = curB->next;
			}
			return NULL;
		}

		if (lenA < lenB) {
			for (int i = 1; i <= lenB - lenA; i++) {
				curB = curB->next;
			}
			while (curA != NULL) {
				if (curA == curB) {
					return curA->data;
				}
				curA = curA->next;
				curB = curB->next;
			}
			return NULL;
		}*/

		//�򻯲���
		//ʼ����curAָ�����
		if (lenB > lenA) {
			swap(lenA, lenB);
			swap(curA, curB);
		}
		for (int i = 1; i <= lenA - lenB; i++)
			curA = curA->next;
		while (curA != NULL) {
			if (curA == curB) {
				return curA->data;
			}
			curA = curA->next;
			curB = curB->next;
		}
		return NULL;

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
	cout << "11.��ת����" << endl;
	cout << "12.������������ֵ" << endl;
	cout << "13.ɾ����������n���ڵ�" << endl;
	cout << "14.Ѱ������������ཻ�ڵ�" << endl;

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
			LNode* L = mylinklist.createList();
			L=mylinklist.reverseList(L);
			mylinklist.printList(L);
		}
			   break;
		case 12: {
			LNode* L = mylinklist.createList();
			L = mylinklist.swapPairs(L);
			mylinklist.printList(L);
		}
			   break;
		case 13: {
			int val;
			LNode* L = mylinklist.createList();
			mylinklist.printList(L);
			cout << "ɾ�������ڼ����ڵ㣺";
			cin >> val;
			L = mylinklist.removeNthFromEnd(L, val);
			mylinklist.printList(L);
		}
			   break;
		case 14: {

			//��������A
			//LNode* headA = new LNode(0);
			//headA->next = new LNode(9);
			//headA->next->next = new LNode(1);
			//headA->next->next->next = new LNode(2);
			//headA->next->next->next->next = new LNode(4);

			////��������B
			//LNode* headB = new LNode(3);
			//headB->next = headA->next->next->next;  // ����B��3��ʼ������A�ཻ

			LNode* headB = new LNode(5);
			headB->next = new LNode(0);
			headB->next->next = new LNode(1);
			headB->next->next->next = new LNode(8);
			headB->next->next->next->next = new LNode(4);
			headB->next->next->next->next->next = new LNode(5);

			LNode* headA = new LNode(4);
			headA->next = new LNode(1);
			headA->next->next = headB->next->next->next;

			int result = mylinklist.getIntersectionNode(headA, headB);

			cout << "����������ཻ�ڵ��ǣ�" << result << endl;
		}
	}
}