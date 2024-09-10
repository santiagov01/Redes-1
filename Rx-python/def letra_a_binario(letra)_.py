def letra_a_binario(letra):
    conversion = {
        'R': '00',
        'G': '01',
        'B': '10',
        'M': '11'
    }
    return conversion.get(letra, '')

def binario_a_hexadecimal(binario):
    return hex(int(binario, 2))[2:].upper()  

def main():
    secuencia_binaria = ''

    print("Ingrese las letras R, G, B, M para construir la secuencia binaria:")
    print("Ingrese la letra C para finalizar la secuencia.")
    
    while True:
        char = input("Ingrese una letra (B, R, G, M, C): ").strip().upper()
        
        if char == 'C':
            break
        elif char in ['B', 'R', 'G', 'M']:
            secuencia_binaria += letra_a_binario(char)
        else:
            print("Letra inválida, intente de nuevo.")
            continue

    secuencia_hexadecimal = ''
    for i in range(0, len(secuencia_binaria), 4):
        bloque_binario = secuencia_binaria[i:i+4]
        if len(bloque_binario) < 4:
            bloque_binario = bloque_binario.ljust(4, '0')
        secuencia_hexadecimal += binario_a_hexadecimal(bloque_binario)

    print(f"Secuencia hexadecimal: {secuencia_hexadecimal}")

if __name__ == "__main__":
    main()
