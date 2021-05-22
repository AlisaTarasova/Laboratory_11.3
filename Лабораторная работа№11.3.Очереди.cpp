#include <iostream>
#include <queue>
using namespace std;
queue <double> Turn2;
queue <double> TurnSTL;

struct QueueItem
{
	int data;
	QueueItem* prev;
};

struct Queue
{
	QueueItem* front;
	QueueItem* back;
};

QueueItem* newItem(int element)
{
	QueueItem* newElement = new QueueItem;
	newElement->data = element;
	newElement->prev = 0;
	return newElement;
}

void push(Queue** queue, int element)
{
	QueueItem* newElement = newItem(element);
	(*queue)->back->prev = newElement;
	(*queue)->back = newElement;
	if (!(*queue)->front) {
		(*queue)->front = newElement;
	}
}

int pop(Queue** queue)
{
	int el = (*queue)->front->data;
	QueueItem* rem = (*queue)->front;
	(*queue)->front = (*queue)->front->prev;
	delete rem;
	return el;
}

Queue* make_queue(int size)
{
	int tmp;
	Queue* queue = new Queue;
	cout<< "Введите элемент 1: ";
	cin >> tmp;

	QueueItem* item = newItem(tmp);
	queue->front = item;
	queue->back = item;

	for (int i = 2; i <= size; i++)
	{
		cout<< "Введите элемент " << i << ": ";
		cin >> tmp;
		push(&queue, tmp);
	}
	return queue;
}

void Print1(Queue*& queue)
{
	if (!queue->front) {
		cout << "Стек пустой" << endl;
		return;
	}
	vector<int> copy = vector<int>();
	while (queue->front)
	{
		copy.push_back(pop(&queue));
	}
	for (int i = 0; i < copy.size(); i++) {
		cout << copy[i] << " ";
		push(&queue, copy[i]);
	}
	cout << endl;
}

void DeleteEl(Queue*& queue)
{
	if (!queue->front)
	{
		cout << "Стек пустой" << endl;
		return;
	}

	vector<int> copy = vector<int>();
	int item;
	while (queue->front)
	{
		item = pop(&queue);
		if (item >= 0) {
			copy.push_back(item);
		}
	}
	for (int i = 0; i < copy.size(); i++) {
		push(&queue, copy[i]);
	}
}


	

//////////////////////////////////////////////////////////////////////////////

void Vvod2(int n2)
{
	double a;
	for (int i = 1; i <= n2; i++)
	{
		cout << "Введите " <<i<< " элемент очереди: ";
		cin >> a;
		Turn2.push(a);
	}
}

void Print2(int n2)
{
	for (int i = 1; i <= n2; i++)
	{
		cout << Turn2.front() << "\t";
		TurnSTL.push(Turn2.front());
		Turn2.pop();
	}
	cout << endl;
}

void Deleting2(int n2)
{
	while (TurnSTL.size() != 0)
	{
		if (TurnSTL.front() < 0)
		{
			TurnSTL.pop();
		}
		else
		{
			Turn2.push(TurnSTL.front());
			TurnSTL.pop();
		}
	}
	while (Turn2.size() != 0)
	{
		cout << Turn2.front() << "\t";
		Turn2.pop();
	}
}

int main()

{
	setlocale(0, "");
	system("color F0");

	cout << "РЕАЛИЗАЦИЯ ЧЕРЕЗ СТРУКТУРЫ: " << endl;

	int k = 0;
	int n1 = 0;
	while (n1 <= 0)
	{
		cout << "Введите размер очреди: ";
		cin >> n1;
	}

	Queue* st3 = make_queue(n1);
	cout<<"Начальная очередь: ";
	Print1(st3);
	DeleteEl(st3);
	cout << "Итоговая очередь: ";
	Print1(st3);

	/////////////////////////////////////////////////////////////////

	cout <<endl<< "РЕАЛИЗАЦИЯ ЧЕРЕЗ БИБЛИОТЕКИ STL: " << endl;

	int n2 = 0;
	while (n2 <= 0)
	{
		cout << "Введите размер очереди: ";
		cin >> n2;
	}

	Vvod2(n2);

	cout << "Начальная очередь: ";
	Print2(n2);

	cout << "Итоговая очередь: ";
	Deleting2(n2);

	return 0;
}
