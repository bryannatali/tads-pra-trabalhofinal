## Trabalho Final de PRA - TADS
`Realizado por: Bryan Gustavo Natali e Henrique Pinheiro Amaral Almeida Santos`

## Árvores AVL, Rubro Negra e B

Os arquivos relacionados às árvores estão localizados no diretório app/trees. Dentro da pasta src estão todos os arquivos utilizados para rodar o programa em C. Dentro da pasta dist estão os arquivos compilados de cada árvore.

Os arquivos de saída gerados pelos programas estão no formato .csv, localizados na `raiz` do projeto.

## Apresentação dos Gráficos

Os gráficos estão sendo apresentados em uma aplicação React `(frontend)` utilizando os dados dos arquivos .csv que estão sendo servidos por um servidor em node `(backend)`.

Para rodar os gráficos, é necessário ter o Node (v14 ou maior) instalado em sua máquina.

Para rodar o `backend` basta acessar o diretório app/backend e rodar os seguintes comandos:
 - npm install
 - npm run dev

Após isso o servidor em node estará em funcionamento, e para rodar a aplicação do `frontend` entre no diretório app/frontend e execute os seguintes comandos:
 - npm install
 - npm run start

Pronto, agora ao acessar em seu navegador o link: `http://localhost:3000` será possível visualizar os gráficos de comparação entre as árvores.