import numpy as np


with open('input.txt', 'r') as file:
    linhas = file.read().splitlines()


matrix = np.array([list(linha) for linha in linhas])


def verificar(i,j,linhas,colunas):
    cont = 0
    adjacentes = [(-1, -1), (-1, 0), (-1, 1),(0, -1),(0, 1),(1, -1),  (1, 0),  (1, 1)]
    for x,y in adjacentes:
        ni, nj = i+x, j+y
        if 0 <= ni < linhas and 0 <= nj < colunas:
            if matrix[ni,nj]=='@':
                cont=cont+1
    return cont;





linhas,colunas = matrix.shape
rolls = 0
for i in range(linhas):
    for j in range(colunas):
        if matrix[i,j]=='@':
            ver = verificar(i,j,linhas,colunas)
            if ver < 4:
                rolls = rolls + 1

print(rolls)
