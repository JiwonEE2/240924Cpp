/*
- singleton
�� ���� �� ���� �ν��Ͻ����� ������ ����
�� �� �ƹ��� ���� ��ü�� �����ص� �� �ϳ��� �ν��Ͻ����� ������ �Ͱ� ����
�� Ŭ������ ��ü�� ���簡 �Ǹ� X.

���ҽ� ����
����. ������� ��������� �����׽�Ʈ(�����׽�Ʈ)�������
*/
#include<iostream>
using namespace std;

class Singleton {
	// �ܺο��� ���� �Ұ����ϵ��� ��õ ����
	Singleton() {
		cout << "�̱��� �ν��Ͻ� ����\n";
	}
	~Singleton() {}

	// ��������ڿ� ���Կ����� ���(���� �� ���� �ν��Ͻ��� ���� ����)
	Singleton(const Singleton&) = delete;				// ���������
	Singleton& operator=(const Singleton&) = delete;	// ���Կ�����
public:
	// �̱��� ��ü�� ��ȯ�ϴ� ��������Լ�
	static Singleton& GetInstance() {
		static Singleton inst;
		return inst;
	}

	void Print() {
		cout << "���� ��Ŭ��\n";
	}
};

int main() {
	Singleton& s1 = Singleton::GetInstance();
	s1.Print();

	Singleton& s2 = Singleton::GetInstance();
	s2.Print();

	if (&s1 == &s2) {
		cout << "���ƿ�\n";
	}
}