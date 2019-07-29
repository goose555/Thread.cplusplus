#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void DoWork(int &a) {
	this_thread::sleep_for(chrono::milliseconds(2000));

	cout << "id thread = " << this_thread::get_id() << " ===========\t" << __FUNCTION__ << " STARTED \t=========" << endl;

	this_thread::sleep_for(chrono::milliseconds(5000));

	a *= 2;
	
	cout << "id thread = " << this_thread::get_id() << " =========== \t" << __FUNCTION__ << " STOPPED \t=========" << endl;
}

int main()
{
	//thread t(Sum, 1, 2);

	int q = 5;

	thread t(DoWork, std::ref(q));
	t.detach();

	for (size_t i = 0; true; i++)
	{
		cout << "id thread = " << this_thread::get_id() << "\tmain works\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}
    
	//t.join();
	cout << q << endl;

	return 0;
}
