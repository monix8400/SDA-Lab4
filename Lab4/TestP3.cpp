#include <assert.h>
#include "PriorityQueue.h"
#include "TestP3.h"
#include <vector>
#include <exception>
#include <iostream>

using namespace std;

bool rel2(TPriority p1, TPriority p2) {
	if (p1 <= p2) {
		return true;
	}
	else {
		return false;
	}
}


void testCreate() {
	cout <<"1.TestCreate "<<endl;
	PriorityQueue pq(rel2);
	assert(pq.isEmpty() == true);
	try {
		pq.top(); //if it is empty it should throw an exception
		assert(false); //if it did not throw an exception the assert will fail
	}
	catch (exception&) {
		assert(true);
	}
	try {
		pq.pop(); //if it is empty it should throw an exception
		assert(false); //if it did not throw an exception the assert will fail
	}
	catch (exception&) {
		assert(true);
	}
}

void testAdd() {
	cout <<"2.TestAdd "<<endl;
	PriorityQueue pq(rel2);
	for (int i = 0; i < 10; i++) {
		pq.push(i, i);
	}
	assert(pq.isEmpty() == false);
	for (int i = -10; i < 20; i++) {
		pq.push(i, i);
	}
	assert(pq.isEmpty() == false);
	for (int i = -100; i < 100; i++) {
		pq.push(i, i);
	}
	assert(pq.isEmpty() == false);
	
	for (int i = -1000; i <= 1000; i++) {
		pq.push(i, i);
	}
	assert(pq.isEmpty() == false);
	assert(pq.top().second != 1000);
	assert(pq.top().second == -1000);

	assert(pq.pop().second == -1000);
	assert(pq.top().second == -999);
}

void testRemove() {
	cout <<"3.TestRemove "<<endl;
	PriorityQueue pq(rel2);
	for (int i = 0; i < 10; i++) {
		pq.push(i, i);
	}
	assert(pq.top().second == 0);
	assert(pq.isEmpty() == false);
	for (int i = -10; i < 20; i++) {
		pq.push(i, i);
	}
	assert(pq.top().second == -10);
	for (int i = 100; i > 50; i--) {
		pq.push(i, i);
	}
	assert(pq.top().second == -10);

	//the elements are given in the order of their priority
	for (int i = -10; i < 0; i++) {
		assert(pq.pop().second == i);
	}
	for (int i = 0; i < 10; i++) {
		assert(pq.pop().second == i);
		assert(pq.pop().second == i);
	}
	for (int i = 10; i < 20; i++) {
		assert(pq.pop().second == i);
	}
	for (int i = 51; i <= 100; i++) {
		assert(pq.pop().second == i);
	}
	assert(pq.isEmpty() == true);
}

void testQuantity() {//add a lot of elements 
	cout <<"4.TestQuantity "<<endl;
	PriorityQueue pq(rel2);
	for (int i = 1; i <= 100; i++) {
		for (int j = 3000; j >= -3000; j --) {
			pq.push(j, j);
		}
	}

	for (int i = -3000; i <= 3000; i++) {
		for (int j = 1; j <= 100; j++) {
			assert(pq.pop().second == i);
		}
	}
}

void testP3() {
	
	testCreate();
	cout <<"Done" << endl;
	
	testAdd();
	cout <<"Done" << endl;
	
	testRemove(); 
	cout <<"Done" << endl;
	
	testQuantity();
	cout <<"Done"<< endl;
	cout << "ALL DONE <3" << endl;
}