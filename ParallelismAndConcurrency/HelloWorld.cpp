#include <thread>
#include <iostream>

using std::cout;
using std::endl;

void HelloWorld() {
	std::thread::id this_id = std::this_thread::get_id();
	cout << "'Hello World' ran from this: " << this_id << " thread\n" << endl;
}

//int main() {
//	std::thread t1(HelloWorld);
//	std::thread t2(HelloWorld);
//
//	t1.join();
//	t2.join();
//
//	return 0;
//}