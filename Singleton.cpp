/*
- singleton
ㄴ 오직 한 개의 인스턴스만을 갖도록 보장
ㄴ 즉 아무리 많은 객체를 생성해도 단 하나의 인스턴스만을 생성한 것과 같다
ㄴ 클래스의 객체가 복사가 되면 X.

리소스 절약
전역. 디버깅이 어려워지며 유닛테스트(단위테스트)어려워짐
*/
#include<iostream>
using namespace std;

class Singleton {
	// 외부에서 접근 불가능하도록 원천 차단
	Singleton() {
		cout << "싱글톤 인스턴스 생성\n";
	}
	~Singleton() {}

	// 복사생성자와 대입연산자 방어(오직 한 개의 인스턴스를 갖기 위해)
	Singleton(const Singleton&) = delete;				// 복사생성자
	Singleton& operator=(const Singleton&) = delete;	// 대입연산자
public:
	// 싱글톤 객체를 반환하는 정적멤버함수
	static Singleton& GetInstance() {
		static Singleton inst;
		return inst;
	}

	void Print() {
		cout << "나는 싱클톤\n";
	}
};

int main() {
	Singleton& s1 = Singleton::GetInstance();
	s1.Print();

	Singleton& s2 = Singleton::GetInstance();
	s2.Print();

	if (&s1 == &s2) {
		cout << "같아요\n";
	}
}