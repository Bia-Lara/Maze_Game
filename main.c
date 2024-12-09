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
        "Voce encontrou uma saida que leva direto para uma fila do SUS. Agora e so esperar! (Fim)",
        "Voce achou uma porta, mas ela da para um protesto no meio de uma avenida congestionada. Boa sorte! (Fim)",
        "Voce caiu em um buraco cheio de contas de luz atrasadas e boletos. O sufoco e real! (Fim)",
        "Voce encontrou um portal que te leva direto para um churrasco na laje. So alegria! (Fim)",
        "Voce tropecou em um cartao de credito estourado. Nao foi dessa vez! (Fim)",
        "Voce encontrou um celular antigo e conseguiu pedir ajuda no grupo da familia. Alguem vai te buscar! (Fim)",
        "Voce foi sugado para uma maquina de cafe quebrada no escritorio. Mais um dia normal! (Fim)",
        "Voce saiu do labirinto, mas parou direto na fila do INSS. Agora e so aguardar... uns anos! (Fim)",
        "Voce conseguiu escapar e foi direto para a praia. Infelizmente, choveu o dia inteiro. (Fim)",
        "Voce encontrou uma saida, mas foi parado por um fiscal e teve que pagar uma taxa. (Fim)",
        "Voce achou um Wi-Fi aberto e decidiu ficar. Quem precisa sair? (Fim)",
        "Voce foi teleportado para a Black Friday, mas so tinha promocao de panela. (Fim)",
        "Voce escapou do labirinto, mas entrou direto em um buzao lotado na hora do rush. (Fim)"
        "Voce caiu no Rio de Janeiro e morreu em um tiroteio (FIM)",
        "Voce caiu em Sao Paulo e acabou nas drogas (FIM)",
        "Voce acordou e viu que tudo não se passava de um sonho (FIM)",
        "Voce escapou (FIM)",
        "Voce caiu em Setealem (FIM)",
        "voce tropeçou em um anao, bateu a cabeca e morreu (FIM)",
        "Voce chegou ao fim e conseguiu sair da matrix (FIM)",
        "Voce encontrou uma saida, mas estava no meio de um assalto e virou refem! (Fim)",
        "Voce escapou do labirinto, mas caiu direto em uma furada: um 'rolezinho' na quebrada. (Fim)",
        "Voce encontrou uma escada, mas no fim dela estava o chefe do tráfico cobrando favores. (Fim)",
        "Voce saiu do labirinto e foi parar no boca de fumo. A coisa nao foi boa! (Fim)",
        "Voce encontrou um mapa, mas ele era só o caminho para o ponto de uma quadrilha. (Fim)",
        "Voce estava indo embora, mas foi pego em flagrante no arrastão. (Fim)",
        "Voce escapou, mas caiu em um esquema de falso motoboy que te levou para lugar nenhum. (Fim)",
        "Voce encontrou um portal, mas ele te levou para o meio de uma negociação duvidosa. (Fim)",
        "Voce finalmente achou a saida, mas foi sequestrado por um 'parente' desconhecido querendo dinheiro. (Fim)",
        "Voce escapou, mas encontrou uma boca de fumo e foi confundido com um delivery. (Fim)",
        "Voce encontrou uma porta e correu para a liberdade, mas foi parar em um carro roubado. (Fim)",
        "Voce achou uma saida, mas entrou em um esquema de golpe do bilhete premiado. (Fim)",
        "Voce achou um esconderijo e pensou que era seguro, mas estava na casa de um informante. (Fim)",
        "Voce finalmente encontrou a saida, mas caiu em uma emboscada dos 'parceiros'. (Fim)",
        "Voce encontrou a saida, mas estava no meio de um 'rolezinho' e foi abordado pela policia. (Fim)"

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
