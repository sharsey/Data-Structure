#pragma once
#include <iostream>
#include <functional>
template<class T>
class Nodo
{
public:
	Nodo();
	Nodo(T, Nodo* next = nullptr);
	Nodo* get_next();
	void set_next(Nodo*);
	T get_data();
	void set_data(T);
private:
	T data;
	Nodo* next;
};

template <class T>
Nodo<T>::Nodo()
{
	data = nullptr;
	next = nullptr;
}

template <class T>
Nodo<T>::Nodo(T _data, Nodo* _next) {
	data = _data;
	next = _next;
}

template <class T>
Nodo<T>* Nodo<T>::get_next() {
	return next;
}

template <class T>
void Nodo<T>::set_next(Nodo* _next) {
	this->next = _next;
}

template <class T>
T Nodo<T>::get_data() {
	return data;
}

template <class T>
void Nodo<T>::set_data(T _data) {
	this->data = _data;
}

template <class T>
class Linked_list
{
public:
	Linked_list();
	Nodo<T>* get_first();
	Nodo<T>* get_last();
	void set_first(Nodo<T>*);
	void set_last(Nodo<T>*);
	void insert_start(T);
	void insert_end(T);
	void print();
	void functional(std::function<void(T, int)>callback);
	void print_recursivity();
	void print_rcs(Nodo<T>*);
	void delete_element(T);
	void delete_first();
	void delete_last();
	bool empty();
	~Linked_list();
private:
	Nodo<T>* first;
	Nodo<T>* last;

};

template <class T>
Nodo<T>* Linked_list<T>::get_first() {
	return this->first;
}

template <class T>
Nodo<T>* Linked_list<T>::get_last() {
	return this->last;
}

template <class T>
void Linked_list<T>::set_first(Nodo<T>* _first) {
	this->first = _first:
}

template <class T>
void Linked_list<T>::set_last(Nodo<T>* _last) {
	this->last = _last;
}

template <class T>
Linked_list<T>::Linked_list() {
	this->first = nullptr;
	this->last = nullptr;
}

template<class T>
bool Linked_list<T>::empty() {
	return(this->first == nullptr);
}

template<class T>
Linked_list<T>::~Linked_list() {

}

template <class T>
void Linked_list<T>::insert_end(T value) {
	Nodo<T>* new_nodo = new Nodo<T>(value);
	if (empty()) {
		this->first = new_nodo;
		first->set_next(nullptr);
		last = new_nodo;
	}
	else {
		this->last->set_next(new_nodo);
		new_nodo->set_next(nullptr);
		last = new_nodo;
	}
	this->last = new_nodo;
}

template <class T>
void Linked_list<T>::insert_start(T value) {
	Nodo<T>* new_nodo = new Nodo<T>(value);
	Nodo<T>* fore = first;
	if (empty()) {
		this->first = new_nodo;
		//first->next = nullptr;
		first->set_next(nullptr);
		last = new_nodo;
	}
	else {
		new_nodo->set_next(first);
		first = new_nodo;
	}
}

template <class T>
void Linked_list<T>::print() {
	Nodo<T>* tmp = this->first;
	while (tmp)
	{
		std::cout << tmp->get_data() << " -> ";
		tmp = tmp->get_next();
	}
	std::cout << "NULL\n";
}

template <class T>
void Linked_list<T>::delete_element(T delete_nodo) {
	if (!empty()) {
		Nodo<T>* search = this->first;
		Nodo<T>* fore = nullptr;
		bool modified = false;
		while (search != nullptr && modified != true)
		{
			if (search->get_data() == delete_nodo) {
				std::cout << "Dato buscado encontrado:" << std::endl;

				if (search == first) {
					first = first->get_next();
				}
				else if (search == last) {
					fore->set_next(nullptr);
					last = fore;
				}
				else {
					last->set_next(search->get_next());
				}
				std::cout << "El nodo ha sido modificado" << std::endl;
				modified = true;
			}
			fore = search;
			search = search->get_next();
		}
		if (!modified) {
			std::cout << "No existe el nodo" << std::endl;
		}
	}
	else if (empty()) {
		std::cout << "Lista vacia" << std::endl;
	}
}

template <class T>
void Linked_list<T>::delete_first() {
	Nodo<T>* actually = this->first;
	Nodo<T>* fore = nullptr;
	if (!empty()) {
		first = first->get_next();
		fore = actually;
		actually = actually->get_next();
	}

}


template <class T>
void Linked_list<T>::delete_last() {
	Nodo<T>* actually = this->first;
	Nodo<T>* fore = nullptr;
	if (!empty()) {
		while (actually != nullptr) {
			if (actually == last) {
				fore->set_next(nullptr);
				last = fore;
			}
			fore = actually;
			actually = actually->get_next();
		}
	}
}

template <class T>
void Linked_list<T>::print_recursivity() {
	Nodo<T>* tmp = this->first;
	print_rcs(tmp);
}

template <class T>
void Linked_list<T>::print_rcs(Nodo<T>* tmp) {
		if (tmp != nullptr) {
			std::cout << tmp->get_data() << " -> ";
			print_rcs(tmp->get_next());
		}
		else {
			std::cout << "NULL\n";
		}
}

template <class T>
void Linked_list<T>::functional(std::function<void(T, int)>callback) {
	Nodo<T>* tmp = first;
	int index = 0;
	while (tmp != nullptr) {
		callback(tmp->get_data(), index++);
		tmp = tmp->get_next();
	}
}