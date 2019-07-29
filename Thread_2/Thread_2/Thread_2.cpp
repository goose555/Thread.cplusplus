#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void DoWork(int a, int b) {
		this_thread::sleep_for(chrono::milliseconds(3000));

		cout << "=========\t" << __FUNCTION__ << " STARTED\t=========" << endl;

		this_thread::sleep_for(chrono::milliseconds(5000));

		cout << "a + b = " << a + b << endl;

		this_thread::sleep_for(chrono::milliseconds(3000));

		cout << "=========\t" << __FUNCTION__ << " STOPPED\t=========" << endl;

}

int main(int argc, char* argv[])
{
	thread th(DoWork, 2, 3);

	for (size_t i = 0; i < 10; i++)
	{
		cout << "id thread = " << this_thread::get_id() << "\t" << __FUNCTION__ << " works" << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));
	}

	th.join();
	return 0;
}