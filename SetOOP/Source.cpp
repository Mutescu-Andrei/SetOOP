#include "Multime.h"

/*clasa Element*/
int Element::ordine = 0;
Element::Element(const char* x) {
	this->x = new char[strlen(x) + 1];
	strcpy(this->x, x);

}
Element::Element(const Element& s) {
	x = new char[strlen(s.x) + 1];
	strcpy(x, s.x);

}
Element::Element() {
	x = 0;
}
Element::~Element() {
	if (x)delete[] x;
}
Element& Element::operator=(const Element& s) {
	if (this != &s) {
		if (x)delete x;
		x = new char[strlen(s.x) + 1];
		strcpy(x, s.x);

	}
	return *this;
}

int Element::operator==(const Element& s) {

	if (strcmp(x, s.x) != 0)
		return false;
	else
		return true;
}

ostream& operator<<(ostream& out, const Element& s) {
	out << s.x << " ";

	return out;
}
istream& operator>>(istream& in, Element& s) {

	return in;
}




/*clasa Submultime*/
Submultime::Submultime() {
	next = 0;
}
Submultime::Submultime(Element info, Submultime* next) {
	this->info = info;
	this->next = next;
}
Submultime::~Submultime() {}
Element Submultime::getInfo() {
	return info;
}
void Submultime::setInfo(Element info) {
	this->info = info;
}
Submultime* Submultime::getNext() {
	return next;
}
void Submultime::setNext(Submultime* next) {
	this->next = next;
}
/*
int Submultime::operator== (const Element& s) {
	return info == s;
}
*/
/*clasa Multime*/
Multime::Multime() {
	prim = ultim = curent = 0;
}
Multime::Multime(const Multime& list) {
	Submultime* p;
	prim = ultim = curent = 0;
	p = list.prim;
	while (p) {
		addElement(p->info);
		p = p->next;
	}
}
Multime::~Multime() {
	clear();
}
int Multime::isEmpty() {
	return prim == 0;
}
void Multime::clear() {
	Submultime* p, * q;
	p = prim;
	while (p) {
		q = p;
		p = p->next;
		delete q;
	}
	prim = ultim = curent = 0;
}
void Multime::addElement(Element info) {
	Submultime* p;
	p = new Submultime;
	p->info = info;
	p->next = 0;
	if (isEmpty()) {
		curent = prim = ultim = p;
	}
	else {
		ultim->next = p;
		ultim = p;
	}
}

void Multime::deleteElement(Element info) {
	if (!isEmpty())
	{
		Submultime* p, * q;
		p = prim;
		q = prim;

		if (p == prim && p->info == info)
		{
			if (p->next != NULL)
			{
				q = p;
				p = p->next;
				delete q;
				curent = prim = p;
			}
			else
			{
				delete p;
				prim = ultim = curent = 0;
			}
		}
		else
			if (p == ultim)
			{

				delete p;


			}
			else
			{
				while (p && !(p->info == info)) {


					q = p;
					p = p->next;
					//delete q;
					//curent = p;



				//p = p->next;
				}
				if (p != NULL)
				{

					q->next = p->next;
					delete p;
				}
			}
	}
}

Submultime* Multime::getFirst() {
	return prim;
}
Submultime* Multime::getLast() {
	return ultim;
}
Submultime* Multime::getCurrent() {
	return curent;
}
Submultime* Multime::getElementAt(int index) {
	int i;
	Submultime* p;
	for (i = 0, p = prim; i < index && p != 0; i++, p = p->next);
	return p;
}
int Multime::getCount() {
	int n = 0;
	Submultime* p = prim;
	while (p) {
		n++;
		p = p->next;
	}
	return n;
}
void Multime::goToStart() {
	curent = prim;
}

Multime& Multime::operator++() {
	if (curent)curent = curent->next;
	return *this;
}
ostream& operator<<(ostream& out, Multime& list) {
	Submultime* p = list.getFirst();
	while (p) {
		out << p->getInfo();
		p = p->getNext();
		if (p != NULL)
			out << ", ";
	}
	return out;
}
Element& Multime::operator[] (int index) {
	return getElementAt(index)->info;
}
Multime& Multime::operator=(const Multime& list) {
	clear();
	Submultime* p = list.prim;
	while (p) {
		addElement(p->info);
		p = p->next;
	}
	return *this;
}
void Multime::operator+=(const Element& s) {
	addElement(s);
}
void Multime::operator-=(const Element& s) {
	deleteElement(s);
}

Multime Multime::operator+(const Multime& list) {

	Submultime* p = list.prim;
	Submultime* p0 = prim;
	Multime tr;
	int ok = 0;

	while (p0) {
		p = list.prim;
		while (p)
		{
			if (p->info == p0->info)
			{
				ok = 1;
				break;
			}
			p = p->next;
		}
		if (ok == 0)
		{
			tr.addElement(p0->info);
		}
		ok = 0;
		p0 = p0->next;



	}
	p = list.prim;
	while (p) {

		tr.addElement(p->info);
		p = p->next;
	}


	return tr;
}

Multime Multime::operator-(const Multime& list) {

	Submultime* p = list.prim;
	Submultime* p0 = prim;
	int ok = 0;
	Multime tr;
	while (p0) {
		p = list.prim;
		while (p)
		{
			if (p->info == p0->info)
			{
				ok = 1;
				break;
			}
			p = p->next;
		}
		if (ok == 0)
		{
			tr.addElement(p0->info);
		}
		ok = 0;
		p0 = p0->next;



	}
	return tr;
}

Multime Multime::operator^(const Multime& list) {

	Submultime* p = list.prim;
	Submultime* p0 = prim;
	int ok = 0;
	Multime tr;
	while (p0) {
		p = list.prim;
		while (p)
		{
			if (p->info == p0->info)
			{
				ok = 1;
				break;
			}
			p = p->next;
		}
		if (ok == 1)
		{
			tr.addElement(p0->info);
		}
		ok = 0;
		p0 = p0->next;



	}
	return tr;
}

int main() {
	Multime A, B, C, D, E, F, G;
	Element s1("P");
	Element s2("V");
	Element s3("F");
	Element s4("R");
	A.addElement(s1);
	A.addElement(Element("G"));
	A += s2;
	A += s3;
	A += Element("I");
	B += s3;
	B += s4;
	cout << "Multimea A={ " << A << " }";
	cout << endl;
	cout << "Multimea B={ " << B << " }";
	cout << endl;

	C = A + B;
	D = A - B;
	E = A ^ B;
	F = C;
	F = F ^ B;
	G = C;
	G -= s2;
	cout << "Multimea C={ " << C << " }";
	cout << endl;
	cout << "Multimea D={ " << D << " }";
	cout << endl;
	cout << "Multimea E={ " << E << " }";
	cout << endl;
	cout << "Multimea F={ " << F << " }";
	cout << endl;
	cout << "Multimea G={ " << G << " }";
	cout << endl;
	cout << endl;

	return 0;
}
