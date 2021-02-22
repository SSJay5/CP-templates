#include <bits/stdc++.h>
using namespace std;
#define v vector
#define ll int
#define pb push_back
#define node Node
#define null NULL

class node
{
public:
	node *left;
	ll data;
	node *right;
} * root;

void create()
{
	deque<node *> q;
	root = new node;
	root->left = root->right = null;
	ll x;
	cout << "Enter value of the root" << endl;
	cin >> root->data;

	q.push_back(root);

	node *p = null;
	while (!q.empty())
	{
		p = q.front();
		q.pop_front();

		cout << "Enter the value of the left child of " << p->data << endl;
		cin >> x;
		if (x != -1)
		{
			node *t = new node;
			t->data = x;
			t->left = t->right = null;
			p->left = t;
			q.push_back(t);
		}
		cout << "Enter the value of the right child of " << p->data << endl;
		cin >> x;
		if (x != -1)
		{
			node *t = new node;
			t->data = x;
			t->left = t->right = null;
			p->right = t;
			q.push_back(t);
		}
	}
}

void levelOrder(node *p)
{
	deque<node *> q;
	if (p != null)
	{
		// cout << p->data << ' ';
		q.push_back(p);

		while (!q.empty())
		{
			node *t = q.front();
			q.pop_front();
			cout << t->data << ' ';
			if (t->left)
			{
				q.push_back(t->left);
			}
			if (t->right)
			{
				q.push_back(t->right);
			}
		}
	}
}
void iterativePreorder(node *p)
{
	stack<node *> st;
	while (p != null || !st.empty())
	{
		if (p != null)
		{
			st.push(p);
			cout << p->data << ' ';
			p = p->left;
		}
		else
		{
			p = st.top();
			st.pop();
			p = p->right;
		}
	}
	cout << endl;
}
void iterativeInorder(node *p)
{
	stack<node *> st;

	while (p != null || !st.empty())
	{
		if (p != null)
		{
			st.push(p);
			p = p->left;
		}
		else
		{
			p = st.top();
			st.pop();
			cout << p->data << ' ';
			p = p->right;
		}
	}
	cout << endl;
}
void iterativePostorder(node *p)
{
	stack<long long int> st;

	while (p != null || !st.empty())
	{
		if (p != null)
		{
			st.push((long long int)p);
			p = p->left;
		}
		else
		{
			if (st.top() > 0)
			{
				p = (node *)st.top();
				st.pop();
				st.push(-1ll * (long long int)p);
				p = p->right;
			}
			else
			{
				cout << ((node *)(-1ll * (st.top())))->data << ' ';
				st.pop();
			}
		}
	}
	cout << endl;
}
bool isValidBST(node *root)
{
	if (!root)
	{
		return true;
	}

	ll prev = INT64_MAX;
	node *p = root;
	stack<node *> st;

	while (p != null || !st.empty())
	{
		if (p != null)
		{
			st.push(p);
			p = p->left;
		}
		else
		{
			p = st.top();
			st.pop();
			if (p->data <= prev)
				return false;
			prev = p->data;
			p = p->right;
		}
	}
	return true;
}
vector<int> printBoundary(node *root)
{
	v<ll> ans;
	if (root == null)
		return ans;

	ans.pb(root->data);

	node *p = root;
	p = p->left;
	while (p != null)
	{
		if (p->left == null && p->right == null)
		{
		}
		else
		{
			ans.pb(p->data);
		}
		p = p->left;
	}

	stack<node *> st;
	st.push(root);
	p = root;
	while (p != null || !st.empty())
	{
		if (p != null)
		{
			if (p->left == null && p->right == null)
			{
				ans.pb(p->data);
			}
			st.push(p);
			p = p->left;
		}
		else
		{
			p = st.top();
			st.pop();
			p = p->right;
		}
	}

	p = root->right;
	while (p != null)
	{
		if (p->left == null && p->right == null)
		{
		}
		else
		{
			ans.pb(p->data);
		}
		p = p->right;
	}
	return ans;
}
node *buildTree(vector<int> &inorder, vector<int> postorder)
{
	if (inorder.empty() || postorder.empty())
	{
		return null;
	}

	node *root = new node;
	root->data = postorder.back();
	v<ll> smaller;
	v<ll> greater;
	for (ll i = 0; i < postorder.size(); i++)
	{
		if (postorder[i] < root->data)
		{
			smaller.pb(postorder[i]);
		}
		else
		{
			greater.pb(postorder[i]);
		}
	}
	root->left = buildTree(inorder, smaller);
	root->right = buildTree(inorder, greater);

	return root;
}
bool node_to_root(node *p, v<node *> &ans, ll n)
{
	if (p != null)
	{
		if (p->data == n)
		{
			ans.pb(p);
			return true;
		}
		if (node_to_root(p->left, ans, n))
		{
			ans.pb(p);
			return true;
		}
		if (node_to_root(p->right, ans, n))
		{
			ans.pb(p);
			return true;
		}
	}
	return false;
}
void print_k_down(node *p, node *block, ll k)
{
	if (p == null || k < 0 || p == block)
	{
		return;
	}

	if (k == 0)
	{
		cout << p->data << endl;
	}
	print_k_down(p->left, block, k - 1);
	print_k_down(p->right, block, k - 1);
}
void print_k_far(node *p, node *block, ll k, ll n)
{
	if (p == null)
	{
		return;
	}
	v<node *> path;
	node_to_root(p, path, n);

	for (ll i = 0; i < path.size(); i++)
	{
		print_k_down(path[i], i == 0 ? null : path[i - 1], k - i);
	}
}
ll height(node *p)
{
	if (!p)
	{
		return 0;
	}
v<v<v<ll>>> dp(41,v<v<ll>>(41,v<ll>(2,-1)));
	ll left_height = height(p->left);
	ll right_height = height(p->right);

	return max(left_height, right_height) + 1;
}
int diameterOfBinaryTree(node *root)
{

	if (!root)
	{
		return 0;
	}

	return height(root->left) + height(root->right);
}
node *trimBST(node *root, int low, int high)
{
	if (!root)
	{
		return null;
	}

	while ((root != null) && (root->data < low || root->data > high))
	{
		if (root->data < low)
		{
			root = root->right;
		}
		if (root->data > high)
		{
			root = root->left;
		}
	}

	stack<node *> st;
	st.push(root);

	while (!st.empty())
	{
		node *p = st.top();
		st.pop();
		bool matchInterval = true;

		if (p != null && p->left != null && p->left->data < low)
		{
			p->left = p->left->right;
			matchInterval = false;
		}
		if (p != null && p->right != null && p->right->data > high)
		{
			p->right = p->right->left;
			matchInterval = false;
		}
		if (!matchInterval)
		{
			st.push(p);
		}
		else
		{
			if (p->left)
			{
				st.push(p->left);
			}
			if (p->right)
			{
				st.push(p->right);
			}
		}
	}
	return root;
}
int main()
{
	create();
	node *p = root;
	cout << diameterOfBinaryTree(p) << endl;
	// print_k_far(p, null, 1, 3);
	// print_k_down(p, 2);
	// v<ll> ans;
	// if (node_to_root(p, ans, 5))
	// {
	// 	for (ll i : ans)
	// 	{
	// 		cout << i << ' ';
	// 	}
	// }
	// cout << endl;
	// printBoundary(root);
	// cout << isValidBST(root);
	// levelOrder(root);
	// root = p;
	// iterativePreorder(root);
	// root = p;
	// iterativeInorder(root);
	// root = p;
	// iterativePostorder(root);
}