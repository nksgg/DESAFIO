#include <stdio.h>
#include <string.h>
#include <ctype.h>

void escreveUnidade(int n, int inicial) {
    char *unidades[] = {"", "Um", "Dois", "Três", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove"};
    if (n > 0) {
        printf("%s", unidades[n]);
    } else if (inicial) {
        printf("Zero");
    }
}

void escreveDezena(int n) {
    char *dezenas[] = {"", "", "Vinte", "Trinta", "Quarenta", "Cinquenta", "Sessenta", "Setenta", "Oitenta", "Noventa"};
    if (n > 1) {
        printf("%s", dezenas[n]);
    }
}

void escreveDezenaComposta(int n) {
    char *compostas[] = {"Dez", "Onze", "Doze", "Treze", "Quatorze", "Quinze", "Dezesseis", "Dezessete", "Dezoito", "Dezenove"};
    if (n >= 10 && n < 20) {
        printf("%s", compostas[n - 10]);
    }
}

void escreveCentena(int n) {
    char *centenas[] = {"", "Cento", "Duzentos", "Trezentos", "Quatrocentos", "Quinhentos", "Seiscentos", "Setecentos", "Oitocentos", "Novecentos"};
    if (n > 0) {
        if (n == 1) {
            printf("Cem");
        } else {
            printf("%s", centenas[n]);
        }
    }
}

void escrevePorExtenso(int n) {
    if (n == 0) {
        printf("Zero Reais\n");
        return;
    }

    int centenasMilhar = n / 100000;
    int dezenasMilhar = (n / 10000) % 10;
    int unidadesMilhar = (n / 1000) % 10;
    int centenas = (n / 100) % 10;
    int dezenas = (n / 10) % 10;
    int unidades = n % 10;

    // Escreve parte dos milhares
    if (centenasMilhar > 0) {
        escreveUnidade(centenasMilhar, 1);
        printf("cento ");
    }

    if (dezenasMilhar == 1) {
        escreveDezenaComposta(dezenasMilhar * 10 + unidadesMilhar);
    } else {
        escreveDezena(dezenasMilhar);
        if (dezenasMilhar > 1 && unidadesMilhar > 0) printf(" e ");
        escreveUnidade(unidadesMilhar, 0);
    }

    if (centenasMilhar > 0 || dezenasMilhar > 0 || unidadesMilhar > 0) {
        printf(" Mil");
    }

    // Escreve parte das centenas
    if (centenas > 0) {
        if (n >= 1000) {
            printf(", ");
        }
        escreveCentena(centenas);
        if ((dezenas > 0 || unidades > 0) && centenas != 0) printf(" e ");
    }

    if (dezenas == 1) {
        escreveDezenaComposta(dezenas * 10 + unidades);
    } else {
        escreveDezena(dezenas);
        if (dezenas > 1 && unidades > 0) printf(" e ");
        escreveUnidade(unidades, 0);
    }

    printf(" Reais\n");
}

int main() {
    int numero;

    printf("Digite um número inteiro de até 6 dígitos: ");
    scanf("%d", &numero);

    if (numero < 0 || numero > 999999) {
        printf("Número fora do intervalo permitido!\n");
    } else {
        escrevePorExtenso(numero);
    }

    return 0;
}
