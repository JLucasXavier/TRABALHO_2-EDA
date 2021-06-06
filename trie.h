struct trie{
    char letra;
    int termino;
    struct trie *filhos[26];
    int ocupacao;
};

typedef struct trie Trie;

Trie *criaNo(char v);

void inserePalavra(Trie *t, char *palavra);

int buscarPalavra(Trie *t, char *palavra);

Trie* buscarPrefixo(Trie *t, char *palavra);

void removerPalavra(Trie *t, char *palavra);

Trie *criaTrie();

void alphabetize(Trie * t);

void alphabetize2(Trie * t, char prefixo[])

void liberar(Trie *t);