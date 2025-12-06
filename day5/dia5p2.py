with open('input.txt', 'r') as file:
    linhas = file.read().splitlines()

intervalos = []

for linha in linhas:
    valores = linha.strip()
    if not valores:
        continue
    if '-' in valores:
        v1, v2 = valores.split('-')
        intervalo = [int(v1), int(v2)]
        intervalos.append(intervalo)

intervalos.sort()

def test():
    i = 0
    while i < len(intervalos) - 1:
        s, f = intervalos[i]
        s_prox, f_prox = intervalos[i + 1]
        if s <= s_prox <= f:
            intervalos[i] = [s, max(f, f_prox)]
            del intervalos[i + 1]
        else:
            i += 1

test()
valor = 0
for s,f in intervalos:
    valor = valor+f-s+1


print(valor)