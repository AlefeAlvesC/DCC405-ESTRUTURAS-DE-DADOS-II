# 🧮 Trabalho Prático 1 - Construção de Árvores Binárias a partir de Expressões Aritméticas

Este trabalho tem como objetivo desenvolver um algoritmo capaz de construir **árvores binárias** que representem corretamente **expressões aritméticas**, respeitando a **precedência de operadores** e a **estrutura de parênteses**.

---
## 📝 Descrição do Problema

O algoritmo deve:

1. **Analisar a Expressão**
   - Ler a expressão aritmética e identificar corretamente **números**, **operadores** (`+`, `-`, `*`, `/`, `^`) e **parênteses**.

2. **Construir a Árvore**
   - Montar uma árvore binária onde a estrutura reflita a **precedência matemática** e os **níveis de agrupamento por parênteses**.

3. **Implementar Percurso**
    - Garantir que a **avaliação da expressão** seja correta ao percorrer a árvore.

---

## 💡 Exemplo de Comportamento

A estrutura da árvore muda conforme a precedência dos operadores:

- Expressão: `2 * 4 + 3`  
  A árvore será construída de modo que a **multiplicação (`*`)** ocorra antes da **adição (`+`)**.

- Expressão: `2 * (4 + 3)`  
  Os **parênteses** alteram a estrutura, fazendo com que a **adição** seja avaliada antes da **multiplicação**.

---

## 🛠️ Solução Adotada

Cada **nó da árvore** armazena as seguintes informações:

- **Valor**: o conteúdo do nó (ex: `2`, `+`, `*`, `^`, etc.)
- **Prioridade**: baseada na precedência do operador  
  *(0 para números, até 3 para operadores de maior precedência como a exponenciação)*
- **Profundidade**: nível de aninhamento causado por parênteses  
  *(por exemplo, expressões dentro de um par de parênteses têm profundidade 1, duas camadas de parênteses resultam em profundidade 2, e assim por diante)*

Com essas informações, o algoritmo consegue construir corretamente a árvore binária que representa qualquer expressão aritmética válida.

---

## 🖨️ Impressão Formatada da Árvore

Para exibir a árvore de forma estruturada e legível, foi utilizada uma **estrutura de fila (queue)**, facilitando a impressão em **níveis (nível por nível)**.

---

## ✅ Conclusão

Este trabalho proporciona uma compreensão prática de:

- Construção de **árvores de expressão**
- Manipulação de **precedência e agrupamento**
- Uso de **estruturas auxiliares** (como filas) para representação e visualização de árvores
- Com as devidas alterações pode ser também submetido ao jugde beecrowd exercício de número 1463.

A implementação serve como base para estudos futuros envolvendo **interpretação de expressões**, **compiladores**, e **avaliação simbólica** em linguagens de programação.