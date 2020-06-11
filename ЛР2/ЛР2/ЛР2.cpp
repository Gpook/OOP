#include <iostream>
#include <istream>
using namespace std;

struct TreeBin {
	TreeBin* left;
	TreeBin* right;
	int key;
};

class btree
{
public:
	int amount;

	btree();
	~btree();

	void setAmount(int amount);
	void insert(int key);
	TreeBin* search(int key);
	void destroy_tree();
	void view();
	void sort();

private:
	void destroy_tree(TreeBin* leaf);
	void insert(int key, TreeBin* leaf);
	TreeBin* deleting(int key, TreeBin* leaf);
	TreeBin* search(int key, TreeBin* leaf);
	void view(TreeBin* leaf);
	TreeBin* sort(TreeBin* root);
	void fetchKeys(TreeBin* leaf, int* treeKeys, int& index);
	void insertSort(int* treeKeys, int amount);
	void sortTree(TreeBin** p, int n, int k, int* treeKeys);

	TreeBin* leaf;
};



std::ostream& operator<< (std::ostream& os, btree& a) {			
	a.view();
	return os;
}

std::ostream& operator>> (std::ostream& os, btree& a) {			
	int nodeAmount = 0;
	cout.width(115);
	cout.setf(ios::right);
	cout << "Задайте количество листьев: ";
	cout.unsetf(ios::right);
	cin.setf(ios::skipws);
	cin >> nodeAmount;
	cin.unsetf(ios::skipws);
	if (nodeAmount <= 0) throw 1;
	a.setAmount(nodeAmount);
	return os;
}

btree::btree()
{
	leaf = NULL;
}

btree::~btree()
{
	destroy_tree();
}

TreeBin* btree::deleting(int key, TreeBin* leaf) {
	if (leaf == NULL)
		return 0;

	if (leaf->key < key)
	{

		leaf->right = deleting(key, leaf->right);
		return leaf;
	}
	else

		if (key < leaf->key)
		{

			leaf->left = deleting(key, leaf->left);
			return leaf;
		}

	destroy_tree(leaf);
}

void btree::setAmount(int amount) {
	this->amount = amount;
}

void btree::insert(int key)
{
	if (leaf != NULL)
		insert(key, leaf);
	else
	{
		leaf = new TreeBin;
		leaf->key = key;
		leaf->left = NULL;
		leaf->right = NULL;
	}
}

TreeBin* btree::search(int key)
{
	try {
		if (search(key, leaf) == NULL) throw key;
		cout << "Элемент " << (search(key, leaf))->key << " найден и удалён!\n";
		return search(key, leaf);
		deleting(key, leaf);
	}
	catch (int e) {
		cout << "Элемент " << e << " не найден.\n";
		return NULL;
	}
}

void btree::destroy_tree()
{
	if (leaf != NULL) destroy_tree(leaf);
	leaf = NULL;
}

void btree::view() {
	cout << "Все листья: ";
	view(leaf);
}

void btree::sort() {
	this->leaf = sort(leaf);
}

void btree::insert(int key, TreeBin* leaf)
{
	if (key < leaf->key)
	{
		if (leaf->left != NULL)
			insert(key, leaf->left);
		else
		{
			leaf->left = new TreeBin;
			leaf->left->key = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else if (key >= leaf->key)
	{
		if (leaf->right != NULL)
			insert(key, leaf->right);
		else
		{
			leaf->right = new TreeBin;
			leaf->right->key = key;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		}
	}
}

TreeBin* btree::search(int key, TreeBin* leaf)
{
	if (leaf != NULL)
	{
		if (key == leaf->key)
			return leaf;
		if (key < leaf->key)
			return search(key, leaf->left);
		else
			return search(key, leaf->right);
	}
	else return NULL;
}

void btree::destroy_tree(TreeBin* leaf)
{
	if (leaf == NULL) return;
	destroy_tree(leaf->left);
	destroy_tree(leaf->right);
	delete(leaf);
	leaf = NULL;
}

void btree::view(TreeBin* leaf) {
	if (leaf == NULL)
	{
		return;
	}
	cout.setf(ios::showpos);
	cout << leaf->key << " ";
	cout.unsetf(ios::showpos);

	cout.unsetf(ios::dec);
	cout.setf(ios::hex);
	cout << leaf->key << " ";
	cout.unsetf(ios::hex);
	cout.setf(ios::dec);

	view(leaf->left);
	view(leaf->right);
	return;
}

TreeBin* btree::sort(TreeBin* root) {
	int* treeKeys = new int[amount], index = 0;
	fetchKeys(root, treeKeys, index);
	insertSort(treeKeys, amount);
	TreeBin* sortedRoot = nullptr;
	sortTree(&sortedRoot, 0, amount, treeKeys);
	return sortedRoot;
}

void btree::fetchKeys(TreeBin* leaf, int* treeKeys, int& index) {
	if ((leaf->left) == nullptr && (leaf->right) == nullptr) {
		treeKeys[index] = leaf->key;
		index++;
		return;
	};
	if ((leaf->left) != nullptr) fetchKeys((leaf->left), treeKeys, index);
	treeKeys[index] = leaf->key;
	index++;
	if ((leaf->right) != nullptr) fetchKeys((leaf->right), treeKeys, index);
}

void btree::insertSort(int* treeKeys, int amount) {
	int i, j, temp;

	for (i = 1; i < amount; i++) {
		temp = treeKeys[i];
		for (j = i - 1; j >= 0 && temp < treeKeys[j]; j--)
			treeKeys[j + 1] = treeKeys[j];
		treeKeys[j + 1] = temp;
	}
	cout << "\nОтсортировано методом Вставки: ";
	for (i = 0; i < amount; i++) {
		cout << " " << treeKeys[i] << " |";
	}

	
}

void btree::sortTree(TreeBin** p, int n, int k, int* treeKeys) {
	if (n == k) {
		*p = NULL;
		return;
	}
	else {
		int m = (n + k) / 2;
		*p = new TreeBin;
		(*p)->key = treeKeys[m];
		sortTree(&(*p)->left, n, m, treeKeys);
		sortTree(&(*p)->right, m + 1, k, treeKeys);
	}
}

void main()
{
	system("chcp 1251");
	system("cls");
	int search = 0, key = 0;

	btree tree;
	try {
		cout >> tree;
	}
	catch (int e) {
		cout.width(300);
		cout.unsetf(ios::right);
		cout.setf(ios::left);
		cout << "Номер ошибки N" << e << " .\n";
		cout.unsetf(ios::left);
		return;
	}

	for (int i = 0; i < tree.amount; i++) {
		cout.width(115);
		cout.setf(ios::right);
		cout << "Введитие значение листа: ";
		try {
			cin.setf(ios::skipws);
			cin >> key;
			cin.unsetf(ios::skipws);
			if (cin.fail()) throw 2;
			tree.insert(key);
		}
		catch (int e) {
			cout << "Номер ошибки N" << e << " .\n";
			cin.clear();
			cin.ignore(256, '\n');
			i--;
		}
	}

	

	cout.width(115);
	cout.setf(ios::right);
	
	cout << "\n";
	tree.sort();
	cout << "\n";
	cout << "\nПоиск элемента на дереве: ";
	cin.setf(ios::skipws);
	cin >> search;
	cin.unsetf(ios::skipws);
	tree.search(search);

	tree.destroy_tree();
}