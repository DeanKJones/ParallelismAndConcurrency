#include <iostream>
#include <thread>

//using std::cout;
//using std::endl;
//
///* Operator */
//class Task {
//public:
//	void operator()() const {
//		doSomething();
//		doSomethingElse();
//	}
//private:
//	void doSomething() const {
//		cout << "Done Something" << endl;
//	}
//
//	void doSomethingElse() const {
//		cout << "Done Something Else" << endl;
//	}
//};
//
///* Do Fuction */
//void doFunction() {
//	cout << "Function" << endl;
//}
//
//int foo() {
//	/* Thread with a class that implements () operator 
//	 * Uses rvalue */
//	std::thread t0{ Task() };
//
//	/* Thread with lambda */
//	std::thread t1([] {
//			doFunction();
//		});
//
//	/* Launch several times your program to remark the order is not deterministic */
//
//	t0.join();
//	t1.join();
//	return 0;
//}