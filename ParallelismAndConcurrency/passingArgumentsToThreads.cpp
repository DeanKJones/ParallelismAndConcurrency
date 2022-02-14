#include <string>
#include <thread>

/* Simple Example */
//void f(int i, std::string const& s);
//std::thread t(f, 3, "hello");		// string is converted to std::string in the context of the thread
//
//
///* If the function requires a reference */
//void updateDataForWidget(WidgetId w, WidgetData& data);
//
//void foo(WidgetId w) {
//	WidgetData data;
//
//	std::thread t0(updateDataForWidget, w, data);				// Function expects a non-const ref
//	std::thread t1(updateDataForWidget, w, std::ref(data));		// Force the use of reference
//
//	displayStatus();
//	t.join();
//	processWidgetData(data);
//}

// Since arguments can be passed as rvalues, std::move() can be passed as an argument