#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void DoWork() {
	for (size_t i = 0; i < 10; i++)
	{
		this_thread::sleep_for(chrono::milliseconds(250));
		cout << "Thread id: " << this_thread::get_id() << "\tDoWork\t" << i << endl;
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");

	/*if (argc > 1)
		cout << argc << endl;
	else
		cout << "Not arguments" << endl;*/

	thread th(DoWork);
	thread th2(DoWork);

	//th.detach(); //Выполняется самостоятельно, не учитывает другой поток (из main)
	
	for (size_t i = 0; i < 10; i++)
	{
		this_thread::sleep_for(chrono::milliseconds(100));
		cout << "Thread id: " << this_thread::get_id() << "\tmain\t" << i << endl;
	}

	th.join(); //Дождаться выполнения (где хотим дождаться выполнения потока)
	//Произойдет блокировка основного потока
	th2.join();
	return 0;
}