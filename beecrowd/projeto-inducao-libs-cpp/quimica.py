while True:
    N = int(input())
    if N == 0:
        break
    recipientes = []
    for x in range(N):
        case = 0
        # Input da formula
        formula = input()
        # Processando string da formula
        formula = formula.replace(" ", "")
        partial1 = formula.split('+')
        s1 = partial1[0]
        partial2 = partial1[1].split('->')
        s2 = partial2[0]
        s3 = partial2[1]
        # Processando caso de uso da combinacao de substancias
        checkSubsExists = lambda s : True if s in recipientes else False
        if(checkSubsExists(s1) and checkSubsExists(s2)):
            case = 3
        elif (checkSubsExists(s1)):
            case = 2
        elif (checkSubsExists(s2)):
            case = 1
        # Processando o gerenciamento de recipientes
        if case == 0:
            emptyRec = "" in recipientes
            if emptyRec:
                recipientes[recipientes.index("")] = s3
            else:
                recipientes.append(s3)
        elif case == 1:
            s2Pos = recipientes.index(s2)
            recipientes[s2Pos] = s3
        elif case == 2:
            s1Pos = recipientes.index(s1)
            recipientes[s1Pos] = s3
        elif case == 3:
            s1Pos = recipientes.index(s1)
            s2Pos = recipientes.index(s2)
            recipientes[s1Pos] = s3
            recipientes[s2Pos] = ""
        lastSub = s3
    print(s3 + " requires " + str(len(recipientes)) + " containers")
