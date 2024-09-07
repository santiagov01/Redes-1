def imprimir_matriz(matriz):
    for fila in matriz:
        print(''.join(fila))

def main():
    matriz = []
    fila_actual = []
    num_columnas = None
    
    while True:
        char = input("Ingrese una letra (A, R, V, Y): ").strip().upper()
        
        if char == 'A':
            fila_actual.append('[*]')  # Celda negra
        elif char == 'R':
            fila_actual.append('[ ]')  # Celda blanca
        elif char == 'V':
            if fila_actual:
                matriz.append(fila_actual)
                num_columnas = len(fila_actual)
                print(f"Se ha completado una fila con {num_columnas} columnas.")
                fila_actual = []
        elif char == 'Y':
            if fila_actual:
                matriz.append(fila_actual)
            break
        else:
            print("Letra inválida, intente de nuevo.")
            continue

        if num_columnas is not None and len(fila_actual) == num_columnas:
            matriz.append(fila_actual)
            fila_actual = []

    print("\nMatriz final:")
    imprimir_matriz(matriz)

if __name__ == "__main__":
    main()
