while True:
    N = int(input())
    if N == 0:
        break

    recipientes = []  # lista de recipientes, pode ser vazia ou já conter substâncias.
    substancias = {}  # dicionário para mapear substâncias a recipientes

    for _ in range(N):
        formula = input().replace(" ", "")
        s1, rest = formula.split('+')
        s2, s3 = rest.split('->')

        # Verificar se as substâncias s1 e s2 já estão em recipientes
        if s1 in substancias and s2 in substancias:
            # Caso em que ambas as substâncias já estão em recipientes
            r1 = substancias[s1]
            r2 = substancias[s2]
            # Esvaziar um recipiente (pode ser qualquer um dos dois)
            recipientes[r2] = ""  # esvaziar o recipiente de s2
            recipientes[r1] = s3  # adicionar a nova substância no recipiente de s1
            substancias[s3] = r1  # mapeia a nova substância ao recipiente usado
        elif s1 in substancias:
            # Caso onde s1 já está em recipiente
            r1 = substancias[s1]
            recipientes[r1] = s3  # armazena s3 no recipiente de s1
            substancias[s3] = r1  # mapeia a nova substância
        elif s2 in substancias:
            # Caso onde s2 já está em recipiente
            r2 = substancias[s2]
            recipientes[r2] = s3  # armazena s3 no recipiente de s2
            substancias[s3] = r2  # mapeia a nova substância
        else:
            # Caso onde ambas as substâncias são novas e precisam de recipientes
            recipientes.append(s3)  # cria um novo recipiente para a substância s3
            substancias[s3] = len(recipientes) - 1  # mapeia a substância ao recipiente

    # Contando o número de recipientes utilizados (não importa se estão vazios ou não)
    recipientes_usados = len([r for r in recipientes if r != ""])  # conta todos recipientes usados
    total_recipientes = len(recipientes)  # total de recipientes usados no processo
    print(f"{s3} requires {total_recipientes} containers")
