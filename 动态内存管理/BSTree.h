BST_t *newBST(CmpFunc_t *cmp, GetKeyFunc_t *getKey);
_Bool BST_insert(BST_t *pBST, const void *pData, size_t size);
const void *BST_search(BST_t *pBST, const void *pKey);
_Bool BST_erase(BST_t *pBST, const void *pKey);
void BST_clear(BST_t *pBST);
int BST_inorder(BST_t *pBST, _Bool (*action)(void *pData));
int BST_rev_inorder(BST_t *pBST, _Bool (*action)(void *pData));
int BST_preorder(BST_t *pBST, _Bool (*action)(void *pData));
int BST_postorder(BST_t *pBST, _Bool (*action)(void *pData));

