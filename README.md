# Covid-genoma-analysis

# Questão 3 - Covid genoma analysis (questão adaptada do professor Rodrigo Nonamor da UFRPE):

# Nesta tarefa, você deverá ler o genoma do Coronavirus em blocos consecutivos de 6 bases nitrogenadas (as bases são identificadas pelas letras A, T, C, G). Cada linha do genoma tem 60 letras, então, em cada linha, você deverá ler 10 blocos. Por exemplo, a primeira linha do arquivo é

# ATTAAAGGTTTATACCTTCCCAGGTAACAAACCAACCAACTTTCGATCTCTTGTAGATCT

# O primeiro bloco é ATTAAA, o segundo é AGGTTT, e assim por diante.
# Seu objetivo é contar, para cada bloco de 6 bases, quantas vezes esse bloco é encontrado no genoma inteiro, durante a leitura (de blocos consecutivos de 6 caracteres). Por exemplo, o primeiro bloco, ATTAAA, repete-se 25 vezes no genoma, em posições diversas (abra o arquivo em um editor de texto e faça uma busca). Todavia, contando-se somente blocos de 6 em 6 símbolos, a partir do começo de cada linha, há somente 3 blocos iguais a ATTAAA no genoma inteiro. É esse último número que seu programa deve encontrar.

# Para isso, você deverá utilizar uma tabela de espalhamento (hash table que você irá implementar) para armazenar os blocos de 6 bases. Também deverá criar uma função de espalhamento que, dado o bloco de 6 bases, produz um inteiro (uma posição na tabela). Para tratamento de colisões, você pode usar encadeamento externo (ex. uma lista ligada de strings) ou encadeamento interno (ex. double hashing).

# Input: arquivo texto contendo o primeiro genoma completo sequenciado do Coronavirus, sequência NC_045512.2 no NCBI (https://www.ncbi.nlm.nih.gov)
# Output: arquivo texto contendo duas colunas: a primeira, são os blocos de 6 bases; a segunda, o número de ocorrências de cada bloco (esse arquivo deve ser gerado pelo seu programa).
