# leituraDeArquivosPokemon
Trabalho feito na disciplina de Programação 2 no qual deveríamos fazer uma leitura de dados de um arquivo e mostrar dados específicos

Especificação
Considere que um Pokemon (struct) e uma Cidade (struct) sejam definidos da seguinte
forma:
Pokemon: Nome / Espécie / Peso / Altura / Poder
Cidade: Nome / Tipo / Arquivo / Pokemons (vetor de 5000 de tamanho)

Faça um programa que leia cidades em um arquivo (cidades.txt). O formato do
arquivo pode ser visualizado no exemplo abaixo (não teremos mais que 5000 cidades):
CeruleanCity Água celulean.txt
LavenderTown Fogo lavender.txt
...
ViridianCity Água viridian.txt

A partir desse arquivo, pegue os nomes dos arquivos de cada uma das cidades. Com
esses nomes de arquivos será possível ler os pokemons de cada cidade. Vejamos, por
exemplo, o arquivo celulean.txt:
Samy Squirtle 30 1,20 120
Loly Blastoise 200 1,80 300
...
Pix Goldeen 10 0,90 120

Veja que o arquivo de cidades obedeceu ao seguinte formato:
nome da cidade tipo arquivo
Veja que o arquivo de uma cidade obececeu ao seguinte formato:
nome> espécie peso altura poder
