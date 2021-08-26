#pragma once
#include <iostream>
#pragma warning(disable : 4996)
using namespace std;

class Element;
class Submultime;
class Multime;
class Element {

	char* x;
	static int ordine;

public:
	Element(const char* x);
	Element(const Element&);
	Element();
	~Element();
	int operator==(const Element&);
	Element& operator=(const Element&);
	friend ostream& operator<<(ostream&, const Element&);
	friend istream& operator>>(istream&, Element&);
	int operator<(const Element&);
	static void setOrdine(int);
	friend class Submultime;
	friend class Multime;
};

class Submultime {
	Element info;	 //informatia
	Submultime* next;	//legatura catre urmatoarea submultime din lista
public:
	Submultime();//Constructor Implicit
	Submultime(Element info, Submultime* next = 0);	//Constructor de initializare
	~Submultime();
	Element getInfo();//
	void setInfo(Element info);
	Submultime* getNext();
	int operator==(const Element&);
	void setNext(Submultime* next);

	friend class Multime;
};
//intersectie && ^
//reuniune +
//diferenta -
class Multime {
protected:
	Submultime* prim, * ultim, * curent;
public:
	Multime(); //constructor implicit
	Multime(const Multime&); //constructor de copiere
	~Multime(); //destructor
	int isEmpty();
	void clear();
	void addElement(Element info);//adauga un nod la sfarsitul listei
	void deleteElement(Element info);
	Submultime* getFirst();//intoarce primul elemnt din lista
	Submultime* getLast(); //intoarce ultimul element din lista
	Submultime* getCurrent();
	Submultime* getElementAt(int index);
	int getCount();//intoarce numarul elementelor
	void goToStart();

	Multime& operator++();
	friend ostream& operator<<(ostream&, const Multime&);
	Element& operator[] (int index);
	Multime& operator=(const Multime&);
	Multime operator+(const Multime&);
	Multime operator^(const Multime&);
	Multime operator-(const Multime&);
	void operator+=(const Element&);
	void operator-=(const Element&);

};