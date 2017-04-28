/*

CONSULT CHAPTER 12 OF CS142 NOTES - EXCELLENT RESCOURCE!
 -remember to compile with -std=c++11 flag

TO DO: 

LEGEND: o == Not done, x == done (to our knowledge), A = ask Maciel, T = test this, it looks a little funny

 x Default constructor --> 'x' means this is already done
 T/A Copy constructor - DEEP COPY
 T/A Destructor - DEALLOCATE MEMORY --> how is this different from clear??
 x Indexing operator - this is insert 
 x size --> we should increment this with every new insert??
 x empty 
 x/T begin 
 x/T end
 x/T find BETTER NOW :)
 T erase(key)
 x erase(iterator) --> I started this
 x clear --> traverses tree and deletes it all
 o swap --> shouldn't be too hard
 x Iterators - that support the following operations
	x default constructor
	x * - RETURN REFERENCE TO PAIR OBJECT
	x ++ We  did this wrong - see notes below.
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
		while(root->left != nullptr){
			root = root->left;
		}
		return root;	
	} 

	iterator end(Node<K, V> maxNode){ return iterator(nullptr); } // Maciel's way

	iterator find (K key){ //Ask the man himself if this is good
		Node<K, V> node = & this.root; 
		while((node != NULL) && (node->key != key)){
			if(node->left == nullptr && node->right == nullptr){//Didn't find nothing, return end of map
				return this.end();
			}
			if(key < node->key) node = node->left;
			else node = node->right;
		}
		//Now we return an interator pointing to our nice node :)
		return iterator(node);
	}

	

	void clear(){
		if(root != NULL){
			(root->left).clear();
			(root->right).clear();
			delete(root);
			root = NULL;
		}	
	}
 
	Node<K, V> const& operator[](K key){ //Indexing Operator ASK MACIEL for real AsK THAT handsome man :) 
		iterator itr = this.find(key);
		if(itr->p_current_node){ //If a value WAS found
			return & itr->p_current_node; //return a reference to the element with that key
		}else{ //If a value wasn't found
			auto * newNode = new Node<K, V>; //Create a new node with that key and default(null?) value, add it to the map!
			newNode->key = key;
			insert(newNode);
		}
	}
	
		
	// erase using a node's key
	void erase(K key){
		erase(find(key));
	}
	
	// erase using a nodes iterator... place in the tree?
	void erase(iterator itr){
		Node<K, V> z = itr.p_current_node;
		if(z->left == nullptr){
                        replace_subtree(root, z, z>right);
                }else if(z->right == nullptr){
                        replace_subtree(root, z, z->left);
                }else{
                        Node<K, V> y = begin(z->right);
                        if(y != z->right){
                                replace_subtree(root, y, y->right);
                                y->right = z->right;
                                y->right->parent = y; //ASK
                        }
                        replace_subtree(root, z, y);
                        y->left = z->left;
                        y->left->parent = y;
                }
                z->left = z->right = nullptr;
        }

	void swap(Map<K, V> & map1, Map<K, V> & map2){
		Node<K, V> * temp_root = map1.root;
		map1.root = map2.root;
		map2.root = temp_root;
	}


	private:
	Node<K, V> * root; //this is the only node the object contains

	void insert(Node<K, V> * node){ //Tisng
		Node<K, V> root = & this.root;
		if (root = NULL){
			root = node;
		}else{
			Node<K, V> * q = root; //THis
			bool done = false;
			while(!done){
				if(node.key < q.key){
					if(q->left == nullptr){
						q->left = node;
						done = true;
					}else{
						q=q->left;
					}
				}else{
					if(q->right == nullptr){
						q->right = node;
						done = true;
					}else{
						q = q->right;
					}
				}
			} node->parent = q;
		}
	}
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

