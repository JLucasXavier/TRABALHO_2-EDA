#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>
#include "trie.h"

#define TAM 26 

int indexAlfabeto(char letra){
    return letra-'a';
} 

Trie *criaNo(char v){
    Trie *no = (Trie*)malloc(sizeof(Trie));
    no->letra=v;
    no->termino=0;
    for(int i=0; i<TAM; i++){
        no->filhos[i]=NULL;
        no->ocupacao=0;
    }
    return no;
}

Trie *criaTrie(){
    Trie *t = criaNo(' ');
    t->termino = 1;
    return t;
}

void inserePalavra(Trie *t, char *palavra){
    for(int i=0; palavra[i]!='\0';i++){
        int indexLetra=indexAlfabeto(tolower(palavra[i]));
        if(t->filhos[indexLetra]==NULL){
            Trie *no = criaNo(tolower(palavra[i]));
            t->filhos[indexLetra] = no;
            t->ocupacao=t->ocupacao+1;
            t=no;
        }else{
            t=t->filhos[indexLetra];
        }
    }
    t->termino=1;
}

int buscarPalavra(Trie *t, char *palavra){
    for(int i=0;palavra[i]!='\0';i++){
        int indexLetra=indexAlfabeto(tolower(palavra[i]));
        if(t->filhos[indexLetra]==NULL){
            return 0;
        }else{
            t=t->filhos[indexLetra];
        }
    }
    if(t->termino==0){
        return 0;
    }else{
        return 1;
    }
}

Trie* buscarPrefixo(Trie *t, char *palavra){
    for(int i=0;palavra[i]!='\0';i++){
        int indexLetra=indexAlfabeto(tolower(palavra[i]));
        if(t->filhos[indexLetra]==NULL){
            return NULL;
        }else{
            t=t->filhos[indexLetra];
        }
    }
    return t;
}

void removerPalavra(Trie *t, char *palavra)
{
 /* implementar remoca de palavras */
}


void alphabetize2(Trie * t, char prefixo[])
{
    int i;

    if (t->termino == 1){
        printf("%s\n", prefixo); 
    }

    for (i = 0; i < TAM; ++i)
    {
        if (t->filhos[i] != NULL)
        {
            char ch = t->filhos[i]->letra;
            
            int l = strlen(prefixo);
            if(l > 0){
                char novo_prefixo[l];
                strcpy(novo_prefixo, prefixo);
                strncat(novo_prefixo, &ch, 1); 
                alphabetize2(t->filhos[i], novo_prefixo);
            }
            else{
                char novo_prefixo[] = {ch, '\0'};
                alphabetize2(t->filhos[i], novo_prefixo);
            }
        }
    }
}

void alphabetize(Trie * t){
    char prefixo[] = "";
    alphabetize2(t, prefixo);
}

void liberar(Trie *t){
    
    int i;
    for (i = 0; i < TAM; ++i)
        if (t->filhos[i] != NULL)
            liberar(t->filhos[i]);
    
    free(t);
}