#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

void base01() {
	//����ע��
	/*����ע��*/

	char c1 = 'a';
	char c2[] = "������";
	string c3 = "������";
	cout << "�ַ�a��ռ�Ŀռ�Ϊ" << sizeof(c1) << endl;
	cout << "�ַ�����ռ�ռ�Ϊ" << sizeof(c2) << endl;
	cout << sizeof(c3) << endl;
}

void base02() {
	int x1 = 0;
	string c1;
	cout << "����������" << endl;
	cin >> x1;
	cout << "���ڵ�ֵΪ" << x1 << endl;
	cout << "�������ַ���" << endl;
	cin >> c1;
	cout << "���ڵ��ַ�Ϊ��" << c1 << endl;
}

void compare_three_num() {
	int a, b, c, max;
	cout << "�������һ�����֣�" << endl;
	cin >> a;
	cout << "������ڶ������֣�" << endl;
	cin >> b;
	cout << "��������������֣�" << endl;
	cin >> c;
	max = a > b ? (a > c ? a : c) : (b > c ? b : c);
	cout << "���ֵΪ��" << max << endl;

	/*if (a > b) {
		if (a > c)
			cout << "���ֵΪ:" << a << endl;
		else
			cout << "���ֵΪ:" << c << endl;
	}
	else {
		if (b > c)
			cout << "��=���ֵΪ:" << b << endl;
		else
			cout << "���ֵΪ" << c << endl;
	}*/
}

void guess_num() {
	//srand��֤ÿ�����ɵ����������һ��
	srand(time(0));
	//ȡģ101��֤��1-100��
	int x = rand() % (101);
	int n;
	cout << "����������������֣�" << endl;
	cin >> n;
	while (n != x) {
		if (n > x) {
			cout << "�´���,������" << endl;
			cin >> n;
		}
		else {
			cout << "��С�ˣ�������" << endl;
			cin >> n;
		}
	}
	cout << "��ϲ��������" << endl;
}

void shuixianhua() {
	//���ո��峯���Ⱑ
	int a, b, c, sum,i;
	for (i = 100; i <= 999; i++) {
		a = i / 100;  //��λ
		b = (i / 10) % 10;   //ʮλ
		c = i % 10;   //��λ
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

int main() {
	int x;
	
	cout << "1.��������01" << endl;
	cout << "2.��������02" << endl;
	cout << "3.�������ֱȴ�С" << endl;
	cout << "4.�����֣�100���ڣ�" << endl;
	cout << "5.ˮ�ɻ���" << endl;
	cout << "6.goto���" << endl;
	cout << "7.����" << endl;

	cout << "��ѡ��ʹ�õĺ���:\n" << endl;
	cin >> x;
	if (x == 1) base01();
	if (x == 2) base02();
	if (x == 3) compare_three_num();
	if (x == 4) guess_num();
	if (x == 5) shuixianhua();
	if (x == 6) GOTO();
	if (x == 7) Array();

	system("pause");

	return 0;
}