#include <stdio.h>
#include <stdlib.h>


struct tree {
    int data;
    struct tree *left;
    struct tree *right;
};


typedef struct tree Tree;

Tree *CreateTree(int data){
    Tree *p = (Tree*)malloc(sizeof(Tree));
    p-> data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}


Tree *InsertData(Tree *root, int data){

    if(root == NULL){
        return CreateTree(data);
    }
    if(data < root->data){
        root->left = InsertData(root->left, data);

    }
    else{
        root->right = InsertData(root->right, data);
    }
    return root;
}




//FindMinData

Tree *MinData(Tree *root){
    Tree *aux = root;
    while (aux && aux->left != NULL){
        aux = aux->left;
    }
    return aux;
}

//Remover dados

Tree *RemoveData (Tree *root, int dataRemove){

    Tree *aux = NULL;
    if(root == NULL){
        return root;
    }

    if(dataRemove < root->data){

        root->left = RemoveData(root->left, dataRemove);

    }
    else if(dataRemove > root->data){
        root->right = RemoveData(root->right, dataRemove);
    }
    else{
        if(root->right==NULL){
            aux = root->left;
            free(root);
            return aux;
        } else if( root->left == NULL){
            aux= root->right;
            free(root);
            return aux;
        }

        aux = MinData(root->right);
        root->data = aux->data;
        root->right = RemoveData(root->right, aux->data);

    }
    return root;

}


void PrintPreorder(Tree *root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    PrintPreorder(root->left);
    PrintPreorder(root->right);
}

void PrintInorder(Tree *root){
    if(root ==NULL){
        return;
    }
    PrintInorder(root->left);
    printf("%d ", root->data);
    PrintInorder(root->right);
}

void PrintPostorder(Tree *root){
    if(root ==NULL){
        return;
    }
    PrintPostorder(root->left);
    PrintPostorder(root->right);
    printf("%d ", root->data);

}




int main() {

    Tree *node = NULL;
    int  option, data, typePrint;
    char moreData;


    do{

        printf("--- TREE --- \n");
        printf("SELECT AN OPTION: \n");
        printf("1 - FOR INSERT DATA \n");
        printf("2 - FOR PRINT TREE\n");
        printf("3 - FOR REMOVE DATA\n");
        printf("9 - EXIT\n");
        printf("CHOOSE THE OPTION: ");
        scanf("%d", &option);
        printf("\n");

        switch (option) {
            case 1:
                printf("YOU CHOSE - INSERT DATA\n");
                printf("ENTER DATA:");
                scanf("%d",&data);
                node = InsertData(node, data);
                printf("DO YOU WISH TO CONTINUE(S/N): ");
                scanf("%s", &moreData);
                while (moreData == 's' || moreData == 'S'){
                    printf("ENTER DATA: ");
                    scanf("%d",&data);
                    node = InsertData(node, data);
                    printf("DO YOU WISH TO CONTINUE(S/N): ");
                    scanf("%s", &moreData);
                };
                break;
            case 2:
                printf("YOU CHOSE - PRINT TREE\n");
                printf("---SELECT PRINT TYPE---\n");
                printf("1 - INORDER\n");
                printf("2 - PREORDER\n");
                printf("3 - POSTORDER\n");
                printf("CHOOSE THE OPTION: ");

                scanf("%d", &typePrint);
                if(typePrint == 1){
                    PrintInorder(node);
                    printf("\n");
                }
                else if(typePrint == 2){
                    PrintPreorder(node);
                    printf("\n");

                }
                else{
                    PrintPostorder(node);
                    printf("\n");

                }

                break;
            case 3:

                printf("YOU CHOSE - REMOVE DATA\n");
                printf("ENTER DATA TO REMOVE: ");
                scanf("%d",&data);
                node = RemoveData(node, data);

                break;
        }





    } while (option != 9);
    printf("\n");
    printf("Bye!");




    return 0;


}