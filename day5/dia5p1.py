with open('input.txt', 'r') as file:
    linhas = file.read().splitlines()

intervalos = []

numeros=[]

for linha in linhas:
    valores = linha.strip()
    if not valores:
        continue
    if '-' in valores:
        v1,v2 = valores.split('-')
        intervalo = (v1,v2)
        intervalos.append(intervalo)
    else:
        numeros.append(valores)



def verificar(n,intv):
    n = int(n)
    for inicio,fim in intv:
        inicio = int(inicio)
        fim = int(fim)
        
        if inicio <= n <=fim:
            print(n,inicio,fim)
            return 1
    return 0

fresh = 0

for i in numeros:
    fresh = fresh + verificar(i,intervalos)

print(fresh)

