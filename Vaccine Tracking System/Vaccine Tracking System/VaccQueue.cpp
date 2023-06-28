#include "VaccQueue.h"

VaccQueue::VaccQueue()
{
	size = 3;
	count = 0;
	front = 0;
	back = 0;
	wait_arr = new int[size];
}


int VaccQueue::Length()
{
	return count;
}


void VaccQueue::enqueue(int ID)
{
	if (isfull())
		extend();
	wait_arr[count] = ID;
	back = (back + 1) % size;
	count++;
	wait_list_num = back;
}


void VaccQueue::dequeue()
{
	if (!isempty())
	{
		front = (front + 1) % size;
		count--;
	}
}


int VaccQueue::Front()
{
	if (!isempty())
		return wait_arr[front];
}


bool VaccQueue::isempty()
{
	return (count == 0);
}

int VaccQueue::Qnum()
{
	wait_list_num = wait_list_num + 1;
	return wait_list_num;
}

bool VaccQueue::isfull()
{
	return (count == size);
}

void VaccQueue::vacdisplayall()
{
	int temp = front;
	cout << "Waiting list contains:" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << i + 1 << "- " << wait_arr[temp] << endl;
		temp = (temp + 1) % size;
	}

}

int VaccQueue::Rfront()
{
	return front;
}

void VaccQueue::extend()
{
	int* arr2 = new int[size * 2];
	for (int i = 0; i < size; i++)
	{
		arr2[i] = wait_arr[i];
	}
	size *= 2;
	delete[] wait_arr;
	wait_arr = arr2;
}

VaccQueue::~VaccQueue()
{
	delete[] wait_arr;
}