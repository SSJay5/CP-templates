#include <bits/stdc++.h>
using namespace std;
#define ll int
#define null nullptr

class node
{
public:
	node *left;
	ll data;
	node *right;

	node(ll key)
	{
		this->data = key;
		this->left = this->right = null;
	}
} *root = null;

void itreativeInsert(ll key)
{
	node *t = null;
	node *r = null;

	if (root == null)
	{
		t = new node(key);
		root = t;
		return;
	}

	t = root;

	while (t != null)
	{
		r = t;
		if (key > t->data)
		{
			t = t->right;
		}
		else if (key < t->data)
		{
			t = t->left;
		}
		else
		{
			return;
		}
	}

	t = new node(key);

	if (key > r->data)
	{
		r->right = t;
	}
	else
	{
		r->left = t;
	}
}

node *rInsert(node *p, ll key)
{
	if (p == null)
	{
		node *t = new node(key);
		return t;
	}

	if (key > p->data)
	{
		p->right = rInsert(p->right, key);
	}
	else if (key < p->data)
	{
		p->left = rInsert(p->left, key);
	}

	return p;
}

void inorder(node *p)
{
	if (p)
	{
		inorder(p->left);
		cout << p->data << ' ';
		inorder(p->right);
	}
}
node *InSucc(node *p)
{
	while (p && p->left != null)
	{
		p = p->left;
	}
	return p;
}
node *InPre(node *p)
{
	while (p && p->right != null)
	{
		p = p->right;
	}
	return p;
}
ll height(node *p)
{
	ll x = 0;
	ll y = 0;
	if (p == null)
		return 0;
	x = height(p->left);
	y = height(p->right);

	return max(x, y) + 1;
}

node *DeleteNode(node *p, ll key)
{
	if (p == null)
	{
		return null;
	}

	if (p->data == key && p->left == null && p->right == null)
	{
		if (p == root)
		{
			root = null;
		}
		delete p;
		return null;
	}

	if (key > p->data)
	{
		p->right = DeleteNode(p->right, key);
	}
	else if (key < p->data)
	{
		p->left = DeleteNode(p->left, key);
	}
	else
	{
		if(height(p->left)>height(p->right))
		{
			node *q=InPre(p->left);
			p->data=q->data;
			p->left=DeleteNode(p->left,q->data);
		}
		else 
		{
			node *q=InSucc(p->right);
			p->data=q->data;
			p->right=DeleteNode(p->right,q->data);
		}
	}
	return p;
}
int main()
{
	// itreativeInsert(9);
	// itreativeInsert(15);
	// itreativeInsert(5);
	// itreativeInsert(20);
	// itreativeInsert(16);
	// itreativeInsert(8);
	// itreativeInsert(12);
	// itreativeInsert(3);
	// itreativeInsert(6);

	// inorder(root);
	// cout<<endl;

	root = rInsert(root, 1);
	rInsert(root, 0);
	rInsert(root, 1);
	rInsert(root, 0);
	rInsert(root, 1);
	rInsert(root, 0);
	rInsert(root, 1);
	
	inorder(root);
	cout << endl;
	cout << height(root);
	cout << endl;

	DeleteNode(root, 9);
	inorder(root);
	cout << endl;
}