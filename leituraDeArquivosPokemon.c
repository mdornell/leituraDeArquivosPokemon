#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5000

typedef struct pokemon{
    char nome[100];
    char especie[100];
    float peso;
    float altura;
    int poder;
}pokemon;

typedef struct city{
    char nomes[100];
    char tipos[50];
    char arquivos[100];
    pokemon * pokemons;
}city;

int menu(){
    int i;
    printf("1. Todas as cidades do tipo Fogo\n");
    printf("2. Pokemons com o maior poder\n");
    printf("3. Pokemons com menor IMC\n");
    printf("4. Cidades com maior quantidade de Pokemons\n");
    printf("0. Sair\n");
    printf("Escolha a operacao a ser printada :\n");
    scanf("%d",&i);

    return i;
}

int operacoes(city * cidades,int qtCidades,int * contAux){
    int i = 1;

    while(i!=0){
    	system("Cls");
        i = menu();
        if(i==1){
            pokemonsFogo(cidades,qtCidades,contAux);
        }else if(i==2){
            pokeMaisPoderoso(cidades,qtCidades,contAux);
        }else if(i==3){
            menorIMC(cidades,qtCidades,contAux);
        }else if(i==4){
            cidadeMaisPokemons(cidades,qtCidades,contAux);
        }
        system("Pause");
    }
    
}

int lerArquivoPrincipal(city * cidade){
    int i = 0;

    FILE * principal;
    principal = fopen("cidades.txt","r");
    
    while(!feof(principal)){    
        fscanf(principal,"%s",cidade[i].nomes);
        fscanf(principal,"%s",cidade[i].tipos);
        fscanf(principal,"%s",cidade[i].arquivos);

        i++;    
    }

    fclose(principal);
    return i;
}

void lerCidades(city * cidades,int qtCidades,int * contAux){
    int i,j=0;

    FILE * cidade;
    for(i=0;i<qtCidades;i++){
        
        cidade = fopen(cidades[i].arquivos,"r");
        cidades[i].pokemons = (pokemon *)malloc(TAM * sizeof(pokemon));
        
        for(j=0;!feof(cidade);j++){
            fscanf(cidade,"%s",cidades[i].pokemons[j].nome);
            fscanf(cidade,"%s",cidades[i].pokemons[j].especie);
            fscanf(cidade,"%f",&cidades[i].pokemons[j].peso);
            fscanf(cidade,"%f",&cidades[i].pokemons[j].altura);
            fscanf(cidade,"%d",&cidades[i].pokemons[j].poder);
        }
        contAux[i] = j;
    }   
}

int pokemonsFogo(city * cidades,int qtCidades,int * contAux){
    int i, j;

    printf("\n//Pokemons de Fogo//\n");
    for(i=0;i<qtCidades;i++){
        if(!(strcmp(cidades[i].tipos,"Fogo"))){
            printf("//%s//\n",cidades[i].nomes);
            printf("//Nome//\t//Especie//\t//Peso//\t//Altura//\t//Poder//\n");
            for(j=0;j<contAux[i];j++){
                printf("//%s//\t",cidades[i].pokemons[j].nome);
                printf("//%s//\t",cidades[i].pokemons[j].especie);
                printf("//%.1f//\t",cidades[i].pokemons[j].peso);
                printf("//%.2f//\t",cidades[i].pokemons[j].altura);
                printf("//%d//\n",cidades[i].pokemons[j].poder);
            }
            printf("\n");
        }
    }
}

int pokeMaisPoderoso(city * cidades,int qtCidades,int * contAux){
    int i,j;
    int maiorPoder = cidades[0].pokemons[0].poder;

    for(i=0;i<qtCidades;i++){
        for(j=0;j<contAux[i];j++){
            if(maiorPoder < cidades[i].pokemons[j].poder){
                maiorPoder = cidades[i].pokemons[j].poder;
            }
        }
    }

    printf("\n//Pokemons Mais Poderosos//\n");
    printf("//Tipo//\t//Nome//\t//Especie//\t//Peso//\t//Altura//\t//Poder//\n");
    for(i=0;i<qtCidades;i++){
        for(j=0;j<contAux[i];j++){
            if(cidades[i].pokemons[j].poder == maiorPoder){
                printf("//%s//\t",cidades[i].tipos);
                printf("//%s//\t",cidades[i].pokemons[j].nome);
                printf("//%s//\t",cidades[i].pokemons[j].especie);
                printf("//%.1f//\t",cidades[i].pokemons[j].peso);
                printf("//%.2f//\t",cidades[i].pokemons[j].altura);
                printf("//%d//\n",cidades[i].pokemons[j].poder);
            }
        }
    }
    printf("\n");
}


int menorIMC(city * cidades,int qtCidades,int * contAux){
    int i,j;
    float calImc;
    float menorImc;

    calImc = cidades[0].pokemons[0].peso / (cidades[0].pokemons[0].altura * cidades[0].pokemons[0].altura);
    menorImc = calImc;

    for(i=0;i<qtCidades;i++){
        for(j=0;j<contAux[i];j++){
            calImc = cidades[i].pokemons[j].peso / (cidades[i].pokemons[j].altura * cidades[i].pokemons[j].altura);
            if(menorImc > calImc){
                menorImc = calImc;;
            }
        }
    }

    printf("\nMenor IMC : %.2f\n",menorImc);
    printf("//Tipo//\t//Nome//\t//Especie//\t//Peso//\t//Altura//\t//Poder//\n");
    for(i=0;i<qtCidades;i++){
        for(j=0;j<contAux[i];j++){
            calImc = cidades[i].pokemons[j].peso / (cidades[i].pokemons[j].altura * cidades[i].pokemons[j].altura);
            if(calImc == menorImc){
                printf("//%s//\t",cidades[i].tipos);
                printf("//%s//\t",cidades[i].pokemons[j].nome);
                printf("//%s//\t",cidades[i].pokemons[j].especie);
                printf("//%.1f//\t",cidades[i].pokemons[j].peso);
                printf("//%.2f//\t",cidades[i].pokemons[j].altura);
                printf("//%d//\n",cidades[i].pokemons[j].poder);
            }
        }
    }
    printf("\n");
}

int cidadeMaisPokemons(city * cidades,int qtCidades,int * contAux){
    int i;
    int maisPokemons = contAux[0];

    for(i=0;i<qtCidades;i++){
        if(maisPokemons<contAux[i]){
            maisPokemons = contAux[i];
        }
    }

    printf("\nCidades com mais pokemons\n");

    for(i=0;i<qtCidades;i++){
        if(contAux[i] == maisPokemons){
            printf("%s",cidades[i].nomes);
        }
        if((i<qtCidades-1)&&(contAux[i] == maisPokemons)){
            printf(",");
        }
    }
    printf("\n\n");
}

int main(){
//     system("color F1");
    city * principal = (city *)malloc(TAM * sizeof(city));
    int * qtPokCidade = (int *)malloc(TAM * sizeof(int));
    int qtCidades;

    qtCidades = lerArquivoPrincipal(principal);
    lerCidades(principal,qtCidades,qtPokCidade);

    operacoes(principal,qtCidades,qtPokCidade);

    // system("pause");
}
