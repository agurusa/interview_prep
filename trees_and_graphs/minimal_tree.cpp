// #include <array>

class TreeNode{
public:
	TreeNode(int d){data = d;}
	TreeNode *left = NULL;
	TreeNode *right = NULL;
	int data;
	friend bool operator == (const TreeNode lhs, const TreeNode rhs){
		if(lhs.data == rhs.data){
			return true;
		}
		return false;
	}
	friend std::ostream& operator <<(std::ostream& os, const TreeNode *tn){
		os << tn->data;
		return os;
	}
	friend std::ostream& operator <<(std::ostream& os, const TreeNode &tn){
		// TreeNode * next;
		// os << tn.data << " :: ";
		// std::vector<TreeNode*> nodes = {};
		// std::vector<TreeNode*> children_nodes = {};
		// next = tn.left;
		// nodes.push_back(tn.right);
		// while(next!= NULL){
		// 	os << next->data << " ";
		// 	children_nodes.push_back(next->left);
		// 	children_nodes.push_back(next->right);
		// 	if(nodes.empty()){
		// 		os << "::";
		// 		nodes = children_nodes;
		// 		children_nodes.clear();
		// 	}
		// 	next = nodes[0];
		// 	nodes.erase(nodes.begin());
		// }
		os << tn.data;
		return os;
	}
};
class Tree{
public:
	Tree(){};
	TreeNode *root = NULL;
	void Insert(TreeNode *tn){
		if(root == NULL){
			root = tn;
		}
		else{
			std::vector<TreeNode*> nodes = {};
			TreeNode*next = root;
			while(next!= NULL){
				TreeNode *l = next->left;
				TreeNode *r = next->right;
				if(l == NULL){
					next->left = tn;
					return;
				}
				else if (r == NULL){
					next->right = tn;
					return;
				}
				else{
					nodes.push_back(l);
					nodes.push_back(r);
					next = nodes[0];
					nodes.erase(nodes.begin());
				}
			}
		}
	}

	TreeNode * minimum(){
		return root;
	}

	friend bool operator == (const Tree lhs, const Tree rhs){
		std::vector<TreeNode*> l_nodes = {};
		std::vector<TreeNode*> r_nodes = {};
		TreeNode *l = lhs.root;
		TreeNode *r = rhs.root;
		while(l!= NULL && r!=NULL){
			if(l!=r){
				return false;
			}
			l_nodes.push_back(l->left);
			l_nodes.push_back(l->right);
			r_nodes.push_back(r->left);
			r_nodes.push_back(r->right);
			l = l_nodes[0];
			l_nodes.erase(l_nodes.begin());
			r = r_nodes[0];
			r_nodes.erase(r_nodes.begin());
		}
		if(l == NULL && r == NULL){
			return true;
		}
		return false;
	}
	friend std::ostream& operator <<(std::ostream& os, const Tree& tree){
		TreeNode *next;
		std::vector<TreeNode*> nodes = {};
		std::vector<TreeNode*> next_level = {};
		nodes.push_back(tree.root);
		next = nodes[0];
		while(next!= NULL){
			next_level.push_back(next->left);
			next_level.push_back(next->right);
			os<< next << " ";
			nodes.erase(nodes.begin());
			if(nodes.empty()){
				os << "::";
				nodes = next_level;
				next_level.clear();
			}
			next = nodes[0];
		}
		return os;
	}
};
TreeNode* minimal_binary_search_tree(std::vector<int> input, int start, int end, Tree * tree){
	if(end<start){
		return NULL;
	}
	int mid = (start + end)/2;
	TreeNode *n = new TreeNode(input[mid]);
	n->left = minimal_binary_search_tree(input, start, mid - 1, tree);
	n->right = minimal_binary_search_tree(input, mid + 1, end, tree);
	return n;
}

Tree* minimal_tree(std::vector<int> input, int start, int end, Tree *tree){
	if(end < start){
		return NULL;
	}
	int mid = (start + end)/2;
	TreeNode *n = new TreeNode(input[mid]);
	tree->Insert(n);
	minimal_tree(input, start, mid - 1, tree);
	minimal_tree(input, mid + 1, end, tree);
	return tree;
}