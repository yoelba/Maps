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
	Map() :
            root () {}//Default constructor should create a map without instantiating it's root node (Don't need a dummy node like in CS142's list implementation per Maciel)
    Map(const K & Key0, const V & Value0) : Key(Key0), Value(Value0) {}

    int Size() const { return size_; }
    V find(V x, K key){
        //while

    }

    //V & operator[]
//		root () {}
	private:
	Node<K, V> * root;  //Yes, this is the only node the object contains! root, however, will maintain it's own 'left'/'right' pointers towards the rest of the nodes

    K Key;
    V Value;
    int size_;
};


int main(){
	Map<int, string> defaultMap();
	Map<char,std::string> mymap;

   /*mymap['a']="an element";
    mymap['b']="another element";
    mymap['c']=mymap['b'];

    std::cout << "mymap['a'] is " << mymap['a'] << '\n';
    std::cout << "mymap['b'] is " << mymap['b'] << '\n';
    std::cout << "mymap['c'] is " << mymap['c'] << '\n';
    std::cout << "mymap['d'] is " << mymap['d'] << '\n';

    std::cout << "mymap now contains " << mymap.Size() << " elements.\n";
    */

	return 0;
};
