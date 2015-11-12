# pmt
Programa desenvolvido em C++, similar ao [Grep-GNU](https://www.gnu.org/software/grep/) para busca de padrões em texto.  

Estrutura principal do projeto:

```
pmt/ 
 +-- doc/
 +-- src/
 +-- README
 +-- LICENSE
 ```
 
## Guia de Execução

####Criar um executável

- clone ou baixe esse o projeto em seu computador

- extraia o arquivo baixado ou acesssa a pasta a qual o projeto foi clonado e navegue até o diretório **pmt/src/** ou **pmt-master/src/**

- abra seu terminal(Shell) e execute execute o comando **cd** afim de chegar até o diretório **pmt/src/** ou **pmt-master/src/**

- estando dentro do diretório **pmt/src/** ou **pmt-master/src/** na linha de comando em seu terminal execute o comando ***make***

Após realizar os passos indicados acima, será criada uma pasta **bin/** no diretório **pmt** contendo os arquivos **.o** e o executável do programa.

Exemplo da estrutura gerada:
```
pmt/ 
 +-- bin/ <--- executável aqui
     +--obj/ 
 +-- doc/
 +-- src/
 +-- README
 +-- LICENSE
 ```

####Executar o programa

- após a execução dos passos [Criar um executável](https://github.com/lab-experiments/pmt/#criar-um-executável), acesse via terminal o diretório onde seu executável se encontra - **pmt/bin/** ou ou **pmt-master/bin/**- execute o comando ***./pmt -h*** ou ***./pmt --help*** para fins de compreensão dos parâmetros de entrada do programa. 

- para realizar um busca é necessário que os arquivos  de texto e/ou padrões estajam no mesmo diretório do arquivo executável do programa(**pmt/bin/** ou ou **pmt-master/bin/**) ou que seja passado como parâmetro o caminho absoluto;


## Comandos

####Busca Padrão(exata)

```
$ pmt pattern textfile [textfile...]
```
-  ***pattern***: uma string com o padrão para busca no texto.

-  ***textfile***: arquivo(s) com extensão .txt, podendo ser um ou vários. Os arquivos podem ser lidos via [wildcard](https://www.gnu.org/software/make/manual/html_node/Wildcard-Examples.html) ex:pagina*.txt (Obs.Arquivos serão lidos pela ordem de inserção.)


```
$ pmt --pattern patternfile textfile [textfile...]

    ou

$ pmt -p patternfile textfile [textfile...]
```
-   ***-p**, ***--pattern***: opção de argumento para padrão via arquivo de texto
 
-   ***patternfile***: arquivo de texto com extensão .txt, podendo conter um ou mais padrões por linha. 
Para mais de um arquivo de texto para busca e mais de um padrão de texto, cada padrão(linha do arquivo), será executado uma busca em todos os textos.

-  ***textfile***: arquivo(s) com extensão .txt, podendo ser um ou vários. Os arquivos podem ser lidos via [wildcard](https://www.gnu.org/software/make/manual/html_node/Wildcard-Examples.html) ex:pagina*.txt (Obs.Arquivos serão lidos pela ordem de inserção.)


```
$pmt --help
    ou
$pmt -h
```
- ***-h, --help***: obter informações sobre os parâmetros utilizados 



##Algoritmo utilizado:

Boyer Moore: 
 -   http://goo.gl/JOudnG
 -   http://goo.gl/JwNtXh




Para mais informações acesse a Wiki do projeto. 
