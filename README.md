# Leitura de Arquivos - Pokemon
Trabalho feito na disciplina de Programação 2 no qual deveríamos fazer uma leitura de dados de um arquivo e mostrar dados específicos
Com a tematica de Pokemon

**Especificação**
Considere que um Pokemon (struct) e uma Cidade (struct) sejam definidos da seguinte
forma:
1. Pokemon: Nome / Espécie / Peso / Altura / Poder
2. Cidade: Nome / Tipo / Arquivo / Pokemons (vetor de 5000 de tamanho)

Faça um programa que leia cidades em um arquivo (cidades.txt). O formato do
arquivo pode ser visualizado no exemplo abaixo (não teremos mais que 5000 cidades):
1. CeruleanCity Água celulean.txt
2. LavenderTown Fogo lavender.txt
3. ViridianCity Água viridian.txt

A partir desse arquivo, pegue os nomes dos arquivos de cada uma das cidades. Com
esses nomes de arquivos será possível ler os pokemons de cada cidade. Vejamos, por
exemplo, o arquivo celulean.txt:
1. Samy Squirtle 30 1,20 120
2. Loly Blastoise 200 1,80 300
3. Pix Goldeen 10 0,90 120

Veja que o arquivo de cidades obedeceu ao seguinte formato:
1. nome da cidade / tipo / arquivo

Veja que o arquivo de uma cidade obececeu ao seguinte formato:
1. nome / espécie / peso / altura / poder

**Requisitos**
1. Os dados dos pokemons de “Fogo” encontrados nos arquivos,
apresentados por cidade (note que será necessário buscar as cidades do tipo =
“Fogo” e imprimir todos os dados dos pokemons dessas cidades)
2. Os dados do pokemon mais poderoso dentre todas as cidades(se houver
empate, imprimir todos).
3. O menor IMC encontrado e os dados dos pokemons com esse IMC (o
IMC – indíce de massa corporea é dado por Peso ÷ (Altura × Altura)
4. A cidade com mais pokemons (se houver empate imprimir todas
separadas por ‘,’ ).
