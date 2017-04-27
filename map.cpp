/*

CONSULT CHAPTER 12 OF CS142 NOTES - EXCELLENT RESCOURCE!
 -remember to compile with -std=c++11 flag

TO DO: 

 x Default constructor --> 'x' means this is already done
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
 o Iterators - that support the following operations
	o default constructor --> how tf is this done????????
	o * - RETURN REFERENCE TO PAIR OBJECT - so a reference to it's node place in the map?
	x ++
	x ==
	x !=
*/

#include <iostream>
#include <string>
#include <iterator>

using namespace std;

template <class K, class V>
class Map; 

template <class K, class V>
class Node{

	friend class Map<K, V>;

	private : //Constructors are private, but Map will be able to access them. (And only Maps should ever instantiate nodes as far as I know)
	Node() :
		key (), value(), left(NULL), right(NULL), parent(NULL) {}
	
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
		root () {} // by calling the root 
	~Map(); // Destructor
	bool operator==(Map<K, V> & mapTwo); 
	Node<K, V> * operator++(Map<K, V> & mapTwo); // return type correct?
	bool operator!=(Map<K, V> & mapTwo);
		
	
	private:
	Node<K, V> * root; //Yes, this is the only node the object contains! root, however, will maintain it's own 'left'/'right' pointers towards the rest of the nodes
};

// Operator ==
template<class K, class V>
inline bool Map<K, V>::operator==(Map<K, V> & mapTwo){

	return ((root->key == mapTwo.root->key) && 
		(root->value == mapTwo.root->value));
}

// Operator ++
template<class K, class V>
inline Node<K, V> * Map<K, V>::operator++(Map<K, V> & myMap){
	
	return myMap = myMap->right;
}

// Operator !=
template<class K, class V>
inline bool Map<K, V>::operator!=(Map<K, V> & mapTwo){
	
	return ((root->key != mapTwo.root->key) || 
		(root->value != mapTwo.root->value));
}

// Destructor
template <class K, class V>
inline Map<K, V>::~Map(){

	Map<K, V> * m = root->right;
	for(auto it = m.begin(); m.end(); ++it){
	// since we have to implement begin and end, should we use
	// those implemented versions here or nah?
		m = m->right;
		delete m->left;	
	}
	delete * root;
}

int main(){

	Map<int, string> myMap(); // explain why this needs '()' for me
	// how do we insert values into this thing??		

	return 0;
};










