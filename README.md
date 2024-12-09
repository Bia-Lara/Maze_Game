# Maze Brazil Life 🗺️

Este projeto é um jogo interativo de labirinto em C, onde o jogador navega por diferentes camadas de um labirinto, tomando decisões em cada sala. O objetivo do jogo é explorar o labirinto até encontrar um "fim". 🌟

---

## Sumário 📑

1. [Descrição 🧩](#descrição-)
2. [Funcionalidades ✨](#funcionalidades-)
3. [Como Jogar 🎮](#como-jogar-)
4. [Compilação 🛠️](#Compilação-)
5. [Estrutura do Código 📚](#estrutura-do-código-)
6. [Exemplo de Execução 🖱️](#exemplo-de-execução-)
7. [Contribuições 🤝](#contribuições-)
8. [Desenvolvedores 👩‍💻👨‍💻](#desenvolvedores-)
9. [Licença 📜](#licença-)

---


## Descrição 🧩

O jogo consiste em uma árvore binária onde cada nó representa uma sala do labirinto. Cada sala tem três caminhos possíveis: Esquerda, Centro e Direita. O jogador escolhe um caminho e continua avançando até chegar a um fim. O labirinto é gerado aleatoriamente, e o jogo pode ser jogado novamente após cada tentativa. 🔄

## Funcionalidades ✨

- **Estrutura de Árvore**: O labirinto é representado por uma árvore, onde cada nó tem três filhos (representando os três caminhos possíveis). 🌳
- **Gerador de Finais Aleatórios**: O jogo tem múltiplos finais possíveis, que são escolhidos aleatoriamente quando o jogador chega a uma sala sem filhos. 🎲
- **Jogo Interativo**: O jogador escolhe entre três opções em cada sala, avançando pela árvore até atingir um fim ou cair em uma armadilha. ⚔️
- **Reiniciar Jogo**: Após o fim de um jogo, o jogador pode optar por jogar novamente com um novo labirinto de um tamanho diferente. 🔁

## Como Jogar 🎮

1. O jogo solicita a quantidade de camadas (níveis) do labirinto. Quanto maior o número, mais complexo o labirinto será. ⬆️
2. A cada sala, o jogador deve escolher entre três caminhos: Esquerda, Centro ou Direita. ➡️
3. O jogo continuará até que o jogador chegue a um "fim".
4. O jogador pode optar por jogar novamente com um novo labirinto. 🎉

## Compilação 🛠️

Para compilar o código, utilize um compilador de C, como o `gcc`. Execute o seguinte comando no terminal:

```bash
gcc -o main.c
````

## Estrutura do Código 📚

- **`Node`**: Estrutura que representa uma sala no labirinto. Cada nó possui uma descrição da sala e três ponteiros para os caminhos (esquerda, centro e direita). 🏠
- **`createNode`**: Função que cria um novo nó (sala) com uma descrição fornecida. 🔨
- **`createRoom`**: Função que gera o labirinto. Ela cria um nó para cada sala e decide se a sala é uma sala de jogo ou se é um "fim". 🛤️
- **`getRandomEnding`**: Função que escolhe aleatoriamente um final para o labirinto, podendo ser uma saída ou uma morte. 🎲
- **`init_maze`**: Função principal que inicia o jogo. Ela imprime a descrição da sala atual e aguarda a escolha do jogador. 🚪
- **`freeMaze`**: Função que libera a memória utilizada pelo labirinto ao final do jogo. 💾


## Exemplo de Execução 🖱️

```plaintext
Digite a quantidade de niveis no labirinto (numero positivo): 3
Voce esta na camada 1 do labirinto. Escolha: (1) Esquerda, (2) Centro, (3) Direita.
Escolha uma opcao (1, 2 ou 3): 1
Voce esta na camada 2 do labirinto. Escolha: (1) Esquerda, (2) Centro, (3) Direita.
Escolha uma opcao (1, 2 ou 3): 2
Voce esta na camada 3 do labirinto. Escolha: (1) Esquerda, (2) Centro, (3) Direita.
Escolha uma opcao (1, 2 ou 3): 3
Voce encontrou uma saida que leva direto para uma fila do SUS. Agora e so esperar! (Fim)
```
## Contribuições 🤝

Este projeto é open-source! Se você quiser contribuir, fique à vontade para fazer um fork, enviar um pull request, ou melhorar o código de outras maneiras. 💡

## Desenvolvedores 👩‍💻👨‍💻

- [Ana Beatriz L. G.](https://github.com/Bia-Lara)
- [Fhelippe Guedes](https://github.com/F-Guedes2003)

## Licença 📜

Este projeto está licenciado sob a Licença MIT - veja o arquivo LICENSE para mais detalhes. 🔐


