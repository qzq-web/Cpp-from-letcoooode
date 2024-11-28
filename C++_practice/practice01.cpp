#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

void base01() {
	//单行注释
	/*多行注释*/

	char c1 = 'a';
	char c2[] = "张晓东";
	string c3 = "哈拉少";
	cout << "字符a所占的空间为" << sizeof(c1) << endl;
	cout << "字符串所占空间为" << sizeof(c2) << endl;
	cout << sizeof(c3) << endl;
}

void base02() {
	int x1 = 0;
	string c1;
	cout << "请输入数字" << endl;
	cin >> x1;
	cout << "现在的值为" << x1 << endl;
	cout << "请输入字符：" << endl;
	cin >> c1;
	cout << "现在的字符为：" << c1 << endl;
}

void compare_three_num() {
	int a, b, c, max;
	cout << "请输入第一个数字：" << endl;
	cin >> a;
	cout << "请输入第二个数字：" << endl;
	cin >> b;
	cout << "请输入第三个数字：" << endl;
	cin >> c;
	max = a > b ? (a > c ? a : c) : (b > c ? b : c);
	cout << "最大值为：" << max << endl;

	/*if (a > b) {
		if (a > c)
			cout << "最大值为:" << a << endl;
		else
			cout << "最大值为:" << c << endl;
	}
	else {
		if (b > c)
			cout << "最=最大值为:" << b << endl;
		else
			cout << "最大值为" << c << endl;
	}*/
}

void guess_num() {
	//srand保证每次生成的随机数都不一样
	srand(time(0));
	//取模101保证在1-100内
	int x = rand() % (101);
	int n;
	cout << "请输入您猜想的数字：" << endl;
	cin >> n;
	while (n != x) {
		if (n > x) {
			cout << "猜大了,请输入" << endl;
			cin >> n;
		}
		else {
			cout << "猜小了，请输入" << endl;
			cin >> n;
		}
	}
	cout << "恭喜，猜中了" << endl;
}

void shuixianhua() {
	//我勒个清朝老题啊
	int a, b, c, sum,i;
	for (i = 100; i <= 999; i++) {
		a = i / 100;  //个位
		b = (i / 10) % 10;   //十位
		c = i % 10;   //百位
		sum = a * a * a + b * b * b + c * c * c;
		if (sum == i)
			cout << i << endl;
	}
}

void GOTO() {
	cout << 1 << endl;
	cout << 1 << endl;
	goto FLAG;
	cout << 1 << endl;
	cout << 1 << endl;
FLAG:
	cout << 2 << endl;
}

void Array() {
	int array1[] = { 1,2,3,4,5 };
	cout << sizeof(array1) << endl;
	cout << sizeof(array1[0]) << endl;
	cout << array1 << endl;
}

void Reverse_num() {
	int array1[] = { 5,1,8,2,0,7,3,4,10,3 }, t;
	int len = sizeof(array1) / sizeof(array1[0]) - 1;
	for (int i = 0; i <= len/2; i++) {
		t = array1[i];
		array1[i] = array1[len - i];
		array1[len-i] = t;
	}
	cout << "逆置后的元素为：";
	for (int i = 0; i <= len; i++)
		cout << array1[i] << ' ';
}

//真几把难搞啊C语言
void bubble_sort() {
	int arry[] = { -1034,9,8245,7,456,5389,4,-33214,2,0.678 }, i, j, t;
	int len = sizeof(arry) / sizeof(arry[0]);
	for (i = 0; i < len - 1; i++) {
		for (j = 0; j < len - i - 1; j++) {
			if (arry[j] > arry[j + 1]) {
				t = arry[j];
				arry[j] = arry[j + 1];
				arry[j + 1] = t;
			}
		}
	}
	cout << "排序后为:";
	for (i = 0; i < len; i++)
		cout << arry[i] << ' ';
}

int main() {
	int x;
	
	cout << "1.基本操作01" << endl;
	cout << "2.基本操作02" << endl;
	cout << "3.三个数字比大小" << endl;
	cout << "4.猜数字（100以内）" << endl;
	cout << "5.水仙花数" << endl;
	cout << "6.goto语句" << endl;
	cout << "7.数组" << endl;
	cout << "8.元素逆置" << endl;
	cout << "9.冒泡排序" << endl;


	cout << "请选择使用的函数:\n" << endl;
	cin >> x;
	if (x == 1) base01();
	if (x == 2) base02();
	if (x == 3) compare_three_num();
	if (x == 4) guess_num();
	if (x == 5) shuixianhua();
	if (x == 6) GOTO();
	if (x == 7) Array();
	if (x == 8) Reverse_num();
	if (x == 9) bubble_sort();

	system("pause");

	return 0;
}