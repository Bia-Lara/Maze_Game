#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

// Função que gera fins diferentes
const char* getRandomEnding() {
    const char* endings[] = {
        "Voce encontrou uma saida secreta e conseguiu se salvar! (Fim)",
        "Voce encontrou uma porta e conseguiu sair do labirinto! (Fim)",
        "Voce encontrou um poco dos desejos e fez um pedido de sair do labirinto! (Fim)",
        "Voce caiu em uma armadilha perigosa e morreu! (Fim)",
        "Voce encontrou uma armadilha de areia movediça e morreu! (Fim)",
       "Voce foi atingido por flechas vindas do teto e morreu! (Fim)",
        "Voce foi atacado por um monstro e morreu! (Fim)",
        "Voce encontrou um portal para outro labirinto! (Fim)",
        "Voce caiu em um poco de lava e morreu! (Fim)",
        "Voce foi capturado por guardioes do labirinto que te comeram vivo! (Fim)",
        "Voce tropecou em um bau vazio... azar! (Fim)",
        "Voce foi teletransportado para o inicio do labirinto!",
        "Voce caiu em um buraco sem fim! (Fim)"
        
    };
    int index = rand() % 13; 
    return endings[index];
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
        room->left = createNode(getRandomEnding());
        room->center = createNode(getRandomEnding());
        room->right = createNode(getRandomEnding());
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
void printMaze(Node* node, int layer) {
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

int init_maze(Node *maze_node) {
    int option;

    printf("%s\n", maze_node->description);

    if (maze_node->left == NULL && maze_node->center == NULL && maze_node->right == NULL) {
        printf("Fim do jogo!\n");
        return 0;
    }

    do {
        printf("Escolha uma opcao (1, 2 ou 3): ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                return init_maze(maze_node->left); 
            case 2:
                return init_maze(maze_node->center);
            case 3:
                return init_maze(maze_node->right);  
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (1); 
}


int main() {
    srand(time(NULL));
    int toContinue = 1;
    int qntLayers=0;

    while(toContinue) {
        printf("\nDigite a quantidade de niveis no labirinto (numero positivo): ");

        
        while (scanf("%d", &qntLayers) != 1 || qntLayers <= 0) {
            printf("Entrada invalida! Por favor, digite um numero inteiro positivo: ");
        }
        
        Node *maze = createRoom(1, qntLayers); 
        init_maze(maze);
        printf("\n\nDo you want to play again:\n1.yes \nPress any NUMBER to stop this shit\n");

        if (scanf("%d", &toContinue) != 1) {
            toContinue = 0;
        }

        if(toContinue != 1) { 
            freeMaze(maze);
            break;
        }

        printf("\n\n");
    }

    return 0;
}
