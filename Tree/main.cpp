#include <list>
#include <iostream>
#include <random>

using namespace std;

class Tree {
public:
	struct Node {
		int data;
		Node *left, *right;
		//Node() {};
		Node(int v) : data(v), left(nullptr), right(nullptr) {};
	};

	Node *root;

	Tree() : root(nullptr) {};
	//~Tree() {}; // delete all nodes

	bool isEmpty() const { return root == nullptr; }

	bool find(int val) const
	{
		Node *t = root;

		while (t != nullptr)
		{
			if (val == t->data)
				return true;

			if (val < t->data)
				t = t->left;

			else t = t->right;
		}

		return false;
	}

	bool findR(int val) const
	{
		if (root != nullptr)
			return _findR(root->left, val) || _findR(root->right, val);
		return false;
	}

	bool _findR(const Node *n, int val) const
	{
		if (n == nullptr) return false;
		else if (n->data == val) return true;

		return _findR(n->left, val) || _findR(n->right, val);
	}

	int _childCount(const Node *n) const
	{
		int retval = 0;
		if (n->left) retval++;
		if (n->right) retval++;
		return retval;
	}

	bool insert(int val)
	{
		if (root == nullptr)
		{
			root = new Node(val);
			return true;
		}

		Node *t = root;
		while (true)
		{
			if (val == t->data)
				return false;
			if (val < t->data)
			{
				if (t->left == nullptr)
				{
					t->left = new Node(val);
					return true;
				}
				t = t->left;
			}
			else //val > t->data
			{
				if (t->right == nullptr)
				{
					t->right = new Node(val);
					return true;
				}
				t = t->right;
			}
		}
	}

	bool remove(int val)
	{
		// If we are deleting the root node and it has no children.
		if (root != nullptr && root->data == val && root->left == nullptr && root->right == nullptr)
		{
			delete root;
			root = nullptr;
			return true;
		}

		Node *t = root;

		while (true)
		{
			if (t == nullptr)
				return false;

			if (t->data == val)
			{
				Node *ts, *tt; // parent and promotee
				ts = t->right; // first assumed parent is the right node

				if (ts->left == nullptr) // if right node doesn't have children
				{
					ts = t;			// the target node becomes the parent
					tt = t->right;  // and the right node becomes the promotee

					t->data = tt->data; // promote the value
					ts->right = tt->right; // parent adopts promotee's child
					delete tt; // delete the promotee
				}
				else
				{
					while (ts->left->left != nullptr)
						ts = ts->left;
					tt = ts->left;

					t->data = tt->data; // promote the value
					ts->left = tt->right; // parent adopts promotee's child
					delete tt; // delete the promotee
				}

				return true;
			}

			if (t->left != nullptr && t->left->data == val && _childCount(t->left) <= 1)
			{
				Node *tt = t->left;
				t->left = t->left->left != nullptr ? t->left->left : t->left->right;
				delete tt;
				return true;
			}

			if (t->right != nullptr && t->right->data == val && _childCount(t->right) <= 1)
			{
				Node *tt = t->right;
				t->right = t->right->right != nullptr ? t->right->right : t->right->left;
				delete tt;
				return true;
			}

			t = val < t->data ? t->left : t->right;
		}

	}

	void inPrint() const
	{
		_inPrint(root);
	}

	void prePrint() const
	{
		_prePrint(root);
	}

	void postPrint() const
	{
		_postPrint(root);
	}

	void _inPrint(Node *n) const
	{
		if (n == nullptr) return;
		_inPrint(n->left);
		cout << n->data << " ";
		_inPrint(n->right);
	}

	void _prePrint(Node *n) const
	{
		if (n == nullptr) return;
		cout << n->data << " ";
		_prePrint(n->left);
		_prePrint(n->right);
	}

	void _postPrint(Node *n) const
	{
		if (n == nullptr) return;
		_postPrint(n->left);
		_postPrint(n->right);
		cout << n->data << " ";
	}

	void bfsPrint() const {

		if (root == nullptr) return;
		
		std::list<Node*> frontier;
		frontier.push_back(root);
		// what is the loop condition

		while (!frontier.empty()) {
			
			// exploration
			Node *t = frontier.front(); // returns first element
			frontier.pop_front(); // removes first element

			std::cout << t->data << " ";

			// discovery		
			if (t->left != nullptr) frontier.push_back(t->left); // puts element into the end
			if (t->right != nullptr) frontier.push_back(t->right);

		}
	}

	void fbsPrint() const {

		if (root == nullptr) return;

		std::list<Node*> frontier;
		frontier.push_back(root);
		// what is the loop condition

		while (!frontier.empty()) {

			// exploration
			Node *t = frontier.back(); // returns first element
			frontier.pop_back(); // removes first element

			std::cout << t->data << " ";

			// discovery		
			if (t->left != nullptr) frontier.push_front(t->left); // puts element into the end
			if (t->right != nullptr) frontier.push_front(t->right);

		}
	}
};

void main() {
	Tree myTree;

	for (int i = 0; i < 20; ++i) {
		int r = rand() % 30;
		myTree.insert(r);
	}
	myTree.inPrint();
	cout << "inprint" << endl;

	myTree.prePrint();
	cout << "preprint" << endl;

	myTree.postPrint();
	cout << "postprint" << endl;

	myTree.bfsPrint();
	cout << "bfsprint" << endl;

	myTree.fbsPrint();
	cout << "fbsprint" << endl;

	system("pause");
}