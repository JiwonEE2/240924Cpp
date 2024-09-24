#pragma once

template<typename T>
class CSingleton {
protected:
	CSingleton() {}
	~CSingleton() {}
public:
	static T& GetInstance() {
		static T inst;
		return inst;
	}
	// ����
	CSingleton(const CSingleton&) = delete;
	void operator=(const CSingleton&) = delete;
};