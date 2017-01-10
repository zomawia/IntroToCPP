

// rule of 5

class Tree {
private:
	struct Node {
		int data;
		Node *left, *right;
		Node() {};
		Node(int v) : data(v), left(nullptr), right(nullptr) {};
	};

	Node *root;

	void insert(int val, Node *leaf) {
		if (val < leaf->data) {
			if (leaf->left != nullptr)
				insert(val, leaf->left);
			else {
				leaf->left = new Node;
				leaf->left->data = val;
				leaf->left->left = nullptr;
				leaf->left->right = nullptr;
			}
		}
		else if (val >= leaf->data) {
			if (leaf->right != nullptr)
				insert(val, leaf->right);
			else {
				leaf->right = new Node;
				leaf->right->data = val;
				leaf->right->left = nullptr;
				leaf->right->right = nullptr;
			}
		}
	}

	Node *find(int val, Node *leaf) {
		if (leaf != nullptr) {
			if (val == leaf->data)
				return leaf;
			if (val < leaf->data)
				return find(val, leaf->left);
			else
				return find(val, leaf->right);
		}
		else return nullptr;
	}
	int _childCount(const Node*n) const { int retval = 0; if (n->left) retval++; if (n->right) retval++; return retval; }
public:
	Tree() : root(nullptr) {};
	~Tree() {}; // delete all nodes

	bool isEmpty() const { return root == nullptr; }

	bool find(int val) {
		Node *t = root;

		while (t != nullptr) {
			if (val == t->data) return true;

			if (val < t->data) t = t->left;
			else t = t->right;
		}
		
		//return find(val, root) != nullptr;
	}
	
	bool insert(int val) {	
		if (find(val)) return false;

		if (isEmpty()) {
			root = new Node(val);
			return true;
		}

		Node *t = root;

		while (true) {
			if (val < t->data) {
				if (t->left == nullptr)
				{
					t->left = new Node(val);
					return true;
				}
				t = t->left;
			}
			else {
				if (t->right == nullptr)
				{
					t->right = new Node(val);
					return true;
				}
				t = t->right;
			}
		}
		
		/*if (root != nullptr)
			insert(val, root);
		else {
			root = new Node;
			root->data = val;
			root->left = nullptr;
			root->right = nullptr;
		}*/
	}
	
	bool remove(int val) {
		Node *t = root;
		
		while (true) {
			if (t == nullptr) return false;

			if (t->data == val) {
				//2 child deletion
				Node *tt;
				Node *ts = t->right;
				
				if (ts->left == nullptr) {
					ts = t;
					tt = t->right;
				}
				
				//find smallest larger number??
				else {
					while (ts->left->left != nullptr) {
						ts = ts->left;
						tt = t->left;
					}							
				}
				t->data = tt->data;
				ts->left = tt->right;
				delete tt;
			}

			if (t->left->data == val && t->left->data == val && _childCount(t->left) <= 1) {
				Node *tt = t->left;
				t->left = t->left->left != nullptr ? t->left->left : t->left->right;
				delete tt;
			}

			if (t->right->data == val && t->right->data == val && _childCount(t->right) <= 1) {
				Node *tt = t->right;
				t->right = t->right->right != nullptr ? t->right->right : t->right->left;
				delete tt;
			}

			t = val < t->data ? t->left : t->right;
		}

	}
	//	if (isEmpty()) return false;
	//	
	//	if (val == root->data) {
	//		delete root;
	//		root = nullptr;
	//		return true;
	//	}

	//	if (find(val))
	//	{
	//		Node *t = find(val, root);			
	//		
	//		//leaf node
	//		if (t->left == nullptr && t->right == nullptr) {
	//			if (t->data > root->data) root->right = nullptr;
	//			else root->left = nullptr;
	//			delete t;
	//		}

	//		//one child
	//		if ((t->left == nullptr && t->right != nullptr) || (t->left != nullptr && t->right == nullptr)) {

	//		}

	//		//two child
	//		if (t->left != nullptr && t->right != nullptr) {
	//			Node *sub = t;
	//			if (t->left)
	//		}
	//	}
	//	else {
	//		//doesnt exist
	//	}
	//}
};