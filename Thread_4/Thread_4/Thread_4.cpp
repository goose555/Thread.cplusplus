#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int Sum(int a, int b) {
	this_thread::sleep_for(chrono::milliseconds(2000));

	cout << "id thread = " << this_thread::get_id() << " ===========\t" << __FUNCTION__ << " STARTED \t=========" << endl;

	this_thread::sleep_for(chrono::milliseconds(5000));

	cout << "id thread = " << this_thread::get_id() << " =========== \t" << __FUNCTION__ << " STOPPED \t=========" << endl;
	return a + b;
}

int main()
{
	int result;
	//cout << "Sum results = " << result << endl;

	thread t([&result]() 
	{ 
		result = Sum(2, 5); 
	});

	for (size_t i = 0; true; i++)
	{
		cout << "id thread = " << this_thread::get_id() << "\tmain works\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	t.join();
	cout << result << endl;


	return 0;
}
