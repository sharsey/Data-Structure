#include "Linked_list.h"

int main() {
	Linked_list<int> lk;
	lk.insert_end(5);
	lk.insert_end(3);
	lk.insert_end(4);
	lk.insert_end(2);
	lk.insert_end(1);
	lk.insert_end(7);
	lk.insert_end(8);
	lk.insert_end(9);
	lk.insert_start(56);
	lk.delete_element(9);
	float sum = 0;
	int index;
	lk.functional([&sum, &index](int data, int i) {
		sum += data;
		index = i;
	});
	float promedio = sum / (index + 1);
	std::cout <<index<<" " << promedio << std::endl;
	lk.print();
}