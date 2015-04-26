template <class T>
class HuffmanTree {
    private:
        HuffmanTreeNode<T> *root;
        void MergeTree(HuffmanTreeNode<T> &ht1, HuffmanTreeNode<T> &ht2, HuffmanTreeNode<T> *parent);
        void DeleteTree(HuffmanTreeNode<T> *root);
    public:
        HuffmanTree(T weight[], int n);
        virtual ~HuffmanTree()
            DeleteTree(root);
}

template <class T>
HuffmanTree<T>:: HuffmanTree(T weight[], int n) {
    MinHeap<HuffmanTreeNode<T>> heap(n);
    HuffmanTreeNode<T> *parent, firstchild, secondchild;
    HuffmanTreeNode<T> *NodeList = new HuffmanTreeNode<T>[n];
    for (int i=0; i<n; i++) {
        NodeList[i].info = weight[i];
        NodeList[i].parent = NodeList[i].left = NodeList[i].right = NULL;
        heap.Insert(NodeList[i]);
    }
    for (i=0; i<n-1; i++){
        parent = new HuffmanTreeNode<T>;
        firstchild = heap.RemoveMin();
        secondchild = heap.RemoveMin();
        MergeTree(firstchild, secondchild, parent);
        heap.Insert(*parent);
        root = parent;
    }
    delete []NodeList;
}
