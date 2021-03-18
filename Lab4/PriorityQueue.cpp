#include "..\Lab4\PriorityQueue.h"
#include <exception>

//Komplexitat:
//best case: Θ(1)
//worst case: Θ(1)
//avg case: Θ(1)
PriorityQueue::PriorityQueue(Relation r) {
	capacity = 1;
	size= 0;
	elems = new Element[capacity];
	relation = r;
}

//Komplexitat:
//best case: Θ(1)
//worst case: O(log3(n)))
//avg case: O(log3(n)))
void PriorityQueue::bubbleUp(int poz) {//poz ist die Position von welchem man den neuen Knoten nach oben schieben muss
	int pos = poz;
	Element elem = elems[poz]; //wir suchen die Position des Elementes
	int parent =(poz-1) / 3;

	while (pos > 0 && relation(elem.second, elems[parent].second)){//der Vaterknoten wird nach unten geschoben
		elems[pos] = elems[parent];
		pos = parent;
		parent = (pos-1) / 3;
	}
	elems[pos] = elem; //wir haben die Position des Elementes gefunden
}

//Komplexitat:   //es wird die Komplexitat von bubbleUp abgenommen 
//best case: Θ(1)
//worst case: O(log3(n)))
//avg case: O(log3(n)))
void PriorityQueue::push(TElem e, TPriority p) {
	if (size == capacity) {			//wenn Lange=Kapazitat, dann wird die Kapazitat verdoppelt, also es wird einen neunen Speicherplatz fur elems allokiert
		if (capacity != 0) capacity *= 2;
		else capacity = capacity + 1;
		Element* new_elems = new Element[capacity];
		for (int i = 0; i < size; ++i)
		{
			new_elems[i] = elems[i];
		}
		delete[] elems;
		elems = new_elems;
	}

	//man fugt den Knoten ein, als ein Blatt,
	elems[size].first = e;
	elems[size].second = p;
	bubbleUp(size); //und schiebt man den Knoten an der Positon, nach der Prioritat 
	size = size + 1;
}

//Komplexitat:
//best case: Θ(1)
//worst case: Θ(1)
//avg case: Θ(1)
Element PriorityQueue::top() const {
	if (isEmpty() == true) {
		exception e;
		throw e;
	}
	return elems[0];	//es wird die Wurzel zuruckgegeben
}

//Komplexitat:   //es wird den ganzen heap durchgequert un die Position zu finden
//best case: Θ(1)
//worst case:  O(log3(n))
//avg case:  O(log3(n))
void PriorityQueue::bubbleDown(int pos) {//pos ist die Position von welchem man den neuen Knoten nach unten schieben muss
	int poz = pos;
	Element elem = elems[pos];

	while (poz < size){
		int kind = -1;
		if (poz * 3+1 < size) {//es gibt ein Kind
			kind = poz * 3 + 1;
		}
		if (poz * 3 + 2 < size && relation(elems[3 * poz + 2].second, elems[kind].second)) {//es gibt ein 2-tes Kind
			kind = poz * 3 + 2;
		}
		if (poz * 3 + 3 < size && relation(elems[3 * poz + 3].second, elems[kind].second)){//der Knoten hat 3 Kinder
			kind = poz * 3 + 3;
		}
		if (kind != -1 && relation(elems[kind].second, elem.second)) { 
			elems[poz] = elems[kind];
			poz = kind;
		}
		else {
			elems[poz] = elem;
			poz = size + 1;
			//um die while-Schleife zu stoppen
		}
	}
		
 }

//Komplexitat:   //es wird die Komplexitat von bubbleDown abgenommen 
//best case: Θ(1)
//worst case: O(log3(n)))
//avg case: O(log3(n)))
Element PriorityQueue::pop() {
	if (isEmpty() == true) {
		exception e;
		throw e;
	}
	else {
		Element deleted = top(); //die Wurzel ist das Knoten, dass entfernt wird
		elems[0] = elems[size-1]; //das letzte Blatt wird an der Stelle der Wurzel geschoben
		bubbleDown(0);//man sucht die neue Wurzel nach der Prioritat
		size = size - 1;
		return deleted;
	}
	return NULL_TELEM;
}

//Komplexitat:
//best case: Θ(1)
//worst case: Θ(1)
//avg case: Θ(1)
bool PriorityQueue::isEmpty() const {
	if (size == 0)
		return true;
	return false;
}

//Komplexitat:
//best case: Θ(1)
//worst case: Θ(1)
//avg case: Θ(1)
PriorityQueue::~PriorityQueue() {
	delete[] elems;
};