#include <iostream>
#include <thread>

//using std::cout;
//using std::endl;
//
//class RepeatQuickly {
//public:
//	int& param;
//	RepeatQuickly(int& paramP) : param(paramP) {}
//
//	void doSomething(int& p) {
//		cout << p << endl;
//	}
//
//	void operator()() {
//		for (int j = 0; j < 100000; ++j) {
//			doSomething(param);
//		}
//	}
//};
//
//int foo() {
//	/* Error with variable that get out of scope while the thread uses it */
//	int localParam = 0;
//	RepeatQuickly repeatQuickly(localParam);
//	std::thread t2(repeatQuickly);
//	t2.detach();
//
//	return 0;
//}