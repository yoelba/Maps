/*

CONSULT CHAPTER 12 OF CS142 NOTES - EXCELLENT RESCOURCE!
 -remember to compile with -std=c++11 flag

TO DO: 

LEGEND: o == Not done, x == done (to our knowledge), A = ask Maciel, T = test this, it looks a little funny

 x Default constructor --> 'x' means this is already done
 o Copy constructor - DEEP COPY
 o Destructor - DEALLOCATE MEMORY --> how is this different from clear??
 o Indexing operator - this is insert 
 o size --> we should increment this with every new insert??
 x empty 
 x/T begin 
 x/T end
 x/T find
 o erase(key) --> I started this
 o erase(iterator) --> I started this
 x clear --> traverses tree and deletes it all
 o swap --> shouldn't be too hard
 x Iterators - that support the following operations
	x default constructor
	x * - RETURN REFERENCE TO PAIR OBJECT
	x ++ We did this wrong - see notes below.
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

/////////////////////////////////////////////////////////////////////////
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

/////////////////////////////////////////////////////////////////////////
template <class K, class V>
class Map{
	typedef Iterator<K, V> iterator;

	public:
	Map() : root () {} // instantiating our head node for the map

	~Map(); // Destructor --> implement this!

	bool empty() { return (root == NULL); }

	iterator begin(Node<K, V> & root){ // MIN operation, fixed
	// on second thought, the STL version doesn't have any args... we should just
	// call root cause we have it as a private data member 
		while(root->left != nullptr){
			root = root->left;
		}
		return root;	
	} 

	iterator end(Node<K, V> maxNode){ return iterator(nullptr); } // Maciel's way :( but fixed
	// or should this go all the way to the right, then when root->right is a nullptr, you return that?
//		maxNode = root;
//		while(root->next != nullptr) root = root->next;
//		return root->next;

	iterator find(Node<K, V> & root, K k){
		while((root != NULL) && (root->key != k)){
			if(k < root->key) root = root->left;
			else root = root->right;
		}
		return root;
	}

	iterator clear(){
		if(root != NULL){
			(root->left).clear();
			(root->right).clear();
			delete(root);
			root = NULL;
		}	
	}
 
	// erase using a nodes key
	iterator erase(Node<K, V> & root, K k){ 		
		while(root->key != k){
			if(k < root->key) root = root->left;
			else root = root->right;
		}
		// this is where you do some bullshit
	}
	
	// erase using a nodes iterator... place in the tree?
	iterator erase(Node<K, V> & root, Iterator<K, V> itr){
		// yeah not really sure
	}

	private:
	Node<K, V> * root; //this is the only node the object contains
};

/////////////////////////////////////////////////////////////////////////
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
	
	Iterator<K, V> * operator++(Node<K, V> & currNode){ // successor operation, fixed
                if(currNode->right != NULL) return begin(currNode->right);
                else{
                        Node<K, V> parentNode = currNode->parent;
                        while((parentNode != NULL) && (currNode = parentNode->right)){
                                currNode = parentNode;
                                parentNode = currNode->parent;
                        }
                        return parentNode;
                }
        }

	pair<K, V> & operator * () const{
		return pair<K, V>(p_current_node->key, p_current_node->value);
	}

	private:
	explicit Iterator(Node<K, V> * p ) : p_current_node(p) {}

	Node<K, V> * p_current_node;

};

/////////////////////////////////////////////////////////////////////////
int main(){

	Map<int, string> myMap();
	
	return 0;
};

