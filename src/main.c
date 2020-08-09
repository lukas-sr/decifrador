/* Tarefa de decifrar uma cifra
 *
 * Dica: veja em referencia/cifrador.c o codigo-fonte do programa
 * que gerou as cifras que voce precisa decifrar!
 */

#include <stdio.h>

#define TAM_BUFFER 64
char buffer_entrada[TAM_BUFFER];
char buffer_saida[TAM_BUFFER];

const char senha[] = "SENHASECRETA";

char soma_modulo_alfabeto(char a, char b) {
  char a0, b0, c0;
  if (a>= 'A' && a<= 'Z') {
    /* Entrada */
    a0 = a - 'A';
    /* Palavra-chave */
    b0 = b - 'A';
    c0 = 'A'+((a0-b0)+('Z'-'A'+1))%('Z'-'A'+1);
    return c0;
  } else return a;
}

int main() {

  int i = 0, j = 0;

  /* Leitura da entrada */
  fgets(buffer_entrada, TAM_BUFFER, stdin);

  for (i=0; (i<TAM_BUFFER) && (buffer_entrada[i]!='\0') && (buffer_entrada[i]!='\n'); i++) {
    buffer_saida[i] = soma_modulo_alfabeto(buffer_entrada[i], senha[j]);
    j++;
    if (senha[j]=='\0') j=0;
  }

  buffer_saida[i]='\0';

  /* Escrever saida na tela */
  printf("%s\n", buffer_saida);

  return 0;
}
