/*

CONSULT CHAPTER 12 OF CS142 NOTES - EXCELLENT RESCOURCE!
 -remember to compile with -std=c++11 flag

TO DO: 

LEGEND: o == Not done, x == done (to our knowledge), A = ask Maciel, T = test this, it looks a little funny

 x Default constructor --> 'x' means this is already done
 o Copy constructor - DEEP COPY
 o Destructor - DEALLOCATE MEMORY
 o Indexing operator - this is insert	
 o size
 x empty
 o begin
 o end
 o find
 o erase(key)
 o erase(iterator)
 o clear
 o swap
 A Iterators - that support the following operations
	x default constructor
	x * - RETURN REFERENCE TO PAIR OBJECT
	o ++ We did this wrong - see notes below.
	x ==
	x !=
*/

#include <iostream>
#include <string>
#include <iterator>

using namespace std;

template <class K, class V>
class Iterator;

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
	typedef Iterator<K, V> iterator;

	public:
	Map() :  //Default constructor should create a map without instantiating it's root node (Don't need a dummy node like in CS142's list implementation per Maciel)
		root () {} // by calling the root 
	~Map(); // Destructor
	bool operator==(Map<K, V> & mapTwo); 
	Node<K, V> * operator++(Map<K, V> & mapTwo); // return type correct?
	bool operator!=(Map<K, V> & mapTwo);
	
	bool empty(){return (root == NULL);}

	iterator begin(){ return iterator(root); } //MIN operation, IE not what we have here. See notes!
	iterator end(){
		Node<K, V> * nodePtr; //'past the end', maybe have it contain a nullptr. (Not what we have here)
		nodePtr = root;
		while( nodePtr->right != nullptr){
			nodePtr = nodePtr->right;
		}
		return iterator(nodePtr); 
		
	}/*rightmost node? Maciel plz help */

	private:
	Node<K, V> * root; //Yes, this is the only node the object contains! root, however, will maintain it's own 'left'/'right' pointers towards the rest of the nodes
};

template <class K, class V>
class Iterator{
	
	friend class Map<K, V>;
	
	public:
	Iterator() : p_current_node(nullptr) {}
	
	bool operator==(const Iterator & itr2) const{
		return (p_current_node == itr2.p_current_node);
	}
	
	bool operator!=(const Iterator & itr2) const{
		return (p_current_node != itr2.p_current_node);
	}
	Iterator<K, V> operator++() { //successor operation!
		Iterator<K, V> original_itr = *this;
		p_current_node = p_current_node->right; //ASK ABOUT THIS
		return original_itr;
	}
	pair<K, V> & operator* () const{
		return pair<K, V>(p_current_node->key, p_current_node->value);
	}
	

	private:
	explicit Iterator(Node<K, V> * p ) :
		p_current_node(p) {}

	Node<K, V> * p_current_node;

};


int main(){

	Map<int, string> myMap(); // explain why this needs '()' for me
	// how do we insert values into this thing??	
	return 0;
};

