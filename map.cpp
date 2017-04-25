/*

CONSULT CHAPTER 12 OF CS142 NOTES - EXCELLENT RESCOURCE!
 -remember to compile with -std=c++11 flag

TO DO:

 x Default constructor
 o Copy constructor - DEEP COPY
 o Destructor - DEALLOCATE MEMORY
 o Indexing operator	
 o size
 o empty
 o begin
 o end
 o find
 o erase(key)
 o erase(iterator)
 o clear
 o swap
 o Iterators
	o default constructor
	o * - RETURN REFERENCE TO PAIR OBJECT
	o ++
	o !=

 -- PLEASE ADD ANY TASKS I'VE FORGOTTEN TO LIST --
*/
#include <iostream>
#include <string>
using namespace std;

template <class K, class V>
class Map; 

template <class K, class V>
class Node{

	friend class Map<K, V>;

	private : //Constructors are private, but Map will be able to access them. (And only Maps should ever instantiate nodes as far as I know)
	Node() :
		key (), value(), left(nullptr), right(nullptr), parent(nullptr) {}
	
	Node(const K & k, const V & v, Node * l, Node * r, Node * p) :
		key(k), value(v), left(l), right(r), parent(p) {}
	
	K key;
	V value;

	Node<K, V> * parent;	
	Node<K, V> * left;
	Node<K, V> * right;
};

template <class K, class V>
class Map{
	public:
	Map() :  //Default constructor should create a map without instantiating it's root node (Don't need a dummy node like in CS142's list implementation per Maciel)
		root () {}
	private:
	Node<K, V> * root; //Yes, this is the only node the object contains! root, however, will maintain it's own 'left'/'right' pointers towards the rest of the nodes

};


int main(){
	Map<int, string> defaultMap();
	
	
	return 0;
};
