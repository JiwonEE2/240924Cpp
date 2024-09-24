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
	// ¸·±â
	CSingleton(const CSingleton&) = delete;
	void operator=(const CSingleton&) = delete;
};