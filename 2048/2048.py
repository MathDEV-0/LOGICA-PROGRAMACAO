n = (int(input("")))

while(n != 0):
    matriz = []
    check2048 = False

    for i in range(4):
        linha = []
        for j in range(4):
            num = int(input("Digite um número :"))
            if num == 2048:
                check2048 = True
            linha.append(num)
        matriz.append(linha)
        
        if(check2048):
            print("NONE\n")
            n = n-1
            continue

    Left, Right, Up, Down = False, False, False, False

    #Verificação da esquerda (j-1)
    for i in range(4):
        for j in range(1,4):
            if((matriz[i][j] != 0 and matriz[i][j-1] == 0) or (matriz[i][j] != 0 and matriz[i][j] == matriz[i][j-1])):
                Left = True
        
    #Verificação da direita
    for i in range(4):
        for j in range(3):
            if((matriz[i][j] != 0 and matriz[i][j+1] == 0) or (matriz[i][j] != 0 and matriz[i][j] == matriz[i][j+1])):
                Right = True

    #Verificação de cima (i-1)
    for i in range(1,4):
        for j in range(4):
            if((matriz[i][j] != 0 and matriz[i-1][j] == 0) or (matriz[i][j] != 0 and matriz[i][j] == matriz[i-1][j])):
                Up = True

    #Verificação de baixo (i+1)
    for i in range(3):
        for j in range(4):
            if((matriz[i][j] != 0 and matriz[i+1][j] == 0) or (matriz[i][j] != 0 and matriz[i][j] == matriz[i+1][j])):
                Down = True
        
    if(not Left and not Right and not Up and not Down):
        print("NONE\n")
    else:
        movimentos = []
        if Down:
            movimentos.append("DOWN")
        if Left:
            movimentos.append("LEFT")
        if Right:
            movimentos.append("RIGHT")
        if Up:
            movimentos.append("UP")

        
        print(" ".join(movimentos))
        print()

    n -= 1