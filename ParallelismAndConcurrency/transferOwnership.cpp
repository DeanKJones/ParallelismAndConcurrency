#include <thread>
#include <vector>

//void someFunction();
//void someOtherFunction();
//
//std::thread t0(someFunction);
//std::thread t1 = std::move(t1);
//
//t1 = std::thread(someOtherFunction);
//
//std::thread t3;
//
//t3 = std::move(t2);
//t1 = std::move(t3);		// Terminates t1
//
//
///* Move support in std::thread also allows for containers of std::thread objects
//*  If these containers are move-aware */
//void doWork(unsigned id);
//void f() {
//	std::vector<std::thread> threads;
//	for (unsigned i = 0; i < 20; ++i) {
//		threads.emplace_back(doWork, i);
//	}
//	for (auto& entry : threads) {
//		entry.join();		// Wait for the threads to end
//	}
//}