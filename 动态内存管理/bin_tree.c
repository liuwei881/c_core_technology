#include <stdio.h>

typedef struct Node {
    struct Node *left, *right;
    size_t size;
    char data[];
} Node_t;

typedef const void *GetKeyFunc_t(const void *dData);
typedef int CmpFunc_t(const void *pKey1, const void *pKey2);

typedef struct {
    struct Node *pRoot;
    CmpFunc_t *cmp;
    GetKeyFunc_t *getKey;
} BST_t;

const void *defaultGetKey(const void *pData){return pData;}

BST_t *newBST(CmpFunc_t *cmp, GetKeyFunc_t *getKey){
    BST_t *pBST = NULL;
    if(cmp != NULL){
        pBST = malloc(sizeof(BST_t));
    }
    if(pBST != NULL){
        pBST->pRoot = NULL;
        pBST->cmp = cmp;
        pBST->getKey = (getKey != NULL) ? getKey : defaultGetKey;
    }
    return pBST;
}

static _Bool insert(BST_t *pBST, Node_t **ppNode, const void *pData, size_t size);

_Bool BST_insert(BST_t *pBST, const void *pData, size_t size){
    if(pBst == NULL || pData == NULL || size == 0){
        return false;
    }
    return insert(pBST, &(pBST->pRoot), pData, size);
}

static _Bool insert(BST_t *pBST, Node_t **ppNode, const void *pData, size_t size){
    Node_t *pNode = *ppNode;
    if(pNode == NULL){
        pNode = malloc(sizeof(Node_t) + size);
        if(pNode != NULL){
            pNode->left = pNode->right = NULL;
            memcpy(pNode->data, pData, size);
            *ppNode = pNode;
            return true;
        }else{
            return false;
        }
    }else{
        const void *key1 = pBST->getKey(pData), *key2 = pBST->getKey(pNode->data);
        if(pBST->cmp(key1, key2) < 0){
            return insert(pBST, &(pNode->left), pData, size);
        }else{
            return insert(pBST, &(pNode->right), pData, size);
        }

    }

}

static const void *search(BST_t *pBST, const Node_t *pNode, const void *pKey);

const void *BST_search(BST_t *pBST, const void *pKey){
    if(pBST == NULL || pKey == NULL){
        return NULL;
    }
    return search(pBST, pBST->pRoot, pKey);
}

static const void *search(BST_t *pBST, const Node_t *pNode, const void *pKey){
    if(pNode == NULL){
        return NULL;
    }else{
        int cmp_res = pBST->cmp(pKey, pBST->getKey(pNode->data));
        if(cmp_res == 0){
            return pNode->data;
        }else if(cmp_res < 0){
            return search(pBst, pNode->left, pKey);
        }else{
            return search(pBST, pNode->right, pKey);
        }
    }
}

static Node_t *detachMin(Node_t **ppNode){
    Node_t *pNode = *ppNode;
    if(pNode == NULL){
        return NULL;
    }else if(pNode->left != NULL){
        return detachMin(&(pNode->left));
    }else{
        *ppNode = pNode->right;
        return pNode;
    }
}

static _Bool erase(BST_t *pBST, Node_t **ppNode, const void *pKey);

_Bool BST_erase(BST_t *pBST, const void *pKey){
    if(pBST == NULL || pKey == NULL){
        return false;
    }
    return erase(pBST, &(pBST->pRoot), pKey);
}

static _Bool erase(BST_t *pBST, Node_t **ppNode, const void *pKey){
    Node_t *pNode = *ppNode;
    if(pNode == NULL){
        return false;
    }
    int cmp_res = pBST->cmp(pKey, pBST->getKey(pNode->data));
    if(cmp_res < 0){
        return erase(pBST, &(pNode->left), pKey);
    }else if(cmp_res > 0){
        return erase(pBST, &(pNode->right), pKey);
    }else{
        if(pNode->left == NULL){
            *ppNode = pNode->right;
        }else if(pNode->right == NULL){
            *ppNode = pNode->left;
        }else{
            Node_t *pMin = detachMin(&(pNode->right));
            *ppNode = pMin;
            pMin->left = pNode->left;
            pMin->right = pNode->right;
        }
        free(pNode);
        return true;
    }
}

static void clear(Node_t *pNode);

void BST_clear(BST_t *pBST){
    if(pBST != NULL){
        clear(pBST->pRoot);
        pBST->pRoot = NULL;
    }
}

static void clear(Node_t *pNode){
    if(pNode != NULL){
        clear(pNode->left);
        clear(pNode->right);
        free(pNode);
    }
}

static int inorder(Node_t *pNode, _Bool (*action)(void *pData));

int BST_inorder(BST_t *pBST, _Bool (*action)(void *pData)){
    if(pBST == NULL || action == NULL){
        return 0;
    }else{
        return inorder(pBST->pRoot, action);
    }
}

static int inorder(Node_t *pNode, _Bool(*action)(void *pData)){
    int count = 0;
    if(pNode == NULL){
        return 0;
    }
    count = inorder(pNode->left, action);
    if(action(pNode->data)){
        ++count;
    }else{
        count += inorder(pNode->right, action);
    }
    return count;
}



