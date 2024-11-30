#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de um nó da árvore
typedef struct Node {
    char description[200]; // Descrição da sala
    struct Node *left;     // Caminho 1
    struct Node *center;   // Caminho 2
    struct Node *right;    // Caminho 3
} Node;

// Função cria um novo nó
Node* createNode(const char *desc) {
    Node *node = (Node*)malloc(sizeof(Node));
    strcpy(node->description, desc);
    node->left = NULL;
    node->center = NULL;
    node->right = NULL;
    return node;
}

// Função cria o labirinto
Node* createRoom(int layer, int qntLayers) {
    char description[200];
    sprintf(description, "Voce esta na camada %d do labirinto. Escolha: (1) Esquerda, (2) Centro, (3) Direita.", layer);

    Node *room = createNode(description);

    if (layer < qntLayers) {
        room->left = createRoom(layer + 1, qntLayers);     
        room->center = createRoom(layer + 1, qntLayers);   
        room->right = createRoom(layer + 1, qntLayers);    
    } else {
        room->left = createNode("Voce encontrou uma saida secreta! (Fim)");
        room->center = createNode("Voce caiu em uma armadilha! (Fim)");
        room->right = createNode("Voce encontrou um bau de tesouro! (Fim)");
    }

    return room;
}

// Função para liberar a memória da árvore
void freeMaze(Node* node) {
    if (node != NULL) {
        freeMaze(node->left);
        freeMaze(node->center);
        freeMaze(node->right);
        free(node);
    }
}

// Função para depuração (remover quando estiver tudo pronto)
void printMaze(Node* node, int layer, int qntLayers) {
    if (node == NULL) {
        return; 
    }
    
    // Exibe a descrição da sala, com indentação baseada na camada
    printf("%*s%s\n", layer * 2, "", node->description);

  
    if (node->left != NULL) {
        printMaze(node->left, layer + 1);    
    }

     if (node->center != NULL) {
        printMaze(node->center, layer + 1);    
    }
   
    if (node->right != NULL) {
        printMaze(node->right, layer + 1);   
    }
}

int main() {
    // Constrói o labirinto de acordo com o número de camadas passadas no parâmetro;
    Node *maze = createRoom(1, 3); 

    printf("Estrutura do Labirinto:\n");
    printMaze(maze, 1, 3);

    freeMaze(maze);

    return 0;
}
